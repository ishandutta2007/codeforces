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

int n, m;
vector<string> a;
int x_now, y_now, x_need, y_need;
map<char, char> mapa;
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

void go(char dir) {
  cout << mapa[dir] << endl;
  cin >> x_now >> y_now;
  assert(x_now != -1);
  x_now--, y_now--;
  if (x_now == x_need && y_now == y_need) {
    exit(0);
  }
}

inline bool ok(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

string bfs() {
  vector<vector<int>> dist(n, vector<int>(m, n * m * 2));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
  dist[x_now][y_now] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(x_now, y_now));
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int X = x + dx[dir];
      int Y = y + dy[dir];
      if (ok(X, Y) && a[X][Y] != '*' && dist[X][Y] > dist[x][y] + 1) {
        dist[X][Y] = dist[x][y] + 1;
        parent[X][Y] = make_pair(x, y);
        q.push(make_pair(X, Y));
      }
    }
  }
  string cur = "";
  pair<int, int> where = make_pair(x_need, y_need);
  assert(dist[x_need][y_need] != 2 * n * m);
  while (where != make_pair(x_now, y_now)) {
    pair<int, int> to = parent[where.first][where.second];
    if (where.first == to.first) {
      if (where.second == to.second + 1) {
        cur.push_back('R');
      } else {
        cur.push_back('L');
      }
    } else {
      if (where.first == to.first + 1) {
        cur.push_back('D');
      } else {
        cur.push_back('U');
      }
    }
    where = to;
  }
  reverse(cur.begin(), cur.end());
  return cur;
}

void Main() {
  cin >> n >> m;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'F') {
        x_need = i;
        y_need = j;
      }
    }
  }
  mapa['U'] = 'U';
  mapa['D'] = 'D';
  mapa['L'] = 'L';
  mapa['R'] = 'R';
  x_now = y_now = 0;
  if (n != 1 && a[1][0] != '*') {
    go('D');
    if (x_now == 0 && y_now == 0) {
      mapa['D'] = 'U';
      mapa['U'] = 'D';
    }
    if (m != 1 && a[x_now][1] != '*') {
      go('R');
      if (y_now == 0) {
        mapa['R'] = 'L';
        mapa['L'] = 'R';
      }
    } else if (x_now == 1 && m != 1 && a[0][1] != '*') {
      go('U');
      go('R');
      if (y_now == 0) {
        mapa['R'] = 'L';
        mapa['L'] = 'R';
      }
    } else {
      int cur_x = x_now;
      while (cur_x < n && a[cur_x][0] == '.') {
        cur_x++;
      }
      if (cur_x != n && a[cur_x][0] == 'F') {
        while (true) {
          go('D');
        }
      }
      assert(m != 1);
      cur_x = x_now;
      while (a[cur_x][1] == '*') {
        cur_x++;
        go('D');
      }
      go('R');
      if (y_now == 0) {
        mapa['R'] = 'L';
        mapa['L'] = 'R';
      }
    }
  } else {
    go('R');
    if (y_now == 0) {
      mapa['R'] = 'L';
      mapa['L'] = 'R';
    }
    if (n != 1 && a[1][y_now] != '*') {
      go('D');
      if (y_now == 0) {
        mapa['D'] = 'U';
        mapa['U'] = 'D';
      }
    } else if (y_now == 1 && n != 1 && a[1][0] != '*') {
      go('L');
      go('D');
      if (y_now == 0) {
        mapa['D'] = 'U';
        mapa['U'] = 'D';
      }
    } else {
      int cur_y = y_now;
      while (cur_y < m && a[0][cur_y] == '.') {
        cur_y++;
      }
      if (cur_y != m && a[0][cur_y] == 'F') {
        while (true) {
          go('R');
        }
      }
      assert(n != 1);
      cur_y = y_now;
      while (a[1][cur_y] == '*') {
        cur_y++;
        go('R');
      }
      go('D');
      if (x_now == 0) {
        mapa['D'] = 'U';
        mapa['U'] = 'D';
      }
    }
  }
  string way = bfs();
  for (int i = 0; i < (int)way.size(); i++) {
    go(way[i]);
  }
  assert(false);
}