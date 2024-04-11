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

string strin() {
  string s;
  cin >> s;
  return s;
}
// ]

// [
void print(ll x) {
  cout << x << "\n";
}

void print(ld x) {
  cout << x << "\n";
}

void print(string& x) {
  cout << x << "\n";
}

template <typename T>
void print_itr(T begin, T end, string sep = " ") {
  if (begin != end) {
    cout << *(begin++);
    for (auto it = begin; it != end; it++) {
      cout << sep << (*it);
    }
  }
  cout << "\n";
}

template <typename T>
void print(vector<T>& x, string sep = " ") {
  print_itr(all(x), sep);
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename A, typename B, typename C>
void print(A x, B y, C z, string sep = " ") {
  cout << x << sep << y << sep << z << "\n";
}

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
struct vec2d {
  ll H, W;
  vector<vector<T>> data;
  vec2d(ll H, ll W) : H(H), W(W), data(H, vector<T>(W)) {}
  void fill(T x) {
    FOR(i, H) { FOR(j, W) data[i][j] = x; }
  }
  void print() { FOR(i, H) print_itr(all(data[i])); }
  vector<T>& operator[](ll i) { return data[i]; }
  pi shape() {return mp(H, W);}
};

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

template <typename T>
ll solve(ll K, T A) {
  auto [H, W] = A.shape();
  using MAP = unordered_map<ll, ll>;
  vec2d<vi> memo(H, W);
  auto left = (H + W - 2) / 2;
  auto right = (H + W - 2) - left;  // 

  //  xor 
  auto calc1 = [&](ll s) -> void {
    auto x = H - 1, y = W - 1;
    ll val = A[x][y];
    FOR(i, right) {
      if (s & 1 << i) {
        --x;
      } else {
        --y;
      }
      if (x < 0 || y < 0) return;
      val ^= A[x][y];
    }
    // print(x, y, val);
    memo[x][y].eb(val);
  };

  // 
  ll ans = 0;
  auto calc2 = [&](ll s) -> void {
    auto x = 0, y = 0;
    ll val = K;
    FOR(i, left) {
      val ^= A[x][y];
      if (s & 1 << i) {
        ++x;
      } else {
        ++y;
      }
      if (x >= H || y >= W) return;
    }
    auto a = upper_bound(all(memo[x][y]), val);
    auto b = lower_bound(all(memo[x][y]), val);
    ans += a - b;
  };

  FOR(s, 1 << right) { calc1(s); }
  FOR(x, H) FOR(y, W) sort(all(memo[x][y]));
  FOR(s, 1 << left) { calc2(s); }
  return ans;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  auto [N, M, K] = in3();
  vec2d<ll> A(N, M);
  FOR(i, N) {
    FOR(j, M) { A[i][j] = in(); }
  }
  // A.print();
  print(solve(K, A));
  return 0;
}