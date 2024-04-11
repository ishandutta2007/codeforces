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

pi read2() {
  ll a, b;
  cin >> a >> b;
  return {a, b};
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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#line 3 "main.cpp"

const ll INF = 1LL << 60;

template <typename T, typename U>
ll solve(ll N, T RAIN, U KASA) {
  sort(all(RAIN));
  sort(all(KASA));

  // [i, i+1] 
  bitset<1 << 17> in_rain;
  for (auto [a, b] : RAIN) {
    FOR3(i, a, b) in_rain[i] = true;
  }

  vi X;
  for (auto [a, b] : RAIN) {
    X.eb(b);
  }
  for (auto [a, b] : KASA) {
    X.eb(a);
  }

  vi DP(N + 1, INF);
  DP[0] = 0;
  FOR(x, N) {
    // 
    auto left = lower_bound(all(KASA), mp(x, -INF));
    auto right = lower_bound(all(KASA), mp(x, INF));
    for (auto it = left; it != right; it++) {
      auto [a, p] = (*it);
      assert(x == a);
      for (auto&& to : X) {
        if (to > a) {
          ll cost = (to - a) * p;
          chmin(DP[to], DP[a] + cost);
        }
      }
    }
    // 
    if (!in_rain[x]) chmin(DP[x + 1], DP[x]);
  }

  ll ans = DP[N];
  if (ans == INF) ans = -1;
  return ans;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  auto X = read();
  auto N = read();
  auto M = read();
  vector<pi> RAIN(N);
  vector<pi> KASA(M);
  FOR(i, N) RAIN[i] = read2();
  FOR(i, M) KASA[i] = read2();
  print(solve(X, RAIN, KASA));
  return 0;
}