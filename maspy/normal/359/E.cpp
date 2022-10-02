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
#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1) & s))
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
  LL(N, x0, y0);
  --x0, --y0;
  ll H = N, W = N;
  VV(int, G, N, N);
  vc<set<ll>> X_to_Y(N);
  vc<set<ll>> Y_to_X(N);
  const ll INF = 1LL << 60;
  FOR(a, N) X_to_Y[a].insert(-INF);
  FOR(a, N) Y_to_X[a].insert(-INF);
  FOR(x, N) FOR(y, N) if (G[x][y]) X_to_Y[x].insert(y);
  FOR(x, N) FOR(y, N) if (G[x][y]) Y_to_X[y].insert(x);
  FOR(a, N) X_to_Y[a].insert(+INF);
  FOR(a, N) Y_to_X[a].insert(+INF);

  vc<pi> PATH;
  PATH.reserve(N * N);

  auto can = [&](ll x, ll y, ll d) -> bool {
    if (d == 0) {
      auto& X = Y_to_X[y];
      auto it = X.upper_bound(x);
      ll nx = *it;
      return 0 <= nx && nx < N;
    }
    if (d == 2) {
      auto& X = Y_to_X[y];
      auto it = X.lower_bound(x);
      --it;
      ll nx = *it;
      return 0 <= nx && nx < N;
    }
    if (d == 1) {
      auto& Y = X_to_Y[x];
      auto it = Y.upper_bound(y);
      ll ny = *it;
      return 0 <= ny && ny < N;
    }
    if (d == 3) {
      auto& Y = X_to_Y[x];
      auto it = Y.lower_bound(y);
      --it;
      ll ny = *it;
      return 0 <= ny && ny < N;
    }
  };

  auto isin = [&](ll x, ll y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W);
  };
  ll dx[] = {1, 0, -1, 0};
  ll dy[] = {0, 1, 0, -1};

  vv(pi, par, N, N, mp(-1, -1));
  vv(bool, vis, N, N);

  auto walk = [&](auto dfs, ll x, ll y) -> void {
    vis[x][y] = true;
    X_to_Y[x].insert(y);
    Y_to_X[y].insert(x);
    PATH.eb(mp(x, y));
    FOR(d, 4) {
      if (!can(x, y, d)) continue;
      ll nx = x + dx[d];
      ll ny = y + dy[d];
      if (vis[nx][ny]) continue;
      par[nx][ny] = mp(x, y);
      dfs(dfs, nx, ny);
      PATH.eb(mp(x, y));
    }
  };

  walk(walk, x0, y0);

  auto dir = [&](pi frm, pi to) -> string {
    if (frm.fi + 1 == to.fi) return "D";
    if (frm.fi - 1 == to.fi) return "U";
    if (frm.se + 1 == to.se) return "R";
    if (frm.se - 1 == to.se) return "L";
  };

  FOR(x, N) FOR(y, N) if (G[x][y] && !vis[x][y]) return NO();

  string ANS;
  // 
  YES();
  FOR(n, PATH.size() - 1) {
    pi frm = PATH[n], to = PATH[n + 1];
    string d = dir(frm, to);

    if (G[frm.fi][frm.se] == 0) {
      G[frm.fi][frm.se] = 1;
      ANS += "1";
    }
    ANS += d;
  }
  // 
  FOR(n, PATH.size() - 1) {
    pi frm = PATH[n], to = PATH[n + 1];
    string d = dir(frm, to);
    if (par[frm.fi][frm.se] == to) { ANS += "2"; }
    ANS += d;
  }
  ANS += "2";
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}