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
#define DBL(...)           \
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
    assert(!prepared && 0 <= frm && 0 <= to);
    chmax(N, frm + 1);
    chmax(N, to + 1);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  void read_tree(bool wt=false, int off=1){
    read_graph(N - 1, wt, off);
  }

  void read_graph(int M, bool wt=false, int off=1){
    FOR_(M){
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

  void read_parent(int off=1){
    FOR3(v, 1, N){
      INT(p);
      p -= off;
      add(p, v);
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
#line 2 "/home/maspy/compro/library/mod/modint.hpp"
template <int mod>
struct modint {
  static constexpr bool is_modint = true;
  int val;
  constexpr modint(const ll val = 0) noexcept
      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}
  bool operator<(const modint &other) const {
    return val < other.val;
  } // To use std::map
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = (int)(1LL * val * p.val % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(-val); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(int64_t n) const {
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr int get_mod() { return mod; }
};

struct ArbitraryModInt {
  static constexpr bool is_modint = true;
  int val;
  ArbitraryModInt() : val(0) {}
  ArbitraryModInt(int64_t y)
      : val(y >= 0 ? y % get_mod()
                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}
  bool operator<(const ArbitraryModInt &other) const {
    return val < other.val;
  } // To use std::map<ArbitraryModInt, T>
  static int &get_mod() {
    static int mod = 0;
    return mod;
  }
  static void set_mod(int md) { get_mod() = md; }
  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((val += p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)val * p.val;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    val = m;
    return *this;
  }
  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ArbitraryModInt operator-() const { return ArbitraryModInt(-val); }
  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }
  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }
  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }
  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }
  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }
  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }
  ArbitraryModInt inverse() const {
    int a = val, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }
  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
};

template<typename mint>
tuple<mint, mint, mint> get_factorial_data(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  static vector<mint> fact = {1, 1};
  static vector<mint> fact_inv = {1, 1};
  static vector<mint> inv = {0, 1};
  while(len(fact) <= n){
    int k = len(fact);
    fact.eb(fact[k - 1] * mint(k));
    auto q = ceil(mod, k);
    int r = k * q - mod;
    inv.eb(inv[r] * mint(q));
    fact_inv.eb(fact_inv[k - 1] * inv[k]);
  }
  return {fact[n], fact_inv[n], inv[n]};
}

template<typename mint>
mint fact(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n);
  if(n >= mod) return 0;
  return get<0>(get_factorial_data<mint>(n));
}

template<typename mint>
mint fact_inv(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  return get<1>(get_factorial_data<mint>(n));
}

template<typename mint>
mint inv(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  return get<2>(get_factorial_data<mint>(n));
}

template<typename mint>
mint C(ll n, ll k, bool large = false) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) {
    x *= mint(n - i);
  }
  x *= fact_inv<mint>(k);
  return x;
}

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
using amint = ArbitraryModInt;
#line 5 "main.cpp"

using mint = modint107;

void solve() {
  LL(M, N);

  Graph<int, 1> G(N);
  vi spec(N);
  vi deg(N);
  FOR(i, M) {
    LL(t);
    if (t == 1) {
      LL(v);
      if (v > 0) spec[abs(v) - 1] |= 1;
      if (v < 0) spec[abs(v) - 1] |= 2;
    } else {
      LL(a, b);
      if (a == b) {
        spec[abs(a) - 1] = 1;
        continue;
      }
      if (a == -b) {
        spec[abs(a) - 1] = 3;
        continue;
      }
      int s = 0, t = 0;
      if (a < 0) s |= 1, t |= 2;
      if (b < 0) s |= 2, t |= 1;
      a = abs(a), b = abs(b);
      --a, --b;
      G.add(a, b, s, i);
      G.add(b, a, t, i);
      deg[a]++, deg[b]++;
    }
  }
  G.prepare();

  vi done_e(M);
  vi done(N);

  auto calc_point = [&](ll s, ll x) -> ll {
    if (s == 0) return 0;
    if (s == 1) return x;
    if (s == 2) return x ^ 1;
    if (s == 3) return 1;
  };

  auto calc_edge = [&](ll e, ll x, ll y) -> ll {
    ll or_v = 0;
    if ((e & 1) == 0) or_v |= x;
    if ((e & 1) != 0) or_v |= (1 ^ x);
    if ((e & 2) == 0) or_v |= y;
    if ((e & 2) != 0) or_v |= (1 ^ y);
    return or_v;
  };

  mint dp0 = 1, dp1 = 0;
  FOR(v, N) if (deg[v] == 0 && !done[v]) {
    done[v] = 1;
    ll s = spec[v];
    auto a = calc_point(s, 0);
    auto b = calc_point(s, 1);
    mint dp2, dp3;
    for (auto&& c: vi({a, b})) {
      if (c == 0)
        dp2 += dp0, dp3 += dp1;
      else
        dp2 += dp1, dp3 += dp0;
    }
    tie(dp0, dp1) = mp(dp2, dp3);
  }

  auto calc_path = [&](vi P, vi E) -> pair<mint, mint> {
    // ,  xor -> 
    vv(mint, DP, 2, 2);
    ll a = calc_point(P[0], 0);
    ll b = calc_point(P[0], 1);
    DP[0][a] = 1;
    DP[1][b] = 1;

    FOR(i, len(P) - 1) {
      ll p = P[i + 1], e = E[i];
      vv(mint, newDP, 2, 2);
      FOR(prev_x, 2) FOR(prev_xor, 2) FOR(x, 2) {
        ll new_xor = prev_xor;
        new_xor ^= calc_point(p, x);
        new_xor ^= calc_edge(e, prev_x, x);
        newDP[x][new_xor] += DP[prev_x][prev_xor];
      }
      swap(DP, newDP);
    }
    return {DP[0][0] + DP[1][0], DP[0][1] + DP[1][1]};
  };

  auto calc_cyc = [&](vi P, vi E) -> pair<mint, mint> {
    // , ,  xor -> 
    vvv(mint, DP, 2, 2, 2);
    ll a = calc_point(P[0], 0);
    ll b = calc_point(P[0], 1);
    DP[0][0][a] = 1;
    DP[1][1][b] = 1;

    FOR(i, len(P) - 1) {
      ll p = P[i + 1], e = E[i];
      vvv(mint, newDP, 2, 2, 2);
      FOR(beg, 2) {
        FOR(prev_x, 2) FOR(prev_xor, 2) FOR(x, 2) {
          ll new_xor = prev_xor;
          new_xor ^= calc_point(p, x);
          new_xor ^= calc_edge(e, prev_x, x);
          newDP[beg][x][new_xor] += DP[beg][prev_x][prev_xor];
        }
      }
      swap(DP, newDP);
    }
    pair<mint, mint> ANS;
    FOR(x, 2) FOR(y, 2) FOR(xor_v, 2) {
      auto e = E.back();
      ll v = xor_v ^ calc_edge(e, y, x);
      if (v == 0)
        ANS.fi += DP[x][y][xor_v];
      else
        ANS.se += DP[x][y][xor_v];
    }
    return ANS;
  };

  FOR(root, N) if (deg[root] == 1 && !done[root]) {
    done[root] = 1;
    vi P = {root};
    vi E = {};
    while (1) {
      ll v = P.back();
      ll nxt = -1;
      for (auto&& e: G[v]) {
        if (done_e[e.id]) continue;
        done_e[e.id] = 1;
        nxt = e.to;
        P.eb(nxt);
        E.eb(e.cost);
        break;
      }
      if (nxt == -1) break;
    }
    for (auto&& v: P) done[v] = 1;
    for (auto&& v: P) v = spec[v];
    auto [a, b] = calc_path(P, E);
    // print("P", P, "E", E, "calc", a, b);
    tie(dp0, dp1) = mp(dp0 * a + dp1 * b, dp0 * b + dp1 * a);
  }

  FOR(root, N) if (deg[root] == 2 && !done[root]) {
    done[root] = 1;
    vi P = {root};
    vi E = {};
    while (1) {
      ll v = P.back();
      ll nxt = -1;
      for (auto&& e: G[v]) {
        if (done_e[e.id]) continue;
        done_e[e.id] = 1;
        nxt = e.to;
        P.eb(nxt);
        E.eb(e.cost);
        break;
      }
      if (nxt == -1) break;
    }
    assert(P.back() == root);
    P.pop_back();
    for (auto&& v: P) done[v] = 1;
    for (auto&& v: P) v = spec[v];
    auto [a, b] = calc_cyc(P, E);
    // print("P", P, "E", E, "calc", a, b);
    tie(dp0, dp1) = mp(dp0 * a + dp1 * b, dp0 * b + dp1 * a);
  }
  print(dp1);
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