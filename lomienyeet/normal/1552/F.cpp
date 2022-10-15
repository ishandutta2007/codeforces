#include <iostream>
#include <algorithm>
const int mod = 998244353;
void eat() {
  int n;
  std::cin >> n;
  int aa[n + 1], bb[n + 1], cc[n + 1], ps[n + 1] = {};
  for (int i = 1; i <= n; i++) std::cin >> aa[i] >> bb[i] >> cc[i];
  int ans = (aa[n] + 1) % mod;
  for (int i = 1; i <= n; i++) {
    int z = (aa[i] - bb[i]) % mod, wa = std::upper_bound(aa + 1, aa + n + 1, bb[i]) - aa;
    if (wa < i) (z += (ps[i - 1] - ps[wa - 1] + mod) % mod) %= mod;
    ps[i] = (ps[i - 1] + z) % mod;
    if (cc[i]) (ans += z) %= mod;
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}