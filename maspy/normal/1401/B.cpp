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
#line 2 "/home/maspy/compro/library/flow/mincostflow.hpp"

// atcoder library 

namespace internal {

template <class E>
struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
      : start(n + 1), elist(edges.size()) {
    for (auto e: edges) { start[e.first + 1]++; }
    for (int i = 1; i <= n; i++) { start[i] += start[i - 1]; }
    auto counter = start;
    for (auto e: edges) { elist[counter[e.first]++] = e.second; }
  }
};

template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T& t) { payload.push_back(t); }
  T& front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

} // namespace internal

/*
atcoder library 
DAG = true  OK 1  dp 
 toposort 
*/
template <class Cap = int, class Cost = ll, bool DAG = false>
struct mcf_graph {
public:
  mcf_graph() {}
  explicit mcf_graph(int n) : _n(n) {}

  // frm, to, cap, cost
  int add(int frm, int to, Cap cap, Cost cost) {
    assert(0 <= frm && frm < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    assert(DAG || 0 <= cost);
    if (DAG) assert(frm < to);
    int m = int(_edges.size());
    _edges.push_back({frm, to, cap, 0, cost});
    return m;
  }

  void debug() {
    print("flow graph");
    print("frm, to, cap, cost");
    for (auto&& [frm, to, cap, flow, cost]: _edges) {
      print(frm, to, cap, cost);
    }
  }

  struct edge {
    int frm, to;
    Cap cap, flow;
    Cost cost;
  };

  edge get_edge(int i) {
    int m = int(_edges.size());
    assert(0 <= i && i < m);
    return _edges[i];
  }
  std::vector<edge> edges() { return _edges; }

  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    int m = int(_edges.size());
    std::vector<int> edge_idx(m);

    auto g = [&]() {
      std::vector<int> degree(_n), redge_idx(m);
      std::vector<std::pair<int, _edge>> elist;
      elist.reserve(2 * m);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] = degree[e.frm]++;
        redge_idx[i] = degree[e.to]++;
        elist.push_back({e.frm, {e.to, -1, e.cap - e.flow, e.cost}});
        elist.push_back({e.to, {e.frm, -1, e.flow, -e.cost}});
      }
      auto _g = internal::csr<_edge>(_n, elist);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] += _g.start[e.frm];
        redge_idx[i] += _g.start[e.to];
        _g.elist[edge_idx[i]].rev = redge_idx[i];
        _g.elist[redge_idx[i]].rev = edge_idx[i];
      }
      return _g;
    }();

    auto result = slope(g, s, t, flow_limit);

    for (int i = 0; i < m; i++) {
      auto e = g.elist[edge_idx[i]];
      _edges[i].flow = _edges[i].cap - e.cap;
    }

    return result;
  }

private:
  int _n;
  std::vector<edge> _edges;

  // inside edge
  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };

  std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>& g, int s, int t,
                                          Cap flow_limit) {
    // variants (C = maxcost):
    // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
    // reduced cost (= e.cost + dual[e.frm] - dual[e.to]) >= 0 for all edge

    // dual_dist[i] = (dual[i], dist[i])
    if (DAG) assert(s == 0 && t == _n - 1);
    std::vector<std::pair<Cost, Cost>> dual_dist(_n);
    std::vector<int> prev_e(_n);
    std::vector<bool> vis(_n);
    struct Q {
      Cost key;
      int to;
      bool operator<(Q r) const { return key > r.key; }
    };
    std::vector<int> que_min;
    std::vector<Q> que;
    auto dual_ref = [&]() {
      for (int i = 0; i < _n; i++) {
        dual_dist[i].second = std::numeric_limits<Cost>::max();
      }
      std::fill(vis.begin(), vis.end(), false);
      que_min.clear();
      que.clear();

      // que[0..heap_r) was heapified
      size_t heap_r = 0;

      dual_dist[s].second = 0;
      que_min.push_back(s);
      while (!que_min.empty() || !que.empty()) {
        int v;
        if (!que_min.empty()) {
          v = que_min.back();
          que_min.pop_back();
        } else {
          while (heap_r < que.size()) {
            heap_r++;
            std::push_heap(que.begin(), que.begin() + heap_r);
          }
          v = que.front().to;
          std::pop_heap(que.begin(), que.end());
          que.pop_back();
          heap_r--;
        }
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        // dist[v] = shortest(s, v) + dual[s] - dual[v]
        // dist[v] >= 0 (all reduced cost are positive)
        // dist[v] <= (n-1)C
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (int i = g.start[v]; i < g.start[v + 1]; i++) {
          auto e = g.elist[i];
          if (!e.cap) continue;
          // |-dual[e.to] + dual[v]| <= (n-1)C
          // cost <= C - -(n-1)C + 0 = nC
          Cost cost = e.cost - dual_dist[e.to].first + dual_v;
          if (dual_dist[e.to].second > dist_v + cost) {
            Cost dist_to = dist_v + cost;
            dual_dist[e.to].second = dist_to;
            prev_e[e.to] = e.rev;
            if (dist_to == dist_v) {
              que_min.push_back(e.to);
            } else {
              que.push_back(Q{dist_to, e.to});
            }
          }
        }
      }
      if (!vis[t]) { return false; }

      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        // dual[v] = dual[v] - dist[t] + dist[v]
        //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
        //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
        //         t) + dual[t] + shortest(s, v) = shortest(s, v) -
        //         shortest(s, t) >= 0 - (n-1)C
        dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
      }
      return true;
    };

    auto dual_ref_dag = [&]() {
      for (int i = 0; i < _n; i++) {
        dual_dist[i].second = std::numeric_limits<Cost>::max();
      }
      dual_dist[s].second = 0;
      std::fill(vis.begin(), vis.end(), false);
      vis[0] = true;

      for (int v = 0; v < _n; ++v) {
        if (!vis[v]) continue;
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (int i = g.start[v]; i < g.start[v + 1]; i++) {
          auto e = g.elist[i];
          if (!e.cap) continue;
          Cost cost = e.cost - dual_dist[e.to].first + dual_v;
          if (dual_dist[e.to].second > dist_v + cost) {
            vis[e.to] = true;
            Cost dist_to = dist_v + cost;
            dual_dist[e.to].second = dist_to;
            prev_e[e.to] = e.rev;
          }
        }
      }
      if (!vis[t]) { return false; }

      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        // dual[v] = dual[v] - dist[t] + dist[v]
        //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
        //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
        //         t) + dual[t] + shortest(s, v) = shortest(s, v) -
        //         shortest(s, t) >= 0 - (n-1)C
        dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
      }
      return true;
    };

    Cap flow = 0;
    Cost cost = 0, prev_cost_per_flow = -1;
    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
    while (flow < flow_limit) {
      if (DAG && flow == 0) {
        if (!dual_ref_dag()) break;
      } else {
        if (!dual_ref()) break;
      }
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
      }
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        auto& e = g.elist[prev_e[v]];
        e.cap += c;
        g.elist[e.rev].cap -= c;
      }
      Cost d = -dual_dist[s].first;
      flow += c;
      cost += c * d;
      if (prev_cost_per_flow == d) { result.pop_back(); }
      result.push_back({flow, cost});
      prev_cost_per_flow = d;
    }
    return result;
  }
};
#line 4 "main.cpp"

void solve() {
  LL(a, b, c, d, e, f);
  mcf_graph<ll, ll, 1> G(8);
  G.add(0, 1, a, 0);
  G.add(0, 2, b, 0);
  G.add(0, 3, c, 0);
  G.add(4, 7, d, 0);
  G.add(5, 7, e, 0);
  G.add(6, 7, f, 0);

  FOR(i, 3) FOR(j, 3) {
    ll v = 0;
    if (i > j) v = i * j;
    if (i < j) v = -i * j;
    G.add(1 + i, 4 + j, a + b + c, -v);
  }

  auto slope = G.slope(0, 7);
  ll ANS = -slope.back().se;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(_, T) solve();

  return 0;
}