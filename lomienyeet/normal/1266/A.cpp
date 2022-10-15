#include <iostream>
void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length(), wa = 0;
  s = "_" + s;
  bool ee[3] = {};
  for (int i = 1; i <= n; i++) {
    int x = s[i] - '0';
    if (ee[0] && !x) ee[1] = 1;
    if (!x) ee[0] = 1;
    else ee[2] = 1;
    if (!(x & 1) && x) ee[1] = 1;
    wa += x;
  }
  std::cout << ((!ee[2] || (ee[0] && ee[1] && !(wa % 3))) ? "red\n" : "cyan\n");
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) solve();
}