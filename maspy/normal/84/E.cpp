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
#line 3 "main.cpp"

void solve() {
  LL(H, W, K);
  VEC(string, G, H);
  ll sx, sy;
  ll tx, ty;
  FOR(h, H) FOR(w, W) {
    if (G[h][w] == 'S') sx = h, sy = w;
    if (G[h][w] == 'T') tx = h, ty = w;
  }

  auto isin = [&](ll x, ll y) -> bool { return (0 <= x && x < H && 0 <= y && y < W); };
  ll dx[] = {1, 0, -1, 0};
  ll dy[] = {0, 1, 0, -1};
  const ll INF = 1LL << 30;

  vv(int, dist, H, W);
  vv(bool, done, H, W);

  auto calc = [&](int s) -> pair<bool, string> {
    //  s 
    // 
    FOR(x, H) FOR(y, W) dist[x][y] = INF;
    FOR(x, H) FOR(y, W) done[x][y] = false;

    queue<pair<int, int>> que;
    dist[tx][ty] = 0;
    que.push(mp(tx, ty));
    auto can_go = [&](int x, int y) -> bool {
      if (!isin(x, y)) return false;
      char c = G[x][y];
      if (c == 'S' || c == 'T') return true;
      return s & 1 << (c - 'a');
    };

    while (!que.empty()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();
      FOR(d, 4) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!can_go(nx, ny)) continue;
        if (chmin(dist[nx][ny], dist[x][y] + 1)) que.push(mp(nx, ny));
      }
    }

    if (dist[sx][sy] == INF) return mp(false, "");

    // 
    string ANS = "";
    que.push(mp(sx, sy));
    done[sx][sy] = true;
    FOR(D, dist[sx][sy]) {
      char nxt_char = 'z' + 1;
      queue<pair<int, int>> nxt_que;
      while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        if (G[x][y] == 'T') break;
        if (D > 0 && ANS[D - 1] != G[x][y]) continue;
        FOR(d, 4) {
          int nx = x + dx[d], ny = y + dy[d];
          if (!can_go(nx, ny)) continue;
          if (!done[nx][ny] && dist[nx][ny] == dist[x][y] - 1) {
            done[nx][ny] = true;
            nxt_que.push(mp(nx, ny));
            chmin(nxt_char, G[nx][ny]);
          }
        }
      }
      if (D < dist[sx][sy] - 1) ANS += nxt_char;
      swap(que, nxt_que);
    }
    return mp(true, ANS);
  };

  bool solved = false;
  string ANS = "";

  FOR_nCk(s, 26, K) {
    auto [bl, S] = calc(s);
    if (!bl) continue;
    if (!solved) {
      solved = true;
      ANS = S;
    } else {
      if (ANS.size() > S.size() || (ANS.size() == S.size() && ANS > S)) ANS = S;
    }
  }
  if (!solved) ANS = "-1";

  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}