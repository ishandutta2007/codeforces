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
  STR(S);
  auto [A, B, C] = [&]() {
    auto i = S.find('+');
    auto j = S.find('=');
    auto x = S.substr(0, i);
    auto y = S.substr(i + 1, j - i - 1);
    auto z = S.substr(j + 1);
    return mt(x, y, z);
  }();

  const ll INF = 1LL << 60;
  /*
  prefix length of A, B, C
  flag 4
    carry up or not
     or not
  */

  using T = tuple<ll, ll, ll>;

  vvvv(ll, DP, A.size() + 1, B.size() + 1, C.size() + 1, 16, INF);
  vvvv(T, SOL, A.size() + 1, B.size() + 1, C.size() + 1, 16);

  DP[0][0][0][0] = 0;

  FOR(flag, 16) {
    ll carry = flag & 1;
    FOR(a, 2) FOR(b, 2) FOR(c, 3) {
      if (a && (flag & 2)) continue;
      if (b && (flag & 4)) continue;
      if (c && (flag & 8)) continue;
      if (a + b + carry != c) continue;
      ll cost = 3 - popcnt(flag & 14);
      if (chmin(DP[0][0][0][flag], cost)) {
        SOL[0][0][0][flag] = mt(a, b, c);
      }
    }
  }

  FOR(na, A.size() + 1) FOR(nb, B.size() + 1) FOR(nc, C.size() + 1) {
    if (na + nb + nc == 0) continue;
    FOR(flag, 16) {
      ll carry = flag & 1;
      FOR(a, 10) FOR(b, 10) {
        ll c = (a + b + carry) % 10;
        if (a && (flag & 2)) continue;
        if (b && (flag & 4)) continue;
        if (c && (flag & 8)) continue;
        ll carry1 = (a + b + carry - c == 10);
        ll ma = (na > 0 && A[na - 1] == '0' + a ? na - 1 : na);
        ll mb = (nb > 0 && B[nb - 1] == '0' + b ? nb - 1 : nb);
        ll mc = (nc > 0 && C[nc - 1] == '0' + c ? nc - 1 : nc);
        if (na + nb + nc == ma + mb + mc) continue;
        ll cost = 3 - (na + nb + nc) + (ma + mb + mc);
        if (flag & 2) --cost;
        if (flag & 4) --cost;
        if (flag & 8) --cost;
        FOR(f, 16) {
          if ((f & 1) != carry1) continue;
          if (ma > 0 && (f & 2)) continue;
          if (mb > 0 && (f & 4)) continue;
          if (mc > 0 && (f & 8)) continue;
          if ((flag & 2) && !(f & 2)) continue;
          if ((flag & 4) && !(f & 4)) continue;
          if ((flag & 8) && !(f & 8)) continue;
          if (chmin(DP[na][nb][nc][flag], DP[ma][mb][mc][f] + cost)) {
            ll x, y, z;
            tie(x, y, z) = SOL[ma][mb][mc][f];
            x = 10 * x + a;
            y = 10 * y + b;
            z = 10 * z + c;
            SOL[na][nb][nc][flag] = mt(x, y, z);
          }
        }
      }
    }
  }

  ll x, y, z;
  tie(x, y, z) = SOL[A.size()][B.size()][C.size()][0];
  string ANS;
  ANS += to_string(x);
  ANS += "+";
  ANS += to_string(y);
  ANS += "=";
  ANS += to_string(z);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}