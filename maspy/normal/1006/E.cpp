#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define FOR3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

// [
ll in() {
  ll i;
  cin >> i;
  return i;
}

pi in2(int off = 0) {
  ll a, b;
  cin >> a >> b;
  return {a + off, b + off};
}

tuple<ll, ll, ll> in3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

vi vin(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string strin() {
  string s;
  cin >> s;
  return s;
}
// ]

// [
void print(ll x) {
  cout << x << "\n";
}

void print(ld x) {
  cout << x << "\n";
}

void print(string& x) {
  cout << x << "\n";
}

template <typename T>
void print_itr(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}

template <typename T>
void print(vector<T>& x, string sep = " ") {
  print_itr(all(x), sep);
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

// ]
template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0);
}

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
struct vec2d {
  ll H, W;
  vector<vector<T>> data;
  vec2d(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  void print() { FOR(i, H) print_itr(all(data[i])); }
  vector<T>& operator[](ll i) { return data[i]; }
};

template <class T, class U>
bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T& a, const U& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#line 3 "/home/maspy/library/graph/base.hpp"

template <typename T>
struct Edge {
  ll frm, to;
  T cost;
  ll id;
  Edge(ll a, ll b, T c, ll d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  ll N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(ll N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add_edge(ll frm, ll to, T cost = 1) {
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

  vector<edge_t>& operator[](ll v) { return G[v]; }
};
#line 3 "/home/maspy/library/graph/treedfs.hpp"

template <class T>
struct TreeDfs {
  T& G;
  vi V, LID, RID, par;
  ll root;

  TreeDfs(T& G, int root = 0) : G(G), V(G.N), LID(G.N), RID(G.N), par(G.N), root(root) {
    ll n = 0;
    auto dfs = [&](auto self, auto v) -> void {
      LID[v] = n;
      V[n] = v;
      ++n;
      for (auto&& e : G[v]) {
        if (e.to != par[e.frm]) {
          par[e.to] = e.frm;
          self(self, e.to);
        }
      }
      RID[v] = n;
    };
    dfs(dfs, root);
  }
};
#line 5 "main.cpp"

template <typename T1, typename T2, typename T3>
void solve(T1 N, T2& G, T3& query) {
  auto dfs = TreeDfs(G);
  auto& LID = dfs.LID;
  auto& RID = dfs.RID;
  auto& V = dfs.V;
  for (auto&& [a, b] : query) {
    auto sz = RID[a] - LID[a];
    if (sz >= b)
      print(1 + V[LID[a] + b - 1]);
    else
      print(-1LL);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  auto N = in(), Q = in();
  Graph<int> G(N);
  FOR3(v, 1, N) {
    auto p = in();
    G.add_edge(--p, v);
  }
  // G.print();
  vector<pi> query;
  FOR(i, Q) {
    auto [v, k] = in2();
    query.eb(mp(--v, k));
  }
  solve(N, G, query);
  return 0;
}