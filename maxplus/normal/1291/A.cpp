#include<iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
      sum += s[i] - '0';
    }
    if (sum % 2 == 1) {
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] % 2 == 1) {
          s = s.substr(0, i) + s.substr(i + 1);
          break;
        }
      }
    }
    while (!s.empty() && s.back() % 2 == 0) {
      s.pop_back();
    }
    while (s.front() == '0') {
      s = s.substr(1);
    }
    if (s.empty()) {
      cout << "-1\n";
    } else {
      cout << s << '\n';
    }
  }
}