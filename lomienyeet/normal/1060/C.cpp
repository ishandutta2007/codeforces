/* 


WACF


dp

HLDGCD



code
OI




code

 fast io afo
pragmaavx



OI

rp
*/

#include <iostream>
#include <algorithm>
int mod = 1e9 + 7;
void m998() { mod = 998244353; } // 
const int mxN = 4e6 + 5;
int dp[2][mxN];
void eat() {
  int n, m, x;
  std::cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::cin >> x;
  for (int i = 1; i <= n; i++) {
    int pp = 0;
    for (int j = i; j <= n; j++) {
      pp += a[j];
      dp[0][pp] = std::max(dp[0][pp], j - i + 1);
    }
  }
  for (int i = 1; i < mxN; i++) dp[0][i] = std::max(dp[0][i], dp[0][i - 1]);
  for (int i = 1; i <= m; i++) {
    int pp = 0;
    for (int j = i; j <= m; j++) {
      pp += b[j];
      dp[1][pp] = std::max(dp[1][pp], j - i + 1);
    }
  }
  for (int i = 1; i < mxN; i++) dp[1][i] = std::max(dp[1][i], dp[1][i - 1]);
  int l = 1, r = mxN - 1, ans = 0;
  while (l < mxN) {
    while (l * r > x) r--;
    ans = std::max(ans, dp[0][l++] * dp[1][r]);
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}