#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

array<int, 3> cnt;
vector<array<int, 3>> dp;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, L, R;
  cin >> n >> L >> R;
  while (L % 3 != 0 && L <= R) {
    cnt[L % 3]++;
    L++;
  }
  while (R % 3 != 2 && R >= L) {
    cnt[R % 3]++;
    R--;
  }
  for (int i = 0; i < 3; i++) {
    cnt[i] += (R - L + 1) / 3;
  }
  dp.assign(n + 1, {0, 0, 0});
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int cur = 0; cur < 3; cur++) {
        int jj = (j - cur + 3) % 3;
        dp[i][j] += 1ll * dp[i - 1][jj] * cnt[cur] % MOD;
        if (dp[i][j] >= MOD) {
          dp[i][j] -= MOD;
        }
      }
    }
  }
  cout << dp[n][0] << '\n';
}