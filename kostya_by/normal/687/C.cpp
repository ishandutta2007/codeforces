#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 505;
const int MAX_K = 505;

bool f[2][MAX_K][MAX_K];

int c[MAX_N];

void solve() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }

  memset(f, false, sizeof(f));

  f[0][0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= j; l++) {
        if (!f[0][j][l]) {
          continue;
        }

        f[1][j][l] = true;
        if (j + c[i] <= k) {
          f[1][j + c[i]][l] = true;
          f[1][j + c[i]][l + c[i]] = true;
        }
      }
    }

    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= j; l++) {
        f[0][j][l] = f[1][j][l];
        f[1][j][l] = false;
      }
    }
  }

  vector<int> answer;
  for (int i = 0; i <= k; i++) {
    if (f[0][k][i]) {
      answer.push_back(i);
    }
  }

  printf("%d\n", (int) answer.size());
  for (int x : answer) {
    printf("%d ", x);
  }
  printf("\n");
}

int main() {
  solve();

  return 0;
}