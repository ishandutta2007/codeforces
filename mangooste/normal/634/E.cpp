#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, val, ans;
vector<int> a;
vector<vector<int>> G;
vector<int> sz, cnt_one, dp;
vector<array<pair<int, int>, 2>> mx;

void calc_dp(int v, int pr) {
  sz[v] = 1;
  cnt_one[v] += (a[v] >= val ? 1 : 0);
  for (auto u : G[v]) {
    if (u != pr) {
      calc_dp(u, v);
      sz[v] += sz[u];
      cnt_one[v] += cnt_one[u];
      if (sz[u] == cnt_one[u]) {
        dp[v] += sz[u];
      } else {
        if (mx[v][0].first <= dp[u]) {
          mx[v][1] = mx[v][0];
          mx[v][0] = make_pair(dp[u], u);
        } else if (mx[v][1].first <= dp[u]) {
          mx[v][1] = make_pair(dp[u], u);
        }
      }
    }
  }
  dp[v] += mx[v][0].first;
  if (a[v] < val) {
    dp[v] = 0;
  } else {
    dp[v]++;
  }
}

void calc_ans(int v, int pr) {
  ans = max(ans, dp[v]);
  for (auto u : G[v]) {
    if (u != pr) {
      // save dp
      array<pair<int, int>, 2> was_mx_v = mx[v];
      array<pair<int, int>, 2> was_mx_u = mx[u];
      int was_dp_v = dp[v];
      int was_dp_u = dp[u];
      int was_sz_v = sz[v];
      int was_sz_u = sz[u];
      int was_cnt_one_v = cnt_one[v];
      int was_cnt_one_u = cnt_one[u];
      // recalc dp v
      dp[v] -= mx[v][0].first;
      if (sz[u] == cnt_one[u]) {
        dp[v] -= dp[u];
      } else if (u == mx[v][0].second) {
        swap(mx[v][0], mx[v][1]);
      }
      dp[v] += mx[v][0].first;
      sz[v] -= sz[u];
      cnt_one[v] -= cnt_one[u];
      if (a[v] < val) {
        dp[v] = 0;
      }
      //recalc dp u
      dp[u] -= mx[u][0].first;
      if (sz[v] == cnt_one[v]) {
        dp[u] += dp[v];
      } else {
        if (mx[u][0].first <= dp[v]) {
          mx[u][1] = mx[u][0];
          mx[u][0] = make_pair(dp[v], v);
        } else if (mx[u][1].first <= dp[v]) {
          mx[u][1] = make_pair(dp[v], v);
        }
      }
      dp[u] += mx[u][0].first;
      sz[u] += sz[v];
      cnt_one[u] += cnt_one[v];
      if (a[u] < val) {
        dp[u] = 0;
      }
      // relax ans
      calc_ans(u, v);
      // backup dp
      mx[v] = was_mx_v;
      mx[u] = was_mx_u;
      dp[v] = was_dp_v;
      dp[u] = was_dp_u;
      sz[v] = was_sz_v;
      sz[u] = was_sz_u;
      cnt_one[v] = was_cnt_one_v;
      cnt_one[u] = was_cnt_one_u;
    }
  }
}

bool check() {
  sz.assign(n, 0);
  cnt_one.assign(n, 0);
  dp.assign(n, 0);
  mx.assign(n, {make_pair(0, -1), make_pair(0, -1)});
  calc_dp(0, 0);
  ans = 0;
  calc_ans(0, 0);
  return ans >= k;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  int L = 0, R = *max_element(a.begin(), a.end()) + 1;
  while (R - L > 1) {
    val = (R + L) / 2;
    if (check()) {
      L = val;
    } else {
      R = val;
    }
  }
  cout << L << '\n';
}