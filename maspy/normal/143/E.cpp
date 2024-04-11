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
  vvv(string, A, 10, 10, 10);
  A[7][9] = {
      "AAA.BC...", ".ABBBCCCD", "EA.FBCDDD", "EEEF.GGGD", "EHFFFIGJ.", ".H.IIIGJ.", "HHH..IJJJ",
  };
  A[8][8] = {
      "AAA.BCCC", ".ABBBDC.", "EA.FBDC.", "EEEFDDDG", "EHFFFGGG", ".HIII.JG", "HHHIJJJ.", "...I..J.",
  };
  A[8][9] = {
      "AAABBB..C", ".AD.BECCC", ".AD.BEEEC", "FDDDGEHHH", "FFFIGGGH.", "FJ.IGK.HL", ".JIIIKLLL", "JJJ.KKK.L",
  };
  A[9][7] = {
      "AAA.B..", ".ABBBC.", ".AD.BC.", "DDDECCC", "F.DEEEG", "FFFEGGG", "FHIIIJG", ".H.I.J.", "HHHIJJJ",
  };
  A[9][8] = {"AAA.BCCC", ".ABBBDC.", "EA.FBDC.", "EEEFDDDG", "EHFFFGGG",
             ".HHHIIIG", "JHKKKIL.", "JJJK.IL.", "J..K.LLL"};
  A[9][9] = {
      "AAA.BCCC.", ".ABBB.CD.", ".AE.BFCD.", "EEEFFFDDD", "G.E.HFIII",
      "GGGJHHHI.", "GK.JHL.IM", ".KJJJLMMM", "KKK.LLL.M",
  };

  LL(H, W);
  ll ans = 0;
  vc<string> ANS(H);
  FOR(h, H) ANS[h].assign(W, '.');

  vc<vi> put(4);
  put[0] = {1, 1, 1, 0, 1, 0, 0, 1, 0};
  put[1] = {0, 0, 1, 1, 1, 1, 0, 0, 1};
  put[2] = {0, 1, 0, 0, 1, 0, 1, 1, 1};
  put[3] = {1, 0, 0, 1, 1, 1, 1, 0, 0};

  auto f = [&](auto dfs, vc<string>& G, ll cnt, ll nxt) -> void {
    // T
    // 
    if (chmax(ans, cnt)) {
      FOR(h, H) FOR(w, W) ANS[h][w] = G[h][w];
    }
    if (cnt + (H * W - nxt) / 5 < ans) return;
    if (nxt >= H * W) return;
    ll x = nxt / W, y = nxt % W;
    FOR(d, 4) {
      if (x + 3 > H) continue;
      if (y + 3 > W) continue;
      bool can = [&]() {
        FOR(dx, 3) FOR(dy, 3) if (put[d][3 * dx + dy] && G[x + dx][y + dy] != '.') return false;
        return true;
      }();
      if (!can) continue;
      FOR(dx, 3) FOR(dy, 3) if (put[d][3 * dx + dy]) { G[x + dx][y + dy] = 'A' + cnt; }
      dfs(dfs, G, cnt + 1, nxt + 1);
      FOR(dx, 3) FOR(dy, 3) if (put[d][3 * dx + dy]) { G[x + dx][y + dy] = '.'; }
    }
    dfs(dfs, G, cnt, nxt + 1);
  };

  if (H + W >= 16) {
    ANS = A[H][W];
  } else {
    vc<string> G = ANS;
    f(f, G, 0, 0);
  }

  ans = 0;
  FOR(h, H) FOR(w, W) ans += ANS[h][w] != '.';
  ans /= 5;

  print(ans);
  FOR(h, H) print(ANS[h].substr(0, W));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}