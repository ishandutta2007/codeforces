#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[505];
int dp[505][1005][2];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;
    int j;
    int ans = 0; 
    for (i=1;i<=n;i++)
    {
        for (j=0;j<=i;j++)
        {
            if (j != 0)
            {
                dp[i][j][0] = dp[i-1][j-1][0] + a[i-1]; // not change
            }
            int k;
            for (k=0;k<i;k++)
            {
                if (dp[i-k-1][j+k][0] != -1)
                {
                    dp[i][j][1] = max(dp[i][j][1], dp[i-k-1][j+k][0] + a[i] * (k + 1));
                }
                if (dp[i-k-1][j+k][1] != -1)
                {
                    dp[i][j][1] = max(dp[i][j][1], dp[i-k-1][j+k][1] + a[i] * (k + 1));
                }
            }
            for (k=0;k<i-1;k++)
            {
                if (dp[i-k-2][j+k][0] != -1)
                {
                    dp[i][j][0] = max(dp[i][j][0], dp[i-k-2][j+k][0] + a[i-1] * (k + 2));
                }
                if (dp[i-k-2][j+k][1] != -1)
                {
                    dp[i][j][0] = max(dp[i][j][0], dp[i-k-2][j+k][1] + a[i-1] * (k + 2));
                }
            }
            for (k=1;k<i;k++)
            {
                if (dp[k][j][0] != -1)
                {
                    dp[i][j][0] = max(dp[i][j][0], dp[k][j][0] + a[k-1] * (i - k));
                }
            }
            ans = max(ans, dp[i][j][0]);
            ans = max(ans, dp[i][j][1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}