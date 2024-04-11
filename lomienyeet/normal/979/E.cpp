#include <iostream>
#define int long long
const int mxN = 55, mod = 1e9 + 7;
int dp[mxN][mxN][mxN][mxN], two[mxN], ans;
int eat(int a, int b) {
  if (b == 1) return (a ? two[a - 1] : 0);
  return two[a] - eat(a, 1);
}
int32_t main() {
  int n, m;
  std::cin >> n >> m;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    if (arr[i] != -1) arr[i] ^= 1;
  }
  two[0] = 1;
  for (int i = 1; i < mxN; i++) two[i] = (two[i - 1] * 2) % mod;
  dp[0][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= i - j - k; l++) {
          if (arr[i] < 1) (dp[i][j][k][l] += ((i == k) ? 0 : two[i - k - 1]) * (eat(k, 1) * (l ? dp[i - 1][j][k][l - 1] : 0) % mod + eat(k, 0) * (j ? dp[i - 1][j - 1][k][l] : 0) % mod)) %= mod;
          if (arr[i] != 0) (dp[i][j][k][l] += ((i == j) ? 0 : two[i - j - 1]) * (eat(j, 1) * dp[i - 1][j][k][l] % mod + eat(j, 0) * (k ? dp[i - 1][j][k - 1][l] : 0) % mod)) %= mod;
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n - i - j; k++) {
        if (((i + j) & 1) == m) (ans += dp[n][i][j][k]) %= mod;
      }
    }
  }
  ((ans %= mod) += mod) %= mod;
  std::cout << ans << "\n";
}