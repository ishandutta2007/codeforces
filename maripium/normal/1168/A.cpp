#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n, m;
int a[N];

bool solve(int md) {
   int last = 0;
   for (int i = 1; i <= n; ++i) {
      if (a[i] + md < last) return false;
      if (a[i] < last) continue;
      else if (a[i] + md - m >= last) continue;
      else last = a[i];
   }
   return true;
}

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; ++i) scanf("%d", a + i);
   int l = 0, r = m - 1;
   while (l < r) {
      int md = (l + r) >> 1;
      if (solve(md)) r = md;
      else l = md + 1;
   }
   printf("%d\n", l);
}