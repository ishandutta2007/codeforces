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

void Main() {
  int n;
  cin >> n;
  vector<int> ans(n + 1, -1);
  ans[0] = n + 1;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (ans[i] == -1) {
      for (int j = i; j <= n; j += i) {
        if (ans[j] == -1) {
          ans[j] = j / i;
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 1; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}