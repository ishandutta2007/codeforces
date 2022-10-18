#include <cctype>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;


int main() {
  cin.sync_with_stdio(0);

  string str;
  cin >> str;

  string output;
  for (int i=0; i<(int)str.size(); ++i) {
    int ch = tolower(str[i]);
    if (strchr("aeiouy", ch) == NULL) {
      output += '.';
      output += ch;
    }
  }
  cout << output << endl;
  
  return 0;
}