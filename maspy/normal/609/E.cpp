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
    return (x > 0 ? x / y : (x + y - 1) / y);
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
#line 3 "/home/maspy/library/ds/unionfind.hpp"

struct UnionFind {
  int num;
  int comp;
  vi v_sz, e_sz, par;
  UnionFind(int n) : num(n), comp(n), v_sz(n, 1), e_sz(n, 0), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) {
    return find(x);
  }


  bool merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      e_sz[x]++;
      return false;
    }
    comp--;
    if (v_sz[x] < v_sz[y]) swap(x, y);
    e_sz[x] += e_sz[y] + 1;
    v_sz[x] += v_sz[y];
    par[y] = x;
    return true;
  }

  vi find_all() {
    vi A(num);
    FOR(i, num) A[i] = find(i);
    return A;
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
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add_edge(int frm, int to, T cost = 1) {
    auto e = edge_t(frm, to, cost, M);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, M);
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

  vector<edge_t>& operator[](int v) { return G[v]; }
};
#line 3 "/home/maspy/library/graph/treedfs.hpp"

template <class T>
struct TreeDfs {
  T& G;
  vector<int> V, LID, RID, par, VR, depth;
  vector<vector<int>> ancestors;
  vector<vector<int>> ch;
  int root;

  TreeDfs(T& G, int root=0) : G(G), V(G.N), LID(G.N), RID(G.N), par(G.N), depth(G.N), ancestors(20, vector<int>(G.N)), ch(G.N), root(root) {
    int n = 0;
    auto dfs = [&](auto self, auto v) -> void {
      LID[v] = n;
      V[n] = v;
      ++n;
      for (auto&& e : G[v]) {
        if (e.to != par[e.frm]) {
          ch[e.frm].eb(e.to);
          par[e.to] = e.frm;
          depth[e.to] = depth[e.frm] + 1;
          self(self, e.to);
        }
      }
      RID[v] = n;
    };
    par[root] = -1;
    dfs(dfs, root);
    VR = V;
    reverse(all(VR));
    // ancestors 
    ancestors[0] = par;
    FOR3(k, 1, 20){
      FOR(v, G.N){
        int w = ancestors[k-1][v];
        ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);
      }
    }
  }

  int LCA(int a, int b){
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
    return par[a];
  }
};
#line 6 "main.cpp"

void solve() {
  LL(N, M);
  Graph<ll> G(N);
  FOR(_, M) {
    LL(a, b, c);
    G.add_edge(--a, --b, c);
  }
  UnionFind uf(N);
  sort(all(G.edges), [](auto& x, auto& y) { return x.cost < y.cost; });
  Graph<ll> MST(N);
  vc<bool> in_MST(M);
  ll MST_cost = 0;

  FORIN(e, G.edges) {
    if (uf.merge(e.frm, e.to)) {
      in_MST[e.id] = true;
      MST.add_edge(e.frm, e.to, e.cost);
      MST_cost += e.cost;
    }
  }

  TreeDfs dfs(MST);

  const int K = 20;
  vv(int, TO, 20, N);
  vv(ll, dp, 20, N);
  FORIN(e, MST.edges) {
    if (dfs.par[e.frm] == e.to) {
      dp[0][e.frm] = e.cost;
    } else {
      dp[0][e.to] = e.cost;
    }
  }

  TO[0] = dfs.par;
  FOR(k, K - 1) {
    FOR(v, N) {
      int to = TO[k][v];
      if (to == -1) {
        dp[k + 1][v] = dp[k][v];
        TO[k + 1][v] = TO[k][v];
      } else {
        dp[k + 1][v] = max(dp[k][v], dp[k][to]);
        TO[k + 1][v] = TO[k][to];
      }
    }
  }
  auto& depth = dfs.depth;
  vi ANS(M);
  FORIN(e, G.edges) {
    if (in_MST[e.id]) {
      ANS[e.id] = MST_cost;
      continue;
    }
    int a = e.frm, b = e.to;
    int c = dfs.LCA(a, b);
    ll best = 0;
    FOR(_, 2) {
      swap(a, b);
      int v = a;
      int n = depth[v] - depth[c];
      FOR(k, K) {
        if (n & 1 << k) {
          chmax(best, dp[k][v]);
          v = TO[k][v];
        }
      }
    }
    ll ans = MST_cost - best + e.cost;
    ANS[e.id] = ans;
  }
  FORIN(x, ANS) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}