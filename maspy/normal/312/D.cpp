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
int bsf(uint x) {
  return __builtin_ctz(x);
}
int bsf(ull x) {
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

#line 6 "main.cpp"

template <class T>
class LARSCH {
  struct reduce_row;
  struct reduce_col;

  struct reduce_row {
    int n;
    std::function<T(int, int)> f;
    int cur_row;
    int state;
    std::unique_ptr<reduce_col> rec;

    reduce_row(int n_) : n(n_), f(), cur_row(0), state(0), rec() {
      const int m = n / 2;
      if (m != 0) { rec = std::make_unique<reduce_col>(m); }
    }

    void set_f(std::function<T(int, int)> f_) {
      f = f_;
      if (rec) {
        rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j); });
      }
    }

    int get_argmin() {
      const int cur_row_ = cur_row;
      cur_row += 1;
      if (cur_row_ % 2 == 0) {
        const int prev_argmin = state;
        const int next_argmin = [&]() {
          if (cur_row_ + 1 == n) {
            return n - 1;
          } else {
            return rec->get_argmin();
          }
        }();
        state = next_argmin;
        int ret = prev_argmin;
        for (int j = prev_argmin + 1; j <= next_argmin; j += 1) {
          if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }
        }
        return ret;
      } else {
        if (f(cur_row_, state) <= f(cur_row_, cur_row_)) {
          return state;
        } else {
          return cur_row_;
        }
      }
    }
  };

  struct reduce_col {
    int n;
    std::function<T(int, int)> f;
    int cur_row;
    std::vector<int> cols;
    reduce_row rec;

    reduce_col(int n_) : n(n_), f(), cur_row(0), cols(), rec(n) {}

    void set_f(std::function<T(int, int)> f_) {
      f = f_;
      rec.set_f([&](int i, int j) -> T { return f(i, cols[j]); });
    }

    int get_argmin() {
      const int cur_row_ = cur_row;
      cur_row += 1;
      const auto cs = [&]() -> std::vector<int> {
        if (cur_row_ == 0) {
          return {{0}};
        } else {
          return {{2 * cur_row_ - 1, 2 * cur_row_}};
        }
      }();
      for (const int j : cs) {
        while ([&]() {
          const int size = cols.size();
          return size != cur_row_ && f(size - 1, cols.back()) > f(size - 1, j);
        }()) {
          cols.pop_back();
        }
        if (cols.size() != n) { cols.push_back(j); }
      }
      return cols[rec.get_argmin()];
    }
  };

  std::unique_ptr<reduce_row> base;

public:
  LARSCH(int n, std::function<T(int, int)> f)
      : base(std::make_unique<reduce_row>(n)) {
    base->set_f(f);
  }

  int get_argmin() { return base->get_argmin(); }
};

template <typename F>
ll d_edge_shortest_path_monge(ll N, ll d, F f, ll f_lim) {
  /*
  https://dic.kimiyuki.net/d-edge-shortest-path-monge
   calc_L(lambda) 
  |f|  f_lim 
  */
  const ll INF = 1LL << 60;
  auto calc_L = [&](ll lambda) -> ll {
    auto cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda; };
    vector<ll> DP(N, INF);
    DP[0] = 0;
    LARSCH<ll> larsch(N - 1, [&](int i, int j) {
      // dp[j]  dp[i+1] 
      if (i + 1 <= j) return INF;
      return DP[j] + cost(j, i + 1);
    });
    FOR3(v, 1, N) {
      ll frm = larsch.get_argmin();
      DP[v] = DP[frm] + cost(frm, v);
    }
    ll ANS = DP.back() - lambda * d;
    return ANS;
  };

  ll ANS = -INF;
  ll L = -3 * f_lim - 10;
  ll R = 3 * f_lim + 10;
  ll x = binary_search([&](ll x) { return calc_L(x - 1) <= calc_L(x); }, L, R);
  return calc_L(x);
}

void solve() {
  LL(N, M, K);
  if (K >= M) return print(0);

  VEC(ll, X, N - 1);
  X = cumsum(X);
  vi A;
  FOR(_, M) {
    LL(i, t);
    --i;
    A.eb(t - X[i]);
  }

  N = A.size();
  sort(all(A));
  auto S = cumsum(A);

  const ll INF = 1LL << 60;
  auto f = [&](int L, int R) -> ll {
    if (L == R) return 0;
    if (L > R) return INF;
    return (R - L) * A[R - 1] - (S[R] - S[L]);
  };

  ll ANS = d_edge_shortest_path_monge(N + 1, K, f, f(0, N));
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}