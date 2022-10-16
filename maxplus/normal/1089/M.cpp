#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

constexpr int N = 9, A = 18;

int a[N][N];

vector<int> ts;
bool vis[N];

void topsort(int v) {
  if (vis[v]) {
    return;
  }
  vis[v] = 1;
  for (int i = 0; i < N; ++i) if (a[i][v]) {
    topsort(i);
  }
  ts.push_back(v);
}

int comp[N];
vector<int> cv[N];

void clr(int v, int c) {
  if (vis[v]) {
    return;
  }
  vis[v] = 1;
  comp[v] = c;
  cv[c].push_back(v);
  for (int i = 0; i < N; ++i) if (a[v][i]) {
    clr(i, c);
  }
}

int b[N][N];
char f[A][3][A];

auto sgn(int x) {
  return (x > 0) - (x < 0);
}

void dig(int x1, int y1, int z1, int x2, int y2, int z2) {
  int dx = sgn(x2 - x1), dy = sgn(y2 - y1), dz = sgn(z2 - z1);
  f[z1][y1][x1] = '.';
  while (tuple{x1, y1, z1} != tuple{x2, y2, z2}) {
    x1 += dx, y1 += dy, z1 += dz;
    f[z1][y1][x1] = '.';
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) {
    cin >> a[i][j];
  }
  for (int i = 0; i < n; ++i) {
    topsort(i);
  }
  reverse(ts.begin(), ts.end());
  int nc = 0;
  memset(vis, 0, sizeof vis);
  for (auto i: ts) if (!vis[i]) {
    clr(i, nc++);
  }
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) if (a[i][j]) {
    b[comp[i]][comp[j]] = 1;
  }
  int xs = 2 * nc - 1;
  for (int i = 0; i < nc; ++i) {
    xs = max(xs, (int)cv[i].size());
  }
  memset(f, '#', sizeof f);
  for (int i = 0; i < nc; ++i) {
    dig(0, 0, 2 * i, xs - 1, 0, 2 * i);
    for (int j = 0; j < i; ++j) if (b[i][j]) {
      dig(2 * j, 1, 2 * i, 2 * j, 2, 2 * i);
      dig(2 * j, 2, 2 * i, 2 * j, 2, 2 * j);
      dig(2 * j, 1, 2 * j, 2 * j, 2, 2 * j);
    }
    for (int j = 0; j < cv[i].size(); ++j) {
      f[2 * i][0][j] = cv[i][j] + '1';
    }
  }
  cout << xs << " 3 " << 2 * nc - 1;
  for (int z = 2 * nc - 1; z--; ) {
    cout << '\n';
    for (int y: {0, 1, 2}) {
      for (int x = 0; x < xs; ++x) {
        cout << f[z][y][x];
      }
      cout << '\n';
    }
  }
}