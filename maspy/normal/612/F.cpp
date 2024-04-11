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
  INT(N, S);
  --S;
  auto dist = [&](int i, int j) -> int {
    if (i > j) swap(i, j);
    return min(j - i, i - j + N);
  };

  VEC(ll, A, N);
  // 
  vi X = A;
  UNIQUE(X);
  FORIN(x, A) x = LB(X, x);
  int K = X.size();
  vvc<ll> ID(K);
  FOR(i, N) ID[A[i]].eb(i);
  vi LEFT(N);
  vi RIGHT(N);
  FOR(x, K) {
    int n = ID[x].size();
    FOR(i, n) {
      int j = (i + 1 < n ? i + 1 : 0);
      int a = ID[x][i], b = ID[x][j];
      RIGHT[a] = b;
      LEFT[b] = a;
    }
  }
  /*
  DPS[i]A[i] 
  DPT[i]A[i] 
  */
  const ll INF = 1LL << 60;
  vi DPS(N, INF);
  vi DPT(N, INF);
  vi PARS(N, -1);
  vi PART(N, -1);
  vi PAR_dir(N);

  FORIN(i, ID[0]) { DPS[i] = dist(S, i); }

  FOR(x, K) {
    FORIN(frm, ID[x]) {
      int to = LEFT[frm];
      int x = (frm <= to ? to - frm : to - frm + N);
      if (chmin(DPT[to], DPS[frm] + x)) {
        PART[to] = frm;
        PAR_dir[to] = 0;
      }
      to = RIGHT[frm];
      x = (to <= frm ? frm - to : frm - to + N);
      if (chmin(DPT[to], DPS[frm] + x)) {
        PART[to] = frm;
        PAR_dir[to] = 1;
      }
    }
    if (x == K - 1) break;
    FORIN(frm, ID[x]) {
      FORIN(to, ID[x + 1]) {
        if (chmin(DPS[to], DPT[frm] + dist(frm, to))) {
          PARS[to] = frm;
        }
      }
    }
  }
  ll ANS = INF;
  int v = -1;
  FORIN(i, ID[K - 1]) if (chmin(ANS, DPT[i])) v = i;
  print(ANS);
  vi HISTORY = {v};
  while (v >= 0) {
    int frm = PART[v];
    int d = PAR_dir[v];
    while (v != frm) {
      v = (d == 0 ? LEFT[v] : RIGHT[v]);
      HISTORY.eb(v);
    }
    v = PARS[v];
    HISTORY.eb(v);
  }
  HISTORY.back() = S;
  reverse(all(HISTORY));
  FOR(i, N) {
    int frm = HISTORY[i], to = HISTORY[i + 1];
    if (frm == to) {
      print("+0");
      continue;
    }
    int r = (frm <= to ? to - frm : to - frm + N);
    int l = (frm >= to ? frm - to : frm - to + N);
    if (l <= r)
      print("-" + to_string(l));
    else
      print("+" + to_string(r));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}