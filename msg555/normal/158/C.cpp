#include <iostream>
#include <vector>

using namespace std;

vector<string> spl(string s) {
  int j = 0;
  vector<string> vs;
  for(int i = 0; i <= s.size(); i++) {
    if(i == s.size() || s[i] == '/') {
      vs.push_back(s.substr(j, i - j));
      j = i + 1;
    }
  }
  return vs;
}

int main() {
  int N; cin >> N;

  vector<string> pwd(1, "");
  for(int i = 0; i < N; i++) {
    string cmd; cin >> cmd;
    if(cmd == "cd") {
      string pt; cin >> pt;
      vector<string> v = spl(pt);
      if(v[0].empty()) pwd.resize(0);
      for(int j = 0; j < v.size(); j++) {
        if(v[j] == "..") {
          pwd.resize(pwd.size() - 1);
        } else {
          pwd.push_back(v[j]);
        }
      }
    } else if(cmd == "pwd") {
      for(int i = 0; i < pwd.size(); i++) {
        cout << pwd[i] << '/';
      }
      cout << endl;
    }
  }
}