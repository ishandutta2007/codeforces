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

tuple<ll, ll, ll, ll, ll> in5() {
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  return {a, b, c, d, e};
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
#line 3 "main.cpp"

ld calc(vi X, vi Y) {
  /*
   x 
   out, in, out, in, ...
   x 
   x 
   in, out 
  */
  ll N = X.size();
  X.resize(3 * N);
  Y.resize(3 * N);
  FOR3(i, N, 3 * N) {
    X[i] = X[i - N];
    Y[i] = Y[i - N];
  }
  VEC<ld> A;
  VEC<pair<ld, ld>> seg_0;
  VEC<pair<ld, ld>> seg_1;
  FOR3(i, N, N + N) {
    assert(Y[i] != 0 || Y[i + 1] != 0 || Y[i + 2] != 0);
    // 
    if ((Y[i] > 0 && Y[i + 1] > 0) || (Y[i] < 0 && Y[i + 1] < 0)) continue;
    // 
    if ((Y[i] < 0 && Y[i + 1] > 0) || (Y[i] > 0 && Y[i + 1] < 0)) {
      ld x = ld(X[i + 1]) * Y[i] - ld(X[i]) * Y[i + 1];
      x /= Y[i] - Y[i + 1];
      A.eb(x);
      continue;
    }
    // i 
    if (Y[i] == 0 && Y[i + 1] != 0 && Y[i - 1] != 0) {
      if ((Y[i - 1] < 0 && Y[i + 1] < 0) || (Y[i - 1] > 0 && Y[i + 1] > 0)) {
        // 
        continue;
      } else {
        A.eb(X[i]);
        continue;
      }
    }
    if (Y[i] == 0 && Y[i + 1] == 0) {
      // [i, i+1]  x 
      if ((Y[i - 1] < 0 && Y[i + 2] < 0) || (Y[i - 1] > 0 && Y[i + 2] > 0)) {
        seg_0.eb(mp(X[i], X[i + 1]));
      } else {
        seg_1.eb(mp(X[i], X[i + 1]));
      }
    }
  }
  struct T {
    ld left, right;
    bool change;
  };
  VEC<T> data;
  FORIN(x, A) data.eb(T({x, x, true}));
  FORIN(p, seg_0) data.eb(T({min(p.fi, p.se), max(p.fi, p.se), false}));
  FORIN(p, seg_1) data.eb(T({min(p.fi, p.se), max(p.fi, p.se), true}));
  sort(all(data), [](auto& x, auto& y) { return x.left < y.left; });

  bool isin = false;
  ld prev = 0.0;
  ld ANS = 0.0;
  FORIN(t, data) {
    if (isin) {
      ANS += t.left - prev;
    }
    ANS += t.right - t.left;
    prev = t.right;
    if (t.change) isin = !isin;
  }
  // assert(!isin);
  return ANS;
}

pair<vi, vi> remove_180(vi X, vi Y) {
  while (1) {
    ll N = X.size();
    ll x1 = X[N - 2];
    ll y1 = Y[N - 2];
    ll x2 = X[N - 1];
    ll y2 = Y[N - 1];
    ll x3 = X[0];
    ll y3 = Y[0];
    if ((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)) {
      X.pop_back();
      Y.pop_back();
    } else
      break;
  }
  reverse(all(X));
  reverse(all(Y));

  vi new_X, new_Y;
  FOR(i, X.size()) {
    if (new_X.size() <= 1) {
      new_X.eb(X[i]);
      new_Y.eb(Y[i]);
      continue;
    }
    ll x1 = new_X[new_X.size() - 2];
    ll y1 = new_Y[new_Y.size() - 2];
    ll x2 = new_X[new_X.size() - 1];
    ll y2 = new_Y[new_Y.size() - 1];
    ll x3 = X[i];
    ll y3 = Y[i];
    if ((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)) {
      new_X.pop_back();
      new_Y.pop_back();
    }
    new_X.eb(x3);
    new_Y.eb(y3);
  }
  return mp(new_X, new_Y);
}

void solve() {
  auto [N, Q] = in2();
  vi X(N), Y(N);
  FOR(i, N) {
    ld x, y;
    cin >> x >> y;
    X[i] = int(round(100 * x));
    Y[i] = int(round(100 * y));
  }
  tie(X, Y) = remove_180(X, Y);
  N = X.size();

  FOR(_, Q) {
    ld _x1, _y1, _x2, _y2;
    cin >> _x1 >> _y1 >> _x2 >> _y2;
    int x1 = int(round(100 * _x1));
    int y1 = int(round(100 * _y1));
    int x2 = int(round(100 * _x2));
    int y2 = int(round(100 * _y2));

    vi _X = X;
    vi _Y = Y;
    FOR(i, N) {
      _X[i] -= x1;
      _Y[i] -= y1;
    }
    ll a = x2 - x1, b = y2 - y1;
    FOR(i, N) {
      ll x = _X[i], y = _Y[i];
      _X[i] = a * x + b * y;
      _Y[i] = -b * x + a * y;
    }

    ld sq = sqrt(ld(a) * a + ld(b) * b);
    ld ANS = calc(_X, _Y) / sq / 100;
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // auto T = in();
  // FOR(_, T) solve();

  solve();

  return 0;
}