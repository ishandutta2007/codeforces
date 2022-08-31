/**
 *    author:  tourist
 *    created: 24.04.2022 15:24:29       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    const int R = 23;
    const int P = 360;
    vector<vector<bool>> ver(R, vector<bool>(P, true));
    vector<vector<bool>> hor(R, vector<bool>(P, true));
    for (int i = 0; i < n; i++) {
      string t;
      cin >> t;
      if (t == "C") {
        int r, p1, p2;
        cin >> r >> p1 >> p2;
        while (p1 != p2) {
          ver[r][p1] = false;
          p1 = (p1 + 1) % P;
        }
      } else {
        int r1, r2, p;
        cin >> r1 >> r2 >> p;
        for (int j = r1; j < r2; j++) {
          hor[j][p] = false;
        }
      }
    }
    vector<vector<bool>> was(R, vector<bool>(P));
    vector<pair<int, int>> que;
    auto Put = [&](int x, int y) {
      if (!was[x][y]) {
        que.emplace_back(x, y);
        was[x][y] = true;
      }
    };
    Put(0, 0);
    bool found = false;
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b].first;
      int j = que[b].second;
      if (i == R - 1) {
        found = true;
        break;
      }
      if (hor[i][j]) {
        Put(i, (j + P - 1) % P);
      }
      if (hor[i][(j + 1) % P]) {
        Put(i, (j + 1) % P);
      }
      if (i < R - 1 && ver[i + 1][j]) {
        Put(i + 1, j);
      }
      if (i > 0 && ver[i][j]) {
        Put(i - 1, j);
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}