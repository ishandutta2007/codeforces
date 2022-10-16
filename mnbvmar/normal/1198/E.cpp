#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

struct Dinic {
  struct Edge { int v, c, inv; };
public:
  Dinic() : n(-1) {}
  void AddEdge(int a, int b, int cap, int bi_dir) {
    debug("Edge", a, b, cap);
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
  static const int kInf = 2e18; // UWAZAC, JESLI NIE INT = LONG LONG
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, m;
  cin >> n >> m;

  vector<int> rstops, cstops;

  vector<int> r1(m), c1(m), r2(m), c2(m);

  for (int i = 0; i < m; ++i) {
    cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
    ++r2[i]; ++c2[i];
    rstops.PB(r1[i]);
    rstops.PB(r2[i]);
    cstops.PB(c1[i]);
    cstops.PB(c2[i]);
  }

  sort(ALL(rstops)); rstops.resize(unique(ALL(rstops)) - rstops.begin());
  sort(ALL(cstops)); cstops.resize(unique(ALL(cstops)) - cstops.begin());

  const int R = SZ(rstops);
  const int C = SZ(cstops);

  Dinic dinic;
  const int source = 0;
  const int sink = 1;
  const int r_base = 2;
  const int c_base = r_base + R;

  for (int i = 0; i < R - 1; ++i) {
    dinic.AddEdge(source, r_base + i, rstops[i + 1] - rstops[i], 0);
  }
  for (int i = 0; i < C - 1; ++i) {
    dinic.AddEdge(c_base + i, sink, cstops[i + 1] - cstops[i], 0);
  }

  for (int i = 0; i < R - 1; ++i) {
    for (int j = 0; j < C - 1; ++j) {
      bool any = false;
      const int rmain = rstops[i];
      const int cmain = cstops[j];

      for (int k = 0; k < m; ++k) {
        if (r1[k] <= rmain && rmain < r2[k] && c1[k] <= cmain && cmain < c2[k]) {
          any = true;
          break;
        }
      }

      if (any) {
        dinic.AddEdge(r_base + i, c_base + j, 1e18, 0);
      }
    }
  }

  cout << dinic.MaxFlow(source, sink) << "\n";
}