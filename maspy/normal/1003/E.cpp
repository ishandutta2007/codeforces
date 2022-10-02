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

  void print(bool detail=false) {
    FOR(v, V) {
      cout << v << " :";
      for (auto e : (*this)[v]) {
        if(detail) cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  vector<edge_t>& operator[](ll v) { return G[v]; }
};
#line 4 "main.cpp"

pair<bool, Graph<int>> solve(ll N, ll diam, ll max_deg) {
  Graph<int> G(N, true);
  if (N <= diam) return {false, G};

  vi deg(N);
  vi dep(N);
  auto max_dep = diam / 2;

  ll nxt = 1;
  if (diam % 2 == 1) {
    G.add_edge(0, 1);
    ++deg[0];
    ++deg[1];
    ++nxt;
  }

  auto add = [&](ll x) {
    // x  y 
    assert(nxt < N);
    assert(dep[x] + 1 <= max_dep);
    G.add_edge(x, nxt);
    ++deg[x];
    ++deg[nxt];
    dep[nxt] = dep[x] + 1;
    return nxt++;
  };

  if (diam % 2 == 0) {
    auto v = 0;
    FOR(i, diam / 2) { v = add(v); }
    v = 0;
    FOR(i, diam / 2) { v = add(v); }
  } else {
    auto v = 0;
    FOR(i, diam / 2) { v = add(v); }
    v = 1;
    FOR(i, diam / 2) { v = add(v); }
  }

  auto v = 0;
  while (nxt < N && v < nxt) {
    if (deg[v] == max_deg || dep[v] == max_dep) {
      ++v;
      continue;
    }
    add(v);
  }
  if (nxt < N) return {false, G};
  if (any_of(all(deg), [&](ll x) { return x > max_deg; })) return {false, G};
  return {true, G};
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  auto N = read(), diam = read(), deg = read();
  auto [bl, G] = solve(N, diam, deg);
  if (bl) {
    print("YES");
    for (auto e : G.edges) {
      print(e.frm + 1, e.to + 1);
    }
  } else {
    print("NO");
  }

  return 0;
}