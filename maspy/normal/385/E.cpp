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
int bsf(uint x) {
  return __builtin_ctz(x);
}
int bsf(ull x) {
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

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
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

#line 3 "/home/maspy/library/matrix/matrix.hpp"
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
#line 1 "/home/maspy/library/mod/amodint.hpp"
struct ArbitraryModInt {

  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y)
      : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {
  }

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) { get_mod() = md; }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)x * p.x;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

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

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
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
#line 5 "main.cpp"

using mint = ArbitraryModInt;

void solve() {
  LL(N);
  mint::set_mod(N);
  LL(sx, sy, dx, dy, t);
  Matrix<mint> A(6, 6);
  A[0] = {2, 1, 1, 0, 1, 0};
  A[1] = {1, 2, 0, 1, 1, 0};
  A[2] = {1, 1, 1, 0, 1, 0};
  A[3] = {1, 1, 0, 1, 1, 0};
  A[4] = {0, 0, 0, 0, 1, 1};
  A[5] = {0, 0, 0, 0, 0, 1};
  A = A.pow(t);

  Matrix<mint> v(6, 1);
  v[0][0] = sx - 1;
  v[1][0] = sy - 1;
  v[2][0] = dx;
  v[3][0] = dy;
  v[4][0] = 2;
  v[5][0] = 1;

  v = A * v;
  mint x = v[0][0];
  mint y = v[1][0];
  print(x.x + 1, y.x + 1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}