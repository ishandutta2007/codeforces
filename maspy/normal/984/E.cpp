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

void solve() {
  LL(N);
  VEC(pi, AB, N);

  /*
  4 99990 = empty
  */
  const int MAX = 10000;
  vi to_standard(MAX);
  vi KEY;
  FOR(key, MAX) {
    ll k = key;
    vi x(4);
    x[3] = k % 10;
    k /= 10;
    x[2] = k % 10;
    k /= 10;
    x[1] = k % 10;
    x[0] = k /= 10;
    sort(all(x));
    k = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
    to_standard[key] = k;
    if (key == k) KEY.eb(k);
  }
  const int K = KEY.size();

  vv(ll, POP, K, 10);
  vv(ll, PUSH, K, 10);
  FOR(i, K) {
    ll k = KEY[i];
    vi x(4);
    x[0] = k % 10;
    k /= 10;
    x[1] = k % 10;
    k /= 10;
    x[2] = k % 10;
    x[3] = k /= 10;
    FOR3(floor, 1, 10) {
      vi y = x;
      FOR(i, 4) if (y[i] == floor) y[i] = 0;
      ll to = y[3] * 1000 + y[2] * 100 + y[1] * 10 + y[0];
      to = to_standard[to];
      POP[i][floor] = LB(KEY, to);
    }
    FOR3(floor, 1, 10) {
      vi y = x;
      FOR(i, 4) if (y[i] == 0) {
        y[i] = floor;
        break;
      }
      ll to = y[3] * 1000 + y[2] * 100 + y[1] * 10 + y[0];
      to = to_standard[to];
      PUSH[i][floor] = LB(KEY, to);
    }
  }

  const ll INF = 1LL << 60;
  ll ANS = INF;
  // 
  vvv(ll, DIST, N + 1, K, 10, INF);
  using T = tuple<ll, ll, ll>;
  deque<T> que;

  DIST[0][0][1] = 0;
  que.push_back(mt(0, 0, 1));

  while (!que.empty()) {
    ll nxt, state, floor;
    tie(nxt, state, floor) = que.front();
    que.pop_front();
    ll cost = DIST[nxt][state][floor];
    if (nxt == N && state == 0) {
      chmin(ANS, cost);
      continue;
    }

    vector<pair<T, ll>> TO;

    // 
    if (floor < 9) TO.eb(mp(mt(nxt, state, floor + 1), cost + 1));
    if (floor > 1) TO.eb(mp(mt(nxt, state, floor - 1), cost + 1));
    // 
    TO.eb(mp(mt(nxt, POP[state][floor], floor), cost));
    // 
    if (nxt < N && floor == AB[nxt].fi) {
      ll new_state = PUSH[state][AB[nxt].se];
      if (new_state > state) {
        TO.eb(mp(mt(nxt + 1, new_state, floor), cost));
      }
    }

    FORIN(p, TO) {
      ll a, b, c;
      tie(a, b, c) = p.fi;
      if (!chmin(DIST[a][b][c], p.se)) continue;
      if (p.se == cost) {
        que.push_front(p.fi);
      } else {
        que.push_back(p.fi);
      }
    }
  }
  print(ANS + 2 * N);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}