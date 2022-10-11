#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 2e9;

int n, k;
vector<vector<int>> cost;
vector<vector<array<array<int, 2>, 6>>> dp;
vector<int> even, used;

int solve() {
  int cur_ans = INF;
  if (even.size() == k / 2 - 1) {
    cur_ans = 0;
    even.push_back(0);
    for (int i = 0, j; i < even.size(); i++) {
      int v = (i ? even[i - 1] : 0), u = even[i];
      for (j = 0; j < 6 && used[dp[v][u][j][1]]; j++);
      if (j == 6 || dp[v][u][j][1] == -1) {
        cur_ans = INF;
        break;
      }
      cur_ans += dp[v][u][j][0];
    }
    even.pop_back();
  } else {
    for (int i = 0; i < n; i++) {
      even.push_back(i);
      used[even.back()]++;
      cur_ans = min(cur_ans, solve());
      used[even.back()]--;
      even.pop_back();
    }
  }
  return cur_ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cost.assign(n, vector<int>(n, 0));
  for (auto &el : cost) {
    for (auto &ell : el) {
      cin >> ell;
    }
  }
  dp.assign(n, vector<array<array<int, 2>, 6>>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int ii = 0; ii < 6; ii++) {
        dp[i][j][ii] = {INF, -1};
      }
      for (int k = 0, ii; k < n; k++) {
        if (k != i && k != j) {
          array<int, 2> cur = {cost[i][k] + cost[k][j], k};
          for (ii = 0; ii < 6 && cur > dp[i][j][ii]; ii++);
          if (ii != 6) {
            for (int jj = 5; jj > ii; jj--) {
              dp[i][j][jj] = dp[i][j][jj - 1];
            }
            dp[i][j][ii] = cur;
          }
        }
      }
    }
  }
  even = {};
  used.assign(n, 0);
  used[0] = INF;
  cout << solve() << '\n';
}