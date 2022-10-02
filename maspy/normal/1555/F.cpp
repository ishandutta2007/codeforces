#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using uint = unsigned int;
using ull = unsigned long long;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
  vector<type> name(size);    \
  IN(name)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  IN(name)
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(uint x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(ull x) { return 63 - __builtin_clzll(x); }
// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)
int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(uint x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(ull x) { return 63 - __builtin_clzll(x); }

ll ceil(ll x, ll y) { return (x > 0 ? (x + y - 1) / y : x / y); }
ll floor(ll x, ll y) { return (x > 0 ? x / y : (x - y + 1) / y); }
pi divmod(ll x, ll y) {
  ll q = floor(x, y);
  return {q, x - q * y};
}

#define INT(...)   \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T>
void scan(pair<T, T> &p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(tuple<T, T, T> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));
}
template <class T>
void scan(tuple<T, T, T, T> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p)), scan(get<3>(p));
}
template <class T>
void scan(vector<T> &a) {
  for (auto &i: a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
  scan(head);
  IN(tail...);
}

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &A) {
  os << A.fi << " " << A.se;
  return os;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {
  os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
  return os;
}
template <typename T1, typename T2, typename T3, typename T4>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &t) {
  os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &A) {
  for (size_t i = 0; i < A.size(); i++) {
    if (i) os << " ";
    os << A[i];
  }
  return os;
}

void print() { cout << "\n"; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> &A) {
  int N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vc<int> bin_count(vi &A, int size) {
  vc<int> C(size);
  for (auto &x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#line 2 "main.cpp"

#line 4 "main.cpp"

#line 3 "/home/maspy/library/ds/unionfind.hpp"

struct UnionFind {
  int num;
  int comp;
  vi size, par;
  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) {
    return find(x);
  }


  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    comp--;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  vi find_all() {
    vi A(num);
    FOR(i, num) A[i] = find(i);
    return A;
  }
};
#line 2 "/home/maspy/library/graph/base.hpp"

// frm, to, cap, cost
template <typename T>
using Edge = tuple<int, int, T, int>;

template <typename T, bool directed = false>
struct Graph {
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    int l, r;
    const Graph* G;
  };

  bool is_prepared() { return prepared; }
  constexpr bool is_directed() { return directed; }

  Graph() {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared);
    assert(0 <= frm && frm < N && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  void prepare() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& [frm, to, cost, id]: edges) {
      indptr[frm + 1]++;
      if (!directed) indptr[to + 1]++;
    }
    FOR(v, N) indptr[v + 1] += indptr[v];
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& [frm, to, cost, id]: edges) {
      csr_edges[counter[frm]++] = {frm, to, cost, id};
      if (!directed) csr_edges[counter[to]++] = {to, frm, cost, id};
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto&& e: edges) print(e);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e);
    }
  }

  int size() { return N; }
};
#line 2 "/home/maspy/library/ds/lazysegtree.hpp"

template <typename Lazy>
struct LazySegTree {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  int n, log, size;
  vc<X> dat;
  vc<A> laz;

  LazySegTree() : LazySegTree(0) {}
  LazySegTree(int n) : LazySegTree(vc<X>(n, Monoid_X::unit)) {}
  LazySegTree(vc<X> v) : n(len(v)) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid_X::unit);
    laz.assign(size, Monoid_A::unit);
    FOR(i, n) dat[size + i] = v[i];
    FOR3_R(i, 1, size) update(i);
  }

  void update(int k) { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }

  void all_apply(int k, A a) {
    dat[k] = Lazy::act(dat[k], a);
    if (k < size) laz[k] = Monoid_A::op(laz[k], a);
  }

  void push(int k) {
    all_apply(2 * k, laz[k]);
    all_apply(2 * k + 1, laz[k]);
    laz[k] = Monoid_A::unit;
  }

  void set(int p, X x) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    dat[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  X get(int p) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return dat[p];
  }

  vc<X> get_all() {
    FOR(i, size) push(i);
    return {dat.begin() + size, dat.begin() + size + n};
  }

  X prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return Monoid_X::unit;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    X xl = Monoid_X::unit, xr = Monoid_X::unit;
    while (l < r) {
      if (l & 1) xl = Monoid_X::op(xl, dat[l++]);
      if (r & 1) xr = Monoid_X::op(dat[--r], xr);
      l >>= 1;
      r >>= 1;
    }

    return Monoid_X::op(xl, xr);
  }

  X all_prod() { return dat[1]; }

  void apply(int p, A a) {
    assert(0 <= p && p < n);
    p += size;
    if (!Monoid_A::commute)
      for (int i = log; i >= 1; i--) push(p >> i);
    dat[p] = Lazy::act(dat[p], a);
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  void apply(int l, int r, A a) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, a);
        if (r & 1) all_apply(--r, a);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <typename C>
  int max_right(C& check, int l) {
    assert(0 <= l && l <= n);
    assert(check(Monoid_X::unit));
    if (l == n) return n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    X sm = Monoid_X::unit;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(Monoid_X::op(sm, dat[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (check(Monoid_X::op(sm, dat[l]))) {
            sm = Monoid_X::op(sm, dat[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = Monoid_X::op(sm, dat[l]);
      l++;
    } while ((l & -l) != l);
    return n;
  }

  template <typename C>
  int min_left(C& check, int r) {
    assert(0 <= r && r <= n);
    assert(check(Monoid_X::unit));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    X sm = Monoid_X::unit;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(Monoid_X::op(dat[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (check(Monoid_X::op(dat[r], sm))) {
            sm = Monoid_X::op(dat[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = Monoid_X::op(dat[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

  void debug() { print("lazysegtree getall:", get_all()); }
};
#line 3 "/home/maspy/library/graph/hld.hpp"

template <typename Graph>
struct HLD {
  Graph &G;
  int N;
  vector<int> LID, RID, head, V, parent, depth;

  HLD(Graph &G, int root = 0)
      : G(G),
        N(G.N),
        LID(G.N),
        RID(G.N),
        head(G.N, root),
        V(G.N),
        parent(G.N, -1),
        depth(G.N) {
    assert(G.is_prepared());
    int t1 = 0;
    dfs_sz(root, -1);
    dfs_hld(root, -1, t1);
  }

  void dfs_sz(int v, int p) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    if (l + 1 < r && get<1>(csr[l]) == p) swap(csr[l], csr[l + 1]);
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto [frm, to, cost, id] = csr[i];
      if (to == p) {
        assert(!G.is_directed());
        continue;
      }
      dfs_sz(to, v);
      sz[v] += sz[to];
      if (chmax(hld_sz, sz[to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int p, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&[frm, to, cost, id]: G[v]) {
      if (to == p) continue;
      head[to] = (heavy ? head[v] : to);
      heavy = false;
      dfs_hld(to, v, times);
    }
  }

  int e_to_v(int e) {
    auto [frm, to, cost, id] = G.edges[e];
    return (parent[frm] == to ? frm : to);
  }

  int ELID(int v) { return 2 * LID[v] - depth[v]; }
  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }

  /* k: 0-indexed */
  int LA(int v, int k) {
    while (1) {
      int u = head[v];
      if (LID[v] - k >= LID[u]) return V[LID[v] - k];
      k -= LID[v] - LID[u] + 1;
      v = parent[u];
    }
  }

  int LCA(int u, int v) {
    for (;; v = parent[head[v]]) {
      if (LID[u] > LID[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int move(int a, int b) {
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }

  void debug() {
    print("V", V);
    print("LID", LID);
    print("RID", RID);
    print("parent", parent);
    print("depth", depth);
    print("head", head);
  }

  void doc() {
    print("HLO(N) ");
    print("LCA, LA  O(logN) ");
    print("");
    print(" DP");
  }
};
#line 1 "/home/maspy/library/algebra/reversemonoid.hpp"
template <class Monoid>
struct ReverseMonoid {
  using value_type = typename Monoid::value_type;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }
  static constexpr X unit = Monoid::unit;
  static const bool commute = Monoid::commute;
};
#line 2 "/home/maspy/library/algebra/reverselazy.hpp"

template <typename Lazy>
struct ReverseLazy {
  using MX = typename Lazy::X_structure;
  using MA = typename Lazy::A_structure;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }
};
#line 4 "/home/maspy/library/graph/lazytreemonoid.hpp"

template <typename HLD, typename Lazy, bool edge = false>
struct LazyTreeMonoid {
  using MonoX = typename Lazy::X_structure;
  using MonoA = typename Lazy::A_structure;
  using X = typename MonoX::value_type;
  using A = typename MonoA::value_type;
  using RevLazy = ReverseLazy<Lazy>;
  HLD &hld;
  int N;
  LazySegTree<Lazy> seg;
  LazySegTree<RevLazy> seg_r;

  LazyTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);
  }

  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {
    vc<X> seg_raw(N, MonoX::unit);
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = hld.e_to_v(e);
        seg_raw[hld.LID[v]] = dat[e];
      }
    }
    seg = LazySegTree<Lazy>(seg_raw);
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);
  }

  void set(int i, X x) {
    if (edge) i = hld.e_to_v(i);
    i = hld.LID[i];
    seg.set(i, x);
    if (!MonoX::commute) seg_r.set(i, x);
  }

  X prod_path_nc(int u, int v) {
    X xl = MonoX::unit, xr = MonoX::unit;
    while (1) {
      if (hld.head[u] == hld.head[v]) break;
      if (hld.LID[u] < hld.LID[v]) {
        xr = MonoX::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), xr);
        v = hld.parent[hld.head[v]];
      } else {
        xl = MonoX::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));
        u = hld.parent[hld.head[u]];
      }
    }
    X xm = (hld.LID[u] < hld.LID[v]
                ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)
                : seg_r.prod(hld.LID[v] + edge, hld.LID[u] + 1));
    return MonoX::op(xl, MonoX::op(xm, xr));
  }

  X prod_path(int u, int v) {
    if (!MonoX::commute) return prod_path_nc(u, v);
    X val = MonoX::unit;
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      val = MonoX::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), val);
      v = hld.parent[hld.head[v]];
    }
    return MonoX::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  void apply_path(int u, int v, A a) {
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      seg.apply(hld.LID[hld.head[v]], hld.LID[v] + 1, a);
      v = hld.parent[hld.head[v]];
    }
    seg.apply(hld.LID[u] + edge, hld.LID[v] + 1, a);
  }

  void apply_subtree(int u, A a) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.apply(l + edge, r, a);
  }

  void debug() {
    print("tree_monoid");
    hld.debug();
    seg.debug();
    seg_r.debug();
  }

  void doc() {
    print("HL + ");
    print(" O(logN)  O(log^2N) ");
  }
};
#line 1 "/home/maspy/library/algebra/maxmonoid.hpp"
template <class X, X INF>
struct MaxMonoid {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }
  static constexpr X unit = -INF;
  static constexpr bool commute = true;
};
#line 2 "/home/maspy/library/algebra/max_max_lazy.hpp"

template <typename E, E INF = 1 << 30>
struct Max_Max_Lazy {
  using MX = MaxMonoid<E, INF>;
  using MA = MaxMonoid<E, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return max(x, a); }
};
#line 9 "main.cpp"

void solve() {
  LL(N, M);
  using T = tuple<int, int, int>;
  vector<T> ED(M);
  FOR(i, M) {
    LL(a, b, c);
    ED[i] = mt(--a, --b, c);
  }

  UnionFind uf(N);
  Graph<int> G(N + 1);
  vector<bool> in_tree(M);
  FOR(i, M) {
    auto [a, b, c] = ED[i];
    if (uf.merge(a, b)) {
      in_tree[i] = true;
      G.add(a, b);
    }
  }

  FOR(v, N) if (uf[v] == v) G.add(v, N);
  G.prepare();
  ++N;

  HLD hld(G);

  using Lazy = Max_Max_Lazy<ll>;

  LazyTreeMonoid<decltype(hld), Lazy, true> TM(hld);

  auto& par = hld.parent;

  vi sgn(N);
  FOR(i, M) {
    if (in_tree[i]) {
      auto [a, b, c] = ED[i];
      if (par[a] == b)
        sgn[a] = c;
      else
        sgn[b] = c;
    }
  }
  for (auto&& v: hld.V) {
    if (par[v] != -1) sgn[v] ^= sgn[par[v]];
  }

  FOR(i, M) {
    auto [a, b, c] = ED[i];
    if (in_tree[i]) {
      YES();
      continue;
    }
    if ((sgn[a] ^ sgn[b] ^ c) == 0) {
      NO();
      continue;
    }
    auto res = TM.prod_path(a, b);
    if (res > 0) {
      NO();
      continue;
    }
    TM.apply_path(a, b, 1);
    YES();
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}