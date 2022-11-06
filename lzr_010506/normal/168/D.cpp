#include <bits/stdc++.h>
using namespace std;
const int st = 200;
int a[210];
double dp[210][210][410], p[210];
int main()
{
    int n,l,k,x;
    double ans = 0;
    scanf("%d%d%d", &n, &l, &k);;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        p[i] = x / 100.0;
    }
    for(int i = 1; i <= n; i ++)
        scanf("%d",&a[i]);
    
    const int end = st + 200;
    dp[0][0][st + k] = 1;
    for(int i = 1; i <= n; i ++)
    	for(int j = 0; j < i; j ++)
      		for(int k = 0; k <= end; k ++)
     		{
           		if(a[i] != -1)
           		{
            		int x = min(end, k + a[i]);
              		dp[i][j + 1][x] += dp[i - 1][j][k] * p[i];
           		}
           		else if(k > 0) dp[i][j + 1][k - 1] += dp[i - 1][j][k] * p[i];
           		dp[i][j][k] += dp[i - 1][j][k] * (1 - p[i]);
        	}
    for(int i = l; i <= n; i ++)
        for(int j = st; j <= end; j ++)
        	ans += dp[n][i][j];
    printf("%.8lf\n", ans);
    return 0;
}