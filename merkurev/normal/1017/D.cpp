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

const int N = (1 << 12);
int cnt[N];
char str[N];

int readS(int n) {
  scanf("%s", str);
  int x = 0;
  for (int i = n - 1; i >= 0; i--) x = x * 2 + str[i] - '0';
  return x;
}

const int K = 105;

int w[K];
int sum[N];
int val[N][K];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%d", &w[i]);
  for (int i = 0; i < m; i++) {
    int x = readS(n);
    cnt[x]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++)
      if (!(i & (1 << j))) sum[i] += w[j];
  }
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < (1 << n); j++) {
      int cur = sum[i ^ j];
      if (cur < K) val[i][cur] += cnt[j];
    }
  for (int i = 0; i < (1 << n); i++)
    for (int j = 1; j < K; j++) val[i][j] += val[i][j - 1];

  for (int i = 0; i < q; i++) {
    int x = readS(n);
    int k;
    scanf("%d", &k);
    printf("%d\n", val[x][k]);
  }

  return 0;
}