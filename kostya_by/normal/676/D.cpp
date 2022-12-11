
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1001;
const int INF = 1e9;
int n, m;

string a[MAXN][4];
bool used[MAXN][MAXN][4];
int d[MAXN][MAXN][4];

char rotate(char c) {
  switch (c) {
    case '+' :
      return '+';
    case '-':
      return '|';
    case '|':
      return '-';
    case '^':
      return '>';
    case '>':
      return 'v';
    case '<':
      return '^';
    case 'v':
      return '<';
    case 'L':
      return 'U';
    case 'R':
      return 'D';
    case 'U':
      return 'R';
    case 'D':
      return 'L';
    case '*':
      return '*';
  }
}

string allowed_right = ">+-ULD";
string allowed_left = "<+-UDR";
string allowed_up = "^+|DLR";
string allowed_down = "v+|LUR";

bool can_go_right_on_layer(int x, int y, int layer) {
  if (y + 1 >= m) return false;
  char src = a[x][layer][y];
  char dst = a[x][layer][y + 1];
  if (allowed_right.find(src) != -1 && allowed_left.find(dst) != -1) {
    return true;
  }
  return false;
}

bool can_go_left_on_layer(int x, int y, int layer) {
  if (y - 1 < 0) return false;
  char src = a[x][layer][y];
  char dst = a[x][layer][y - 1];
  if (allowed_left.find(src) != -1 && allowed_right.find(dst) != -1) {
    return true;
  }
  return false;
}

bool can_go_up_on_layer(int x, int y, int layer) {
  if (x - 1 < 0) return false;
  char src = a[x][layer][y];
  char dst = a[x - 1][layer][y];
  if (allowed_up.find(src) != -1 && allowed_down.find(dst) != -1) {
    return true;
  }
  return false;
}

bool can_go_down_on_layer(int x, int y, int layer) {
  if (x + 1 >= n) return false;
  char src = a[x][layer][y];
  char dst = a[x + 1][layer][y];

  if (allowed_down.find(src) != -1 && allowed_up.find(dst) != -1) {
    return true;
  }
  return false;
}


queue<pair<pair<int, int>, int>> q;

pair<pair<int, int>, int> bundle(int x, int y, int layer) {
  return make_pair(make_pair(x, y), layer);
}

void bfs() {
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int layer = q.front().second;
    q.pop();
    int d_to_cur_cell = d[x][y][layer];
    used[x][y][layer] = true;

    if (!used[x][y][(layer + 1) % 4]) {
      d[x][y][(layer + 1) % 4] = d_to_cur_cell + 1;
used[x][y][(layer + 1) % 4] = true;
      //cout << "switching layer in " << x << " " << y << " from " << layer << endl;
      q.push(bundle(x, y, (layer + 1) % 4));
    }

    // go down
    if (x + 1 < n && !used[x + 1][y][layer] && can_go_down_on_layer(x, y, layer)) {
      d[x + 1][y][layer] = d_to_cur_cell + 1;
used[x + 1][y][layer] = true;
      //cout << "going down from " << x << " " << y << " layer " << layer << endl;
      q.push(bundle(x + 1, y, layer));
    }

    // go up
    if (x - 1 >= 0 && !used[x - 1][y][layer] && can_go_up_on_layer(x, y, layer)) {
      d[x - 1][y][layer] = d_to_cur_cell + 1;
used[x - 1][y][layer] = true;
      //cout << "going up from " << x << " " << y << " layer " << layer << endl;
      q.push(bundle(x - 1, y, layer));
    }

    // go right
    if (y + 1 < m && !used[x][y + 1][layer] && can_go_right_on_layer(x, y, layer)) {
      d[x][y + 1][layer] = d_to_cur_cell + 1;
used[x][y + 1][layer] = true;
      //cout << "going right from " << x << " " << y << " layer " << layer << endl;
      q.push(bundle(x, y + 1, layer));
    }

    // go left
    if (y - 1 >= 0 && !used[x][y - 1][layer] && can_go_left_on_layer(x, y, layer)) {
      d[x][y - 1][layer] = d_to_cur_cell + 1;
used[x][y - 1][layer] = true;
      //cout << "going left from " << x << " " << y << " layer " << layer << endl;
      q.push(bundle(x, y - 1, layer));
    }
  }
}

void init_d() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 4; ++k) {
        d[i][j][k] = -1;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    cin >> a[i][0];
  }

  for (int k = 1; k < 4; ++k) {
    for (int i = 0; i < n; ++i) {
      string cur = a[i][k - 1];
      for (int j = 0; j < m; ++j) {
        cur[j] = rotate(cur[j]);
      }
      a[i][k] = cur;
    }
  }

  int x_t, y_t;
  int x_m, y_m;

  scanf("%d%d", &x_t, &y_t);
  scanf("%d%d", &x_m, &y_m);

  --x_t, --x_m, --y_t, --y_m;

  init_d();
  d[x_t][y_t][0] = 0;

  q.push(bundle(x_t, y_t, 0));
used[x_t][y_t][0] = true;
  bfs();

  int ans = INF;
  for (int k = 0; k < 4; ++k) {
    if (d[x_m][y_m][k] != -1) {
      ans = min(ans, d[x_m][y_m][k]);
    }
  }

  cout << (ans == INF ? -1 : ans) << "\n";
  return 0;
}