#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    if (count(s.begin(), s.end(), '2') && count(s.begin(), s.end(), '2') < 3) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      s += s;
      for (int i = 0; i < n; ++i) {
        int loser = s.rfind('2', n + i - 1) % n;
        int winner = s.find('2', i + 1) % n;
        for (int j = 0; j < n; ++j) {
          if (i == j) {
            cout.put('X');
          } else if (s[i] == '2' && s[j] == '2' && j == loser) {
            cout.put('+');
          } else if (s[i] == '2' && s[j] == '2' && j == winner) {
            cout.put('-');
          } else {
            cout.put('=');
          }
        }
        cout << '\n';
      }
    }
  }
  return 0;
}