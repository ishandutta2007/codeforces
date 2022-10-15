// hi, do you like chtholly?
// if you don't it's fine, i don't as well

#include <iostream>
const int mod = 998244353;
void solve() {
  int n, k;
  std::cin >> n >> k;
  int a[n + 1], b[k + 1], idx[n + 1], ono[n + 1] = {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> b[i];
    ono[idx[b[i]]] = 1;
  }
  ono[0] = ono[n + 1] = 1;
  int ans = 1;
  for (int i = 1; i <= k; i++) {
    if (ono[idx[b[i]] - 1] && ono[idx[b[i]] + 1]) ans = 0;
    else if (!ono[idx[b[i]] - 1] && !ono[idx[b[i]] + 1]) (ans *= 2) %= mod;
    ono[idx[b[i]]] = 0;
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}