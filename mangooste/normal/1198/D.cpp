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

int n;
vector<string> a;
const int N = 52;
int dp[N][N][N][N];
int pref[N][N];

int get_dp(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] != -1) {
    return dp[x1][y1][x2][y2];
  }
  dp[x1][y1][x2][y2] = max(x2 - x1, y2 - y1) + 1;
  if (pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1] == 0) {
    dp[x1][y1][x2][y2] = 0;
    return dp[x1][y1][x2][y2];
  }
  if (x2 - x1 >= y2 - y1) {
    for (int x = x1; x < x2; x++) {
      dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], get_dp(x1,y1,x,y2) + get_dp(x + 1,y1,x2,y2));
    }
  } else {
    for (int y = y1; y < y2; y++) {
      dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], get_dp(x1, y1, x2, y) + get_dp(x1, y + 1, x2, y2));
    }
  }
  return dp[x1][y1][x2][y2];
}

void Main() {
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pref[i + 1][j + 1] = (a[i][j] == '#' ? 1 : 0) + pref[i + 1][j] + pref[i][j + 1] - pref[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
          dp[i][j][ii][jj] = -1;
        }
      }
    }
  }
  cout << get_dp(0, 0, n - 1, n - 1) << '\n';
}