#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int timer = 0;
vector<vector<int>> G;
vector<int> used, par;

bool dfs(int v) {
  used[v] = timer;
  for (auto u : G[v]) {
    if (par[u] == -1) {
      par[u] = v;
      return true;
    }
  }
  for (auto u : G[v]) {
    if (used[par[u]] != timer && dfs(par[u])) {
      par[u] = v;
      return true;
    }
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> edges;
  int def = 0;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    if (edges.find({v, u}) != edges.end()) {
      def++;
    }
    edges.insert({v, u});
  }
  int ans = 1e9;
  for (int c = 0; c < n; c++) {
    G.assign(n, {});
    timer = 0;
    used.assign(n, -1);
    par.assign(n, -1);
    int res = def;
    for (int i = 0; i < n; i++) {
      res += (edges.find({c, i}) == edges.end());
      res += (i != c) * (edges.find({i, c}) == edges.end());
    }
    res += n - 1;
    for (auto &[v, u] : edges) {
      if (v != c && u != c) {
        G[v].push_back(u);
        res++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != c) {
        res -= 2 * dfs(i);
        timer++;
      }
    }
    ans = min(ans, res);
  }
  cout << ans;
}