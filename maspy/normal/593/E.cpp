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
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  IN(name)
#define vvv(type, name, h, w, ...) \
  vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

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
  sort(all(ids), [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
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
#line 1 "/home/maspy/library/mod/modint.hpp"
template< int mod >
struct modint {
  int x;

  modint() : x(0) {}

  modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  modint &operator+=(const modint &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  modint &operator-=(const modint &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  modint &operator*=(const modint &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }

  modint operator-() const { return modint(-x); }

  modint operator+(const modint &p) const { return modint(*this) += p; }

  modint operator-(const modint &p) const { return modint(*this) -= p; }

  modint operator*(const modint &p) const { return modint(*this) *= p; }

  modint operator/(const modint &p) const { return modint(*this) /= p; }

  bool operator==(const modint &p) const { return x == p.x; }

  bool operator!=(const modint &p) const { return x != p.x; }

  modint inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }

  modint pow(int64_t n) const {
    modint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const modint &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, modint &a) {
    int64_t t;
    is >> t;
    a = modint< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

template< typename T >
struct ModCalc {
  vector<T> _fact = {1, 1};
  vector<T> _fact_inv = {1, 1};
  vector<T> _inv = {0, 1};
  
  T pow(T a, int n){
    T x(1);
    while(n) {
      if(n & 1) x *= a;
      a *= a;
      n >>= 1;
    }
    return x;
  }
  void expand(int n){
    while(_fact.size() <= n){
      auto i = _fact.size();
      _fact.eb(_fact[i-1] * T(i));
      auto q = T::get_mod() / i, r = T::get_mod() % i;
      _inv.eb(_inv[r] * T(T::get_mod()-q));
      _fact_inv.eb(_fact_inv[i-1] * _inv[i]);
    }
  }

  T fact(int n){
    if(n >= _fact.size()) expand(n);
    return _fact[n];
  }

  T fact_inv(int n){
    if(n >= _fact.size()) expand(n);
    return _fact_inv[n];
  }
  
  T inv(int n){
    if(n >= _fact.size()) expand(n);
    return _inv[n];
  }
  
  T C(ll n, ll k, bool large=false){
    assert(n >= 0);
    if (k < 0 || n < k) return 0;
    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);
    k = min(k, n-k);
    T x(1);
    FOR(i, k){
      x *= n - i;
      x *= inv(i + 1);
    }
    return x;
  }
};

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
#line 2 "/home/maspy/library/matrix/matrix.hpp"

template <typename T>
struct Matrix {
  int H, W;
  vector<vector<T>> data;

  Matrix(int H, int W) : H(H), W(W), data(H, vector<T>(W, 0)){};
  vector<T>& operator[](int i) { return data[i]; }
  Matrix<T> operator*(Matrix<T>& other) {
    assert(W == other.H);
    int a = H, b = W, c = other.W;
    Matrix<T> C(a, c);
    FOR(i, a) {
      FOR(j, b) {
        FOR(k, c) { C[i][k] += data[i][j] * other[j][k]; }
      }
    }
    return C;
  }
  void eye() { FOR(i, H) FOR(j, W) data[i][j] = (i == j ? 1 : 0); }
  Matrix<T> pow(ll K) {
    Matrix<T> P(H, H);
    P.eye();
    Matrix<T> Q(H, H);
    FOR(i, H) FOR(j, H) Q[i][j] = data[i][j];
    while (K) {
      if (K & 1) P = P * Q;
      Q = Q * Q;
      K >>= 1;
    }
    return P;
  }
};


template <class T>
bool is_zero(const T& a) {
  return a == T(0);
}

template <class T>
int row_reduce(std::vector<std::vector<T>>& a, int limit = -1) {
  int h = std::size(a);
  if (h == 0) return 0;
  int w = std::size(a[0]), rank = 0;
  if (limit < 0 or w < limit) limit = w;
  for (int p = 0; p < limit; ++p) {
    for (int i = rank + 1; i < h; ++i)
      if constexpr (std::is_floating_point_v<T>) {
        if (std::abs(a[rank][p]) < std::abs(a[i][p])) std::swap(a[rank], a[i]);
      } else if (not is_zero(a[i][p])) {
        std::swap(a[rank], a[i]);
        break;
      }
    if (is_zero(a[rank][p])) continue;
    T inv = T(1) / a[rank][p];
    for (auto&& e : a[rank]) e *= inv;
    for (int i = 0; i < h; ++i)
      if (i != rank and not is_zero(a[i][p])) {
        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j] * a[i][p];
        a[i][p] = 0;
      }
    if (++rank == h) break;
  }
  return rank;
}

template <class T>
std::pair<std::vector<T>, std::vector<std::vector<T>>> solve_linear(
  std::vector<std::vector<T>> a, const std::vector<T>& b) {
  assert(std::size(a) == std::size(b));
  assert(not std::empty(a));
  int h = std::size(a), w = std::size(a[0]);
  for (int i = 0; i < h; ++i) a[i].push_back(b[i]);
  int rank = row_reduce(a, w);
  for (int i = rank; i < h; ++i)
    if (not is_zero(a[i][w])) return {};
  std::vector<T> x(w);
  std::vector pivot(w, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (is_zero(a[i][j])) ++j;
    x[j] = a[i][w];
    pivot[j] = i;
  }
  std::vector<std::vector<T>> basis;
  for (int p = 0; p < w; ++p)
    if (pivot[p] == -1) {
      basis.emplace_back(w);
      basis.back()[p] = -1;
      for (int j = 0; j < p; ++j)
        if (pivot[j] != -1) basis.back()[j] = a[pivot[j]][p];
    }
  return {x, basis};
}
#line 4 "main.cpp"

using mint = modint107;

void solve() {
  LL(H, W, Q);
  vv(ll, G, H, W);
  auto isin = [&](ll x, ll y) -> bool { return (0 <= x && x < H && 0 <= y && y < W); };
  ll dx[] = {1, 0, -1, 0, 0};
  ll dy[] = {0, 1, 0, -1, 0};

  ll N = H * W;
  auto to_mat = [&]() -> Matrix<mint> {
    Matrix<mint> A(N, N);
    FOR(x, H) FOR(y, W) FOR(d, 5) {
      ll nx = x + dx[d], ny = y + dy[d];
      if (isin(nx, ny) && G[x][y] == 0 && G[nx][ny] == 0) { A[W * x + y][W * nx + ny] = 1; }
    }
    return A;
  };

  vc<mint> DP(N);
  DP[0] = 1;
  auto A = to_mat();
  ll t = 1;
  FOR(_, Q) {
    LL(tp, x, y, nt);
    --x, --y;
    ll dt = nt - t;
    t = nt;
    while (dt) {
      if (dt & 1) {
        vc<mint> newDP(N);
        FOR(a, N) FOR(b, N) newDP[b] += DP[a] * A[a][b];
        swap(DP, newDP);
      }
      dt >>= 1;
      if (dt) A = A * A;
    }
    if (tp == 2) G[x][y] = 1;
    if (tp == 3) G[x][y] = 0;
    A = to_mat();
    FOR(x, H) FOR(y, W) if (G[x][y] == 1) DP[W * x + y] = 0;

    if (tp == 1) print(DP[W * x + y]);
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