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
int topbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x==0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x==0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }
int lowbit(u32 x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }
int lowbit(ll x) { return (x==0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(u64 x) { return (x==0 ? -1 : 63 - __builtin_clzll(x)); }

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

template <typename T, typename CNT = int>
vc<CNT> bincount(vc<T> &A, int size) {
  vc<CNT> C(size);
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
    write(a);
    write(' ');
    write(b);
    write(' ');
    write(c);
  }
  template <class A, class B, class C, class D>
  void write(const tuple<A, B, C, D> &val) {
    auto &[a, b, c, d] = val;
    write(a);
    write(' ');
    write(b);
    write(' ');
    write(c);
    write(' ');
    write(d);
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
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
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
#line 2 "/home/maspy/compro/library/alg/monoid_cntsummin.hpp"
struct Monoid_CntSumMin {
  static constexpr ll INF = 1LL << 60;
  using value_type = tuple<ll, ll, ll>;
  using X = value_type;
  static X op(X x, X y) {
    auto [xc, xs, xm] = x;
    auto [yc, ys, ym] = y;
    return {xc + yc, xs + ys, min(xm, ym)};
  }
  static constexpr X unit() { return {0, 0, INF}; }
  static constexpr bool commute = true;
};
#line 1 "/home/maspy/compro/library/alg/monoid_set.hpp"
template <typename E, E none_val>
struct Monoid_Set {
  using value_type = E;
  using X = value_type;
  static X op(X x, X y) { return (y == none_val ? x : y); }
  static constexpr X unit() { return none_val; }
  static constexpr bool commute = false;
};
#line 3 "/home/maspy/compro/library/alg/lazy_cntsummin_set.hpp"

struct Lazy_CntSumMin_Set {
  static constexpr ll INF = 1LL<<60;
  using MX = Monoid_CntSumMin;
  using MA = Monoid_Set<ll, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    if (a == INF) return x;
    auto [xc, xs, xm] = x;
    return {xc, xc * a, a};
  }
};
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
  LazySegTree(int n) : LazySegTree(vc<X>(n, Monoid_X::unit())) {}
  LazySegTree(vc<X> v) : n(len(v)) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, Monoid_X::unit());
    laz.assign(size, Monoid_A::unit());
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
    laz[k] = Monoid_A::unit();
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
    if (l == r) return Monoid_X::unit();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    X xl = Monoid_X::unit(), xr = Monoid_X::unit();
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
    assert(check(Monoid_X::unit()));
    if (l == n) return n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    X sm = Monoid_X::unit();
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
    assert(check(Monoid_X::unit()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    X sm = Monoid_X::unit();
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
#line 5 "main.cpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  using T = tuple<ll, ll, ll>;
  vc<T> seg_raw(N);
  FOR(i, N) seg_raw[i] = {1, A[i], A[i]};
  LazySegTree<Lazy_CntSumMin_Set> seg(seg_raw);
  FOR_(Q) {
    LL(t);
    if (t == 1) {
      LL(i, x);
      auto check = [&](auto e) -> bool {
        auto& [cnt, sum, mx] = e;
        return mx >= x;
      };
      int r = seg.max_right(check, 0);
      // i x 
      if (r < i) seg.apply(r, i, x);
    } else {
      LL(p, x);
      --p;
      ll ANS = 0;
      while (p < N) {
        // x 
        {
          auto check = [&](auto e) -> bool {
            auto& [cnt, sum, mx] = e;
            return mx > x;
          };
          p = seg.max_right(check, p);
          if (p == N) break;
        }
        {
          auto check = [&](auto e) -> bool {
            auto& [cnt, sum, mx] = e;
            return sum <= x;
          };
          int to = seg.max_right(check, p);
          auto [cnt, sum, mx] = seg.prod(p, to);
          ANS += to - p;
          // print("take", p, to, ",", x, mx);
          x -= sum;
          p = to;
        }
      }
      print(ANS);
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