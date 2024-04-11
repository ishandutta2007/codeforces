#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, q, timer = 0;
vector<vector<int>> G;
vector<int> used, dep, tin, tout, par;
vector<vector<int>> jump;

void dfs(int v) {
  used[v] = 1;
  jump[v][0] = v;
  tin[v] = timer++;
  for (auto u : G[v]) {
    if (!used[u]) {
      dep[u] = dep[v] + 1;
      dfs(u);
    } else {
      if (dep[u] < dep[jump[v][0]]) {
        jump[v][0] = u;
      }
    }
  }
  par[v] = jump[v][0];
  tout[v] = timer++;
}

bool is_par(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  G.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  used.assign(n, 0);
  dep.assign(n, 0);
  jump.assign(n, vector<int>(32 - __builtin_clz(n), -1));
  tin.assign(n, 0);
  tout.assign(n, 0);
  par.assign(n, 0);
  dfs(0);
  for (int level = 1; level < jump[0].size(); level++) {
    for (int i = 0; i < n; i++) {
      jump[i][level] = jump[jump[i][level - 1]][level - 1];
    }
  }
  while (q--) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    auto get = [&](int v, int u) {
      int ans = 0;
      if (!is_par(v, u)) {
        for (int level = jump[0].size() - 1; level >= 0; level--) {
          if (!is_par(jump[v][level], u)) {
            ans += (1 << level);
            v = jump[v][level];
          }
        }
        ans++;
        v = par[v];
      }
      if (!is_par(u, v)) {
        for (int level = jump[0].size() - 1; level >= 0; level--) {
          if (!is_par(jump[u][level], v)) {
            ans += (1 << level);
            u = jump[u][level];
          }
        }
        ans++;
        u = par[u];
      }
      return ans;
    };
    cout << min(get(v, u), get(u, v)) << '\n';
  }
}