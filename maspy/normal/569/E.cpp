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

ll mod(ll x, ll y) {
  return x - y * floor(x, y);
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

#line 2 "/home/maspy/library/densegraph/base.hpp"

template <typename T> struct Graph {
  // only simple graph.
  int N, M;
  vector<vector<T>> G;
  T none_val;
  bool directed;
  Graph() {}
  Graph(int N, bool bl = false, T none_val = -1)
      : N(N), M(0), G(N, vector<int>(N, none_val)), none_val(none_val),
        directed(bl) {}

  void add(int frm, int to, T cost = 1, bool check_mult = true) {
    if(check_mult) assert(G[frm][to] == none_val);
    G[frm][to] = cost;
    if (!directed) {
      G[to][frm] = cost;
    }
    ++M;
  }

  void debug(bool detail = false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if (detail)
          cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id
               << ")";
        else
          cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  int size() { return N; }
  vector<T> &operator[](int v) { return G[v]; }
};
#line 3 "/home/maspy/library/densegraph/scc.hpp"

template <class T> struct SCC {
  T &G;
  ll N;
  ll n_comp;
  vc<int> comp_id;
  vc<int> low;
  vc<int> ord;
  vc<int> visited;
  ll now = 0;

  SCC(T &G)
      : G(G), N(G.N), n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {
    assert(G.directed);
    build();
  }

  ll operator[](ll v) { return comp_id[v]; }

  void dfs(int v) {
    low[v] = now;
    ord[v] = now;
    ++now;
    visited.eb(v);
    FOR(to, N) if(G[v][to]!=G.none_val){
      if (ord[to] == -1) {
        dfs(to);
        chmin(low[v], low[to]);
      } else {
        chmin(low[v], ord[to]);
      }
    }
    if (low[v] == ord[v]) {
      while (1) {
        ll u = visited.back();
        visited.pop_back();
        ord[u] = N;
        comp_id[u] = n_comp;
        if (u == v)
          break;
      }
      ++n_comp;
    }
  }

  void build() {
    FOR(v, N) {
      if (ord[v] == -1)
        dfs(v);
    }
    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];
  }

  vc<vc<int>> comp() {
    if (n_comp == 0)
      build();
    vc<vc<int>> res;
    res.resize(n_comp);
    FOR(v, N) { res[comp_id[v]].eb(v); }
    return res;
  };
};
#line 1 "/home/maspy/library/densegraph/twosat.hpp"
struct TwoSat {
  vc<int> values;

  Graph<int> G;
  TwoSat(ll n) {
    G = Graph<int>(2 * n, 1);
    values.assign(n, -1);
  }
  void add(int a, int b) {
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));
    G.add(a ^ 1, b, 1, false);
    G.add(b ^ 1, a, 1, false);
  }
  void set(int a) {
    if (a >= 0)
      values[a] = 1;
    else
      values[~a] = 0;
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    G.add(a ^ 1, a, 1, false);
  }
  void implies(int a, int b) { add(~a, b); }

  bool calc() {
    ll n = len(values);
    SCC<Graph<int>> scc(G);
    FOR(i, n) {
      if (scc[2 * i] == scc[2 * i + 1]) return false;
      values[i] = scc[2 * i] < scc[2 * i + 1];
    }
    return true;
  }
};
#line 6 "main.cpp"

void solve() {
  STR(SVC);
  ll sigma = len(SVC);
  vi VC;
  FOR(i, sigma) VC.eb(SVC[i] == 'V');

  // true: v, false: c
  LL(N, Q);
  using T = pi;
  vc<T> query(Q);
  FOR(q, Q) {
    LL(i);
    STR(a);
    LL(j);
    STR(b);
    --i, --j;
    if (a == "C") i = ~i;
    if (b == "C") j = ~j;
    query[q] = mp(i, j);
  }
  STR(S);

  /*
   V or  C
  */
  if (SUM(VC) == sigma) {
    FOR(q, Q) {
      auto [a, b] = query[q];
      if (a >= 0 && b < 0) return print(-1);
    }
    return print(S);
  }
  if (SUM(VC) == 0) {
    FOR(q, Q) {
      auto [a, b] = query[q];
      if (a < 0 && b >= 0) return print(-1);
    }
    return print(S);
  }

  auto A = s_to_vi(S, 'a');

  auto check = [&](vi& A) -> bool {
    vi C(N, -1);
    FOR(i, N) if (A[i] != -1) C[i] = VC[A[i]];
    TwoSat ts(N);
    FOR(i, N) {
      if (C[i] == -1) continue;
      if (C[i] == 1) ts.set(i);
      if (C[i] == 0) ts.set(~i);
    }
    FOR(q, Q) {
      auto [a, b] = query[q];
      /*
      if (a >= 0 && C[a] == 0) continue;
      if (a < 0 && C[~a] == 1) continue;
      if (a >= 0 && C[a] == 1 && b >= 0 && C[b] == 0) return false;
      if (a < 0 && C[~a] == 0 && b >= 0 && C[b] == 0) return false;
      if (a >= 0 && C[a] == 1 && b < 0 && C[~b] == 1) return false;
      if (a < 0 && C[~a] == 0 && b < 0 && C[~b] == 1) return false;
      */
      ts.implies(a, b);
    }
    bool ok = ts.calc();
    return ok;
  };

  ll p = N - 1;
  while (p >= 0) {
    // p 
    bool done_v = false, done_c = false;
    bool success = false;
    if (A[p] == -1) A[p] = 0;
    while (A[p] < sigma) {
      if (VC[A[p]] && done_v) {
        ++A[p];
        continue;
      }
      if (!VC[A[p]] && done_c) {
        ++A[p];
        continue;
      }
      if (VC[A[p]]) done_v = true;
      if (!VC[A[p]]) done_c = true;
      if (check(A)) {
        success = true;
        break;
      }
    }
    if (success)
      ++p;
    else {
      A[p] = -1;
      --p;
      if (p >= 0) ++A[p];
    }
    if (p == N) {
      string ANS;
      FOR(i, N) ANS += 'a' + A[i];
      return print(ANS);
    }
  }
  print(-1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // LL(T);
  ll T = 1;
  FOR(_, T) solve();

  return 0;
}