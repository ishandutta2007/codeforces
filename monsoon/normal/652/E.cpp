#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

template<typename T>
inline void minimize(T& a, const T& b) { if (a > b) a = b; }

namespace cp {

struct graph {
  int n,m;
  vector<vector<int>> adj;
  vector<int> ea,eb;

  void create(int _n, int _m = 0) {
    n = _n;
    m = 0;
    adj.resize(n);
    ea.reserve(_m);
    eb.reserve(_m);
  }

  int add_edge(int a, int b) {
    ea.push_back(a);
    eb.push_back(b);
    adj[a].push_back(m);
    adj[b].push_back(~m);
    return m++;
  }

  int efrom(int e) const {
    return e >= 0 ? ea[e] : eb[~e];
  }
  int eto(int e) const {
    return e >= 0 ? eb[e] : ea[~e];
  }

  int dfs_path(int v, int par, int b, vector<int>& ans) const {
    if (v == b) { ans.push_back(v); return 1; }
    for (int i : adj[v]) {
      int w = eto(i);
      if (w == par) continue;
      if (dfs_path(w, v, b, ans)) {
        ans.push_back(v);
        return 1;
      }
    }
    return 0;
  }

  vector<int> path_between(int a, int b) const {
    vector<int> ans;
    dfs_path(a, -1, b, ans);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

template<class G>
struct gr_edge_biconnected {
  vector<int> comp;
  int cn;
  const G& g;

  vector<int> tin, low;
  int T;
  vector<int> bridges;

  G cg;
  vector<int> map_edge;

  gr_edge_biconnected(const G& g) : g(g) {
    init();
  }

  void dfs(int v, int par, int e) {
    tin[v] = T++;
    low[v] = tin[v];
    for (auto i : g.adj[v]) {
      int w = g.eto(i);
      if (w == par) continue;
      if (tin[w] == -1) {
        dfs(w, v, i);
        minimize(low[v], low[w]);
      } else {
        minimize(low[v], tin[w]);
      }
    }
    if (low[v] == tin[v] && par != -1) {
      bridges[e >= 0 ? e : ~e] = 1;
    }
  }

  void dfs2(int v) {
    comp[v] = cn;
    for (auto i : g.adj[v]) {
      if (bridges[i >= 0 ? i : ~i]) continue;
      int w = g.eto(i);
      if (comp[w] == -1) { dfs2(w); }
    }
  }

  void init() {
    comp.assign(g.n, -1);
    cn = 0;
    tin.assign(g.n, -1);
    low.resize(g.n);
    bridges.resize(g.m);
    T = 0;
    REP(i,g.n) if (tin[i] == -1) { dfs(i, -1, -1); }
    REP(i,g.n) if (comp[i] == -1) { dfs2(i); ++cn; }
    create_comps_graph();
  }

  vector<int> comps() const { return comp; }
  int comps_size() const { return cn; }

  void create_comps_graph() {
    cg.create(cn, cn-1);
    vector<int> map_edge(cn-1);
    REP(i,g.n) for (int e : g.adj[i]) if (e >= 0) {
      if (comp[g.efrom(e)] != comp[g.eto(e)]) {
        int E = cg.add_edge(comp[g.efrom(e)], comp[g.eto(e)]);
        map_edge[E] = e;
      }
    }
  }

  const G& comps_graph() const { return cg; }
  vector<int> comps_graph_map_edge() const { return map_edge; }

  int edge_comp(int e) {
    return comp[g.efrom(e)] == comp[g.eto(e)] ? comp[g.efrom(e)] : -1;
  }
};

}

const int N = 310000;
int n,m,sa,sb,z[N];
cp::graph g;

int main() {
  scanf("%d%d",&n,&m);
  g.create(n, m);
  REP(i,m) {
    int a,b; scanf("%d%d%d",&a,&b,&z[i]); --a,--b;
    g.add_edge(a, b);
  }
  scanf("%d%d",&sa,&sb); --sa,--sb;

  cp::gr_edge_biconnected<cp::graph> gg(g);
  auto comps = gg.comps();
  
  int ok = 0;
  auto gt = gg.comps_graph();
  auto path = gt.path_between(comps[sa], comps[sb]);
  vector<int> onpath(gg.comps_size());
  for (int i : path) { onpath[i] = 1; }
  REP(i,m) if (z[i]) {
    if (onpath[comps[g.efrom(i)]] && onpath[comps[g.eto(i)]]) ok = 1;
  }

  puts(ok ? "YES" : "NO");
}