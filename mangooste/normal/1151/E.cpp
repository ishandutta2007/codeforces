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

int n;
vector<int> a;
ll ans = 0;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  ans += 1ll * a[0] * (n - a[0] + 1);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      ans += 1ll * (a[i] - a[i - 1]) * (n - a[i] + 1);
    } else {
      ans += 1ll * (a[i - 1] - a[i]) * a[i];
    }
  }
  cout << ans << '\n';
}