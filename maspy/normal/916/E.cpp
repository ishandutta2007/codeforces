#line 1 "/home/maspy/compro/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

#line 1 "/home/maspy/compro/library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};
template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

struct Scanner {
  FILE* fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T, is_modint_t<T> * = nullptr>
  bool read_single(T &ref) {
    long long val = 0;
    bool f = read_single(val);
    ref = T(val);
    return f;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <class A, class B, class C>
  bool read_single(tuple<A, B, C> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)));
  }
  template <class A, class B, class C, class D>
  bool read_single(tuple<A, B, C, D> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)) && read_single(get<3>(p)));
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string &s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double &x) {
    ostringstream oss;
    oss << setprecision(12) << x;
    string s = oss.str();
    write(s);
  }
  template <class T, is_modint_t<T> * = nullptr>
  void write(T &ref) {
    write(ref.val);
  }
  template <class T>
  void write(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> &val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
};

Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 6 "/home/maspy/compro/library/my_template.hpp"

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

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
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
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

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(u32 x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(u64 x) { return 63 - __builtin_clzll(x); }
// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)
int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(u32 x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(u64 x) { return 63 - __builtin_clzll(x); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
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

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename T>
vc<int> bincount(vc<T> &A, int size) {
  vc<int> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  // stable
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}
#line 1 "/home/maspy/compro/library/graph/lazytreemonoid.hpp"
// https://codeforces.com/contest/916/problem/E
#line 2 "/home/maspy/compro/library/ds/lazysegtree.hpp"

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

  X prod_all() { return dat[1]; }

  void apply(int p, A a) {
    assert(0 <= p && p < n);
    p += size;
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
#line 2 "/home/maspy/compro/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
};

template <typename T = int, bool directed = false>
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

  Graph() : N(0), M(0), prepared(0) {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared && 0 <= frm && 0 <= to);
    chmax(N, frm + 1);
    chmax(N, to + 1);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  void read_tree(bool wt=false, int off=1){
    FOR_(N - 1){
      INT(a, b);
      a -= off, b -= off;
      if(!wt){
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    prepare();
  }

  void prepare() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& e: edges) {
      indptr[e.frm + 1]++;
      if (!directed) indptr[e.to + 1]++;
    }
    FOR(v, N) indptr[v + 1] += indptr[v];
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& e: edges) {
      csr_edges[counter[e.frm]++] = e;
      if (!directed)
        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
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
      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }
};
#line 3 "/home/maspy/compro/library/graph/hld.hpp"

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
    if (l + 1 < r && csr[l].to == p) swap(csr[l], csr[l + 1]);
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (e.to == p) {
        assert(!G.is_directed());
        continue;
      }
      dfs_sz(e.to, v);
      sz[v] += sz[e.to];
      if (chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int p, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&e: G[v]) {
      if (e.to == p) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, v, times);
    }
  }

  int e_to_v(int eid) {
    auto e = G.edges[eid];
    return (parent[e.frm] == e.to ? e.frm : e.to);
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

  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) {
    // [, ] ""
    vc<pair<int, int>> up, down;
    while (1) {
      if (head[u] == head[v]) break;
      if (LID[u] < LID[v]) {
        down.eb(LID[head[v]], LID[v]);
        v = parent[head[v]];
      } else {
        up.eb(LID[u], LID[head[u]]);
        u = parent[head[u]];
      }
    }
    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);
    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);
    reverse(all(down));
    up.insert(up.end(), all(down));
    return up;
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
#line 1 "/home/maspy/compro/library/alg/monoid_reverse.hpp"
template <class Monoid>
struct Monoid_Reverse {
  using value_type = typename Monoid::value_type;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }
  static constexpr X unit = Monoid::unit;
  static const bool commute = Monoid::commute;
};
#line 2 "/home/maspy/compro/library/alg/lazy_reverse.hpp"

template <typename Lazy>
struct Lazy_Reverse {
  using MX = Monoid_Reverse<typename Lazy::X_structure>;
  using MA = typename Lazy::A_structure;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }
};
#line 5 "/home/maspy/compro/library/graph/lazytreemonoid.hpp"

template <typename HLD, typename Lazy, bool edge = false>
struct LazyTreeMonoid {
  using MonoX = typename Lazy::X_structure;
  using MonoA = typename Lazy::A_structure;
  using X = typename MonoX::value_type;
  using A = typename MonoA::value_type;
  using RevLazy = Lazy_Reverse<Lazy>;
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

  X prod_path(int u, int v) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    X val = MonoX::unit;
    for (auto &&[a, b]: pd) {
      X x = (a <= b ? seg.prod(a, b + 1)
                    : (MonoX::commute ? seg.prod(b, a + 1)
                                       : seg_r.prod(b, a + 1)));
      val = MonoX::op(val, x);
    }
    return val;
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  X prod_all() {
    return seg.prod_all();
  }

  void apply_path(int u, int v, A a) {
    auto pd = hld.get_path_decomposition(u, v, edge);
    for (auto &&[x, y]: pd) {
      int l = min(x, y), r = max(x, y);
      seg.apply(l, r + 1, a);
      if(!MonoX::commute) seg_r.apply(l, r + 1, a);
    }
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
#line 2 "/home/maspy/compro/library/alg/group_add.hpp"
template <class X, X ZERO = X(0)>
struct Group_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return n * x; }
  static constexpr X unit = ZERO;
  static constexpr bool commute = true;
};
#line 1 "/home/maspy/compro/library/alg/group_cntsum.hpp"
template <typename E = long long>
struct Group_CntSum {
  using value_type = pair<E,E>;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) { return {x.fi + y.fi, x.se + y.se}; }
  static constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }
  static constexpr X unit = {0, 0};
  static constexpr bool commute = true;
};
#line 3 "/home/maspy/compro/library/alg/lazy_cntsum_add.hpp"

template <typename E>
struct Lazy_CntSum_Add {
  using MX = Group_CntSum<E>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.se + x.fi * a};
  }
};
#line 4 "main.cpp"

void solve() {
  LL(N, Q);
  vc<pi> seg_raw(N);
  FOR(i, N) {
    LL(a);
    seg_raw[i] = {1, a};
  }
  Graph G(N);
  G.read_tree();
  HLD hld(G);
  auto par = hld.parent;
  auto dep = hld.depth;
  LazyTreeMonoid<decltype(hld), Lazy_CntSum_Add<ll>, false> TM(hld, seg_raw);

  ll root = 0;
  FOR_(Q) {
    LL(t);
    if (t == 1) {
      LL(v);
      --v;
      root = v;
    }
    elif (t == 2) {
      LL(a, b, x);
      --a, --b;
      if (hld.dist(a, b) == hld.dist(a, root) + hld.dist(b, root)) {
        TM.apply_subtree(0, x);
        continue;
      }
      ll c = hld.LCA(a, b);
      if (hld.LCA(c, root) != c) {
        TM.apply_subtree(c, x);
        continue;
      }
      ll p = hld.LCA(root, a), q = hld.LCA(root, b);
      if (dep[p] < dep[q]) swap(p, q);
      ll r = hld.move(p, root);
      TM.apply_subtree(0, x);
      TM.apply_subtree(r, -x);
    }
    elif (t == 3) {
      LL(v);
      --v;
      if (v == root) {
        print(TM.prod_all().se);
        continue;
      }
      auto to = hld.move(v, root);
      if (to == par[v]) {
        print(TM.prod_subtree(v).se);
        continue;
      }
      print(TM.prod_all().se - TM.prod_subtree(to).se);
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