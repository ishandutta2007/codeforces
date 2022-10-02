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
#line 1 "/home/maspy/compro/library/other/interactive_io.hpp"
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
  cout.flush();
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}
#line 3 "main.cpp"

void solve() {
  LL(N);
  using T = tuple<ll, ll, ll, ll>;

  map<T, ll> MEMO;
  auto ask = [&](ll x1, ll y1, ll x2, ll y2) -> ll {
    if (x1 >= x2) return 0;
    if (y1 >= y2) return 0;
    ++x1, ++y1;
    T key = {x1, y1, x2, y2};
    if (MEMO.count(key)) return MEMO[key];
    print("?", x1, y1, x2, y2);
    LL(k);
    return (MEMO[key] = k);
  };

  vector<vector<ll>> ANS(2);

  auto out = [&]() -> void {
    ANS[0][0]++;
    ANS[0][1]++;
    ANS[1][0]++;
    ANS[1][1]++;
    print("!", ANS[0], ANS[1]);
  };

  auto find_one_range = [&]() -> T {
    ll xl = 0, yl = 0, xr = N, yr = N;
    while (1) {
      ll xm = (xl + xr) / 2, ym = (yl + yr) / 2;
      {
        ll k = ask(xl, yl, xm, yr);
        if (k == 1) return {xl, yl, xm, yr};
        if (xr != xm && k == 2) {
          xr = xm;
          continue;
        }
      }
      {
        ll k = ask(xm, yl, xr, yr);
        if (k == 1) return {xm, yl, xr, yr};
        if (xl != xm && k == 2) {
          xl = xm;
          continue;
        }
      }
      {
        ll k = ask(xl, yl, xr, ym);
        if (k == 1) return {xl, yl, xr, ym};
        if (yr != ym && k == 2) {
          yr = ym;
          continue;
        }
      }
      {
        ll k = ask(xl, ym, xr, yr);
        if (k == 1) return {xl, ym, xr, yr};
        if (yl != ym && k == 2) {
          yl = ym;
          continue;
        }
      }
    }
  };

  auto solve_in_one_range = [&](ll xl, ll yl, ll xr, ll yr) -> T {
    auto check_xl = [&](ll a) -> bool { return ask(a, yl, xr, yr) == 1; };
    auto check_yl = [&](ll a) -> bool { return ask(xl, a, xr, yr) == 1; };
    auto check_xr = [&](ll a) -> bool { return ask(xl, yl, a, yr) == 1; };
    auto check_yr = [&](ll a) -> bool { return ask(xl, yl, xr, a) == 1; };
    ll a = binary_search(check_xl, xl, xr);
    ll b = binary_search(check_yl, yl, yr);
    ll c = binary_search(check_xr, xr, xl);
    ll d = binary_search(check_yr, yr, yl);
    // print("solve in", xl, yl, xr, yr, a, b, c, d);
    return {a, b, c, d};
  };

  auto [xl, yl, xr, yr] = find_one_range();
  tie(xl, yl, xr, yr) = solve_in_one_range(xl, yl, xr, yr);
  ANS[0] = {xl, yl, xr, yr};

  vector<T> cand;
  cand.eb(0, 0, xl, N);
  cand.eb(xr, 0, N, N);
  cand.eb(0, 0, N, yl);
  cand.eb(0, yr, N, N);
  for (auto&& [a, b, c, d]: cand) {
    if (ask(a, b, c, d) == 1) {
      tie(a, b, c, d) = solve_in_one_range(a, b, c, d);
      ANS[1] = {a, b, c, d};
      break;
    }
  }

  out();
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}