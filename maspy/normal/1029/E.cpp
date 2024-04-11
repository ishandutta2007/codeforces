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

template <typename T>
struct Grid {
  ll H, W;
  vector<vector<T>> data;
  pi shape;
  Grid(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)), shape({H,W}) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  vector<T>& operator[](ll i) { return data[i]; }
  bool operator==(Grid<T>& other){
    if(H != other.H || W != other.W) return false;
    FOR(i, H) FOR(j, W){
      if(data[i][j] != other[i][j]) return false;
    }
    return true;
  }
  Grid rot(){
    auto B = Grid(W,H);
    FOR(i, W){
      FOR(j, H){
        B[i][j] = (*this)[j][W-1-i];
      }
    }
    return B;
  }
};


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

string sin() {
  string s;
  cin >> s;
  return s;
}

Grid<ll> gridin(int H, int W){
  Grid<ll> A(H, W);
  FOR(i, H){
    FOR(j, W){
      A[i][j] = in();
    }
  }
  return A;
}

Grid<char> cgridin(int H, int W){
  Grid<char> A(H, W);
  FOR(i, H){
    string S = sin();
    FOR(j, W){
      A[i][j] = S[j];
    }
  }
  return A;
}

// ]

// [
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

ostream& operator<<(ostream& os, const vector<ll>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

ostream& operator<<(ostream& os, const vector<char>& A) {
  for (size_t i = 0; i < A.size(); i++) {
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

void YES() {print("YES");}
void NO() {print("NO");}
void Yes() {print("Yes");}
void No() {print("No");}
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
ostream& operator<<(ostream& os, Grid<T>& A) {
  FOR(i, A.H){
    if(i) os << "\n";
    os << A[i];
  }
  return os;
}

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
    par[0] = -1;
    dfs(dfs, root);
  }
};
#line 5 "main.cpp"

void solve(ll N, Graph<ll>& G) {
  auto dfs = TreeDfs(G);
  auto V = dfs.V;
  auto par = dfs.par;

  auto VR = V;
  reverse(all(VR));
  // -1 
  // 1 
  vi DP(N, -1);
  for (auto&& v : VR) {
    auto p = par[v];
    if (v == 0) {
      DP[v] = 1;
      break;
    }
    if (DP[v] == -1) {
      DP[p] = 1;
    } else if (DP[v] == 0) {
    } else {
      if (DP[p] == -1) {
        DP[p] = 0;
      }
    }
  }
  DP[0] = 0;
  for (auto&& e : G[0]) {
    DP[e.to] = 0;
  }
  auto x = count(all(DP), 1);
  print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  auto N = in();
  Graph<ll> G(N);
  FOR(_, N - 1) {
    auto [a, b] = in2();
    G.add_edge(a - 1, b - 1);
  }
  solve(N, G);

  return 0;
}