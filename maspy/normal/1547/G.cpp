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
#define FORIN(x, A) for (auto&& x : A)
#define all(x) x.begin(), x.end()

#define elif else if

#define popcnt __builtin_popcount

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define VEC vector

template <typename T>
struct Matrix {
  ll H, W;
  vector<vector<T>> data;
  pi shape;
  Matrix(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)), shape({H,W}) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  vector<T>& operator[](ll i) { return data[i]; }
  bool operator==(Matrix<T>& other){
    if(H != other.H || W != other.W) return false;
    FOR(i, H) FOR(j, W){
      if(data[i][j] != other[i][j]) return false;
    }
    return true;
  }
  Matrix rot(){
    auto B = Matrix(W,H);
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

pi in2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
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

vi vin(int n) {
  vi A(n);
  for (auto&& x : A) {
    cin >> x;
  }
  return A;
}

string sin() {
  string s;
  cin >> s;
  return s;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

Matrix<ll> matrixin(int H, int W){
  Matrix<ll> A(H, W);
  FOR(i, H){
    FOR(j, W){
      A[i][j] = in();
    }
  }
  return A;
}

Matrix<char> cmatrixin(int H, int W){
  Matrix<char> A(H, W);
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

template <typename T>
string join(vector<T>& v){
  ostringstream os;
  for(auto&& x : v){
    os << x;
  }
  return os.str();
}

void YES() {print("YES");}
void NO() {print("NO");}
void Yes() {print("Yes");}
void No() {print("No");}
// ]

template <typename T>
ll sum(T A) {
  return accumulate(all(A), 0LL);
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
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){return mp(A[i],i)<=mp(A[j],j);});
  return ids;
}

template <typename T>
int argmax(vector<T>& A){
  return max_element(all(A)) - A.begin();
}


template <typename T>
ostream& operator<<(ostream& os, Matrix<T>& A) {
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
#line 3 "/home/maspy/library/graph/scc.hpp"

template <class T>
struct SCC {
  T& G;
  ll N;
  ll n_comp;
  vi comp_id;
  vector<vi> comp;

  SCC(T& G) : G(G), N(G.N), n_comp(0), comp_id(G.N, 0) { assert(G.directed); }

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
  cout << setprecision(15);

  auto T = in();
  FOR(_, T) {
    auto [N, M] = in2();
    Graph<ll> G(N, 1);
    FOR(_, M) {
      auto [a, b] = in2();
      G.add_edge(--a, --b);
    }
    SCC scc(G);
    scc.build();
    ll C = scc.n_comp;
    vi comp_id = scc.comp_id;
    /*
    
    */
    Graph<ll> H(C, 1);
    FORIN(e, G.edges) { H.add_edge(comp_id[e.frm], comp_id[e.to]); }

    const ll INF = 1LL << 60;
    vi DP(C);
    vi has_loop(C);
    FOR(c, C) {
      FORIN(e, H[c]) {
        if (e.to == c) {
          has_loop[c] = 1;
        }
      }
    }
    DP[comp_id[0]] = 1;
    FOR(c, C) {
      if (DP[c] == 0) continue;
      if (has_loop[c]) DP[c] = INF;
      if (DP[c] < INF && DP[c] >= 2) DP[c] = 2;
      FORIN(e, H[c]) {
        ll d = e.to;
        if (c == d) continue;
        DP[d] += DP[c];
        chmin(DP[d], INF);
      }
    }
    FOR(c, C) {
      if (DP[c] == INF) DP[c] = -1;
    }
    vi ANS(N);
    FOR(v, N) { ANS[v] = DP[comp_id[v]]; }
    print(ANS);
  }

  return 0;
}