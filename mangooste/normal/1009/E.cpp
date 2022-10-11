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

const int N = 1'000'000 + 228;
const int MOD = 998244353;
int p2[N], n;
vector<int> a, pref;
int ans = 0;

inline int mult(int a, int b) {
  return 1ll * a * b % MOD;
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

void Main() {
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = mult(p2[i - 1], 2);
  }
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  pref.resize(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = add(pref[i], a[i]);
  }
  for (int delta = 1; delta <= n; delta++) {
    int pmask_len = delta + 1;
    if (pmask_len <= n - 1) {
      ans = add(ans, mult(pref[delta], mult(p2[n - 1 - pmask_len], n - 1 - pmask_len + 1)));
    }
    ans = add(ans, mult(pref[delta], p2[n - delta]));
  }
  cout << ans << '\n';
}