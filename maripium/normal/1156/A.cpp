#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main() {
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
   }
   for (int i = 2; i <= n; ++i) {
      if (a[i] + a[i - 1] == 5) {
         puts("Infinite");
         return 0;
      }
   }
   int ans = 0;
   for (int i = 2; i <= n; ++i) ans += a[i] + a[i - 1];
   for (int i = 3; i <= n; ++i) {
      if (a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3) ans--;
   }
   puts("Finite");
   printf("%d\n", ans);
}