#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 5005;
int h[N];
long long dp[2][N][3];

void upd(long long &a, long long b) {
  if (b == -1) return;
  if (a == -1 || a > b) a = b;
}

int diff(int x, int s) {
  int nx = min(s, x - 1);
  return s - nx;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);

  memset(dp, -1, sizeof dp);
  int t = 0, nt = 1;
  dp[t][0][2] = 0;

  for (int i = 1; i <= n; i++) {
    memset(dp[nt], -1, sizeof dp[nt]);
    for (int k = 0; k <= i; k++)
      for (int x = 0; x <= 2; x++) {
        long long cur = dp[t][k][x];
        if (cur == -1) continue;
        if (x == 0) {
          upd(dp[nt][k][1], cur);
        } else if (x == 1) {
          upd(dp[nt][k][2], cur);
          upd(dp[nt][k + 1][0], cur + diff(h[i], min(h[i - 1], h[i - 2] - 1)) +
                                    diff(h[i], h[i + 1]));
        } else if (x == 2) {
          upd(dp[nt][k][2], cur);
          upd(dp[nt][k + 1][0],
              cur + diff(h[i], h[i - 1]) + diff(h[i], h[i + 1]));
        }
      }
    swap(t, nt);
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    long long x = -1;
    for (int k = 0; k <= 2; k++) upd(x, dp[t][i][k]);
    printf("%lld ", x);
  }
  printf("\n");
  return 0;
}