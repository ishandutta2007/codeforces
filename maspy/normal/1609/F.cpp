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
  LL(N);
  VEC(ll, A0, N);
  vi P(N);
  FOR(i, N) P[i] = popcnt(A0[i]);

  ll ANS = 0;
  const ll INF = 1LL << 60;

  auto calc = [&](ll L, ll M, ll R) -> void {
    vi A(M - L), B(R - M);
    vi PA(M - L), PB(R - M);
    FOR(i, M - L) {
      A[i] = A0[M - 1 - i];
      PA[i] = P[M - 1 - i];
    }
    FOR(i, R - M) {
      B[i] = A0[M + i];
      PB[i] = P[M + i];
    }
    // A  0 
    // B  1 
    vi AH(len(A) + 1), AL(len(A) + 1);
    vi BH(len(B) + 1), BL(len(B) + 1);
    vi AHP(len(A) + 1), ALP(len(A) + 1);
    vi BHP(len(B) + 1), BLP(len(B) + 1);
    AH[0] = -INF, AL[0] = INF, AHP[0] = 0, ALP[0] = 0;
    FOR(i, len(A)) {
      AH[i + 1] = max(AH[i], A[i]);
      AL[i + 1] = min(AL[i], A[i]);
      AHP[i + 1] = AHP[i], ALP[i + 1] = ALP[i];
      if (AH[i + 1] == A[i]) AHP[i + 1] = PA[i];
      if (AL[i + 1] == A[i]) ALP[i + 1] = PA[i];
    }
    BH[0] = -INF, BL[0] = INF, BHP[0] = 0, BLP[0] = 0;
    FOR(i, len(B)) {
      BH[i + 1] = max(BH[i], B[i]);
      BL[i + 1] = min(BL[i], B[i]);
      BHP[i + 1] = BHP[i], BLP[i + 1] = BLP[i];
      if (BH[i + 1] == B[i]) BHP[i + 1] = PB[i];
      if (BL[i + 1] == B[i]) BLP[i + 1] = PB[i];
    }

    // 
    FORIN(x, AL) x = 2 * x;
    FORIN(x, AH) x = 2 * x;
    FORIN(x, BL) x = 2 * x | 1;
    FORIN(x, BH) x = 2 * x | 1;

    //  min, max 
    {
      ll r = 0;
      FOR3(i, 1, len(A) + 1) {
        while (r < len(B) && BH[r + 1] < AH[i] && BL[r + 1] > AL[i]) ++r;
        if (ALP[i] == AHP[i]) ANS += r;
      }
    }
    //  min, max 
    {
      ll l = 0;
      FOR3(i, 1, len(B) + 1) {
        while (l < len(A) && AH[l + 1] < BH[i] && AL[l + 1] > BL[i]) ++l;
        if (BLP[i] == BHP[i]) ANS += l + 1;
      }
    }
    /*
    vc<vi> BHpos(61);
    vc<vi> BLpos(61);
    FOR(i, len(BHP)) BHpos[BHP[i]].eb(i);
    FOR(i, len(BLP)) BLpos[BLP[i]].eb(i);
    */
    {
      vi BL_CNT_1(61), BL_CNT_2(61);
      vi BH_CNT_1(61), BH_CNT_2(61);
      //  min,  max
      //  min  R1
      //  max  R2
      // R1, R2inclusive
      ll R1 = 0, R2 = 0;
      FOR3(i, 1, len(A) + 1) {
        while (R1 < len(B) && BL[R1 + 1] > AL[i]) {
          ++R1;
          BL_CNT_1[BLP[R1]]++;
          BH_CNT_1[BHP[R1]]++;
        }
        while (R2 < len(B) && BH[R2 + 1] < AH[i]) {
          ++R2;
          BL_CNT_2[BLP[R2]]++;
          BH_CNT_2[BHP[R2]]++;
        }
        if (R2 < R1) {
          ll k = ALP[i];
          ANS += BH_CNT_1[k] - BH_CNT_2[k];
          // ANS += LB(BHpos[k], R1 + 1) - LB(BHpos[k], R2 + 1);
        }
        if (R1 < R2) {
          ll k = AHP[i];
          ANS += BL_CNT_2[k] - BL_CNT_1[k];
          // ANS += LB(BLpos[k], R2 + 1) - LB(BLpos[k], R1 + 1);
        }
      }
    }
    return;
  };

  vc<pi> que = {{0, N}};
  while (!que.empty()) {
    auto [L, R] = que.back();
    que.pop_back();
    ll M = (L + R) / 2;
    calc(L, M, R);
    if (L < M) que.eb(L, M);
    if (M + 1 < R) que.eb(M + 1, R);
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