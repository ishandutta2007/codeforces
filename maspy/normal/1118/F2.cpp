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
#define VEC vector

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

tuple<ll, ll, ll, ll> in4() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  return {a, b, c, d};
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
int argmax(vector<T>& A){
  return max_element(all(A)) - A.begin();
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
  vi V, LID, RID, par, VR, depth;
  Grid<ll> ancestors;
  vector<vi> ch;
  ll root;

  TreeDfs(T& G, int root = 0) : G(G), V(G.N), LID(G.N), RID(G.N), par(G.N), root(root), ch(G.N), ancestors(20, G.N), depth(G.N) {
    ll n = 0;
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
    par[0] = -1;
    dfs(dfs, root);
    VR = V;
    reverse(all(VR));
    // ancestors 
    ancestors[0] = par;
    FOR3(k, 1, 20){
      FOR(v, G.N){
        ll w = ancestors[k-1][v];
        ancestors[k][v] = (w == -1 ? -1 : ancestors[k-1][w]);
      }
    }
  }

  ll LCA(ll a, ll b){
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
#line 3 "/home/maspy/library/mod/modint.hpp"

template <std::uint_fast64_t Modulus> class modint {
  long long val;
  public:
    static const uint_fast64_t mod = Modulus;
    constexpr modint(long long x = 0) noexcept : val(x % Modulus) {}
    constexpr modint operator+(const modint rhs) const noexcept {return modint(*this) += rhs;}
    constexpr modint operator-(const modint rhs) const noexcept {return modint(*this) -= rhs;}
    constexpr modint operator*(const modint rhs) const noexcept {return modint(*this) *= rhs;}
    constexpr modint operator/(const modint rhs) const noexcept {return modint(*this) /= rhs;}
    constexpr modint &operator+=(const modint rhs) noexcept {
      val += rhs.val;
      if (val >= Modulus) val -= Modulus;
      return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
      if (val < rhs.val) val += Modulus;
      val -= rhs.val;
      return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
      val = val * rhs.val % Modulus;
      return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
      auto exp = Modulus - 2;
      while (exp) {
        if (exp % 2) {
          *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
      }
      return *this;
    }
    friend ostream &operator<<(ostream &os, const modint &p) {
      return os << p.val;
    }
};

template< typename T >
struct ModCalc {
  vector<T> _fact = {1, 1};
  vector<T> _fact_inv = {1, 1};
  vector<T> _inv = {0, 1};
  
  T pow(T a, int n){
    T x(1);
    while(n) {
      if(n & 1) x *= a;
      a *= a;
      n >>= 1;
    }
    return x;
  }
  void expand(int n){
    while(_fact.size() <= n){
      auto i = _fact.size();
      _fact.eb(_fact[i-1] * i);
      auto q = T::mod / i, r = T::mod % i;
      _inv.eb(_inv[r] * (T::mod-q));
      _fact_inv.eb(_fact_inv[i-1] * _inv[i]);
    }
  }

  T fact(int n){
    if(n >= _fact.size()) expand(n);
    return _fact[n];
  }

  T fact_inv(int n){
    if(n >= _fact.size()) expand(n);
    return _fact_inv[n];
  }
  
  T inv(int n){
    if(n >= _fact.size()) expand(n);
    return _inv[n];
  }
  
  T C(int n, int k, bool large=false){
    assert(n >= 0);
    if (k < 0 || n < k) return 0;
    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);
    T x(1);
    FOR(i, k){
      x *= n - i;
      x *= inv(i + 1);
    }
    return x;
  }
};

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
#line 6 "main.cpp"

using mint = modint998;

/*
LCA
 DP
LCA 
LCA 
*/

mint solve(ll N, ll K, Graph<ll>& G, vi& A) {
  auto dfs = TreeDfs(G);
  //  -> 
  vector<vi> C(K);
  FOR(i, N) {
    if (A[i] >= 0) C[A[i]].eb(i);
  }

  vi C_LCA(K);
  FOR(k, K) {
    ll l = -1, r = -1;
    for (auto&& v : C[k]) {
      if (l == -1 || dfs.LID[l] > dfs.LID[v]) l = v;
      if (r == -1 || dfs.LID[r] < dfs.LID[v]) r = v;
    }
    auto lca = dfs.LCA(l, r);
    C_LCA[k] = lca;
  }

  // 
  vi AA(N, -1);
  FOR(v, N) {
    auto k = A[v];
    auto vv = v;
    if (k == -1) continue;
    while (1) {
      if (AA[vv] != -1 && AA[vv] != k) return 0;
      if (AA[vv] == k) break;
      AA[vv] = k;
      if (vv == C_LCA[k]) break;
      vv = dfs.par[vv];
    }
  }
  A = AA;
  // print(A);

  VEC<mint> DP_0(N);  // 
  VEC<mint> DP_1(N);  // 

  for (auto&& v : dfs.VR) {
    mint x = 1;
    for (auto&& to : dfs.ch[v]) {
      x *= (DP_0[to] + DP_1[to]);
    }
    if (A[v] >= 0) {
      DP_1[v] = x;
    } else {
      DP_0[v] = x;

      // 
      auto& ch = dfs.ch[v];
      auto n = ch.size();
      VEC<mint> dpl(n + 1);
      VEC<mint> dpr(n + 1);
      dpl[0] = 1;
      dpr[n] = 1;
      FOR(i, n) { dpl[i + 1] = dpl[i] * (DP_0[ch[i]] + DP_1[ch[i]]); }
      FOR_R(i, n) { dpr[i] = dpr[i + 1] * (DP_0[ch[i]] + DP_1[ch[i]]); }
      FOR(i, n) { DP_1[v] += DP_1[ch[i]] * dpl[i] * dpr[i + 1]; }
    }
    // print(v, DP_0[v], DP_1[v]);
  }
  return DP_1[0];
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto [N, K] = in2();
  auto A = vin(N);
  FOR(i, N) { --A[i]; }
  Graph<ll> G(N);
  FOR(_, N - 1) {
    auto [a, b] = in2();
    --a;
    --b;
    G.add_edge(a, b);
  }
  print(solve(N, K, G, A));

  return 0;
}