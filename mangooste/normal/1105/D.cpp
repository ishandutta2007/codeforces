#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, p;
vector<int> s;
vector<string> a;
vector<vector<char>> used;
vector<deque<pair<int, int>>> q;
vector<vector<vector<int>>> when;
vector<int> ans;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> p;
  s.resize(p);
  for (auto &el : s) {
    cin >> el;
  }
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  when.assign(n, vector<vector<int>>(m, vector<int>(p, -1)));
  used.assign(n, vector<char>(m, 0));
  q.resize(p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ('1' <= a[i][j] && a[i][j] <= '9') {
        used[i][j] = 1;
        q[a[i][j] - '1'].push_back(make_pair(i, j));
        when[i][j][a[i][j] - '1'] = 0;
      } else if (a[i][j] == '#') {
        used[i][j] = 1;
      }
    }
  }
  ans.assign(p, 0);
  for (int i = 0, cnt = 0, cur = 1; cnt < p; i = (i + 1) % p, cnt = (cur == 0 ? 0 : cnt + 1), cur = 1) {
    for (auto &[x, y] : q[i]) {
      when[x][y][i] = 0;
    }
    while (!q[i].empty()) {
      auto [x, y] = q[i].front();
      if (when[x][y][i] == s[i]) {
        break;
      }
      cur = 0;
      ans[i]++;
      q[i].pop_front();
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (abs(dx) + abs(dy) == 1) {
            int xx = x + dx;
            int yy = y + dy;
            if (0 <= xx & xx < n && 0 <= yy && yy < m) {
              if (!used[xx][yy]) {
                when[xx][yy][i] = when[x][y][i] + 1;
                used[xx][yy] = 1;
                q[i].push_back(make_pair(xx, yy));
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < p; i++) {
    ans[i] += q[i].size();
  }
  for (auto &el : ans) {
    cout << el << ' ';
  }
  cout << '\n';
}