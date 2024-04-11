#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
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
#define len(x) ll(x.size())

#define elif else if

using ull = unsigned long long;
using uint = unsigned int;
int popcnt(uint x) {
  return __builtin_popcount(x);
}
int popcnt(int x) {
  return __builtin_popcount(x);
}
int popcnt(ull x) {
  return __builtin_popcountll(x);
}
int popcnt(ll x) {
  return __builtin_popcountll(x);
}
int bsr(uint x) {
  return 31 - __builtin_clz(x);
}
int bsr(ull x) {
  return 63 - __builtin_clzll(x);
}
int ctz(int x) {
  return __builtin_ctz(x);
}
int ctz(ll x) {
  return __builtin_ctzll(x);
}
int ctz(ull x) {
  return __builtin_ctzll(x);
}

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

ll ceil(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
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

ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
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

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}
#line 2 "main.cpp"

void solve() {
  VV(ll, pts, 8, 3);
  FOR(i, 8) sort(all(pts[i]));
  auto tmp = pts;
  sort(all(tmp));

  auto perm = [&](ll i, ll x) -> vi {
    if (x == 0) return {pts[i][0], pts[i][1], pts[i][2]};
    if (x == 1) return {pts[i][0], pts[i][2], pts[i][1]};
    if (x == 2) return {pts[i][1], pts[i][0], pts[i][2]};
    if (x == 3) return {pts[i][1], pts[i][2], pts[i][0]};
    if (x == 4) return {pts[i][2], pts[i][0], pts[i][1]};
    if (x == 5) return {pts[i][2], pts[i][1], pts[i][0]};
  };

  auto set_eq = [&](vi A, vi B) -> bool {
    sort(all(A));
    sort(all(B));
    return A == B;
  };

  FOR(a, 8) FOR(b, a) FOR(c, b) FOR(d, c) {
    FOR(pb, 6) FOR(pc, 6) FOR(pd, 6) {
      vv(ll, P, 8, 3);
      P[0] = pts[a];
      P[1] = perm(b, pb);
      P[2] = perm(c, pc);
      P[3] = perm(d, pd);
      FOR(k, 3) {
        P[4][k] = P[1][k] + P[2][k] - P[0][k];               // 12
        P[5][k] = P[1][k] + P[3][k] - P[0][k];               // 13
        P[6][k] = P[2][k] + P[3][k] - P[0][k];               // 23
        P[7][k] = P[1][k] + P[2][k] + P[3][k] - 2 * P[0][k]; // 123
      }
      bool ok = [&]() {
        // 
        auto dot = [&](ll a, ll b, ll c) -> ll {
          ll res = 0;
          FOR(d, 3) res += (P[b][d] - P[a][d]) * (P[c][d] - P[a][d]);
          return res;
        };
        if (dot(0, 1, 1) == 0) return false;
        if (dot(0, 1, 1) != dot(0, 2, 2)) return false;
        if (dot(0, 1, 1) != dot(0, 3, 3)) return false;
        if (dot(0, 1, 2) != 0) return false;
        if (dot(0, 1, 3) != 0) return false;
        if (dot(0, 2, 3) != 0) return false;
        // 
        auto Q = P;
        FOR(i, 8) sort(all(Q[i]));
        sort(all(Q));
        return Q == tmp;
      }();
      if (ok) {
        YES();
        // 
        vi ID(8);
        ll done = 0;
        FOR(i, 8) {
          FOR(j, 8) {
            if (done & 1 << j) continue;
            if (!set_eq(P[i], pts[j])) continue;
            ID[i] = j;
            done |= 1 << j;
            break;
          }
        }
        vv(ll, ANS, 8, 3);
        FOR(i, 8) ANS[ID[i]] = P[i];
        FOR(i, 8) print(ANS[i]);
        return;
      }
    }
  }
  NO();
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}