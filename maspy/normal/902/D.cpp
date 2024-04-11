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
#line 2 "/home/maspy/compro/library/mod/modint.hpp"
template <u32 mod>
struct modint {
  static constexpr bool is_modint = true;
  u32 val;
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
    val = (u32)(1LL * val * p.val % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(get_mod() - val); }
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
  static constexpr u32 get_mod() { return mod; }
};

struct ArbitraryModInt {
  static constexpr bool is_modint = true;
  u32 val;
  ArbitraryModInt() : val(0) {}
  ArbitraryModInt(int64_t y)
      : val(y >= 0 ? y % get_mod()
                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}
  bool operator<(const ArbitraryModInt &other) const {
    return val < other.val;
  } // To use std::map<ArbitraryModInt, T>
  static u32 &get_mod() {
    static u32 mod = 0;
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
  ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod() - val); }
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

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {0, 1};
  assert(0 <= n);
  if (n >= mod) n %= mod;
  while (int(dat.size()) <= n) {
    int k = dat.size();
    auto q = (mod + k - 1) / k;
    int r = k * q - mod;
    dat.emplace_back(dat[r] * mint(q));
  }
  return dat[n];
}

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {1, 1};
  assert(0 <= n);
  if (n >= mod) return 0;
  while (int(dat.size()) <= n) {
    int k = dat.size();
    dat.emplace_back(dat[k - 1] * mint(k));
  }
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {1, 1};
  assert(0 <= n && n < mod);
  while (int(dat.size()) <= n) {
    int k = dat.size();
    dat.emplace_back(dat[k - 1] * inv<mint>(k));
  }
  return dat[n];
}

template <typename mint, bool large = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) { x *= mint(n - i); }
  x *= fact_inv<mint>(k);
  return x;
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

using modint107 = modint<1000000007>;
using modint998 = modint<998244353>;
using amint = ArbitraryModInt;
#line 2 "/home/maspy/compro/library/poly/count_terms.hpp"
template<typename mint>
int count_terms(const vc<mint>& f){
  int t = 0;
  FOR(i, len(f)) if(f[i] != mint(0)) ++t;
  return t;
}
#line 2 "/home/maspy/compro/library/mod/mod_inv.hpp"
// long 
ll mod_inv(ll val, ll mod) {
  ll a = val, b = mod, u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b), swap(u -= t * v, v);
  }
  if(u < 0) u += mod;
  return u;
}
#line 1 "/home/maspy/compro/library/poly/convolution_naive.hpp"
template <class T>
vector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {
  int n = int(a.size()), m = int(b.size());
  vector<T> ans(n + m - 1);
  if (n < m) {
    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];
  } else {
    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];
  }
  return ans;
}
#line 2 "/home/maspy/compro/library/poly/ntt.hpp"

template <class mint>
struct ntt_info {
  static constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
  }

  static constexpr int rank2 = bsf_constexpr(mint::get_mod() - 1);
  array<mint, rank2 + 1> root;
  array<mint, rank2 + 1> iroot;
  array<mint, max(0, rank2 - 1)> rate2;
  array<mint, max(0, rank2 - 1)> irate2;
  array<mint, max(0, rank2 - 2)> rate3;
  array<mint, max(0, rank2 - 2)> irate3;

  ntt_info() {
    int g = primitive_root(mint::get_mod());
    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);
    iroot[rank2] = mint(1) / root[rank2];
    FOR_R(i, rank2) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }

    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }

  constexpr int primitive_root(int m) {
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 880803841) return 26;
    if (m == 998244353) return 3;
    return -1;
  }
};

template <class mint>
void ntt(vector<mint>& a, bool inverse) {
  int n = int(a.size());
  int h = topbit(n);
  assert(n == 1 << h);
  static const ntt_info<mint> info;
  if (!inverse) {
    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len < h) {
      if (h - len == 1) {
        int p = 1 << (h - len - 1);
        mint rot = 1;
        FOR(s, 1 << len) {
          int offset = s << (h - len);
          FOR(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * rot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          rot *= info.rate2[topbit(~s & -~s)];
        }
        len++;
      } else {
        int p = 1 << (h - len - 2);
        mint rot = 1, imag = info.root[2];
        for (int s = 0; s < (1 << len); s++) {
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();
            auto a0 = 1ULL * a[i + offset].val;
            auto a1 = 1ULL * a[i + offset + p].val * rot.val;
            auto a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;
            auto a3 = 1ULL * a[i + offset + 3 * p].val * rot3.val;
            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val * imag.val;
            auto na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          rot *= info.rate3[topbit(~s & -~s)];
        }
        len += 2;
      }
    }
  } else {
    mint coef = mint(1) / mint(len(a));
    FOR(i, len(a)) a[i] *= coef;
    int len = h;
    while (len) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint irot = 1;
        FOR(s, 1 << (len - 1)) {
          int offset = s << (h - len + 1);
          FOR(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p];
            a[i + offset] = l + r;
            a[i + offset + p]
                = (unsigned long long)(mint::get_mod() + l.val - r.val)
                  * irot.val;
            ;
          }
          irot *= info.irate2[topbit(~s & -~s)];
        }
        len--;
      } else {
        int p = 1 << (h - len);
        mint irot = 1, iimag = info.iroot[2];
        FOR(s, (1 << (len - 2))) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len + 2);
          for (int i = 0; i < p; i++) {
            auto a0 = 1ULL * a[i + offset + 0 * p].val;
            auto a1 = 1ULL * a[i + offset + 1 * p].val;
            auto a2 = 1ULL * a[i + offset + 2 * p].val;
            auto a3 = 1ULL * a[i + offset + 3 * p].val;

            auto a2na3iimag
                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;

            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p]
                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;
            a[i + offset + 2 * p]
                = (a0 + a1 + (mint::get_mod() - a2) + (mint::get_mod() - a3))
                  * irot2.val;
            a[i + offset + 3 * p]
                = (a0 + (mint::get_mod() - a1) + (mint::get_mod() - a2na3iimag))
                  * irot3.val;
          }
          irot *= info.irate3[topbit(~s & -~s)];
        }
        len -= 2;
      }
    }
  }
}
#line 1 "/home/maspy/compro/library/poly/fft.hpp"
namespace CFFT {
using real = double;

struct C {
  real x, y;

  C() : x(0), y(0) {}

  C(real x, real y) : x(x), y(y) {}
  inline C operator+(const C& c) const { return C(x + c.x, y + c.y); }
  inline C operator-(const C& c) const { return C(x - c.x, y - c.y); }
  inline C operator*(const C& c) const {
    return C(x * c.x - y * c.y, x * c.y + y * c.x);
  }

  inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  rts.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  while (base < nbase) {
    real angle = PI * 2.0 / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      real angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void fft(vector<C>& a, int n) {
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = a[i + j + k] * rts[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}
} // namespace CFFT
#line 7 "/home/maspy/compro/library/poly/convolution.hpp"

template <class mint>
vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {
  int n = int(a.size()), m = int(b.size());
  int sz = 1;
  while (sz < n + m - 1) sz *= 2;

  // sz = 2^k 
  if ((n + m - 3) <= sz / 2) {
    auto a_last = a.back(), b_last = b.back();
    a.pop_back(), b.pop_back();
    auto c = convolution(a, b);
    c.eb(0);
    c.eb(0);
    c.back() = a_last * b_last;
    FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;
    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;
    return c;
  }

  a.resize(sz), b.resize(sz);
  bool same = a == b;
  ntt(a, 0);
  if (same) {
    b = a;
  } else {
    ntt(b, 0);
  }
  FOR(i, sz) a[i] *= b[i];
  ntt(a, 1);
  a.resize(n + m - 1);
  return a;
}

template <typename mint>
vector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  static const long long nttprimes[] = {754974721, 167772161, 469762049};
  using mint0 = modint<754974721>;
  using mint1 = modint<167772161>;
  using mint2 = modint<469762049>;
  vc<mint0> a0(n), b0(m);
  vc<mint1> a1(n), b1(m);
  vc<mint2> a2(n), b2(m);
  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;
  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;
  auto c0 = convolution_ntt<mint0>(a0, b0);
  auto c1 = convolution_ntt<mint1>(a1, b1);
  auto c2 = convolution_ntt<mint2>(a2, b2);
  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;
  static const long long m01_inv_m2 = mint2(m01).inverse().val;
  static const int mod = mint::get_mod();
  auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint {
    int r0 = x0.val, r1 = x1.val, r2 = x2.val;
    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);
    return mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);
  };
  vc<mint> c(len(c0));
  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);
  return c;
}

template <typename R>
vc<double> convolution_fft(const vc<R>& a, const vc<R>& b) {
  using C = CFFT::C;
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  CFFT::ensure_base(nbase);
  int sz = 1 << nbase;
  vector<C> fa(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i] : 0);
    int y = (i < (int)b.size() ? b[i] : 0);
    fa[i] = C(x, y);
  }
  CFFT::fft(fa, sz);
  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz >> 1) + i];
    fa[i] = A0 + A1 * s;
  }
  CFFT::fft(fa, sz >> 1);
  vector<double> ret(need);
  for (int i = 0; i < need; i++) {
    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
  }
  return ret;
}

// atcoder library
vector<ll> convolution(const vector<ll>& a, const vector<ll>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  // if (min(n, m) <= 60) return convolution_naive(a, b);

  static constexpr unsigned long long MOD1 = 754974721; // 2^24
  static constexpr unsigned long long MOD2 = 167772161; // 2^25
  static constexpr unsigned long long MOD3 = 469762049; // 2^26
  static constexpr unsigned long long M2M3 = MOD2 * MOD3;
  static constexpr unsigned long long M1M3 = MOD1 * MOD3;
  static constexpr unsigned long long M1M2 = MOD1 * MOD2;
  static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

  static const unsigned long long i1 = mod_inv(MOD2 * MOD3, MOD1);
  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);
  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);

  using mint1 = modint<MOD1>;
  using mint2 = modint<MOD2>;
  using mint3 = modint<MOD3>;

  vc<mint1> a1(n), b1(m);
  vc<mint2> a2(n), b2(m);
  vc<mint3> a3(n), b3(m);
  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] = a[i];
  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];

  auto c1 = convolution_ntt<mint1>(a1, b1);
  auto c2 = convolution_ntt<mint2>(a2, b2);
  auto c3 = convolution_ntt<mint3>(a3, b3);

  vc<ll> c(n + m - 1);
  FOR(i, n + m - 1) {
    u64 x = 0;
    x += (c1[i].val * i1) % MOD1 * M2M3;
    x += (c2[i].val * i2) % MOD2 * M1M3;
    x += (c3[i].val * i3) % MOD3 * M1M2;
    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));
    if (diff < 0) diff += MOD1;
    static constexpr unsigned long long offset[5]
        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
    x -= offset[diff % 5];
    c[i] = x;
  }
  return c;
}

template <typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(
    const vc<mint>& a, const vc<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_ntt(a, b);
}

template <typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> convolution(
    const vc<mint>& a, const vc<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_garner(a, b);
}
#line 4 "/home/maspy/compro/library/poly/fps_inv.hpp"

template <typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv(
    const vc<mint>& f) {
  if (count_terms(f) <= 200) return fps_inv_sparse(f);
  return fps_inv_dense(f);
}

template <typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_inv(
    const vc<mint>& f) {
  if (count_terms(f) <= 700) return fps_inv_sparse(f);
  return fps_inv_dense(f);
}

template <typename mint>
vc<mint> fps_inv_sparse(const vc<mint>& f) {
  assert(f[0] != mint(0));
  int N = len(f);
  vc<pair<int, mint>> dat;
  FOR3(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);
  vc<mint> g(N);
  mint g0 = mint(1) / f[0];
  g[0] = g0;
  FOR3(n, 1, N) {
    mint rhs = 0;
    for (auto&& [k, fk]: dat) {
      if (k > n) break;
      rhs -= fk * g[n - k];
    }
    g[n] = rhs * g0;
  }
  return g;
}

template <typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(
    const vc<mint>& F) {
  assert(F[0] != mint(0));
  vc<mint> G = {mint(1) / F[0]};
  G.reserve(len(F));
  ll N = len(F), n = 1;
  while (n < N) {
    vc<mint> f(2 * n), g(2 * n);
    FOR(i, min(N, 2 * n)) f[i] = F[i];
    FOR(i, n) g[i] = G[i];
    ntt(f, false);
    ntt(g, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR(i, n) f[i] = 0;
    ntt(f, false);
    FOR(i, 2 * n) f[i] *= g[i];
    ntt(f, true);
    FOR3(i, n, 2 * n) G.eb(f[i] * mint(-1));
    n *= 2;
  }
  G.resize(N);
  return G;
}

template <typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(
    const vc<mint>& F) {
  int N = len(F);
  assert(F[0] != mint(0));
  vc<mint> R = {mint(1) / F[0]};
  vc<mint> p;
  int m = 1;
  while (m < N) {
    p = convolution(R, R);
    p.resize(m + m);
    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};
    p = convolution(p, f);
    R.resize(m + m);
    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];
    m += m;
  }
  R.resize(N);
  return R;
}
#line 2 "/home/maspy/compro/library/poly/poly_divmod.hpp"
template <typename mint>
pair<vc<mint>, vc<mint>> poly_divmod(vc<mint> f, vc<mint> g) {
  assert(g.back() != 0);
  if (len(f) < len(g)) { return {{}, f}; }
  auto rf = f, rg = g;
  reverse(all(rf)), reverse(all(rg));
  ll deg = len(rf) - len(rg) + 1;
  rf.resize(deg), rg.resize(deg);
  rg = fps_inv(rg);
  auto q = convolution(rf, rg);
  q.resize(deg);
  reverse(all(q));
  auto h = convolution(q, g);
  FOR(i, len(f)) f[i] -= h[i];
  while (len(f) > 0 && f.back() == 0) f.pop_back();
  return {q, f};
}
#line 1 "/home/maspy/compro/library/other/random.hpp"
struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  ll operator()(ll a, ll b) {  // [a, b)
    uniform_int_distribution<ll> dist(a, b - 1);
    return dist(mt);
  }

  ll operator()(ll b) {  // [0, b)
    return (*this)(0, b);
  }
};
#line 6 "main.cpp"

using mint = modint998;

void solve() {
  LL(N);
  auto check = [&](auto f, auto g) -> int {
    ll step = 0;
    while (1) {
      while (len(g) && g.back() == mint(0)) { g.pop_back(); }
      if (len(g) == 0) return step;
      auto [q, r] = poly_divmod(f, g);
      f = g;
      g = r;
      ++step;
    }
    return 0;
  };

  RandomNumberGenerator RNG;

  auto out = [&](vc<mint> f) -> void {
    vc<int> ff;
    for (auto&& x: f) { ff.eb(x.val); }
    for (auto&& x: ff) {
      if (x > 1) x -= mint::get_mod();
    }
    print(len(ff) - 1);
    print(ff);
  };

  while (1) {
    vc<mint> f(N + 1, 1), g(N, 1);
    FOR(i, N) f[i] = RNG(0, 2) - 1;
    FOR(i, N - 1) g[i] = RNG(0, 2) - 1;
    if (check(f, g) == N) {
      out(f);
      out(g);
      return;
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