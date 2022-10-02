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
#line 2 "/home/maspy/compro/library/mod/modint61.hpp"
struct modint61 {
  static constexpr bool is_modint = true;
  static constexpr ll mod = (1LL << 61) - 1;
  ll val;
  constexpr modint61(const ll val = 0) : val(val) {}
  bool operator<(const modint61 &other) const {
    return val < other.val;
  } // To use std::map
  bool operator==(const modint61 &p) const { return val == p.val; }
  bool operator!=(const modint61 &p) const { return val != p.val; }
  modint61 &operator+=(const modint61 &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint61 &operator-=(const modint61 &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint61 &operator*=(const modint61 &p) {
    ll a = val, b = p.val;
    const ll MASK30 = (1LL << 30) - 1;
    const ll MASK31 = (1LL << 31) - 1;
    const ll MASK61 = (1LL << 61) - 1;
    ll au = a >> 31, ad = a & MASK31;
    ll bu = b >> 31, bd = b & MASK31;
    ll x = ad * bu + au * bd;
    ll xu = x >> 30, xd = x & MASK30;
    x = au * bu * 2 + xu + (xd << 31) + ad * bd;
    xu = x >> 61, xd = x & MASK61;
    x = xu + xd;
    if (x >= MASK61) x -= MASK61;
    val = x;
    return *this;
  }
  modint61 &operator/=(const modint61 &p) {
    *this *= p.inverse();
    return *this;
  }
  modint61 operator+(const modint61 &p) const { return modint61(*this) += p; }
  modint61 operator-(const modint61 &p) const { return modint61(*this) -= p; }
  modint61 operator*(const modint61 &p) const { return modint61(*this) *= p; }
  modint61 operator/(const modint61 &p) const { return modint61(*this) /= p; }

  modint61 inverse() const {
    ll a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint61(u);
  }
  modint61 pow(int64_t n) const {
    modint61 ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret = ret * mul;
      mul = mul * mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr ll get_mod() { return mod; }
};
#line 3 "/home/maspy/compro/library/mod/modular_subset_sum.hpp"

// Faster Deterministic Modular Subset Sum. arXiv preprint arXiv:2012.06062.
// modular subset sum 
// shift  2^(N-k) 
struct ShiftTree {
  using M61 = modint61;
  int delta;
  int N, n;
  M61 base;
  vc<M61> dat;
  vc<M61> base_pow;

  ShiftTree(int N, ll base) : delta(0), N(N), n(topbit(N)), base(base) {
    assert(N == (1 << n));
    dat.assign(2 * N, 0);

    base_pow.assign(n, 1);
    base_pow[n - 1] = base;
    FOR_R(i, n - 1) base_pow[i] = base_pow[i + 1] * base_pow[i + 1];
  }

  inline int skew(int k) { return (delta >> (n - k)) & 1; }

  inline int left(int k, int i) {
    int mask = (1 << (k + 1)) - 1;
    return ((2 * i + 0 - skew(k + 1)) & mask) + (1 << (k + 1));
  }

  inline int right(int k, int i) {
    int mask = (1 << (k + 1)) - 1;
    return ((2 * i + 1 - skew(k + 1)) & mask) + (1 << (k + 1));
  }

  inline int parent(int k, int i) {
    int mask = (1 << k) - 1;
    return (((i + skew(k)) & mask) + (1 << k)) / 2;
  }

  inline void update(int k, int i) {
    M61 b = base_pow[k];
    dat[i] = b * dat[left(k, i)] + dat[right(k, i)];
  }

  inline void set(int i, ll x) {
    i = (i + N - delta) % N + N;
    dat[i] = x;
    int k = n;
    while (i != 1) {
      i = parent(k, i);
      --k;
      update(k, i);
    }
  }

  void shift(int k) {
    k %= N;
    if (k < 0) k += N;
    if (k == 0) return;
    int j = lowbit(k);
    delta = (delta + k) % N;
    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k) update(k, i); }
  }

  // [a,b)  difference output sensitive
  // T  iQ  j  (x,y) 
  static void find_differences(vc<int>& res, ShiftTree& T, ShiftTree& Q, int a,
                               int b, int k, int i, int j, int x, int y) {
    if (T.dat[i] == Q.dat[j]) return;
    if (max(a, x) >= min(b, y)) return;
    if (y == x + 1) {
      res.eb(x);
      return;
    }
    int z = (x + y) / 2;
    find_differences(res, T, Q, a, b, k + 1, T.left(k, i), Q.left(k, j), x, z);
    find_differences(res, T, Q, a, b, k + 1, T.right(k, i), Q.right(k, j), z,
                     y);
  }

  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {
    assert(T.N == Q.N);
    vc<int> res;
    find_differences(res, T, Q, a, b, 0, 1, 1, 0, T.N);
    return res;
  }
};

/*
(|vals| + mod) * log(mod)
can(x)  [x]  bool 
restore(x) 
(mod, vals) 
*/
template<typename INT>
struct Modular_Subset_Sum {
  int mod;
  vc<INT>& vals;
  vc<int> par;

  Modular_Subset_Sum(int mod, vc<INT>& vals) : mod(mod), vals(vals) {
    for(auto&& x : vals) assert(0 <= x && x < mod);
    par.assign(mod, -1);

    RandomNumberGenerator RNG;
    const ll base = RNG(0, (1LL << 61) - 1);

    int k = 1;
    while ((1 << k) < 2 * mod) ++k;

    int L = 1 << k;
    assert(L >= 2 * mod);

    ShiftTree T1(L, base);
    ShiftTree T2(L, base);
    T1.set(0, 1);
    T2.set(0, 1);
    T2.set(L - mod, 1);

    auto bit_rev = [&](int i) -> int {
      int x = 0;
      FOR(k) {
        x = 2 * x + (i & 1);
        i >>= 1;
      }
      return x;
    };

    vc<vi> IDS(L);
    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }

    FOR(i, 1, L) {
      int x = bit_rev(i);
      if (len(IDS[x]) == 0) continue;
      T2.shift(x - T2.delta);
      for (auto&& idx: IDS[x]) {
        auto diff = ShiftTree::diff(T1, T2, 0, mod);
        for (auto&& d: diff) {
          if (can(d)) continue;
          par[d] = idx;
          T1.set(d, 1);
          T2.set((d + x) % L, 1);
          T2.set((L + d + x - mod) % L, 1);
        }
      }
    }
  }

  bool can(int x) { return (x == 0 || par[x] != -1); }
  bool operator[](int x) { return can(x); }
  vc<int> restore(int x) {
    vc<int> res;
    while (x) {
      int i = par[x];
      res.eb(i);
      x -= vals[i];
      if (x < 0) x += mod;
    }
    reverse(all(res));
    return res;
  }
};
#line 4 "main.cpp"

void solve() {
  LL(N, mod);
  VEC(int, A, N);
  for (auto&& x: A) x = gcd(x, mod);
  UNIQUE(A);
  vc<int> B;
  for (auto&& a: A) {
    ll x = a;
    FOR(k, 20) {
      B.eb(x);
      x += x;
      x %= mod;
    }
  }
  for (auto&& x: B) x %= mod;
  UNIQUE(B);
  Modular_Subset_Sum<int> X(mod, B);
  vi ANS;
  FOR(k, mod) if (X[k]) ANS.eb(k);
  print(len(ANS));
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}