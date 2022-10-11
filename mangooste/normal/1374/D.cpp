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

#define int ll

void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> mapa;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mapa[a % k]++;
    }
    if (k == 1) {
      cout << "0\n";
      continue;
    }
    int where_mx = -1;
    for (auto [ost, cnt] : mapa) {
      if (ost == 0) {
        continue;
      }
      if (where_mx == -1 || mapa[where_mx] < cnt) {
        where_mx = ost;
      }
    }
    if (where_mx == -1) {
      cout << "0\n";
      continue;
    }
    cout << (mapa[where_mx] - 1) * k + k - where_mx + 1 << '\n';
  }
}