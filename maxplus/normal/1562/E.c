#include <stdio.h>

int main()
{
  enum { N = (int)5e3 + 2 };
  int t, n;
  char s[N] = {};
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, s + 1);
    short lcp[N] = {};
    int dp[N] = {};
    for (int i = ++n - 1; i > -1; --i) {
      for (int j = i + 1; j < n; ++j) {
        lcp[j] = (1 + lcp[j + 1]) & -(s[i] == s[j]);
        int t = dp[j] + n - j - lcp[j] - dp[i];
        dp[i] += t & ~(t >> 31) & -(s[i + lcp[j]] < s[j + lcp[j]]);
      }
    }
    printf("%d\n", dp[0]);
  }
}