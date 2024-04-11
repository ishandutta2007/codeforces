#include <iostream>
void solve() {
  int n, m;
  std::cin >> n >> m;
  if (n == 1 && m == 1) {
    std::cout << "0\n";
    return;
  }
  if (n > m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) std::cout << (i + m) * j << " ";
      std::cout << "\n";
    }
  }
  else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) std::cout << (j + n) * i << " ";
      std::cout << "\n";
    }
  }
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}