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

const int INF = (int)1e9 + 100;

const int N = (int)2e5 + 100;
int a[N];

int main() {
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);

  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + 2 * n);
  int maxX = a[n - 1];
  int minX = a[0];
  int maxY = a[2 * n - 1];
  int minY = a[n];
  long long ans = (maxX - minX) * 1LL * (maxY - minY);

  for (int i = 1; i + n < 2 * n; i++) {
    minX = a[0];
    maxX = a[2 * n - 1];
    minY = a[i];
    maxY = a[i + n - 1];
    long long cur = (maxX - minX) * 1LL * (maxY - minY);
    ans = min(ans, cur);
  }

  printf("%lld\n", ans);

  return 0;
}