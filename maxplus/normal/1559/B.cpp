#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
      int pb = s.rfind('B', i), pr = s.rfind('R', i);
      int nb = s.find('B', i), nr = s.find('R', i);
      (nb += n + 1) %= n + 1;
      (nr += n + 1) %= n + 1;
      if (pb > pr) {
        s[i] = (i - pb) & 1? 'R': 'B';
      } else if (pr > pb) {
        s[i] = (i - pr) & 1? 'B': 'R';
      } else if (nb < nr) {
        s[i] = (i - nb) & 1? 'R': 'B';
      } else {
        s[i] = (i - nr) & 1? 'B': 'R';
      }
    }
    cout << s << '\n';
  }
  return 0;
}