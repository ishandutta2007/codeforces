#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, x;
int a[N];
int l[N], r[N];
bool fl[N], fr[N];
int gl[N], gr[N];

int main() {
   scanf("%d %d", &n, &x);
   for (int i = 0; i <= x + 1; ++i) l[i] = 0, r[i] = n + 1, gl[i] = 0, gr[i] = n + 1;
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      l[a[i]] = max(l[a[i]], i);
      r[a[i]] = min(r[a[i]], i);
   }
   fl[0] = true;
   for (int i = 1; i <= x; ++i) {
      fl[i] = fl[i - 1] & (r[i] > gl[i - 1]);
      // if (fl[i]) printf("%d ", i);
      gl[i] = max(l[i], gl[i - 1]);
   }
   fr[x + 1] = true;
   for (int i = x; i > 0; --i) {
      fr[i] = fr[i + 1] & (l[i] < gr[i + 1]);
      // if (fr[i]) printf("%d ", i);
      gr[i] = min(r[i], gr[i + 1]);
   }

   long long ans = 0;

   for (int i = 0; i < x; ++i) {
      if (!fl[i]) break;
      int l = i + 2, r = x + 1;
      while (l < r) {
         int md = (l + r) >> 1;
         if (fr[md] && ::gr[md] > ::gl[i]) r = md;
         else l = md + 1;
      }
      // printf("%d %d\n", i + 1, l - 1);
      ans += x + 2 - l;
   }

   printf("%lld\n", ans);
}