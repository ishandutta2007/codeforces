#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5050;
const int MOD = 1000000007;

int n;
int lcp[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

char s[MAX_N];

bool less_than(int l1, int r1, int l2, int r2) {
  if (l1 + lcp[l1][l2] > r1) {
    return false;
  }

  return s[l1 + lcp[l1][l2]] < s[l2 + lcp[l1][l2]];
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);

  for (int i = n; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      if (s[i] == s[j]) {
        lcp[i][j] = lcp[j][i] = 1 + lcp[i + 1][j + 1];
      } else {
        lcp[i][j] = lcp[j][i] = 0;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    f[1][i] = 1;
  }

  for (int r = 1; r < n; r++) {
    if (s[r + 1] == '0') {
      continue;
    }

    int sum = 0;
    int last_rs = -1;

    for (int l = r; l >= 1; l--) {
      int len = r - l + 1;

      int ls = r + 1;
      int rs = r + len;
      last_rs = rs;

      if (rs > n) {
        break;
      }

      if (less_than(l, r, ls, rs)) {
        (sum += f[l][r]) %= MOD;
        (f[ls][rs] += sum) %= MOD;
      } else {
        (f[ls][rs] += sum) %= MOD;
        (sum += f[l][r]) %= MOD;
      }
    }

    for (int i = last_rs + 1; i <= n; i++) {
      (f[r + 1][i] += sum) %= MOD;
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j++) {
  //     cerr << i << " " << j << " " << f[i][j] << "\n";
  //   }
  // }

  int answer = 0;
  for (int l = 1; l <= n; l++) {
    (answer += f[l][n]) %= MOD;
  }

  printf("%d\n", answer);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}