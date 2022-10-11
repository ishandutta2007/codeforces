#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> G;
vector<vector<int>> jump;
vector<int> del, sz, dep;
vector<ll> dp_all, dp_down;

void dfs1(int v, int pr) {
  dp_down[v] = 0;
  sz[v] = 1;
  for (int u : G[v]) {
    if (u != pr) {
      dep[u] = dep[v] + 1;
      jump[u][0] = v;
      dfs1(u, v);
      dp_down[v] += dp_down[u] + sz[u];
      sz[v] += sz[u];
    }
  }
}

void dfs2(int v, int pr) {
  for (int u : G[v]) {
    if (u != pr) {
      dp_all[u] = dp_all[v] - sz[u] + n - sz[u];
      dfs2(u, v);
    }
  }
}

int la(int v, int len) {
  for (int i = 0; i < jump[0].size(); i++) {
    if (len & (1 << i)) {
      v = jump[v][i];
    }
  }
  return v;
}

int lca(int v, int u) {
  if (dep[v] < dep[u]) {
    swap(v, u);
  }
  v = la(v, dep[v] - dep[u]);
  if (u == v) {
    return v;
  }
  for (int level = jump[0].size() - 1; level >= 0; level--) {
    if (jump[v][level] != jump[u][level]) {
      v = jump[v][level];
      u = jump[u][level];
    }
  }
  return jump[v][0];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  G.assign(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--; u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  jump.assign(n, vector<int>(32 - __builtin_clz(n), 0));
  dep.assign(n, 0);
  sz.assign(n, 0);
  dp_down.assign(n, 0);
  dp_all.assign(n, 0);
  dfs1(0, 0);
  for (int level = 1; level < jump[0].size(); level++) {
    for (int i = 0; i < n; i++) {
      jump[i][level] = jump[jump[i][level - 1]][level - 1];
    }
  }
  dp_all[0] = dp_down[0];
  dfs2(0, 0);
  cout << fixed << setprecision(10);
  while (m--) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    if (dep[v] > dep[u]) {
      swap(v, u);
    }
    int w = lca(v, u);
    double ans = 1.0;
    ans += dep[v] + dep[u] - 2 * dep[w];
    if (v != w) {
      ans += (double)dp_down[v] / sz[v];
      ans += (double)dp_down[u] / sz[u];
    } else {
      assert(v == w);
      ans += (double)dp_down[u] / sz[u];
      u = la(u, dep[u] - dep[v] - 1);
      ans += (double)(dp_all[v] - dp_down[u] - sz[u]) / (n - sz[u]);
    }
    cout << ans << '\n';
  }
}