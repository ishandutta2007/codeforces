#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug & operator<<
#define eni(x) sim>typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim> struct rge { c b, e; };
sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim> auto dud(c*x) -> decltype(cerr<<*x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor (pair<b,c> d) {
  ris<<"("<<d.first<<", "<<d.second<<")";
}
sim dor(rge<c> d) {
  *this<<"[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris <<" ]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
#define int ll
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define SZ(x) ((int)(x).size())
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define VI vector<int>
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

struct Dinic {
  struct Edge { int v, c, inv; };
public:
  Dinic() : n(-1) {}
  void AddEdge(int a, int b, int cap, int bi_dir) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e_orig[a].PB(Edge{b, cap, SZ(e_orig[b])});
    e_orig[b].PB(Edge{a, bi_dir * cap, SZ(e_orig[a]) - 1});
  }
  int MaxFlow(int s, int t) {
    if (t > n || s > n) {
      n = max(s, t);
      ResizeVectors();
    }
    e = e_orig; int result = 0;
    while (Bfs(s, t)) {
      fill_n(beg.begin(), n + 1, 0);
      result += Dfs(s, t, kInf);
    }
    return result;
  }
  vector<bool> MinCut(int s, int t) {
    assert(!Bfs(s, t));
    vector<bool> res(n + 1);
    FOR (i, 0, n) { res[i] = (dis[i] <= n); }
    return res;
  }
  
  vector<PII> EdgeCut(int s, int t) {
    vector<bool> left_part = MinCut(s, t);
    vector<PII> cut;
    FOR (v, 0, n) {
      for (auto edge : e_orig[v]) {
        if (edge.c != 0 && left_part[v] && !left_part[edge.v]) {
          cut.PB({v, edge.v});
        }
      }
    }
    return cut;
  }
private:
  int n;
  vector<vector<Edge>> e_orig, e;
  VI dis, beg;
  
  bool Bfs(int s, int t) {
    fill_n(dis.begin(), n + 1, n + 1);
    dis[s] = 0;
    VI que;
    que.push_back(s);
    REP (i, SZ(que)) {
      int v = que[i];
      for (auto edge : e[v]) {
        int nei = edge.v;
        if (edge.c && dis[nei] > dis[v] + 1) {
          dis[nei] = dis[v] + 1;
          que.push_back(nei);
          if (nei == t) { return true; }
        }
      }
    }
    return false;
  }  
  int Dfs(int v, int t, int min_cap) {
    int result = 0;
    if (v == t || min_cap == 0) { return min_cap; }
    for (int& i = beg[v]; i < SZ(e[v]); i++) {
      int nei = e[v][i].v, c = e[v][i].c;
      if (dis[nei] == dis[v] + 1 && c > 0) {
        int flow_here = Dfs(nei, t, min(min_cap, c));
        result += flow_here;
        min_cap -= flow_here;
        e[v][i].c -= flow_here;
        e[nei][e[v][i].inv].c += flow_here;
      }
      if (min_cap == 0) { break; }
    }
    return result;
  }
  
  void ResizeVectors() {
    e_orig.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }
  
  #ifndef int
  #warning
  #endif
  static const int kInf = 1e18; // UWAZAC, JESLI NIE INT = LONG LONG
};

const int MaxN = 2048;
const int MaxItems = 5e5;

int n, m;
vi adj[MaxN];
int s, b, k, h;
int dist[MaxN][MaxN];
vector<pii> at_vert[MaxN];

int sp_loc[MaxItems], sp_atk[MaxItems], sp_fuel[MaxItems], sp_price[MaxItems];
int bs_loc[MaxItems], bs_def[MaxItems], bs_gold[MaxItems];

vi dep_adj[MaxItems];
bool any_dep[MaxItems];
int dep_idx[MaxItems];

int32_t main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dist[i][j] = 2e9;
    }
    dist[i][i] = 0;
  }
  
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (u != v) {
      dist[u][v] = dist[v][u] = 1;
    }
  }
  
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  scanf("%lld%lld%lld", &s, &b, &k);
  
  for (int i = 0; i < s; ++i) {
    scanf("%lld%lld%lld%lld", &sp_loc[i], &sp_atk[i], &sp_fuel[i], &sp_price[i]);
  }
  for (int i = 0; i < b; ++i) {
    scanf("%lld%lld%lld", &bs_loc[i], &bs_def[i], &bs_gold[i]);
    at_vert[bs_loc[i]].emplace_back(bs_def[i], bs_gold[i]);
  }
  
  for (int v = 1; v <= n; ++v) {
    auto &X = at_vert[v];
    sort(X.begin(), X.end());
    
    const int sz = X.size();
    int cur_max = -1;
    int ptr = 0;
    for (int i = 0; i < sz; ++i) {
      if (X[i].second <= cur_max) { continue; }
      X[ptr++] = X[i];
      cur_max = X[i].second;
    }
    X.resize(ptr);
    
    debug() << imie(v) << imie(X);
  }
  
  const int kSmallInf = 2e16;
  const ll kLargeInf = 2e16;
  
  vll sp_best(s, -kLargeInf);
  for (int i = 0; i < s; ++i) {
    for (int v = 1; v <= n; ++v) {
      if (sp_fuel[i] < dist[sp_loc[i]][v]) { continue; }
      const int atk = sp_atk[i];
      auto iter =
        lower_bound(at_vert[v].begin(), at_vert[v].end(),
                    pii(atk, kSmallInf));
      if (iter == at_vert[v].begin()) {
        continue;
      } else {
        int bnd = prev(iter)->second;
        sp_best[i] = max(sp_best[i], (ll)bnd - sp_price[i]);
      }
    }
    debug() << imie(i) << imie(sp_best[i]);
  }
  
  for (int i = 0; i < k; ++i) {
    int u, v;
    scanf("%lld%lld", &u, &v);
    --u; --v;
    any_dep[u] = any_dep[v] = true;
    dep_adj[u].PB(v);
  }
  
  
  ll ans = 0;
  int curidx = 0;
  for (int i = 0; i < s; ++i) {
    if (!any_dep[i] && sp_best[i] >= 0) {
      ans += sp_best[i];
    }
    /*if (any_dep[i]) {
      dep_idx[i] = curidx++;
    }*/
    dep_idx[i] = curidx++;
  }
  
  Dinic dinic;
  const int source = curidx;
  const int sink = source + 1;
  
  debug() << imie(source) << imie(sink);
  
  for (int i = 0; i < s; ++i) {
    if (!any_dep[i]) { continue; }
    if (sp_best[i] >= 0) {
      dinic.AddEdge(source, dep_idx[i], sp_best[i], 0);
      ans += sp_best[i];
    } else {
      dinic.AddEdge(dep_idx[i], sink, -sp_best[i], 0);
    }
    
    for (int j : dep_adj[i]) {
      dinic.AddEdge(dep_idx[i], dep_idx[j], kLargeInf, 0);
    }
  }
  
  const ll flow = dinic.MaxFlow(source, sink);
  ans -= flow;
  assert(ans >= 0);
  
  printf("%lld\n", ans);
}