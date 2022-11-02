#include <bits/stdc++.h>

using namespace std;

long long mod;
long long n;

long long solve(int rows, const vector<int>& cnt) {
  if (rows == 0)
    return 1;
  vector<vector<long long>> cur_dp(rows + 5, vector<long long>(rows + 5, 0));
  vector<vector<long long>> old_dp = cur_dp;
  old_dp[rows][0] = 1;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > 0) {
      for (int f0 = 0; f0 <= rows; f0++)
	for (int f1 = 0; f1 <= rows; f1++)
	  cur_dp[f0][f1] = 0;
    } else {
      cur_dp = old_dp;
    }
    if (cnt[i] == 1) {
      for (int f0 = 0; f0 <= rows; f0++)
	for (int f1 = 0; f1 <= rows; f1++) {
	  if (old_dp[f0][f1] == 0)
	    continue;
	  if (f0 > 0) {
	    cur_dp[f0 - 1][f1 + 1] += old_dp[f0][f1] * f0;
	    cur_dp[f0 - 1][f1 + 1] %= mod;
	  }
	  if (f1 > 0) {
	    cur_dp[f0][f1 - 1] += old_dp[f0][f1] * f1;
	    cur_dp[f0][f1 - 1] %= mod;
	  }
	}
    } else if (cnt[i] == 2) {
      for (int f0 = 0; f0 <= rows; f0++)
	for (int f1 = 0; f1 <= rows; f1++) {
	  if (old_dp[f0][f1] == 0)
	    continue;
	  if (f0 > 0 && f1 > 0) {
	    cur_dp[f0 - 1][f1] += old_dp[f0][f1] * f0 * 1ll * f1;
	    cur_dp[f0 - 1][f1] %= mod;
	  }
	  if (f0 >= 2) {
	    cur_dp[f0 - 2][f1 + 2] += old_dp[f0][f1] * f0 * 1ll * (f0 - 1) / 2;
	    cur_dp[f0 - 2][f1 + 2] %= mod;
	  }
	  if (f1 >= 2) {
	    cur_dp[f0][f1 - 2] += old_dp[f0][f1] * f1 * 1ll * (f1 - 1) / 2;
	    cur_dp[f0][f1 - 2] %= mod;
	  }
	}
    }
    old_dp = cur_dp;
  }
  return old_dp[0][0];
}

int main() {
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m >> mod;
  vector<int> cnt(n, 2);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      if (s[j] == '1')
	cnt[j]--;
  }
  cout << solve(n - m, cnt) << endl;
  return 0;
}