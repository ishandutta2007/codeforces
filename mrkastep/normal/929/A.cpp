#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 998244353;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<int> ans(n, INF);
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (ans[i] == INF) {
      cout << -1 << endl;
      return;
    }
    for (int j = i + 1; j < n; ++j) {
      if (v[j] - v[i] <= k)
        ans[j] = min(ans[j], ans[i] + 1);
    }
  }
  cout << ans[n - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}