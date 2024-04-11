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
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  IN(name)
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
template <typename T1, typename T2, typename T3, typename T4>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &t) {
  os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
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
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
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
#line 1 "/home/maspy/library/ds/fastset.hpp"
struct FastSet {
  using uint = unsigned;
  using ull = unsigned long long;

  int bsr(ull x) { return 63 - __builtin_clzll(x); }
  int bsf(ull x) { return __builtin_ctzll(x); }

  static constexpr uint B = 64;
  int n, lg;
  vc<vc<ull>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vc<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void insert(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void erase(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B])
        break;
      i /= B;
    }
  }
  // x
  int next(int i) {
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size())
        break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      // find
      i += bsf(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsf(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }
  // x
  int prev(int i) {
    if(i < 0) return -1;
    chmin(i, n - 1);
    for (int h = 0; h < lg; h++) {
      if (i == -1)
        break;
      ull d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      // find
      i += bsr(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsr(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }
  void debug(){
    for(int i=0;i<n;++i) cout << (*this)[i];
    cout << endl;
  }
};
#line 3 "main.cpp"

void solve() {
  LL(N, M);
  VEC(pi, PA, N);
  auto I = argsort(PA);

  // 
  sort(all(PA));
  vi T(N), P(N), A(N);
  FOR(i, N) { T[i] = 0, P[i] = PA[i].fi, A[i] = PA[i].se; }
  FastSet ss(N);
  FOR(i, N) ss.insert(i);

  const ll INF = 1LL << 60;

  auto nxt = [&](ll me) -> ll {
    ll x = ss.next(me + 1);
    if (x < N) return x;
    return ss.next(0);
  };
  auto prev = [&](ll me) -> ll {
    ll x = ss.prev(me - 1);
    if (x >= 0) return x;
    return ss.prev(N);
  };
  auto calc_time = [&](ll me) -> ll {
    ll op = nxt(me);
    if (op == me) return INF;
    ll t1 = T[me], t2 = T[op];
    ll p1 = P[me], p2 = P[op];
    ll a1 = A[me], a2 = A[op];
    if (me > op) p2 += M;
    ll t = max(t1, t2);
    p1 += a1 * (t - t1);
    p2 += a2 * (t - t2);
    if (p1 >= p2) return t;
    if (I[me] > I[op]) { p2 += a2; }
    // 
    if (p1 + a1 >= p2) return t + 1;
    if (a1 <= a2) return INF;
    return t + ceil(p2 - p1 - a2, a1 - a2);
  };

  vi plan(N);
  FOR(i, N) plan[i] = calc_time(i);
  using E = tuple<ll, ll, ll>;
  pqg<E> que; // time, priority_who, who
  FOR(i, N) if (plan[i] < INF) que.emplace(plan[i], I[i], i);

  while (len(que)) {
    auto [t, pri, me] = que.top();
    que.pop();
    if (t != plan[me]) continue;
    if (t == INF) break;
    ll get = 0;
    while (calc_time(me) <= t) {
      ++get;
      ll op = nxt(me);
      // print(I[me], "kill", I[op]);
      plan[op] = INF;
      ss.erase(op);
    }
    ll dt = t - T[me];
    T[me] = t;
    P[me] += dt * A[me];
    A[me] -= get;
    plan[me] = calc_time(me);
    ll who = prev(me);
    plan[who] = calc_time(who);
    que.emplace(plan[me], I[me], me);
    que.emplace(plan[who], I[who], who);
  }
  vi ANS;
  FOR(i, N) if (ss[i]) ANS.eb(I[i] + 1);
  sort(all(ANS));
  print(len(ANS));
  print(ANS);
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