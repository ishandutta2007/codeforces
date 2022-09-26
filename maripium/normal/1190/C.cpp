#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k;
char s[N];

int main() {
   scanf("%d %d %s", &n, &k, s + 1);
   for (int rot = 0; rot < 2; ++rot) {
      int l = n + 1, r = 0;
      for (int i = 1; i <= n; ++i) {
         if (s[i] == '0') {
            l = min(l, i);
            r = max(r, i);
         }
      }
      if (r - l + 1 <= k) {
         puts("tokitsukaze");
         return 0;
      }
      for (int i = 1; i <= n; ++i) {
         s[i] = '0' + '1' - s[i];
      }
   }
   bool lose = true;
   for (int rot = 0; rot < 2; ++rot) {
      int l = n + 1, r = 0;
      for (int i = 1; i <= n; ++i) {
         if (s[i] == '0') {
            l = min(l, i);
            r = max(r, i);
         }
      }
      if (r - l - 1 >= k) {
         lose = false;
      }
      l = n + 1, r = 0;
      for (int i = k + 1; i <= n; ++i) {
         if (s[i] == '0') {
            l = min(l, i);
            r = max(r, i);
         }
      }
      if (r - l + 1 > k) {
         lose = false;
      }
      l = n + 1, r = 0;
      for (int i = 1; i <= n - k; ++i) {
         if (s[i] == '0') {
            l = min(l, i);
            r = max(r, i);
         }
      }
      if (r - l + 1 > k) {
         lose = false;
      }
      for (int i = 1; i <= n; ++i) {
         s[i] = '0' + '1' - s[i];
      }
   }
   if (lose) {
      puts("quailty");
   } else {
      puts("once again");
   }
   return 0;
}