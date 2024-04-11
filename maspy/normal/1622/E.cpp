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
#line 2 "main.cpp"

void solve() {
  LL(K, N);
  VEC(ll, A, K);
  VEC(string, S, K);
  const ll INF = 1LL << 60;
  ll best = -INF;
  vi ANS;

  auto eval = [&](vi P) -> void {
    assert(len(P) == N);
    ll x = 0;
    FOR(k, K) {
      ll he = 0;
      FOR(n, N) if (S[k][n] == '1') he += P[n];
      x += abs(he - A[k]);
    }
    if (chmax(best, x)) ANS = P;
  };

  FOR(s, 1 << K) {
    // 
    vi coef(N);
    FOR(k, K) FOR(n, N) if (S[k][n] == '1') { coef[n] += (s & 1 << k ? 1 : -1); }
    auto X = argsort(coef);
    vi cand(N);
    FOR(i, N) cand[X[i]] = i + 1;
    eval(cand);
  }
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