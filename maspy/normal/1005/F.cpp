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

vi bin_count(vi& A, ll size){
  vi C(size);
  for(auto&& x : A){ ++C[x]; }
  return C;
}

template <typename T>
struct vec2d {
  ll H, W;
  vector<vector<T>> data;
  vec2d(ll H, ll W) : H(W), W(W), data(H, vector<T>(W)) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  void print() { FOR(i, H) print_all(data[i]); }
  vector<T>& operator[](ll i) { return data[i]; }
};

template<class T, class U>bool chmax(T &a, const U &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T, class U>bool chmin(T &a, const U &b) { if (b<a) { a=b; return 1; } return 0; }
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

  void print(bool detail=false) {
    FOR(v, V) {
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
#line 3 "/home/maspy/library/graph/bfs01.hpp"

pair<vi, vi> bfs01(Graph<ll>& G, ll v) {
  const ll INF = 1LL << 60;
  auto N = G.V;
  vi dist(N, INF);
  vi par(N, -1);
  deque<ll> que;

  dist[v] = 0;
  que.push_front(v);
  while (!que.empty()) {
    auto v = que.front();
    que.pop_front();
    for (auto&& e : G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        par[e.to] = e.frm;
        if (e.cost == 0)
          que.push_front(e.to);
        else
          que.push_back(e.to);
      }
    }
  }
  return {dist, par};
}
#line 5 "main.cpp"

vector<vi> solve(ll N, ll M, ll K, Graph<ll> G) {
  vector<vi> ANS;
  auto [dist, par] = bfs01(G, 0);
  // 
  vector<vi> cand(N);
  for (auto&& e : G.edges) {
    if (dist[e.to] == dist[e.frm] + 1) cand[e.to].eb(e.id);
    if (dist[e.frm] == dist[e.to] + 1) cand[e.frm].eb(e.id);
  }

  vi select(G.E);
  auto dfs = [&](auto self, auto v) -> void {
    if (ANS.size() >= K) return;
    if (v == N) {
      ANS.eb(select);
      return;
    }
    // v 
    for (auto&& i : cand[v]) {
      select[i] = 1;
      self(self, v + 1);
      select[i] = 0;
    }
    return;
  };
  dfs(dfs, 1);
  return ANS;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  auto [N, M, K] = read3();
  auto G = Graph<int>(N);
  FOR(i, M) {
    auto [a, b] = read2(-1);
    G.add_edge(a, b);
  }
  auto ANS = solve(N, M, K, G);
  print(ANS.size());
  for (auto&& S : ANS) {
    print_all(S, "");
  }

  return 0;
}