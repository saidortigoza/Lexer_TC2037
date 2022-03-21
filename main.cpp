#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> extraerArchivo (string archivo) {
  ifstream inputFile(archivo);
  string line;
  vector<string> aux;
  if (inputFile.is_open()){
    while(getline(inputFile, line)) {
      aux.push_back(line);
    }
  }
  inputFile.close();
  return aux;
}
void printIdentificador (string str) {
  regex reg("[^0-9][a-zA-Z_]+[a-zA-Z_0-9]*");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : VARIABLE" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printInt (string str) {
  regex reg("\\d+(?!.)");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : INTEGER" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printReal (string str) {
  regex reg("[+-]*[0-9]+[.][0-9]+([eE][+-][0-9]+)?");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : REAL" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printSum (string str) {
  regex reg("[+]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : SUMA" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printAsig (string str) {
  regex reg("[=]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : ASSIGMENT" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printMult(string str) {
  regex reg("[*]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : MULTIPLICATION" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printComment(string str) {
  regex reg("[/][/][ a-zA-Z0-9]*");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : COMMENT" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printDiv(string str) {
  regex reg("(?!\\/\\/)[/]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : DIVISION" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printMinus(string str) {
  regex reg("[-]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : SUBTRACTION" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printOpenParenthesis(string str) {
  regex reg("[(]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : LEFT PARENTHESIS" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printCloseParenthesis(string str) {
  regex reg("[)]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : RIGHT PARENTHESIS" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void printPower(string str) {
  regex reg("[\\^]");
  sregex_iterator currentMatch(str.begin(), str.end(), reg);
  sregex_iterator lastMatch;
  while (currentMatch != lastMatch) {
    smatch match = *currentMatch;
    cout << match.str() << " : POWER" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    currentMatch++;
  }
}

void clasificarColumna (string str) {

  printIdentificador(str);
  printInt(str);
  printDiv(str);
  printReal(str);
  printSum(str);
  printAsig(str);
  printMult(str);
  printComment(str);
  printMinus(str);
  printOpenParenthesis(str);
  printCloseParenthesis(str);
  printPower(str);
}

void lexerAritmetico(string archivo) {
  vector<string> aux;
  vector<string>::iterator itr;
  aux = extraerArchivo(archivo);
  string auxStr;

  cout << "Token                                  |Type                                   \n";
  cout << "--------------------------------------------------------------------------------" << endl;
  for (int i = 0; i < aux.size(); i++) {
    auxStr = aux[i];
    clasificarColumna(auxStr);
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "usage: " << argv[0] << " pathname\n";
    return -1;
  }
  lexerAritmetico(argv[1]);

  return 0;
}
