#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

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
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt_int __builtin_popcount
#define popcnt __builtin_popcountll

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
#line 2 "main.cpp"

void solve() {
  LL(N);
  VEC(pi, XY, N);
  FORIN(p, XY) {
    p.fi *= 2;
    p.se *= 2;
  }
  VEC(ll, A, 9);
  sort(all(A));

  /*
  x, y  168 
  
  */
  vi THREE;
  FOR(k, 9) FOR(j, k) FOR(i, j) THREE.eb(A[i] + A[j] + A[k]);
  UNIQUE(THREE);

  vi X(N), Y(N);
  FOR(i, N) { X[i] = XY[i].fi, Y[i] = XY[i].se; }

  auto find_important = [&](vi X) -> vi {
    sort(all(X));
    vi ANS;
    FORIN(n, THREE) {
      //  n 
      if (X[n - 1] < X[n]) ANS.eb(X[n] - 1);
      if (X[N - n - 1] < X[N - n]) ANS.eb(X[N - n] - 1);
    }
    UNIQUE(ANS);
    return ANS;
  };

  X = find_important(X);
  Y = find_important(Y);
  const ll INF = 1LL << 60;
  X.insert(X.begin(), -INF);
  X.eb(INF);
  Y.insert(Y.begin(), -INF);
  Y.eb(INF);

  ll H = X.size(), W = Y.size();

  vv(ll, CNT, H, W);
  FOR(i, N) {
    auto [x, y] = XY[i];
    x = LB(X, x);
    y = LB(Y, y);
    CNT[x][y]++;
  }

  FOR(h, H - 1) FOR(w, W) CNT[h + 1][w] += CNT[h][w];
  FOR(h, H) FOR(w, W - 1) CNT[h][w + 1] += CNT[h][w];

  auto get = [&](ll x1, ll x2, ll y1, ll y2) -> ll {
    chmin(x2, H - 1);
    chmin(y2, W - 1);
    ll cnt = 0;
    cnt += CNT[x1][y1];
    cnt -= CNT[x1][y2];
    cnt -= CNT[x2][y1];
    cnt += CNT[x2][y2];
    return cnt;
  };

  vc<pi> AB;
  FOR(b, H) FOR(a, b) {
    ll x = get(0, a, 0, W);
    ll y = get(a, b, 0, W);
    ll z = get(b, H, 0, W);
    if (UB(THREE, x) == LB(THREE, x)) continue;
    if (UB(THREE, y) == LB(THREE, y)) continue;
    if (UB(THREE, z) == LB(THREE, z)) continue;
    AB.eb(mp(a, b));
  }

  vc<pi> CD;
  FOR(d, W) FOR(c, d) {
    ll x = get(0, H, 0, c);
    ll y = get(0, H, c, d);
    ll z = get(0, H, d, W);
    if (UB(THREE, x) == LB(THREE, x)) continue;
    if (UB(THREE, y) == LB(THREE, y)) continue;
    if (UB(THREE, z) == LB(THREE, z)) continue;
    CD.eb(mp(c, d));
  }

  FOR(i, AB.size()) FOR(j, CD.size()) {
    auto [a, b] = AB[i];
    auto [c, d] = CD[j];
    vi B(9);
    B[0] = get(0, a, 0, c);
    B[1] = get(0, a, c, d);
    B[2] = get(0, a, d, W);
    B[3] = get(a, b, 0, c);
    B[4] = get(a, b, c, d);
    B[5] = get(a, b, d, W);
    B[6] = get(b, H, 0, c);
    B[7] = get(b, H, c, d);
    B[8] = get(b, H, d, W);
    sort(all(B));
    if (A == B) {
      print(X[a] * 0.5, X[b] * 0.5);
      print(Y[c] * 0.5, Y[d] * 0.5);
      return;
    }
  }
  print(-1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}