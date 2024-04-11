#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

bool solve(ll a, ll b, ll n, ll m) {
  if (n == 0) {
    return min(a, b) >= m;
  }
  if (m == 0) {
    return a + b >= n;
  }
  if (a == b) {
    if (n <= m) {
      if (b >= n) {
        return solve(a - n, b - n, 0, m - n);
      } else {
        assert(false);
      }
    } else {
      if (a >= m) {
        return solve(a - m, b - m, n - m, 0);
      } else {
        assert(false);
      }
    }
  } else if (a > b) {
    ll delta = a - b;
    if (delta <= n) {
      n -= delta;
      return solve(b, b, n, m);
    } else {
      return solve(a - n, b, 0, m);
    }
  } else {
    ll delta = b - a;
    if (delta <= n) {
      n -= delta;
      return solve(a, a, n, m);
    } else {
      return solve(a, b - n, 0, m);
    }
  }
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
      cout << "No\n";
      continue;
    }
    cout << (solve(a, b, n, m) ? "Yes\n" : "No\n");
  }
}