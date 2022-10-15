#include <iostream>
void solve() {
  int64_t n;
  std::cin >> n;
  std::cout << ((n > 14 && n % 14 && n % 14 < 7) ? "YES\n" : "NO\n");
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) solve();
}