/*
reading problem: 22:22 - 22:24
thinking: 22:24 - 22:39
coding: 22:39 - 22:44
debugging: hopefully none
*/

#include <iostream>
#include <algorithm>
#define int long long
void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "0\n";
    return;
  }
  int z = 0;
  for (int i = 1; i < 31; i++) {
    if ((1ll << (i + 1)) > n) {
      z = i;
      break;
    }
  }
  int ans[z + 1] = {}, ee = (1ll << (z + 1)) - n - 1;
  for (int i = 0; i < z; i++) ans[i] = (1ll << i);
  std::reverse(ans, ans + z + 1);
  for (int i = z; i > 0; i--) {
    int a = (1ll << i) - 1;
    while (ee >= a) {
      ee -= a;
      for (int j = 1; j <= i; j++) {
        int pp = std::max(i - j - 1, 0ll);
        ans[j] -= (1ll << pp);
      }
    }
  }
  std::cout << z << "\n";
  for (int i = z; i > 0; i--) std::cout << ans[i] << " ";
  std::cout << "\n";
}
int32_t main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}