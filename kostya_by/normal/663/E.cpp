#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 21;
const int MAX_M = 1000100;

void rec(int f[][MAX_N], int n, int l, int r) {
  if (l == r) {
    return;
  }

  int x = (l + r) / 2;
  rec(f, n, l, x);
  rec(f, n, x + 1, r);

  int len = r - x;
  for (int i = l; i <= x; i++) {
    for (int j = n - 1; j >= 0; j--) {
      f[i][j + 1] += f[i + len][j];
      f[i + len][j + 1] += f[i][j];
    }
  }
}

// f[i] - number of masks equal to i 
void count_xor_ones(int n, int a[], int f[][MAX_N]) {
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = 0;
    }

    f[i][0] = a[i];
  }

  rec(f, n, 0, (1 << n) - 1);
}

int n;
int columns[MAX_M];
int a[1 << MAX_N];
int f[1 << MAX_N][MAX_N];

char buffer[MAX_M];

void solve() {
  int n, m; scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s", buffer);
    for (int j = 0; j < m; j++) {
      if (buffer[j] == '1') {
        columns[j] += 1 << i;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    a[columns[i]] += 1;
  }

  count_xor_ones(n, a, f);

  int answer = n * m;
  for (int mask = 0; mask < (1 << n); mask++) {
    int penalty = 0;
    for (int i = 0; i <= n; i++) {
      penalty += f[mask][i] * min(i, n - i);
    }

    answer = min(answer, penalty);
  }

  printf("%d\n", answer);
}

int main() {
  solve();

  return 0;
}