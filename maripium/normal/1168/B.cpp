#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n;
char s[N];

int main() {
   scanf("%s", s + 1);
   n = strlen(s + 1);
   long long ans = 0;
   for (int i = 1; i <= n; ++i) {
      int nxt = n + 1;
      int len = min(n + 1 - i, 9);
      for (int x = 0; x < len; ++x) {
         for (int k = 1; k < len; ++k) {
            if (x + 2 * k >= len) continue;
            if (s[i + x] == s[i + x + k] && s[i + x] == s[i + x + 2 * k]) nxt = min(nxt, i + x + 2 * k);
         }
      }
      ans += n + 1 - nxt;
   }
   printf("%lld\n", ans);
}