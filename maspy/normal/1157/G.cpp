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

tuple<bool, vi, vi> solve(Matrix<ll>& A) {
  auto [H, W] = A.shape;

  auto check = [&](vi& X, vi& Y) -> bool {
    vi seq(H * W);
    FOR(h, H) {
      FOR(w, W) { seq[W * h + w] = A[h][w] ^ X[h] ^ Y[w]; }
    }
    FOR(i, H * W - 1) {
      if (seq[i] > seq[i + 1]) return false;
    }
    return true;
  };

  if (H == 1) {
    vi X(H);
    vi Y = A[0];
    return mt(true, X, Y);
  }
  if (H == 2) {
    // 1 
    vi B(W, 1);
    FOR(w, W + 1) {
      FOR(i, 2) {
        vi X({0, i});
        vi Y(W);
        FOR(w, W) { Y[w] = B[w] ^ A[0][w]; }
        if (check(X, Y)) {
          return mt(true, X, Y);
        }
      }
      if (w == W) break;
      B[w] = 0;
    }
    vi X, Y;
    return mt(false, X, Y);
  }
  assert(H >= 3);

  // 1 
  vi B(H, 1);
  FOR(h, H + 1) {
    vi X(H);
    vi Y(W);
    FOR(i, H) { X[i] = A[i][0] ^ B[i]; }
    // h  h+1  h = h0 
    ll h0 = -1;
    FOR(i, H - 1) {
      if (B[i] == B[i + 1]) h0 = i;
    }
    assert(h0 != -1);
    ll to = B[h0];
    // h0  to 
    FOR(w, W) { Y[w] = A[h0][w] ^ X[h0] ^ to; }
    if (check(X, Y)) {
      return mt(true, X, Y);
    }
    if (h == H) break;
    B[h] = 0;
  }
  vi X, Y;
  return mt(false, X, Y);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto [H, W] = in2();
  Matrix<ll> A = matrixin(H, W);
  auto [bl, X, Y] = solve(A);
  if (bl) {
    YES();
    string XX, YY;
    for (auto&& x : X) {
      XX += '0' + x;
    }
    for (auto&& x : Y) {
      YY += '0' + x;
    }
    print(XX);
    print(YY);
  } else {
    NO();
  }

  return 0;
}