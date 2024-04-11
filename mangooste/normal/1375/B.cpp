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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &el : a) {
      for (auto &ell : el) {
        cin >> ell;
      }
    }
    vector<vector<int>> ans(n, vector<int>(m));
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (abs(di) + abs(dj) != 1) {
              continue;
            }
            int ii = i + di;
            int jj = j + dj;
            if (0 <= ii && ii < n && 0 <= jj && jj < m) {
              cur++;
            }
          }
        }
        ok &= (a[i][j] <= cur);
        ans[i][j] = cur;
      }
    }
    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto el : ans) {
        for (auto ell : el) {
          cout << ell << ' ';
        }
        cout << '\n';
      }
    }
  }
}