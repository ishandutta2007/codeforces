#include <iostream>
#define int long long
const int mxN = 2e3 + 5, mod = 998244353;
int s2[mxN][mxN], fact[mxN];
void eat() {
  s2[0][0] = fact[0] = 1;
  for (int i = 1; i < mxN; i++) {
    for (int j = 1; j < mxN; j++) s2[i][j] = (s2[i - 1][j - 1] + s2[i - 1][j] * j) % mod;
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
int bm(int b, int p, int m = mod) {
  int ans = 1;
  b %= m;
  while (p) {
    if (p & 1) (ans *= b) %= m;
    (b *= b) %= m;
    p >>= 1;
  }
  return ans;
}
int32_t main() {
  eat();
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, k, ans = 0, cur = 1;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
      (cur *= (n - i + 1) % mod) %= mod;
      (ans += (((s2[k][i] * cur) % mod * bm((m + 1) >> 1, i)) % mod * (n - i >= 0 ? bm(m, n - i) : bm(bm(m, i - n), mod - 2))) % mod) %= mod;
    }
    std::cout << ans << "\n";
  }
}