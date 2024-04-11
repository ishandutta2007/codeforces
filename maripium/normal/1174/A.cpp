#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n;
int a[N];

int main() {
   scanf("%d", &n);
   int start_sum = 0;
   for (int i = 1; i <= 2 * n; ++i) {
      scanf("%d", a + i);
      if (i <= n) start_sum += a[i];
   }
   sort(a + 1, a + 1 + n + n);
   if (accumulate(a + 1, a + n + 1, 0) != start_sum) {
      for (int i = 1; i <= n + n; ++i) {
         printf("%d ", a[i]);
      }
      return 0;
   }
   reverse(a + 1, a + n + n + 1);
   if (accumulate(a + 1, a + n + 1, 0) != start_sum) {
      for (int i = 1; i <= n + n; ++i) {
         printf("%d ", a[i]);
      }
      return 0;
   }
   puts("-1");
}