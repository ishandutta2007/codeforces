#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k;
int x[N];
int l[N], r[N];

int main() {
   scanf("%d %d", &n, &k);
   for (int i = 1; i <= k; ++i) scanf("%d", x + i);
   for (int i = 1; i <= n; ++i) r[i] = 0, l[i] = k + 1;
   for (int i = 1; i <= k; ++i) {
      l[x[i]] = min(l[x[i]], i);
      r[x[i]] = max(r[x[i]], i);
   }
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = max(i - 1, 1); j <= min(n, i + 1); ++j) {
         if (l[i] > r[j]) ans++;
      }
   }
   printf("%d\n", ans);
}