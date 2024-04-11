#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 5010;

int low[N];
int high[N];
int dp[N][N];
int n, a, b, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b >> k;
  for (int i = 1; i <= n; i++) {
    low[i] = n;
    high[i] = 0;
    for (int j = 1; j <= n; j++)
      if (abs(i - j) < abs(i - b)) {
	low[i] = min(low[i], j);
	high[i] = max(high[i], j);
      }
  }
  dp[0][a] = 1;
  dp[0][a + 1] = MOD - 1;
  for (int c = 0; c <= k; c++) {
    int s = 0;
    for (int f = 0; f <= n; f++) {
      s += dp[c][f];
      s %= MOD;
      dp[c][f] = s;
    }
    for (int f = 1; f <= n; f++) {
      if (low[f] < f) {
	dp[c + 1][low[f]] += dp[c][f];
	dp[c + 1][low[f]] %= MOD;
	dp[c + 1][f] += MOD - dp[c][f];
	dp[c + 1][f] %= MOD;
      }
      if (high[f] > f) {
	dp[c + 1][f + 1] += dp[c][f];
	dp[c + 1][f + 1] %= MOD;
	dp[c + 1][high[f] + 1] += MOD - dp[c][f];
	dp[c + 1][high[f] + 1] %= MOD;
      }
    }
  }
  int res = 0;
  for (int f = 1; f <= n; f++) {
    res += dp[k][f];
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}