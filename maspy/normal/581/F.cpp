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

#line 3 "/home/maspy/library/graph/base.hpp"

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  int N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(){}
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    if(i == -1) i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void debug(bool detail=false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  vector<int> degrees(){
    vector<int> deg(N);
    FORIN(e, edges) {
      deg[e.frm]++;
      deg[e.to]++;
    }
    return deg;
  }

  int size(){return N;}

  vector<edge_t>& operator[](int v) { return G[v]; }
};
#line 1 "/home/maspy/library/graph/eulertour.hpp"
template <class T>
struct EulerTour {
  T& G;
  int root;
  bool calc_anc;
  vector<int> V, VR, parent, LID, RID, depth;
  vector<vector<int>> ancestors;

  EulerTour(){}
  EulerTour(T& G, int root = 0, bool calc_anc=true) : G(G), root(root), calc_anc(calc_anc) { build(); };

  void dfs(int v, int p) {
    LID[v] = V.size();
    V.eb(v);
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    FORIN(e, G[v]) {
      int w = e.to;
      if (w == p) continue;
      dfs(w, v);
    }
    RID[v] = V.size();
  }

  void build() {
    int N = G.N;
    V.reserve(N);
    parent.resize(N);
    LID.resize(N);
    RID.resize(N);
    depth.resize(N);
    parent[root] = -1;
    depth[root] = 0;
    dfs(root, -1);
    VR = V;
    reverse(all(VR));

    if(calc_anc){
      FOR(k, 20) ancestors.eb(vector<int>(N));
      ancestors[0] = parent;
      FOR3(k, 1, 20){
        FOR(v, G.N){
          int w = ancestors[k-1][v];
          ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);
        }
      }
    }
  }

  int LCA(int a, int b){
    assert(calc_anc);
    if(depth[a] > depth[b]) swap(a, b);
    auto n = depth[b] - depth[a];
    FOR(k, 20){
      if(n & 1<<k) b = ancestors[k][b];
    }
    if(a==b) return a;
    FOR_R(k, 20){
      if(ancestors[k][a] != ancestors[k][b]){
        a = ancestors[k][a];
        b = ancestors[k][b];
      }
    }
    return parent[a];
  }

  int LA(int v, int n){
    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if (v==-1) return -1;}
    return v;
  }  

  int dist(int a, int b){
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  bool in_subtree(int a, int b){
    return LID[b] <= LID[a] && LID[a] < RID[b];
  }

  int move(int a, int b){
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }
};

template <class T>
struct EulerTour_e {
  T& G;
  int root;
  bool calc_anc;
  vector<int> tour, parent, LID, RID, depth;
  vector<vector<int>> ancestors;

  EulerTour_e(T& G, int root = 0, bool calc_anc=true) : G(G), root(root), calc_anc(calc_anc) { build(); };

  void dfs(int v, int p) {
    LID[v] = tour.size();
    tour.eb(v);
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    FORIN(e, G[v]) {
      int w = e.to;
      if (w == p) continue;
      dfs(w, v);
    }
    RID[v] = tour.size();
    tour.eb(~v);
  }

  void build() {
    int N = G.N;
    tour.reserve(N * 2);
    parent.resize(N);
    LID.resize(N);
    RID.resize(N);
    depth.resize(N);
    parent[root] = -1;
    depth[root] = 0;
    dfs(root, -1);
    if(calc_anc){
      FOR(k, 20) ancestors.eb(vector<int>(N));
      ancestors[0] = parent;
      FOR3(k, 1, 20){
        FOR(v, G.N){
          int w = ancestors[k-1][v];
          ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);
        }
      }
    }
  }

  int LCA(int a, int b){
    assert(calc_anc);
    if(depth[a] > depth[b]) swap(a, b);
    auto n = depth[b] - depth[a];
    FOR(k, 20){
      if(n & 1<<k) b = ancestors[k][b];
    }
    if(a==b) return a;
    FOR_R(k, 20){
      if(ancestors[k][a] != ancestors[k][b]){
        a = ancestors[k][a];
        b = ancestors[k][b];
      }
    }
    return parent[a];
  }

  int LA(int v, int n){
    FOR(k, 20) if(n & 1<<k) {v = ancestors[k][v]; if (v==-1) return -1;}
    return v;
  }  

  int dist(int a, int b){
    int c = LCA(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
  }

  bool in_subtree(int a, int b){
    return LID[b] <= LID[a] && LID[a] < RID[b];
  }

  int move(int a, int b){
    assert(a != b);
    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);
  }
};
#line 5 "main.cpp"

template <typename E, typename F1, typename F2, typename F3, typename T>
pair<vc<T>, vc<T>> tree_dp(E& ET, F1 f_ee, F2 f_ev, F3 f_ve, T unit) {
  /*
  f_ee(T t1, T t2)edge subtree data 
  f2edge subtree data -> node subtree data
  */
  auto& V = ET.V;
  auto& G = ET.G;
  auto& par = ET.parent;
  ll N = len(V);
  vc<T> dp_v(N), dp_e(N);
  FOR_R(i, N) {
    auto v = V[i];
    T dp = unit;
    FORIN(e, G[v]) if (e.to != par[v]) {
      dp_e[e.to] = f_ve(dp_v[e.to], e.id);
      dp = f_ee(dp, dp_e[e.to]);
    }
    dp_v[v] = f_ev(dp, v);
  }
  return {dp_v, dp_e};
}

void solve() {
  LL(N);
  const ll INF = 1LL << 60;
  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(--a, --b);
  }
  if (N == 2) return print(1);
  auto deg = G.degrees();
  ll root = -1;
  FOR(v, N) if (deg[v] > 1) root = v;

  EulerTour<Graph<int>> ET(G, root);
  using T = vi;
  T unit = {0};
  auto f_ee = [&](T x, T y) -> T {
    vi z(len(x) + len(y) - 1, INF);
    FOR(i, len(x)) FOR(j, len(y)) chmin(z[i + j], x[i] + y[j]);
    return z;
  };
  auto f_ev = [&](T x, ll v) -> T {
    if (len(x) == 1) return {INF, 0};
    return x;
  };
  auto f_ve = [&](T x, ll eid) -> T {
    T y(len(x));
    FOR(i, len(x)) { y[i] = min(x[i], x[len(x) - 1 - i] + 1); }
    return y;
  };
  auto [dp_v, dp_e] = tree_dp(ET, f_ee, f_ev, f_ve, unit);
  // FORIN(v, ET.V) { print(v, ",", dp_v[v]); }
  auto dp = dp_v[root];
  print(dp[len(dp) / 2]);
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