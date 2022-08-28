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

const int N = (int)2e5 + 100;
long long b[N], a[N];

int fix(int i, int n) { return ((i % n) + n) % n; }

void increase(long long &x, long long to, long long d) {
  long long k = (to + 1 - x + d - 1) / d;
  x += max(0LL, k) * d;
  while (x <= to) x += d;
}

int main() {
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);

  bool all0 = true;
  for (int i = 0; i < n; i++)
    if (b[i]) all0 = false;
  if (all0) {
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("1 ");
    printf("\n");
    return 0;
  }

  int s = -1;
  for (int i = 0; i < n; i++)
    if (b[i] > b[fix(i - 1, n)]) s = (i + 1) % n;

  if (s == -1) {
    printf("NO\n");
    return 0;
  }

  long long mx = 0;
  a[fix(s - 1, n)] = b[fix(s - 1, n)];
  for (int it = 0; it < n - 1; it++) {
    int i = fix(s - it - 1, n), pi = fix(s - it - 2, n),
        ppi = fix(s - it - 3, n);
    a[pi] = b[pi];
    increase(a[pi], b[ppi], a[i]);
  }
  for (int i = 0; i < n; i++)
    if (i != s) mx = max(mx, a[i]);
  increase(a[s], mx, a[fix(s + 1, n)]);

#ifdef LOCAL
  eprintf("%lld\n", a[0]);
  for (int i = 0; i < n; i++)
    if (a[i] % a[fix(i + 1, n)] != b[i]) throw;
#endif
  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%lld ", a[i]);
  printf("\n");

  return 0;
}