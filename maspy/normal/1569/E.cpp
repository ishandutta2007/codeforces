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

const int MOD = 998244353;

void solve() {
  LL(K, base, H);
  // 
  auto gen_rank = [&](auto dfs, ll K) -> vc<vi> {
    vc<vi> ANS;
    if (K == 0) {
      ANS.eb(vi({0}));
      return ANS;
    }
    auto X = dfs(dfs, K - 1);
    FORIN(left, X) FORIN(right, X) {
      vi B = left;
      B.insert(B.end(), all(right));
      FORIN(x, B)++ x;
      FOR(i, B.size()) if (B[i] == 1) {
        B[i] = 0;
        ANS.eb(B);
        B[i] = 1;
      }
    }
    return ANS;
  };

  vi POW(1000);
  POW[0] = 1;
  FOR(i, 999) POW[i + 1] = POW[i] * base % MOD;

  auto ranks = gen_rank(gen_rank, K - 1);
  FORIN(A, ranks) FORIN(x, A) x = (1 << x) + 1;

  //  1  ->  hash val, ranks 
  vc<vi> HASH((1 << K) + 1);
  vc<vi> I((1 << K) + 1);

  FOR(i, ranks.size()) {
    auto& A = ranks[i];
    ll who = min_element(all(ranks[i])) - ranks[i].begin();
    ll lh = 0, rh = 0;
    FOR(j, A.size()) {
      lh += (j + 1) * POW[A[j]];
      rh += (A.size() + j + 1) * POW[A[j]];
    }
    lh %= MOD, rh %= MOD;
    HASH[who + 1].eb(lh);
    HASH[A.size() + who + 1].eb(rh);
  }

  ll n = 1 << (K - 1);
  FOR(i, n + n + 1) sort(all(HASH[i]));

  auto get_answer = [&](ll lhx, ll rhx, ll lwin, ll rwin, bool bl) -> void {
    vi ANS(n + n);
    FOR(i, ranks.size()) {
      auto& A = ranks[i];
      ll who = min_element(all(ranks[i])) - ranks[i].begin();
      ll lh = 0, rh = 0;
      FOR(j, A.size()) {
        lh += (j + 1) * POW[A[j]];
        rh += (A.size() + j + 1) * POW[A[j]];
      }
      lh %= MOD, rh %= MOD;
      if (lh == lhx && who + 1 == lwin) {
        FOR(i, n) ANS[i] = A[i];
      }
      if (rh == rhx && A.size() + who + 1 == rwin) {
        FOR(i, n) ANS[n + i] = A[i];
      }
    }
    FOR(i, n + n) if (ANS[i] == 2 && bl && i < n) ANS[i] = 1;
    FOR(i, n + n) if (ANS[i] == 2 && !bl && i >= n) ANS[i] = 1;
    print(ANS);
  };

  FOR3(lwin, 1, n + 1) FOR3(rwin, n + 1, n + n + 1) {
    FOR(i, HASH[lwin].size()) {
      ll lh = HASH[lwin][i];
      // 
      ll add = (POW[1] - POW[2] + MOD) * lwin % MOD;
      ll rh = (H - add - lh) % MOD;
      if (rh < 0) rh += MOD;
      if (UB(HASH[rwin], rh) - LB(HASH[rwin], rh) >= 1) {
        get_answer(lh, rh, lwin, rwin, true);
        return;
      }
      // 
      add = (POW[1] - POW[2] + MOD) * rwin % MOD;
      rh = (H - add - lh) % MOD;
      if (rh < 0) rh += MOD;
      if (UB(HASH[rwin], rh) - LB(HASH[rwin], rh) >= 1) {
        get_answer(lh, rh, lwin, rwin, false);
        return;
      }
    }
  }
  print(-1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}