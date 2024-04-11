#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using pi = pair<int, int>;
using vi = vector<int>;

#define range(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define range3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define range_r(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define range3_r(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

#define eb emplace_back
#define mp make_pair
#define mt make_tuple

template <typename T>
void print(T x) {
  cout << x << endl;
}

ll read() {
  ll i;
  cin >> i;
  return i;
}

vi readvi(int n, int off = 0) {
  vi v(n);
  range(i, n) v[i] = read() + off;
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

ll solve(ll N, vi A) {
  // 
  auto comp = [](ll x, ll y) { return (x & 1) < (y & 1); };
  sort(all(A), comp);

  ll ans = 0;
  range(i, N) {
    range3(j, i + 1, N) { ans += gcd(A[i], 2 * A[j]) > 1; }
  }
  return ans;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  range(_, T) {
    int N = read();
    auto A = readvi(N);
    print(solve(N, A));
  }
  return 0;
}