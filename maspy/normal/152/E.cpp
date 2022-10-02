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
  double __VA_ARGS__;                                                                                                                                        \
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
  sort(all(ids), [&](ll i, ll j){return mp(A[i],i)<=mp(A[j],j);});
  return ids;
}


template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#line 3 "main.cpp"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  LL(H, W, K);
  VV(ll, A, H, W);
  VEC(pi, XY, K);
  FORIN(p, XY) p.fi--, p.se--;
  const ll INF = 1LL << 60;
  vvv(ll, DP, 1 << K, H, W, INF);
  FOR(h, H) FOR(w, W) DP[0][h][w] = A[h][w];

  FOR3(s, 1, 1 << K) {
    FOR(k, K) {
      int t = s ^ 1 << k;
      if (t < s) {
        ll x = XY[k].fi, y = XY[k].se;
        chmin(DP[s][x][y], DP[t][x][y]);
      }
    }
    for (int t = s;; t = (t - 1) & s) {
      FOR(h, H) FOR(w, W) { chmin(DP[s][h][w], DP[t][h][w] + DP[s ^ t][h][w] - A[h][w]); }
      if (t == 0) break;
    }
    pqg<tuple<ll, ll, ll>> que;
    FOR(h, H) FOR(w, W) { que.push(mt(DP[s][h][w], h, w)); }

    while (!que.empty()) {
      ll cost, x, y;
      tie(cost, x, y) = que.top();
      que.pop();
      if (cost != DP[s][x][y]) continue;
      FOR(d, 4) {
        ll x1 = x + dx[d], y1 = y + dy[d];
        if (x1 < 0 || H <= x1 || y1 < 0 || W <= y1) continue;
        if (chmin(DP[s][x1][y1], cost + A[x1][y1])) {
          que.push(mt(DP[s][x1][y1], x1, y1));
        }
      }
    }
  }
  ll ans = INF;
  ll x = -1, y = -1;
  auto dp = DP.back();
  FOR(h, H) FOR(w, W) if (chmin(ans, dp[h][w])) x = h, y = w;
  // 

  vc<string> ANS(H);
  FOR(h, H) ANS[h].assign(W, '.');

  vvv(bool, vis, 1 << K, H, W, false);
  vc<tuple<ll, ll, ll>> st;
  vis[(1 << K) - 1][x][y] = true;
  st.eb(mt((1 << K) - 1, x, y));
  while (!st.empty()) {
    ll s, x, y;
    tie(s, x, y) = st.back();
    st.pop_back();

    ANS[x][y] = 'X';
    if (s == 0) continue;
    auto prev = [&]() -> vc<tuple<ll, ll, ll>> {
      FOR(k, K) {
        int t = s ^ 1 << k;
        if (t < s) {
          if (x == XY[k].fi && y == XY[k].se && DP[s][x][y] == DP[t][x][y]) return {mt(t, x, y)};
        }
      }
      vc<tuple<ll, ll, ll>> res;
      for (int t = s;; t = (t - 1) & s) {
        if (t < s && 0 < t && DP[s][x][y] == DP[t][x][y] + DP[s ^ t][x][y] - A[x][y]) {
          res.eb(mt(t, x, y));
          res.eb(mt(s ^ t, x, y));
          return res;
        }
        if (t == 0) break;
      }
      FOR(d, 4) {
        ll x1 = x + dx[d], y1 = y + dy[d];
        if (x1 < 0 || H <= x1 || y1 < 0 || W <= y1) continue;
        if (DP[s][x][y] == DP[s][x1][y1] + A[x][y]) {
          res.eb(mt(s, x1, y1));
          break;
        }
      }
      return res;
    }();
    FORIN(p, prev) {
      ll s, x, y;
      tie(s, x, y) = p;
      if (vis[s][x][y]) continue;
      vis[s][x][y] = true;
      st.eb(p);
    }
  }

  print(ans);
  FORIN(S, ANS) print(S);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}