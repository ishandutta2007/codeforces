#include <iostream>
#include <cstring>
void solve() {
  int n, q, ans = 0;
  std::cin >> n >> q;
  bool fuck[3][n + 1];
  memset(fuck, 0, sizeof fuck);
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    int c = (!fuck[a][b] ? 1 : -1);
    fuck[a][b] ^= 1;
    for (int i = -1; i < 2; i++) {
      if (b + i < 1 || b + i > n) continue;
      if (fuck[3 - a][b + i]) ans += c;
    }
    std::cout << (!ans ? "yEs\n" : "nO\n"); // still have ptsd from using ternary operators
  }
}
int32_t main(){
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}