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
#line 1 "/home/maspy/compro/library/other/io2.hpp"
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

#define VEC(type, name, size) \
  vector<type> name(size);    \
  scan(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  scan(name)

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
  ll H = N, W = N;
  auto isin = [&](ll x, ll y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W);
  };

  auto ask = [&](ll xl, ll yl, ll xr, ll yr) -> bool {
    print("?", xl + 1, yl + 1, xr + 1, yr + 1);
    LL(x);
    return x;
  };

  vv(ll, A, H, W, -1);
  A[0][0] = 1;
  A.back().back() = 0;
  A[0][1] = 0; // 
  vc<pi> que;
  que.eb(0, 0);
  que.eb(0, 1);
  while (len(que)) {
    auto [x, y] = que.back();
    que.pop_back();
    FOR(dx, 3) {
      ll dy = 2 - dx;
      ll nx = x + dx, ny = y + dy;
      if (!isin(nx, ny) || A[nx][ny] != -1) continue;
      A[nx][ny] = A[x][y] ^ (1 ^ ask(x, y, nx, ny));
      que.eb(nx, ny);
    }
    FOR(dx, 3) {
      ll dy = 2 - dx;
      ll nx = x - dx, ny = y - dy;
      if (!isin(nx, ny) || A[nx][ny] != -1) continue;
      A[nx][ny] = A[x][y] ^ (1 ^ ask(nx, ny, x, y));
      que.eb(nx, ny);
    }
  }

  auto check = [&](ll x1, ll y1, ll x4, ll y4, bool flip) -> bool {
    ll v1 = A[x1][y1];
    ll v4 = A[x4][y4];
    if (flip) v4 ^= 1;
    if (v1 != v4) return false;
    ll s2 = 0, s3 = 0;
    FOR(dx, 2) {
      ll dy = 1 - dx;
      ll x2 = x1 + dx;
      ll y2 = y1 + dy;
      if (x1 <= x2 && x2 <= x4 && y1 <= y2 && y2 <= y4) s2 |= 1 << A[x2][y2];
      ll x3 = x4 - dx, y3 = y4 - dy;
      if (x1 <= x3 && x3 <= x4 && y1 <= y3 && y3 <= y4) s3 |= 1 << A[x3][y3];
    }
    if (s2 == 3) return true;
    if (s3 == 3) return true;
    assert(s2 == 1 || s2 == 2);
    assert(s3 == 1 || s3 == 2);
    ll v2 = (s2 == 1 ? 0 : 1);
    ll v3 = (s3 == 1 ? 0 : 1);
    if (flip) v2 ^= 1;
    return v1 == v4 && v2 == v3;
  };

  bool flip = [&]() -> bool {
    FOR(x, N) FOR(y, N) FOR(dx, 4) {
      ll dy = 3 - dx;
      ll nx = x + dx, ny = y + dy;
      if (!isin(nx, ny)) continue;
      bool b0 = check(x, y, nx, ny, 0);
      bool b1 = check(x, y, nx, ny, 1);
      if (b0 == b1) continue;
      bool b = ask(x, y, nx, ny);
      return b == b1;
    }
    return 1;
  }();

  FOR(x, N) FOR(y, N) if (flip && ((x + y) % 2 == 1)) A[x][y] ^= 1;

  print("!");
  FOR(x, N) {
    string S;
    FOR(y, N) S += '0' + A[x][y];
    print(S);
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