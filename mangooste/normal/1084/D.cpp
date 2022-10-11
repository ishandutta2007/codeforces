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

const ll INF = (ll)1e18;
int n;
vector<int> w;
vector<vector<pair<int, int>>> G;
vector<ll> dp;
ll ans = -INF;

void dfs(int v, int pr) {
  dp[v] = w[v];
  vector<ll> curs;
  for (auto [u, c] : G[v]) {
    if (u != pr) {
      dfs(u, v);
      dp[v] = max(dp[v], dp[u] + w[v] - c);
      curs.push_back(dp[u] + w[v] - c);
    }
  }
  sort(curs.rbegin(), curs.rend());
  if (curs.size() > 1) {
    ans = max(ans, curs[0] + curs[1] - w[v]);
  }
  ans = max(ans, dp[v]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  w.resize(n);
  for (auto &el : w) {
    cin >> el;
  }
  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u, c;
    cin >>  v >> u >> c;
    v--, u--;
    G[v].emplace_back(u, c);
    G[u].emplace_back(v, c);
  }
  dp.assign(n, -INF);
  dfs(0, 0);
  cout << ans << '\n';
}