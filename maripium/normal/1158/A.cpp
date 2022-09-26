#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m;
int b[N], g[N];

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; ++i) scanf("%d", b + i);
   for (int i = 1; i <= m; ++i) scanf("%d", g + i);
   sort(b + 1, b + 1 + n);
   sort(g + 1, g + 1 + m);
   if (b[n] > g[1]) { puts("-1"); return 0; }
   long long ans = 0;
   for (int i = 1; i <= n; ++i) ans += (long long) m * b[i];
   for (int i = 1; i <= m; ++i) ans += g[i] - b[n];
   if (b[n] != g[1]) ans += b[n] - b[n - 1];
   printf("%lld\n", ans);
}