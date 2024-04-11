#include <bits/stdc++.h>

using namespace std;

const int N = 20200;
const int inf = 1e9;

struct Line {
   int a, b;
   Line(int a = 0, int b = 0) : a(a), b(b) {}
   int f(int x) { return a * x + b; }
};

bool bad(Line x, Line y, Line z) {
   return (long long) (z.b - x.b) * (x.a - y.a) <= (long long) (y.b - x.b) * (x.a - z.a);
}

struct ConvexHull {
   Line a[N];
   int sz;
   void reset() { sz = 0; }
   void add(Line z) {
      while (sz > 0 && z.a == a[sz].a) {
         z.b = min(z.b, a[sz].b);
         --sz;
      }
      while (sz > 1 && bad(a[sz - 1], a[sz], z)) {
         --sz;
      }
      a[++sz] = z;
   }
   int get(int x) {
      if (!sz) return inf;
      int l = 1, r = sz;
      while (l < r) {
         int md = (l + r) >> 1;
         if (a[md].f(x) > a[md + 1].f(x)) l = md + 1;
         else r = md;
      }
      return a[l].f(x);
   }
} ch;

int n, k;
int a[N], f[N], nf[N];
int pref[N], suf[N];

void solve(int l, int r) {
   if (l == r) return;
   int md = (l + r) >> 1;
   solve(l, md);
   solve(md + 1, r);
   suf[md + 1] = 0;
   for (int i = md; i >= l; --i) {
      suf[i] = max(suf[i + 1], a[i]);
   }
   pref[md] = 0;
   for (int i = md + 1; i <= r; ++i) {
      pref[i] = max(pref[i - 1], a[i]);
   }
   // max is suf
   ch.reset();
   int ptr = l;
   for (int i = r; i > md; --i) {
      while (ptr <= md && suf[ptr + 1] >= pref[i]) {
         if (f[ptr] < inf) ch.add(Line(suf[ptr + 1], f[ptr] - ptr * suf[ptr + 1]));
         ++ptr;
      }
      nf[i] = min(nf[i], ch.get(i));
   }
   // max is pref;
   ch.reset();
   ptr = md;
   for (int i = md + 1; i <= r; ++i) {
      while (ptr >= l && suf[ptr + 1] <= pref[i]) {
         if (f[ptr] < inf) ch.add(Line(ptr, f[ptr]));
         --ptr;
      }
      nf[i] = min(nf[i], ch.get(-pref[i]) + i * pref[i]);
   }
}

int main() {
   scanf("%d %d", &n, &k);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
   }
   for (int i = 1; i <= n; ++i) {
      pref[i] = max(pref[i - 1], a[i]);
      f[i] = i * pref[i];
   }
   for (int i = 2; i <= k; ++i) {
      for (int j = 1; j <= n; ++j) nf[j] = inf;
      solve(1, n);
      for (int j = 1; j <= n; ++j) f[j] = nf[j];
   }
   printf("%d\n", f[n]);
}