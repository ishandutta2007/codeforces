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

const int N = 150;
char f[N][N];

int main() {
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", f[i]);
  }

  int mi = n, Mi = 0, mj = m, Mj = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (f[i][j] == 'B') {
        mi = min(mi, i);
        Mi = max(Mi, i);
        mj = min(mj, j);
        Mj = max(Mj, j);
      }
  printf("%d %d\n", (mi + Mi) / 2 + 1, (mj + Mj) / 2 + 1);

  return 0;
}