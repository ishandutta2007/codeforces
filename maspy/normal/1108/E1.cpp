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
#line 3 "main.cpp"

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  auto [N, M] = in2();
  auto A = vin(N);
  VEC<pi> LR;
  vi X;
  FOR(i, M) {
    auto [a, b] = in2();
    --a;
    LR.eb(mp(a, b));
    X.eb(a);
    X.eb(b);
  }
  X.eb(0);
  X.eb(N);
  sort(all(X));
  auto it = unique(all(X));
  X.resize(it - X.begin());

  const ll INF = 1LL << 60;
  vi LOW(X.size() - 1, INF);
  vi HIGH(X.size() - 1, -INF);
  FOR(i, N) {
    auto j = upper_bound(all(X), i) - X.begin() - 1;
    chmin(LOW[j], A[i]);
    chmax(HIGH[j], A[i]);
  }

  FOR(i, M) {
    auto [a, b] = LR[i];
    a = upper_bound(all(X), a) - X.begin() - 1;
    b = upper_bound(all(X), b) - X.begin() - 1;
    LR[i] = mp(a, b);
  }

  ll best = -1;
  ll best_i = -1;

  FOR(i, X.size() - 1) {
    // i 
    auto me = HIGH[i];
    auto B = LOW;
    FOR(m, M) {
      auto [l, r] = LR[m];
      if (r <= i || i < l) {
        FOR3(j, l, r) { --B[j]; }
      }
    }
    auto low = *min_element(all(B));
    if (best <= me - low) {
      best = me - low;
      best_i = i;
    }
  }
  vi ANS;
  auto i = best_i;
  FOR(m, M) {
    auto [l, r] = LR[m];
    if (r <= i || i < l) {
      ANS.eb(m + 1);
    }
  }
  print(best);
  print(ANS.size());
  print(ANS);

  return 0;
}