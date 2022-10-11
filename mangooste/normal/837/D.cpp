#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXSUM = 200 * 27;
int n, k;
vector<int> p2, p5;
vector<vector<int>> dp, new_dp;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  p2.assign(n + 1, 0);
  p5.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    while (a % 2 == 0) {
      p2[i + 1]++;
      a /= 2;
    }
    while (a % 5 == 0) {
      p5[i + 1]++;
      a /= 5;
    }
  }
  dp.resize(k + 1, vector<int>(MAXSUM, -1));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    new_dp.assign(k + 1, vector<int>(MAXSUM, -1));
    for (int cnt = 0; cnt <= k; cnt++) {
      for (int sum = 0; sum < MAXSUM; sum++) {
        if (dp[cnt][sum] != -1) {
          new_dp[cnt][sum] = dp[cnt][sum];
        }
      }
    }
    for (int cnt = 1; cnt <= k; cnt++) {
      for (int sum = p5[i]; sum < MAXSUM; sum++) {
        if (dp[cnt - 1][sum - p5[i]] != -1) {
          new_dp[cnt][sum] = max(new_dp[cnt][sum], dp[cnt - 1][sum - p5[i]] + p2[i]);
        }
      }
    }
    dp = new_dp;
  }
  int ans = 0;
  for (int i = 0; i < MAXSUM; i++) {
    if (dp[k][i] != -1) {
      ans = max(ans, min(dp[k][i], i));
    }
  }
  cout << ans << '\n';
}