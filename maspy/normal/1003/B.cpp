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
#line 3 "main.cpp"

string solve(ll a, ll b, ll x) {
  return [&]() {
    string ans;
    if (x % 2 == 1) {
      FOR(i, a - (x + 1) / 2) ans += "0";
      FOR(i, (x + 1) / 2) ans += "01";
      FOR(i, b - (x + 1) / 2) ans += "1";
      return ans;
    }
    if (a < b) {
      ans = "1";
      FOR(i, b - (x / 2 + 1)) ans += "1";
      FOR(i, a - x / 2) ans += "0";
      FOR(i, x / 2) ans += "01";
      return ans;
    }
    {
      ans = "0";
      FOR(i, a - (x / 2 + 1)) ans += "0";
      FOR(i, b - x / 2) ans += "1";
      FOR(i, x / 2) ans += "10";
      return ans;
    }
  }();
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a = read(), b = read(), x = read();
  print(solve(a, b, x));
  return 0;
}