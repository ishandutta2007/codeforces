#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

const int MAX_LEN = 25;
bool dp[MAX_LEN][10][10][152];
array<int, 3> parent[MAX_LEN][10][10][152];

void solve(int n, int k) {
  for (int i = 0; i < MAX_LEN; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int ii = 0; ii <= k; ii++) {
        for (int jj = 0; jj <= n; jj++) {
          dp[i][j][ii][jj] = false;
          parent[i][j][ii][jj] = {-1, -1, -1};
        }
      }
    }
  }
  for (int fir = 0; fir <= 9; fir++) {
    int when = (10 - fir > k ? 0 : 10 - fir);
    int sum = 0;
    for (int i = fir; i <= fir + k; i++) {
      sum += i % 10;
    }
    if (sum > n) {
      continue;
    }
    dp[0][fir][when][sum] = true;
  }
  for (int len = 1; len < MAX_LEN; len++) {
    for (int cur_dig = 0; cur_dig <= 9; cur_dig++) {
      for (int when = 0; when <= k; when++) {
        for (int sum = 0; sum <= n; sum++) {
          int cur_sum = 0;
          if (when == 0) {
            cur_sum = cur_dig * (k + 1);
          } else {
            cur_sum += cur_dig * when + (k - when + 1) * ((cur_dig + 1) % 10);
          }
          if (sum < cur_sum) {
            continue;
          }
          int need_sum = sum - cur_sum;
          if (when == 0) {
            if (len != 1) {
              for (int last_dig = 0; last_dig <= 8 && !dp[len][cur_dig][when][sum]; last_dig++) {
                for (int twhen = 0; twhen <= k && !dp[len][cur_dig][when][sum]; twhen++) {
                  if (dp[len - 1][last_dig][twhen][need_sum]) {
                    dp[len][cur_dig][when][sum] = true;
                    parent[len][cur_dig][when][sum] = {last_dig, need_sum, twhen};
                  } 
                }
              }
              if (!dp[len][cur_dig][when][sum] && dp[len - 1][9][when][need_sum]) {
                dp[len][cur_dig][when][sum] = true;
                parent[len][cur_dig][when][sum] = {9, need_sum, when};
              }
            } else {
              for (int last_dig = 0; last_dig <= 9 && !dp[len][cur_dig][when][sum]; last_dig++) {
                if (dp[len - 1][last_dig][when][need_sum]) {
                  dp[len][cur_dig][when][sum] = true;
                  parent[len][cur_dig][when][sum] = {last_dig, need_sum, when};
                }
              }
            }
          } else {
            for (int last_dig = (len == 1 ? 0 : 9); last_dig <= 9 && !dp[len][cur_dig][when][sum]; last_dig++) {
              if (dp[len - 1][last_dig][when][need_sum]) {
                dp[len][cur_dig][when][sum] = true;
                parent[len][cur_dig][when][sum] = {last_dig, need_sum, when};
              }
            }
          }
        }
      }
    }
  }
  bool any = false;
  string ans = "";
  for (int len = 0; len < MAX_LEN && !any; len++) {
    for (int dig = 0; dig <= 9 && !any; dig++) {
      for (int when = 0; when <= k && !any; when++) {
        if ((when != 0 && dig == 9) || (len == 0 && when != 0)) {
          continue;
        }
        if (dp[len][dig][when][n]) {
          any = true;
          int cur_len = len, cur_dig = dig, cur_sum = n, cur_when = when;
          while (cur_len >= 0) {
            ans.push_back('0' + cur_dig);
            int tdig = cur_dig;
            int tsum = cur_sum;
            int twhen = cur_when;
            cur_dig = parent[cur_len][tdig][twhen][tsum][0];
            cur_sum = parent[cur_len][tdig][twhen][tsum][1];
            cur_when = parent[cur_len][tdig][twhen][tsum][2];
            cur_len--;
          }
        }
      }
    }
  }
  if (!any) {
    cout << "-1\n";
  } else {
    reverse(ans.begin(), ans.end());
    while (!ans.empty() && ans.back() == '0') {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty()) {
      ans = "0";
    }
    cout << ans << '\n';
  }
}

void Main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    solve(n, k);
  }
}