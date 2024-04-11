#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

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
#line 2 "main.cpp"

#line 3 "/home/maspy/library/ds/fenwick.hpp"

template< typename T >
struct FenwickTree {
  vector< T > data;

  FenwickTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }

  ll find_kth_element(T k){
    auto N = data.size();
    ll x = 0;
    T sx = 0;
    ll dx = 1;
    while (2 * dx < N) dx *= 2;
    while(dx){
      ll y = x + dx;
      if(y<N){
        T sy = sx + data[y];
        if(sy < k){
          swap(x, y);
          swap(sx, sy);
        }
      }
      dx /= 2;
    }
    return x;
  }
};
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

  void add_edge(int frm, int to, T cost = 1, int i = -1) {
    if(i == -1)i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void add(int frm, int to, T cost = 1, int i = -1) {
    if(i == -1)i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void print(bool detail=false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e : G[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
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
  vector<vector<int>> ch;

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
  vector<int> tour, parent, LID, RID, depth;

  EulerTour_e(T& G, int root = 0) : G(G), root(root) { build(); };

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
  }
};
#line 6 "main.cpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  FORIN(x, A) x = abs(x);

  Graph<int> G(N);
  FOR(_, N - 1) {
    LL(a, b);
    G.add(--a, --b);
  }
  EulerTour<Graph<int>> ET0(G);
  EulerTour_e<Graph<int>> ET(G);
  auto& LID = ET.LID;
  auto& RID = ET.RID;
  auto& dep = ET0.depth;

  FenwickTree<ll> bit(N + N + 10);
  FOR(v, N) {
    bit.add(LID[v], A[v]);
    bit.add(RID[v], -A[v]);
  }

  FOR(_, Q) {
    LL(t, a, b);
    if (t == 1) {
      ll v = a - 1;
      bit.add(LID[v], -A[v]);
      bit.add(RID[v], +A[v]);
      A[v] = abs(b);
      bit.add(LID[v], +A[v]);
      bit.add(RID[v], -A[v]);
    } else {
      --a, --b;
      ll ANS = [&]() -> ll {
        if (dep[a] > dep[b]) swap(a, b);
        if (a == b) return 0;
        ll lca = ET0.LCA(a, b);
        if (lca == a) {
          ll x = bit.sum(LID[b]) - bit.sum(LID[a] + 1);
          x *= 2;
          x += A[b];
          x += A[a];
          return x;
        }
        ll x = bit.sum(LID[a]) - bit.sum(LID[lca] + 1);
        x += bit.sum(LID[b]) - bit.sum(LID[lca] + 1);
        x += A[lca];
        x *= 2;
        x += A[a];
        x += A[b];
        return x;
      }();
      print(ANS);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}