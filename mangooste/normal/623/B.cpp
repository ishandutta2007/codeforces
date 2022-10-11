#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int n;
ll delete_cost, add_cost, ans = 0;
vector<int> a, maybe;
vector<array<ll, 3>> dp;

inline void gen_maybe(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      maybe.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x != 1) {
    maybe.push_back(x);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> delete_cost >> add_cost;
  a.assign(n, 0);
  for (auto &el : a) {
    cin >> el;
  }
  for (int d = -1; d <= 1; d++) {
    gen_maybe(a[0] + d);
    gen_maybe(a.back() + d);
  }
  sort(maybe.begin(), maybe.end());
  maybe.resize(unique(maybe.begin(), maybe.end()) - maybe.begin());
  ans = delete_cost * (n - 1);
  for (auto &g : maybe) {
    dp.assign(n, {INF, INF, INF});
    if (a[0] % g == 0) {
      dp[0][0] = 0;
    } else if ((a[0] + 1) % g == 0 || (a[0] - 1) % g == 0) {
      dp[0][0] = add_cost;
    }
    dp[0][1] = delete_cost;
    for (int i = 1; i < n; i++) {
      dp[i][1] = min({dp[i][1], dp[i - 1][1] + delete_cost, dp[i - 1][0] + delete_cost});
      if (a[i] % g == 0) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        dp[i][2] = min({dp[i][2], dp[i - 1][2], dp[i - 1][1]});
      } else if ((a[i] + 1) % g == 0 || (a[i] - 1) % g == 0) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + add_cost);
        dp[i][2] = min({dp[i][2], dp[i - 1][2] + add_cost, dp[i - 1][1] + add_cost});
      }
    }
    ans = min(ans, *min_element(dp.back().begin(), dp.back().end()));
  }
  cout << ans << '\n';
}