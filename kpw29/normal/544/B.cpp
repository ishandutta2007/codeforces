#include <bits/stdc++.h>
#define maxn 1010
int t[maxn][maxn];
int main()
{
    int n,k;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j)
      {
        int ile = (i + j) % 2;
        if (ile == 0 && k > 0) t[i][j] = 1, --k;
      }
    if (k > 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j) if (t[i][j]) printf("L");
        else printf("S");
        puts("");
    }
}