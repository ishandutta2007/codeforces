#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())

#define elif else if

using ull = unsigned long long;
using uint = unsigned int;
int popcnt(uint x) {
  return __builtin_popcount(x);
}
int popcnt(int x) {
  return __builtin_popcount(x);
}
int popcnt(ull x) {
  return __builtin_popcountll(x);
}
int popcnt(ll x) {
  return __builtin_popcountll(x);
}
int bsr(uint x) {
  return 31 - __builtin_clz(x);
}
int bsr(ull x) {
  return 63 - __builtin_clzll(x);
}
int ctz(int x) {
  return __builtin_ctz(x);
}
int ctz(ll x) {
  return __builtin_ctzll(x);
}
int ctz(ull x) {
  return __builtin_ctzll(x);
}

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

ll ceil(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

ll mod(ll x, ll y) {
  return x - y * floor(x, y);
}

#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}
#line 2 "main.cpp"

#line 3 "/home/maspy/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  int N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(){}
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    if(i == -1) i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void debug(bool detail=false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  vector<int> degrees(){
    vector<int> deg(N);
    FORIN(e, edges) {
      deg[e.frm]++;
      deg[e.to]++;
    }
    return deg;
  }

  int size(){return N;}

  vector<edge_t>& operator[](int v) { return G[v]; }
};
#line 1 "/home/maspy/library/graph/hld.hpp"
template <typename G, typename E, bool edge = false, bool commute = true>
struct HLD_seg {
  using F = function<E(E, E)>;
  G &g;
  int N;
  F seg_f;
  E E_unit;
  vector<int> sz, LID, RID, EID, head, V, parent;
  vector<E> dat;
  vector<E> dat_r;

  HLD_seg(G &g, F f, E E_unit)
      : g(g), N(g.size()), seg_f(f), E_unit(E_unit), sz(g.size()),
        LID(g.size()), RID(g.size()), EID(g.size() - 1), head(g.size()),
        V(g.size()), parent(g.size(), -1), dat(g.size() * 2, E_unit) {
    int t = 0;
    FOR(v, g.size()) {
      if (parent[v] == -1) {
        dfs_sz(v, -1);
        dfs_hld(v, -1, t);
      }
    }
    FOR(i, N - 1) {
      auto e = g.edges[i];
      EID[i] = LID[(parent[e.frm] == e.to ? e.frm : e.to)];
    }

    if (!commute)
      dat_r.assign(2 * N, E_unit);
  }

  void dfs_sz(int idx, int p) {
    parent[idx] = p;
    sz[idx] = 1;
    if (g[idx].size() && g[idx][0].to == p)
      swap(g[idx][0], g[idx].back());
    for (auto &e : g[idx]) {
      if (e.to == p)
        continue;
      dfs_sz(e.to, idx);
      sz[idx] += sz[e.to];
      if (sz[g[idx][0].to] < sz[e.to])
        swap(g[idx][0], e);
    }
  }

  void dfs_hld(int idx, int par, int &times) {
    LID[idx] = times++;
    V[LID[idx]] = idx;
    for (auto &e : g[idx]) {
      if (e.to == par)
        continue;
      head[e.to] = (g[idx][0].to == e.to ? head[idx] : e.to);
      dfs_hld(e.to, idx, times);
    }
    RID[idx] = times;
  }

  /* k: 0-indexed */
  int la(int v, int k) {
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u])
        return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int lca(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v])
        swap(u, v);
      if (head[u] == head[v])
        return u;
    }
  }

  void init(vc<E> &v) {
    // (vertex ) OR (edge index )
    if (!edge) {
      assert(len(v) == N);
      FOR(i, N) dat[N + LID[i]] = v[i];
    } else {
      assert(len(v) == N - 1);
      FOR(i, N - 1) { dat[N + EID[i]] = v[i]; }
    }
    FOR3_R(i, 1, N) dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]);
    if (!commute) {
      FOR(i, N) dat_r[N + i] = dat[N + i];
      FOR3_R(i, 1, N) dat_r[i] = seg_f(dat_r[i << 1 | 1], dat_r[i << 1 | 0]);
    }
  }

  void set(int i, E x) {
    i = (edge ? EID[i] : LID[i]);
    dat[i += N] = x;
    if (!commute)
      dat_r[i] = x;
    while (i >>= 1) {
      dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]);
      if (!commute)
        dat_r[i] = seg_f(dat_r[i << 1 | 1], dat_r[i << 1 | 0]);
    }
  }

  E fold_seg(int L, int R, bool rev = false) {
    if (commute)
      rev = false;
    E vl = E_unit, vr = E_unit;
    L += N, R += N;
    while (L < R) {
      if (L & 1)
        vl = (rev ? seg_f(dat_r[L++], vl) : seg_f(vl, dat[L++]));
      if (R & 1)
        vr = (rev ? seg_f(vr, dat_r[--R]) : seg_f(dat[--R], vr));
      L >>= 1, R >>= 1;
    }
    return (rev ? seg_f(vr, vl) : seg_f(vl, vr));
  }

  E fold_path(int u, int v) {
    E vl = E_unit, vr = E_unit;
    while (1) {
      if (head[u] == head[v])
        break;
      if (LID[u] < LID[v]) {
        vr = seg_f(fold_seg(LID[head[v]], LID[v] + 1), vr);
        v = parent[head[v]];
      } else {
        vl = seg_f(vl, fold_seg(LID[head[u]], LID[u] + 1, true));
        u = parent[head[u]];
      }
    }
    E vm = (LID[u] < LID[v] ? fold_seg(LID[u] + edge, LID[v] + 1)
                            : fold_seg(LID[v] + edge, LID[u] + 1, true));
    return seg_f(vl, seg_f(vm, vr));
  }

  E fold_subtree(int v) { return fold_seg(LID[v] + edge, RID[v]); }
};
#line 5 "main.cpp"

void solve() {
  LL(N, Q);
  Graph<ll> G(N);
  FOR(_, N - 1) {
    LL(a, b, c);
    G.add(--a, --b, c);
  }

  const ll INF = 1LL << 60;

  // [hld_seg template
  using E = ll;
  const bool is_edge = true;
  const bool commute = true;
  HLD_seg<Graph<ll>, E, is_edge, commute> hld(
    G,
    [&](E x, E y) -> E {
      return (x == INF || y == INF || x > ceil(INF, y) ? INF : x * y);
    },
    E(1));
  // hld_seg template]

  vi C(N - 1);
  FOR(i, N - 1) C[i] = G.edges[i].cost;
  hld.init(C);

  FOR(_, Q) {
    LL(t);
    if (t == 1) {
      LL(a, b, x);
      --a, --b;
      auto prod = hld.fold_path(a, b);
      print(x / prod);
    } else {
      LL(i, x);
      --i;
      hld.set(i, x);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}