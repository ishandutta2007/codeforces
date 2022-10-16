#include <stdio.h>

int main() {
   int n, k, i, j, cur, max;
   char str[101];
   char xx[101];
   scanf("%d%d", &n, &k);
   scanf("%s\n", str);

   for (i = 0; i + k <= n; i++) {
      for (j = 0; j < n; j++) {
        xx[j] = str[j];
        if (xx[j] == '?') {
            if (j >= i && j < i + k) {
              xx[j] = 'N';
            } else {
              xx[j] = 'Y';
            }
        }
      }
      cur = 0;
      max = 0;
      for (j = 0; j < n; j++) {
        if (xx[j] == 'N') {
          cur++;
        } else {
          cur = 0;
        }
        if (cur > max) max = cur;
      }
      if (max == k) {
        printf("YES\n");
        return 0;
      }
   }

   printf("NO\n");
   return 0;
}