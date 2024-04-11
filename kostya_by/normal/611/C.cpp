#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 505;

char a[MAX_N][MAX_N];

int f[MAX_N][MAX_N];
int g[MAX_N][MAX_N];

int fsum(int c[][MAX_N], int r1, int c1, int r2, int c2) {
  return c[r2][c2] - c[r1 - 1][c2] - c[r2][c1 - 1] + c[r1 - 1][c1 - 1];
}

void solve() {
  int w, h; scanf("%d%d", &w, &h);

  for (int i = 1; i <= w; i++) {
    scanf("%s", a[i] + 1);
  }

  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= h; j++) {
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (a[i][j] == '.' && a[i][j - 1] == '.');
      g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + (a[i][j] == '.' && a[i - 1][j] == '.');
    }
  }

  int q; scanf("%d", &q);

  for (int it = 0; it < q; it++) {
    int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    int answer = 0;
    if (r1 < r2) {
      answer += fsum(g, r1 + 1, c1, r2, c2);
    }

    if (c1 < c2) {
      answer += fsum(f, r1, c1 + 1, r2, c2);
    }

    printf("%d\n", answer);
  }
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}