#include <bits/stdc++.h>
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

template <typename T>
void print(T x) {
  cout << x << "\n";
}

template <typename A, typename B>
void print(A x, B y, string sep = " ") {
  cout << x << sep << y << "\n";
}

template <typename T>
void printseq(T begin, T end, string sep = " ") {
  cout << *(begin++);
  for (auto it = begin; it != end; it++) {
    cout << sep << (*it);
  }
  cout << "\n";
}

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

vi readvi(int n, int off = 0) {
  vi v(n);
  for (auto&& x : v) {
    x = read() + off;
  }
  return v;
}

pi readpi(int off = 0) {
  int a, b;
  cin >> a >> b;
  return pi(a + off, b + off);
}

string readstr() {
  string s;
  cin >> s;
  return s;
}

vi solve(ll N) {
  vi v;
  ll mod = 1;
  while (mod <= N) {
    mod *= 10;
    ll r = N % mod;
    if (r > 0) {
      v.eb(r);
      N -= r;
    }
  }
  return v;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll T = read();
  FOR(_, T) {
    ll N = read();
    auto v = solve(N);
    print(v.size());
    printseq(all(v));
  }
  return 0;
}