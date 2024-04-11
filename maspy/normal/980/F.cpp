#line 1 "/home/maspy/compro/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

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

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define FOR4_R(i, a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) \
  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

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
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

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

template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    if (check(x)) {
      ok = x;
    } else {
      ng = x;
    }
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi s_to_vi(const string &S, char first_char) {
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

template <typename CNT, typename T>
vc<CNT> bincount(const vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(const vector<T> &A) {
  // stable
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  int n = len(A);
  assert(len(I) == n);
  vc<T> B(n);
  FOR(i, n) B[i] = A[I[i]];
  return B;
}
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
  FILE *fp;
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
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
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
    oss << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double &x) {
    ostringstream oss;
    oss << setprecision(15) << x;
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
  template <class A, class B, class C>
  void write(const tuple<A, B, C> &val) {
    auto &[a, b, c] = val;
    write(a), write(' '), write(b), write(' '), write(c);
  }
  template <class A, class B, class C, class D>
  void write(const tuple<A, B, C, D> &val) {
    auto &[a, b, c, d] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d);
  }
  template <class A, class B, class C, class D, class E>
  void write(const tuple<A, B, C, D, E> &val) {
    auto &[a, b, c, d, e] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e);
  }
  template <class A, class B, class C, class D, class E, class F>
  void write(const tuple<A, B, C, D, E, F> &val) {
    auto &[a, b, c, d, e, f] = val;
    write(a), write(' '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e), write(' '), write(f);
  }
  template <class T, size_t S>
  void write(const array<T, S> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if(val < 0){
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if(negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
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
#define CHAR(...)      \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
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
    assert(!prepared);
    assert(0 <= frm && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  // wt, off
  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off); }

  void read_graph(int M, bool wt = false, int off = 1) {
    FOR(M) {
      INT(a, b);
      a -= off, b -= off;
      if (!wt) {
        add(a, b);
      } else {
        T c;
        read(c);
        add(a, b, c);
      }
    }
    build();
  }

  void read_parent(int off = 1) {
    FOR3(v, 1, N) {
      INT(p);
      p -= off;
      add(p, v);
    }
    build();
  }

  void build() {
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

/*
HLO(N) 
LCA, LA  O(logN) 
dfs
*/
template <typename Graph>
struct HLD {
  Graph &G;
  using Graph_type = Graph;
  using WT = typename Graph::cost_type;
  int N;
  vector<int> LID, RID, head, V, parent, root;
  vc<int> depth;
  vc<WT> depth_weighted;
  vector<bool> in_tree;

  HLD(Graph &G, int r = -1)
      : G(G),
        N(G.N),
        LID(G.N),
        RID(G.N),
        head(G.N, r),
        V(G.N),
        parent(G.N, -1),
        depth(G.N, -1),
        depth_weighted(G.N, 0),
        root(G.N, -1),
        in_tree(G.M, 0) {
    assert(G.is_prepared());
    int t1 = 0;
    if (r != -1) {
      dfs_sz(r, -1);
      dfs_hld(r, t1);
    } else {
      FOR(r, N) if (parent[r] == -1) {
        head[r] = r;
        dfs_sz(r, -1);
        dfs_hld(r, t1);
      }
    }
    for (auto &&v: V) root[v] = (parent[v] == -1 ? v : root[parent[v]]);
  }

  void dfs_sz(int v, int p) {
    auto &sz = RID;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sz[v] = 1;
    int l = G.indptr[v], r = G.indptr[v + 1];
    auto &csr = G.csr_edges;
    // 
    FOR3_R(i, l, r - 1) {
      if (depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);
    }
    int hld_sz = 0;
    for (int i = l; i < r; ++i) {
      auto e = csr[i];
      if (depth[e.to] != -1) continue;
      in_tree[e.id] = 1;
      depth_weighted[e.to] = depth_weighted[v] + e.cost;
      dfs_sz(e.to, v);
      sz[v] += sz[e.to];
      if (chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }
    }
  }

  void dfs_hld(int v, int &times) {
    LID[v] = times++;
    RID[v] += LID[v];
    V[LID[v]] = v;
    bool heavy = true;
    for (auto &&e: G[v]) {
      if (!in_tree[e.id] || depth[e.to] <= depth[v]) continue;
      head[e.to] = (heavy ? head[v] : e.to);
      heavy = false;
      dfs_hld(e.to, times);
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
    assert(k <= depth[v]);
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

  int lca(int u, int v) { return LCA(u, v); }
  int la(int u, int v) { return LA(u, v); }

  int subtree_size(int v) { return RID[v] - LID[v]; }

  int dist(int a, int b) {
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  WT dist(int a, int b, bool weighted) {
    assert(weighted);
    int c = LCA(a, b);
    return depth_weighted[a] + depth_weighted[b] - 2 * depth_weighted[c];
  }

  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }

  int move(int a, int b) {
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }

  vc<int> collect_child(int v) {
    vc<int> res;
    for (auto &&e: G[v])
      if (e.to != parent[v]) res.eb(e.to);
    return res;
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
    print("in_tree(edge)", in_tree);
    print("root", root);
  }
};
#line 2 "/home/maspy/compro/library/graph/two_edge_component.hpp"

// (,  vector)
template <typename Graph>
pair<int, vc<int>> two_edge_component(Graph& G) {
  HLD hld(G);
  int N = G.N;
  vc<int> DP(N);
  for (auto&& e: G.edges) {
    if (!hld.in_tree[e.id]) {
      int a = e.frm, b = e.to;
      if (hld.depth[a] < hld.depth[b]) swap(a, b);
      DP[a]++, DP[b]--;
    }
  }
  auto& V = hld.V;
  FOR_R(i, len(V)) {
    int v = V[i];
    int p = hld.parent[v];
    if (p != -1) DP[p] += DP[v];
  }
  int C = 0;
  vc<int> comp(N, -1);
  FOR(v, N) if (DP[v] == 0) comp[v] = C++;
  for (auto&& v: V)
    if (comp[v] == -1) comp[v] = comp[hld.parent[v]];
  return {C, comp};
}
#line 2 "/home/maspy/compro/library/ds/segtree.hpp"

template <class Monoid>
struct SegTree {
  using X = typename Monoid::value_type;
  using value_type = X;
  vc<X> dat;
  int n, log, size;

  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit())) {}
  SegTree(vc<X> v) : n(len(v)) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid::unit());
    FOR(i, n) dat[size + i] = v[i];
    FOR3_R(i, 1, size) update(i);
  }

  void reset() { fill(all(dat), Monoid::unit()); }

  void set_all(const vc<X>& v){
    dat.assign(size << 1, Monoid::unit());
    FOR(i, n) dat[size + i] = v[i];
    FOR3_R(i, 1, size) update(i);
  }

  X operator[](int i) { return dat[size + i]; }

  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }

  void set(int i, const X& x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }

  void multiply(int i, const X& x){
    assert(i < n);
    i += size;
    dat[i] = Monoid::op(dat[i], x);
    while (i >>= 1) update(i);
  }

  X prod(int L, int R) {
    assert(L <= R);
    assert(R <= n);
    X vl = Monoid::unit(), vr = Monoid::unit();
    L += size, R += size;
    while (L < R) {
      if (L & 1) vl = Monoid::op(vl, dat[L++]);
      if (R & 1) vr = Monoid::op(dat[--R], vr);
      L >>= 1, R >>= 1;
    }
    return Monoid::op(vl, vr);
  }

  X prod_all() { return dat[1]; }

  template <class F>
  int max_right(F &check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    L += size;
    X sm = Monoid::unit();
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(Monoid::op(sm, dat[L]))) {
        while (L < size) {
          L = 2 * L;
          if (check(Monoid::op(sm, dat[L]))) {
            sm = Monoid::op(sm, dat[L]);
            L++;
          }
        }
        return L - size;
      }
      sm = Monoid::op(sm, dat[L]);
      L++;
    } while ((L & -L) != L);
    return n;
  }

  template <class F>
  int min_left(F &check, int R) {
    assert(0 <= R && R <= n && check(Monoid::unit()));
    if (R == 0) return 0;
    R += size;
    X sm = Monoid::unit();
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(Monoid::op(dat[R], sm))) {
        while (R < size) {
          R = 2 * R + 1;
          if (check(Monoid::op(dat[R], sm))) {
            sm = Monoid::op(dat[R], sm);
            R--;
          }
        }
        return R + 1 - size;
      }
      sm = Monoid::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  // prod_{l<=i<r}A[i^x] 
  // https://codeforces.com/contest/1401/problem/F
  X Xor_prod(int l, int r, int xor_val) {
    assert(Monoid::commute);
    X x = Monoid::unit();
    FOR(k, log + 1) {
      if (l >= r) break;
      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++) ^ xor_val)]); }
      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r) ^ xor_val)]); }
      l /= 2, r /= 2, xor_val /= 2;
    }
    return x;
  }

  void debug() { print("segtree", dat); }
};
#line 1 "/home/maspy/compro/library/ds/disjointsparse.hpp"
template <class Monoid>
struct DisjointSparse {
  using X = typename Monoid::value_type;
  using value_type = X;
  int n, log;
  vc<vc<X>> dat;

  DisjointSparse(vc<X>& A) : n(len(A)) {
    log = 1;
    while ((1 << log) < n) ++log;
    dat.assign(log, A);

    FOR(i, log) {
      auto& v = dat[i];
      int b = 1 << i;
      for (int m = b; m <= n; m += 2 * b) {
        int L = m - b, R = min(n, m + b);
        FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j - 1], v[j]);
        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j], v[j + 1]);
      }
    }
  }

  X prod(int L, int R) {
    if (L == R) return Monoid::unit();
    --R;
    if (L == R) return dat[0][L];
    int k = 31 - __builtin_clz(L ^ R);
    return Monoid::op(dat[k][L], dat[k][R]);
  }

  void debug() {
    print("disjoint sparse table");
    FOR(i, log) print(dat[i]);
  }
};
#line 2 "/home/maspy/compro/library/alg/monoid_max.hpp"
template <class X>
struct Monoid_Max {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }
  static constexpr X unit() { return numeric_limits<X>::lowest(); }
  static constexpr bool commute = true;
};
#line 8 "main.cpp"

using Mono = Monoid_Max<int>;

void solve() {
  LL(N, M);
  const ll INF = 1LL << 30;
  Graph<int, 0> G(N);
  G.read_graph(M);
  auto [C, comp] = two_edge_component(G);
  Graph<int, 0> T(C);
  for (auto&& e: G.edges) {
    ll a = comp[e.frm], b = comp[e.to];
    if (a == b) continue;
    T.add(a, b);
  }
  T.build();
  HLD<decltype(T)> hld(T, comp[0]);
  auto& par = hld.parent;
  vc<int> root(C);
  root[comp[0]] = 0;
  for (auto&& e: G.edges) {
    ll a = comp[e.frm], b = comp[e.to];
    if (a == b) continue;
    if (par[a] == b) root[a] = e.frm;
    if (par[b] == a) root[b] = e.to;
  }

  vvc<int> cyc(C);
  FOR(cls, C) {
    ll v = root[cls];
    vc<int> P = {v};
    while (1) {
      ll p = P.back();
      for (auto&& e: G[p]) {
        ll to = e.to;
        if (comp[to] != cls) continue;
        if (len(P) >= 2 && P[len(P) - 2] == to) continue;
        P.eb(to);
        break;
      }
      if (P.back() == v) break;
    }
    assert(len(P) != 2);
    if (len(P) >= 2) P.pop_back();
    cyc[cls] = P;
  }

  vc<int> dp1(C, INF);
  {
    // 
    auto dfs = [&](auto& dfs, int cls) -> int {
      auto& P = cyc[cls];
      ll n = len(P);
      vc<int> A(n);
      FOR(i, n) {
        ll v = P[i];
        for (auto&& e: G[v]) {
          ll to = e.to;
          if (comp[to] == cls || comp[to] == par[cls]) continue;
          chmax(A[i], 1 + dfs(dfs, comp[to]));
        }
      }

      if (n == 1) {
        dp1[cls] = A[0];
        return dp1[cls];
      }
      vc<int> B(n), C(n);
      FOR(i, n) B[i] = A[i] + i, C[i] = A[i] + n - i;
      DisjointSparse<Mono> sp1(B), sp2(C);

      FOR(i, n + 1) { chmin(dp1[cls], max(sp1.prod(0, i), sp2.prod(i, n))); }
      return dp1[cls];
    };
    dfs(dfs, comp[0]);
  }

  // print("dp1", dp1);

  vc<int> dp2(C);
  vc<int> ANS(N, -1);
  {
    // 
    auto dfs = [&](auto& dfs, int cls) -> void {
      auto& P = cyc[cls];
      ll n = len(P);
      vc<int> A(n);
      FOR(i, n) {
        ll v = P[i];
        for (auto&& e: G[v]) {
          ll to = e.to;
          if (comp[to] == cls || comp[to] == par[cls]) continue;
          chmax(A[i], 1 + dp1[comp[to]]);
        }
      }
      chmax(A[0], dp2[cls]);
      // print("A", A);

      // 
      vc<int> to_other(n, INF);
      if (n == 1) { to_other[0] = 0; }
      if (n >= 2) {
        vc<int> B(2 * n), C(2 * n);
        FOR(i, 2 * n) B[i] = A[i % n] + i, C[i] = A[i % n] - i;
        DisjointSparse<Monoid_Max<int>> sp1(B), sp2(C);
        FOR(i, n) {
          auto cost_l = [&](ll k) -> ll {
            ll x = sp2.prod(n + i - k, n + i);
            if (x == Mono::unit()) return x;
            return x + n + i;
          };
          auto cost_r = [&](ll k) -> ll {
            ll x = sp1.prod(i + 1, i + k + 1);
            if (x == Mono::unit()) return x;
            return x - i;
          };
          auto check
              = [&](int k) -> bool { return cost_l(k) >= cost_r(n - 1 - k); };
          ll k = binary_search(check, n - 1, 0);
          FOR(diff, -2, 3) {
            ll l = k + diff;
            ll r = n - 1 - l;
            if (l < 0 || r < 0) continue;
            chmin(to_other[i], max(cost_l(l), cost_r(r)));
          }
        }
      }
      // print("to other", to_other);

      FOR(i, n) {
        ll v = P[i];
        vc<int> nbd;
        for (auto&& e: G[v]) {
          if (comp[e.to] == comp[v]) continue;
          nbd.eb(e.to);
        }
        ll k = len(nbd);
        vc<int> dat(k);
        FOR(j, k) {
          ll to = nbd[j];
          if (comp[to] == par[cls]) {
            dat[j] = dp2[cls];
          } else {
            dat[j] = dp1[comp[to]] + 1;
          }
        }
        SegTree<Monoid_Max<int>> seg(dat);
        ANS[v] = to_other[i];
        chmax(ANS[v], seg.prod_all());
        FOR(j, k) {
          ll to = nbd[j];
          if (comp[to] == par[cls]) continue;
          dat[j] = dp2[cls];
          ll x = to_other[i];
          chmax(x, seg.prod(0, j));
          chmax(x, seg.prod(j + 1, k));
          dp2[comp[to]] = x + 1;
          dfs(dfs, comp[to]);
        }
      }
      return;
    };
    dfs(dfs, comp[0]);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}