#include <iostream>
#include <vector>
#include <algorithm>
const int mxN = 2e5 + 5, lg = 18;
struct edge {
  int u, v, w;
};
int n, m, timer, go = 1, st[lg][mxN], dep[mxN], dfn[mxN], sz[mxN], idx[mxN], pp[mxN], chain[mxN], fro[mxN], sz2[mxN], child[mxN], dp[mxN], sum[mxN];
std::vector<int> adj[mxN], ps[mxN];
std::vector<edge> ee[mxN];
int lca(int x,int y) {
  if (dep[x] > dep[y]) std::swap(x, y);
  int z = dep[y] - dep[x];
  for (int i = 0; i < lg; i++) {
    if ((z >> i) & 1) y = st[i][y];
  }
  for (int i = lg - 1; i >= 0; i--) {
    if (st[i][x] != st[i][y]) {
      x = st[i][x];
      y = st[i][y];
    }
  }
  return (x == y ? x : st[0][x]);
}
void dfs(int u, int p) {
  dfn[u] = ++timer;
  idx[dfn[u]] = u;
  st[0][u] = p;
  for (int i = 1; i < lg; i++) st[i][u] = st[i-1][st[i-1][u]];
  for (auto i : adj[u]) {
    if (i != p) {
      dep[i] = dep[u] + 1;
      dfs(i, u);
      sz[u] += sz[i];
    }
  }
  sz[u]++;
}
void hld(int u) {
  pp[u] = go;
  chain[u] = ++sz2[go];
  int maxi = -1, ptr = -1;
  for (auto i : adj[u]) {
    if (i != st[0][u] && sz[i] > maxi) {
      maxi = sz[i];
      ptr = i;
    }
  }
  if (maxi == -1) return;
  child[u] = ptr;
  hld(ptr);
  for (auto i : adj[u]) {
    if (i != st[0][u] && i != ptr) {
      fro[++go] = i;
      hld(i);
    }
  }
}
int qsum(int lvl, int l, int r) {
  return (l > r ? 0 : ps[lvl][l] - ps[lvl][r + 1]);
}
int eat(int u, int v, int zz) {
  int ans = 0;
  while (pp[u] != pp[zz]) {
    ans += qsum(pp[u], 1, chain[u]);
    u = st[0][fro[pp[u]]];
  }
  ans += qsum(pp[zz], chain[zz] + 1, chain[u]);
  while (pp[v] != pp[zz]) {
    ans += qsum(pp[v], 1, chain[v]);
    v = st[0][fro[pp[v]]];
  }
  return ans + qsum(pp[zz], chain[zz] + 1, chain[v]) + sum[zz];
}
int32_t main() {
  std::cin >> n >> m;
  for (int i = 2, x; i <= n; i++) {
    std::cin >> x;
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  dfs(1, 0);
  for (int i = 1, u, v, w; i <= m; i++) {
    std::cin >> u >> v >> w;
    ee[lca(u, v)].push_back({u, v, w});
  }
  hld(1);
  for (int i = 1; i <= go; i++) ps[i].resize(sz2[i] + 2);
  for (int i = n; i > 0; i--) {
    int z = idx[i];
    for (auto j : adj[z]) {
      if (j != st[0][z]) sum[z] += dp[j];
    }
    int wa = sum[z];
    for (auto j : ee[z]) wa = std::max(wa, eat(j.u, j.v, z) + j.w);
    dp[z] = wa;
    wa = sum[z] - dp[z];
    ps[pp[z]][chain[z]] = ps[pp[z]][chain[z] + 1] + wa;
  }
  std::cout << dp[1] << "\n";
}