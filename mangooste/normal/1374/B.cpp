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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt2 = 0;
    for (; n % 2 == 0; n /= 2, cnt2++);
    int cnt3 = 0;
    for (; n % 3 == 0; n /= 3, cnt3++);
    if (n != 1 || cnt2 > cnt3) {
      cout << "-1\n";
    } else {
      cout << cnt3 - cnt2 + cnt3 << '\n';
    }
  }
}