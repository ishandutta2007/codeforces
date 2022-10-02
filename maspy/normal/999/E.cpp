#line 1 "main.cpp"
#include <bits/stdc++.h>
#line 3 "/home/maspy/library/my_template.hpp"

using namespace std;

using ll = long long;
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
ll read() {
  ll i;
  cin >> i;
  return i;
}

pi read2(int off = 0) {
  ll a, b;
  cin >> a >> b;
  return {a + off, b + off};
}

tuple<ll, ll, ll> read3() {
  ll a, b, c;
  cin >> a >> b >> c;
  return {a, b, c};
}

vi read_vec(int n, int off = 0) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
    x += off;
  }
  return A;
}

string read_str() {
  string s;
  cin >> s;
  return s;
}
// ]

// [
template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

template <typename T>
void print_seq(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}
template <typename T>
void print_all(T A, string sep = " ") {
  print_seq(all(A), sep);
}
// ]

template <typename T>ll sum(T A){return accumulate(all(A), 0);}

template <typename T>vector<T> cumsum(vector<T> A) {
  ll N = A.size(); vector<T> B(N + 1); B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
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
  ll V, E;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph(ll N, bool bl = false) : V(N), E(0), G(N), directed(bl) {}

  void add_edge(ll frm, ll to, T cost = 1) {
    auto e = edge_t(frm, to, cost, E);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, E);
      G[to].eb(e_rev);
    }
    ++E;
  }

  void print() {
    FOR(v, V) {
      cout << v;
      for (auto e : (*this)[v]) {
        cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
      }
      cout << "\n";
    }
  }

  vector<edge_t>& operator[](ll v) { return G[v]; }
};
#line 3 "/home/maspy/library/graph/scc.hpp"

template <class T>
struct SCC {
  T& G;
  ll N;
  ll n_comp;
  vi comp_id;
  vector<vi> comp;

  SCC(T& G) : G(G), N(G.V), n_comp(0), comp_id(G.V, 0) { assert(G.directed); }

  ll operator[](ll v) { return comp_id[v]; }
  void build() {
    vi low(N, 0);
    vi ord(N, -1);
    ll now = 0;
    vi visited;

    auto dfs = [&](auto self, ll v) -> void {
      low[v] = now;
      ord[v] = now;
      ++now;
      visited.eb(v);
      for (auto e : G[v]) {
        if (ord[e.to] == -1) {
          self(self, e.to);
          chmin(low[v], low[e.to]);
        } else {
          chmin(low[v], ord[e.to]);
        }
      }
      if (low[v] == ord[v]) {
        while (1) {
          ll u = visited.back();
          visited.pop_back();
          ord[u] = N;
          comp_id[u] = n_comp;
          if (u == v) break;
        }
        ++n_comp;
      }
    };

    FOR(v, N) {
      if (ord[v] == -1) dfs(dfs, v);
    }
    comp.resize(n_comp);
    FOR(v, N) {
      comp_id[v] = n_comp - 1 - comp_id[v];
      comp[comp_id[v]].eb(v);
    }
  }
};
#line 5 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  auto [N, M, S] = read3();
  Graph<ll> G(N, true);

  FOR(i, M) {
    auto [a, b] = read2(-1);
    G.add_edge(a, b);
  }

  // G.print();

  auto scc = SCC(G);
  scc.build();

  /*
  print_all(scc.comp_id);
  for (auto comp : scc.comp) {
    print_all(comp);
  }
  */

  /*
  
  in_deg = 0
  S 
  */
  auto n = scc.n_comp;
  vi in_deg(n, 0);
  for (auto e : G.edges) {
    auto a = scc[e.frm];
    auto b = scc[e.to];
    if (a != b) in_deg[b]++;
  }
  auto v = S - 1;
  ++in_deg[scc.comp_id[v]];
  auto ans = count(all(in_deg), 0);
  print(ans);
  return 0;
}