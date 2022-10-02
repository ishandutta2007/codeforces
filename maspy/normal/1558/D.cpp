#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
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
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

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

#define INT(...)                                                                                                                                               \
  int __VA_ARGS__;                                                                                                                                           \
  IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
  ll __VA_ARGS__;                                                                                                                                            \
  IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
  string __VA_ARGS__;                                                                                                                                        \
  IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
  char __VA_ARGS__;                                                                                                                                          \
  IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
  long double __VA_ARGS__;                                                                                                                                        \
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


template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#line 3 "/home/maspy/library/ds/fenwick.hpp"

template< typename T >
struct FenwickTree {
  vector< T > data;

  FenwickTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }

  ll find_kth_element(T k){
    auto N = data.size();
    ll x = 0;
    T sx = 0;
    ll dx = 1;
    while (2 * dx < N) dx *= 2;
    while(dx){
      ll y = x + dx;
      if(y<N){
        T sy = sx + data[y];
        if(sy < k){
          swap(x, y);
          swap(sx, sy);
        }
      }
      dx /= 2;
    }
    return x;
  }
};
#line 3 "/home/maspy/library/mod/modint.hpp"

template <std::uint_fast64_t Modulus> class modint {
  long long val;
  public:
    static const uint_fast64_t mod = Modulus;
    constexpr modint(long long x = 0) {
      x %= ll(Modulus);
      if(x<0) x += ll(Modulus);
      val = x;
    }
    constexpr modint operator+(const modint rhs) const noexcept {return modint(*this) += rhs;}
    constexpr modint operator-(const modint rhs) const noexcept {return modint(*this) -= rhs;}
    constexpr modint operator*(const modint rhs) const noexcept {return modint(*this) *= rhs;}
    constexpr modint operator/(const modint rhs) const noexcept {return modint(*this) /= rhs;}
    constexpr modint &operator+=(const modint rhs) noexcept {
      val += rhs.val;
      if (val >= Modulus) val -= Modulus;
      return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
      if (val < rhs.val) val += Modulus;
      val -= rhs.val;
      return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
      val = val * rhs.val % Modulus;
      return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
      auto exp = Modulus - 2;
      while (exp) {
        if (exp % 2) {
          *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
      }
      return *this;
    }
    bool operator==(const modint &rhs) {
      return val==rhs.val;
    }
    friend ostream &operator<<(ostream &os, const modint &p) {
      return os << p.val;
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
      _fact.eb(_fact[i-1] * i);
      auto q = T::mod / i, r = T::mod % i;
      _inv.eb(_inv[r] * (T::mod-q));
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
  
  T C(int n, int k, bool large=false){
    assert(n >= 0);
    if (k < 0 || n < k) return 0;
    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);
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
#line 5 "main.cpp"

using mint = modint998;

const int MAX = 200'010;

FenwickTree<ll> bit(200'100);
int rk[200'100];
int pos[200'100];
int A[200'100];
ModCalc<mint> MM;

void solve() {
  LL(N, M);

  vi I(M);

  FOR(i, M) {
    LL(a, b);
    --a;
    I[i] = a;
    rk[a] = b;
  }

  vi filled;
  FOR_R(i, I.size()) {
    ll x = I[i];
    ll p = bit.find_kth_element(rk[x]);
    bit.add(p, -1);
    pos[x] = p;
    A[p] = x;
    filled.eb(p);
  }

  vi cand;  // A[i] > A[i+1]  i
  FORIN(p, filled) {
    if (p > 0) cand.eb(p - 1);
    if (p + 1 < N) cand.eb(p);
  }
  UNIQUE(cand);

  auto get_A = [&](ll p) -> ll {
    if (A[p] != -1) return A[p];
    return bit.sum(p);
  };

  FORIN(x, I) A[pos[x]] = x;
  ll K = 0;
  FORIN(p, cand) { K += get_A(p) > get_A(p + 1); }
  K = N - 1 - K;
  // print(N, K);

  mint ANS = MM.C(N + K, K);
  print(ANS);

  // rollback
  FORIN(x, I) {
    bit.add(pos[x], 1);
    A[pos[x]] = -1;
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // initialize bit
  FOR(i, MAX) bit.add(i, 1);
  FOR(i, MAX) A[i] = -1;

  LL(T);
  FOR(_, T) solve();

  // solve();

  return 0;
}