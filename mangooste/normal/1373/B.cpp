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
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto el : s) {
      if (el == '1') {
        a++;
      } else {
        b++;
      }
    }
    cout << (min(a, b) % 2 == 0 ? "NET\n" : "DA\n");
  }
}