#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;

void add(int &x,int y) {
  x += y;
  if (x >= mod) x -= mod;
}

int f[N][N];

int main() {
  int n;
  scanf("%d", &n);
  n = n + n;
  f[0][0] = 1;
  auto ok = [&](int i,int j) {
    return j <= i && j <= n - i;
  };

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j) add(f[i][j - 1], f[i - 1][j]);
      add(f[i][j + 1], f[i - 1][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    for (int j = 0; j <= n; ++j) {
      if (ok(i, j)) add(ans, f[i][j]);
    }
  }
  printf("%d\n", ans);
}