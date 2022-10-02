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
#line 4 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto T = in();
  const ll K = 20;
  FOR(_, T) {
    auto N = in();
    auto TO = vin(N);
    FOR(v, N) TO[v]--;
    Matrix<ll> TO2(K, N);
    FOR(v, N) TO2[0][v] = TO[v];
    FOR(k, K - 1) {
      FOR(v, N) {
        ll to = TO2[k][v];
        TO2[k + 1][v] = TO2[k][to];
      }
    }
    vi in_cycle(N);
    FOR(v, N) {
      ll to = TO2[K - 1][v];
      in_cycle[to] = 1;
    }

    vi in_deg(N);
    FOR(v, N)++ in_deg[TO[v]];

    UnionFind uf(N);
    FOR(v, N) uf.merge(v, TO[v]);
    vi root = uf.find_all();
    VEC<vi> VV(N);
    FOR(v, N) { VV[root[v]].eb(v); }

    vi ANS(N, -1);
    vi FRM(N, -1);
    VEC<pi> PATH;

    FOR(r, N) {
      if (root[r] != r) continue;
      bool is_cycle = true;
      vi V = VV[r];

      FORIN(v, V) if (in_deg[v] == 0) is_cycle = false;
      if (is_cycle) {
        FORIN(v, V) ANS[v] = TO[v];
        continue;
      }
      FORIN(v, V) {
        ll to = TO[v];
        if (in_deg[to] >= 2 && in_cycle[v]) continue;
        FRM[to] = v;
      }

      FORIN(v, V) {
        ll frm = FRM[v];
        if (frm == -1) continue;
        ANS[frm] = v;
      }
      FORIN(v, V) {
        if (FRM[v] != -1) continue;
        ll S = v;
        ll w = v;
        while (ANS[w] != -1) w = ANS[w];
        ll T = w;
        PATH.eb(mp(S, T));
      }
    }

    ll n = PATH.size();
    FOR(i, n) {
      ll frm = PATH[i].se;
      ll to = PATH[(i + 1) % n].fi;
      ANS[frm] = to;
    }
    ll ans = 0;
    FOR(i, N) ans += TO[i] == ANS[i];
    print(ans);
    FORIN(x, ANS)++ x;
    print(ANS);
  }

  return 0;
}