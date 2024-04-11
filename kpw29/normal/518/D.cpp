#include <bits/stdc++.h>
#define maxn 2010
typedef double ld;

ld dp[maxn][maxn];
int n,t;
ld p;

int main()
{
    scanf("%d%lf%d", &n, &p, &t);
    dp[0][0]=1.;
    for (int i=1; i<=t; ++i){
        dp[i][0]=dp[i-1][0]*(1-p);
          for (int j=1; j<=n; ++j) 
            dp[i][j]=(dp[i-1][j]*(1-p))+(dp[i-1][j-1]*p);
        dp[i][n]+=dp[i-1][n]*p;
    }
    ld ret =0.;
    for (int i=1; i<=n; ++i) ret += (dp[t][i] * i);
    printf("%.9lf", ret);
}