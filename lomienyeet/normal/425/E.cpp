// when will i accept the fact that i will just never be as good as other people?

#include <iostream>
#pragma GCC optimize ("Ofast, inline, unroll-loops")
#define int long long
const int mod = 1e9 + 7;
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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  std::cin >> n >> k;
  int dp[2][k + 5][n + 5];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= k + 4; j++) {
      for (int e = 0; e <= n + 4; e++) dp[i][j][e] = 0;
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int e = 0; e <= i; e++) {
        if (!dp[0][j][e]) continue;
        int z = bm(2, e);
        (dp[1][j][e] += (dp[0][j][e] * z) % mod) %= mod;
        int aaa = ((bm(2, i - e + 1) - 1 + mod) % mod * z) % mod;
        (dp[1][j + 1][i + 1] += (dp[0][j][e] * aaa) % mod) %= mod;
      }
    }
    for (int j = 0; j <= k; j++) {
      for (int e = 0; e <= n; e++) {
        dp[0][j][e] = dp[1][j][e];
        dp[1][j][e] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) (ans += dp[0][k][i]) %= mod;
  std::cout << ans << "\n";
}