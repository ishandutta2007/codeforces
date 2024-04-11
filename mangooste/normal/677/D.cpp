#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = (int)1e9;

int n, m, p;
vector<vector<int>> a;
vector<vector<pair<int, int>>> where;
vector<vector<int>> dp, dist;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> p;
  a.assign(n, vector<int>(m, 0));
  where.assign(p, vector<pair<int, int>>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
      where[a[i][j]].emplace_back(i, j);
    }
  }
  dp.assign(p, vector<int>());
  dp[0].assign(where[0].size(), 0);
  for (int i = 0; i < where[0].size(); i++) {
    dp[0][i] = where[0][i].first + where[0][i].second;
  }
  for (int i = 1; i < p; i++) {
    assert(where[i].size());
    dp[i].assign(where[i].size(), INF);
    if (where[i].size() * where[i].size() <= n * m * 17) {
      for (int j = 0; j < dp[i].size(); j++) {
        for (int was = 0; was < dp[i - 1].size(); was++) {
          dp[i][j] = min(dp[i][j], dp[i - 1][was] + abs(where[i][j].first - where[i - 1][was].first) + abs(where[i][j].second - where[i - 1][was].second));
        }
      }
    } else {
      dist.assign(n, vector<int>(m, INF));
      priority_queue<array<int, 3>> pq;
      for (int j = 0; j < where[i - 1].size(); j++) {
        auto [x, y] = where[i - 1][j];
        dist[x][y] = dp[i - 1][j];
        pq.push({-dist[x][y], x, y});
      }
      while (!pq.empty()) {
        array<int, 3> arr = pq.top();
        pq.pop();
        int x = arr[1], y = arr[2];
        if (dist[x][y] != -arr[0]) {
          continue;
        }
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (abs(dx) + abs(dy) == 1) {
              int xx = x + dx;
              int yy = y + dy;
              if (0 <= xx && xx < n && 0 <= yy && yy < m) {
                if (dist[xx][yy] > dist[x][y] + 1) {
                  dist[xx][yy] = dist[x][y] + 1;
                  pq.push({-dist[xx][yy], xx, yy});
                }
              }
            }
          }
        }
      }
      for (int j = 0; j < dp[i].size(); j++) {
        auto [x, y] = where[i][j];
        dp[i][j] = dist[x][y];
      }
    }
  }
  cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
}