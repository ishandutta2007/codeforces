#include <bits/stdc++.h>

using namespace std;

const int N = 75;
const int M = 1 << 17;
const int inf = 2e9 + 123;

int n, m, a, b;
vector<int> ga[N], gb[N];
int comp[N];
int par[N], sz[N];
int d[N][M];

int anc(int u) { return par[u] == u ? u : par[u] = anc(par[u]); }

void mrg(int u,int v) {
  u = anc(u), v = anc(v);
  if (u == v) return;
  par[v] = u;
  sz[u] += sz[v];
}

int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);;
  for (int u = 1; u <= n; ++u) {
    par[u] = u, sz[u] = 1;
  }
  while (m--) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    if (c == a) {
      mrg(u, v);
      ga[u].push_back(v);
      ga[v].push_back(u);
    } else {
      gb[u].push_back(v);
      gb[v].push_back(u);
    }
  }
  m = 0;
  for (int u = 1; u <= n; ++u) comp[u] = -1;
  for (int u = 1; u <= n; ++u) if (anc(u) == u && sz[u] > 3) comp[u] = m++;
  for (int u = 1; u <= n; ++u) comp[u] = comp[anc(u)];
  for (int u = 1; u <= n; ++u) comp[u] = comp[u] == -1 ? 0 : 1 << comp[u];
  for (int u = 1; u <= n; ++u) {
    for (int msk = 0; msk < (1 << m); ++msk) {
      d[u][msk] = inf;
    }
  }
  priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > q;
  auto mdf = [&](int u,int msk,int val) {
    if (d[u][msk] > val) {
      d[u][msk] = val;
      q.push(make_tuple(-val, u, msk));
    }
  };
  mdf(1, comp[1], 0);
  while (!q.empty()) {
    int u, msk, val;
    tie(val, u, msk) = q.top(); q.pop();
    val = -val;
    if (d[u][msk] != val) continue;
    for (int v : ga[u]) {
      mdf(v, msk, val + a);
    }
    for (int v : gb[u]) {
      if (anc(u) != anc(v) && ((msk & comp[v]) == 0)) {
        mdf(v, msk | comp[v], val + b);
      }
    }
  }
  for (int u = 1; u <= n; ++u) {
    int ans = inf;
    for (int msk = 0; msk < (1 << m); ++msk) {
      ans = min(ans, d[u][msk]);
    }
    printf("%d ", ans);
  }
}