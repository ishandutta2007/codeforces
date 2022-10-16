//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
  *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
// using PII=pair<int, int>;

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

const int kMaxN = 1024;

int xi[kMaxN], yi[kMaxN], wi[kMaxN];
map<pii, int> mapping;
int first_id[kMaxN];
vi types[2][2];

int GetID(int x, int y) {
  pii p{x, y};
  auto iter = mapping.find(p);
  if (iter == mapping.end()) { return -1; }
  return iter->second;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;

  Dinic dinic;
  const int source = 0;
  const int sink = 1;

  int max_id = 2;

  const ll kInf = 1e18;
  ll sum_elems = 0;

  for (int i = 0; i < n; ++i) {
    cin >> xi[i] >> yi[i] >> wi[i];
    sum_elems += wi[i];
    pii P{xi[i], yi[i]};
    mapping[P] = i;

    const int tx = abs(xi[i]) % 2;
    const int ty = abs(yi[i]) % 2;
    types[tx][ty].push_back(i);
    first_id[i] = max_id;
    if (tx == 0) {
      dinic.AddEdge(first_id[i], first_id[i] + 1, wi[i], 0);
      max_id += 2;
    } else {
      if (ty == 0) {
        dinic.AddEdge(first_id[i], sink, wi[i], 0);
      } else {
        dinic.AddEdge(source, first_id[i], wi[i], 0);
      }
      ++max_id;
    }
  }

  for (int id01 : types[0][1]) {
    for (int dx : {-1, 1}) {
      const int j = GetID(xi[id01] + dx, yi[id01]);
      if (j != -1) {
        dinic.AddEdge(first_id[j], first_id[id01], kInf, 0);
      }
    }
    for (int dy : {-1, 1}) {
      const int j = GetID(xi[id01], yi[id01] + dy);
      if (j != -1) {
        dinic.AddEdge(first_id[id01] + 1, first_id[j], kInf, 0);
      }
    }
  }
  for (int id00 : types[0][0]) {
    for (int dx : {-1, 1}) {
      const int j = GetID(xi[id00] + dx, yi[id00]);
      if (j != -1) {
        dinic.AddEdge(first_id[id00] + 1, first_id[j], kInf, 0);
      }
    }
  }

  const ll cost = dinic.MaxFlow(source, sink);
  debug() << imie(cost);
  cout << sum_elems - cost << "\n";

}