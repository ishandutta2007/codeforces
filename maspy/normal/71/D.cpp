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
  long double __VA_ARGS__;                                                                                                                                        \
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
  LL(H, W);
  VV(string, G, H, W);
  vv(pi, A, H, W);
  string nums = "A23456789TJQK";
  string suits = "SDCH";
  vc<pi> JK(2, mp(-1, -1));
  ll JK_cnt = 0;

  set<pi> deck_s;
  FOR(n, 13) FOR(s, 4) deck_s.insert(mp(n, s));

  FOR(x, H) FOR(y, W) {
    char c;
    c = G[x][y][1];
    if (c == '1' || c == '2') {
      JK[c - '1'] = mp(x, y);
      ++JK_cnt;
      continue;
    }
    ll suit = suits.find(c);
    ll num = nums.find(G[x][y][0]);
    A[x][y] = mp(num, suit);
    deck_s.erase(mp(num, suit));
  }

  vc<pi> deck(all(deck_s));

  auto f = [&](string mes) -> bool {
    vv(bool, ok, H, W);
    FOR(h, H) FOR(w, W) {
      if (h + 3 > H || w + 3 > W) {
        ok[h][w] = false;
        continue;
      }
      ll a = 0, b = 0;
      FOR3(x, h, h + 3) FOR3(y, w, w + 3) {
        ll n, s;
        tie(n, s) = A[x][y];
        a |= 1 << n;
        b |= 1 << s;
      }
      ok[h][w] = (popcnt(a) == 9 || popcnt(b) == 1);
    }
    FOR(a, H) FOR(b, W) FOR(c, H) FOR(d, W) {
      if (!ok[a][b]) continue;
      if (!ok[c][d]) continue;
      // overlap
      if (abs(a - c) < 3 && abs(b - d) < 3) continue;

      ++a, ++b, ++c, ++d;
      string ab = "(" + to_string(a) + ", " + to_string(b) + ")";
      string cd = "(" + to_string(c) + ", " + to_string(d) + ")";
      print("Solution exists.");
      print(mes);
      print("Put the first square to", ab + ".");
      print("Put the second square to", cd + ".");
      return true;
    }

    return false;
  };

  if (JK_cnt == 0) {
    string mes = "There are no jokers.";
    if (f(mes)) return;
  }
  elif (JK_cnt == 1) {
    ll x, y;
    ll JK_id = -1;
    FOR(i, 2) if (JK[i].fi != -1) JK_id = i;
    tie(x, y) = JK[JK_id];
    FOR(i, deck.size()) {
      A[x][y] = deck[i];
      string jk = "J" + to_string(JK_id + 1);
      string card = {nums[deck[i].fi], suits[deck[i].se]};
      string mes = "Replace " + jk + " with " + card + ".";
      if (f(mes)) return;
    }
  }
  elif (JK_cnt == 2) {
    ll a, b, c, d;
    tie(a, b) = JK[0];
    tie(c, d) = JK[1];
    FOR(i, deck.size()) FOR(j, deck.size()) {
      if (i == j) continue;
      A[a][b] = deck[i];
      A[c][d] = deck[j];
      string c1 = {nums[deck[i].fi], suits[deck[i].se]};
      string c2 = {nums[deck[j].fi], suits[deck[j].se]};
      string mes = "Replace J1 with " + c1 + " and J2 with " + c2 + ".";
      if (f(mes)) return;
    }
  }
  print("No solution.");
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}