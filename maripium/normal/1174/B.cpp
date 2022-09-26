#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n;
int a[N];

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
   }
   bool all = true;
   for (int i = 2; i <= n; ++i) {
      if (a[i] % 2 != a[1] % 2) {
         all = false;
      }
   }
   if (all) {
      for (int i = 1; i <= n; ++i) {
         printf("%d ", a[i]);
      }
   } else {
      sort(a + 1, a + n + 1);
      for (int i = 1; i <= n; ++i) {
         printf("%d ", a[i]);
      }
   }
}