#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n, x;
long long a[N];
long long f[N][3];

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 0; i <= n; ++i) {
    f[i][0] = f[i][1] = f[i][2] = -1e18;
  }
  long long ans = 0;
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = max(f[i - 1][0], 0LL) + a[i];
    ans = max(ans, f[i][0]);
    f[i][1] = max(f[i - 1][0], max(f[i - 1][1], 0LL)) + a[i] * x;
    ans = max(ans, f[i][1]);
    f[i][2] = max(f[i - 1][1], max(f[i - 1][2], 0LL)) + a[i];
    ans = max(ans, f[i][2]);
  }
  printf("%lld\n", ans);
}