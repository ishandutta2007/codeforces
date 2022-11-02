#include <bits/stdc++.h>

using namespace std;

const int N = 2222;
const long long MOD = 1000 * 1000 * 1000 + 7;

int n, h;
int a[N];
long long dp[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> h;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int delta = 0; delta <= 2000; delta++)
      for (int dx = -1; dx <= 1; dx++) {
        int c_val = delta + dx;
        if (c_val < 0 || a[i] + c_val != h)
          continue;
        dp[i + 1][c_val] = (dp[i + 1][c_val] + dp[i][delta]) % MOD;
        if (dx == 0 && delta > 0)
          dp[i + 1][c_val] = (dp[i + 1][c_val] + delta * dp[i][delta]) % MOD;
        if (dx == -1 && delta > 0)
          dp[i + 1][c_val] = (dp[i + 1][c_val] + (delta - 1) * dp[i][delta]) % MOD;
      }
  cout << (dp[n][0] + dp[n][1]) % MOD;
  return 0;
}