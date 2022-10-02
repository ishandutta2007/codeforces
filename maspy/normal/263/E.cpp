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
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
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


template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#line 4 "main.cpp"

void solve() {
  LL(H, W, K);
  H += 2;
  W += 2;
  --K;
  vv(ll, A, H, W);
  FOR3(h, 1, H - 1) FOR3(w, 1, W - 1) {
    LL(x);
    A[h][w] = x;
  }

  auto rot90 = [&](vc<vi>& A) -> vc<vi> {
    ll H = A.size(), W = A[0].size();
    vv(ll, B, W, H);
    FOR(h, H) FOR(w, W) B[W - 1 - w][h] = A[h][w];
    return B;
  };

  auto cum = [&](vc<vi>& A) -> void {
    ll H = A.size(), W = A[0].size();
    FOR_R(h, H - 1) FOR(w, W - 1) A[h][w + 1] += A[h + 1][w];
    FOR(h, H - 1) FOR(w, W) A[h + 1][w] += A[h][w];
    FOR(h, H - 1) FOR(w, W) A[h + 1][w] += A[h][w];
    FOR(h, H) FOR(w, W - 1) A[h][w + 1] += A[h][w];
    FOR(h, H) FOR(w, W - 1) A[h][w + 1] += A[h][w];
    return;
  };

  auto diff = [&](vc<vi>& A) -> void {
    ll H = A.size(), W = A[0].size();
    FOR_R(h, H) FOR_R(w, W - 1) A[h][w + 1] -= A[h][w];
    FOR_R(h, H) FOR_R(w, W - 1) A[h][w + 1] -= A[h][w];
    FOR_R(h, H - 1) FOR_R(w, W) A[h + 1][w] -= A[h][w];
    FOR_R(h, H - 1) FOR_R(w, W) A[h + 1][w] -= A[h][w];
    FOR(h, H - 1) FOR_R(w, W - 1) A[h][w + 1] -= A[h + 1][w];
    return;
  };

  auto add_triangle = [&](vc<vi>& A, ll i, ll j, ll x, ll K) -> void {
    ll H = A.size(), W = A[0].size();
    A[i][j] += K * x;
    A[i + 1][j] -= (K + 1) * x;
    A[i - 1][j + 1] -= K * x;
    A[i + 1][j + 1] += (K + 2) * x;
    A[i - 1][j + 2] += (K + 1) * x;
    A[i][j + 2] -= (K + 2) * x;

    A[i + K + 1][j] += x;
    A[i + K + 1][j + 1] -= 2 * x;
    A[i + K + 1][j + 2] += x;
    A[i - 1][j + K + 2] -= x;
    A[i][j + K + 2] += 2 * x;
    A[i + 1][j + K + 2] -= x;
  };

  vv(ll, COST, H, W);
  FOR(h, H) FOR(w, W) COST[h][w] += (K + 1) * A[h][w];

  FOR(i, 4) {
    A = rot90(A);
    COST = rot90(COST);

    ll H = A.size();
    ll W = A[0].size();
    vv(ll, B, H + K + 3, W + K + 3);
    FOR(h, H) FOR(w, W) if (A[h][w] != 0) { add_triangle(B, h, w, A[h][w], K); }
    cum(B);
    FOR(h, H - 1) FOR(w, W) COST[h + 1][w] += B[h][w];
  }

  ++K;
  FOR(h, H) FOR(w, W) {
    if (h < K || h >= H - K) COST[h][w] = -1;
    if (w < K || w >= W - K) COST[h][w] = -1;
  }
  ll ans = -1;
  pi ANS = mp(-1, -1);
  FOR(h, H) FOR(w, W) {
    if (chmax(ans, COST[h][w])) ANS = mp(h, w);
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}