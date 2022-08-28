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

const int N = (int)1e5 + 100;
char a[N], b[N];
long long cnt[2][2];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  scanf("%s%s", a, b);

  for (int i = 0; i < n; i++) {
    int xa = a[i] - '0';
    int xb = b[i] - '0';
    cnt[xa][xb]++;
  }

  long long ans =
      cnt[0][1] * cnt[1][0] + cnt[0][0] * cnt[1][1] + cnt[0][0] * cnt[1][0];
  printf("%lld\n", ans);

  return 0;
}