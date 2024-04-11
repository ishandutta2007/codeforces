#include <bits/stdc++.h>

using namespace std;

int n, p;

inline bool valid(const string& s, int pos) {
  for (int i = max(0, pos - 2); i < pos; i++)
    if (s[i] == s[pos])
      return false;
  return true;
}

string solve(string s, char c, int pos) {
  s[pos] = c;
  if (!valid(s, pos))
    return "";
  for (int i = pos + 1; i < n; i++) {
    int c = -1;
    for (int j = 0; j < p; j++) {
      s[i] = j + 'a';
      if (valid(s, i)) {
        c = j;
        break;
      }
    }
    if (c == -1)
      return "";
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> p;
  string s;
  cin >> s;
  for (int i = n - 1; i >= 0; i--)
    for (int c = s[i] - 'a' + 1; c < p; c++) {
      string r = solve(s, c + 'a', i);
      if (r != "") {
        cout << r << "\n";
        return 0;
      }
    }
  cout << "NO\n";
  return 0;
}