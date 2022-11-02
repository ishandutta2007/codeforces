#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  vector<string> names = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  int f;
  cin >> f;
  string s;
  cin >> s;
  for (string n : names) {
    if (n.length() != s.length())
      continue;
    bool ok = true;
    for (int i = 0; i < s.length(); i++)
      if (s[i] != '.' && n[i] != s[i])
        ok = false;
    if (ok) {
      cout << n;
      return 0;
    }
  }
  return 0;
}