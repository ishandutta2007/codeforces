#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, c, a[500001], f[500011], v[500001], r[500001], w[500001];

int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) 
    f[i] = f[i - 1] + (a[i] == c),
    v[i] = ++w[a[i]];

  int ans = f[n];
  memset(r, 128, sizeof(r));
  f[n + 1] = f[n];
  for (int i = n; i; --i)
    r[a[i]] = max(r[a[i]], f[n] - f[i] + v[i]),
    ans = max(ans, r[a[i]] - (v[i] - 1) + f[i - 1]);
  printf("%d\n", ans);
}