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
long long dp[5005][2];
char a[10005];
char b[10005];
int c[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s%s",a,b);
        int i;
        for (i=0;i<n;i++)
        {
            if (a[i] != b[i])
            {
                c[i] = 1;
            }
            else
            {
                c[i] = 0;
            }
        }
        if (x<=y)
        {
            long long sum = 0;
            long long ans = 0;
            for (i=0;i<n;i++)
            {
                if (c[i] == 1)
                {
                    sum ++;
                }
            }
            if (sum % 2 == 1)
            {
                puts("-1");
                continue;
            }
            dp[0][0] = 0;
            dp[0][1] = 1000000000000000000ll;
            for (i=1;i<=n;i++)
            {
                if (c[i-1] == 0)
                {
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1] + 2 * x;
                    continue;
                }
                else
                {
                    dp[i][0] = min(dp[i-1][1] + x, dp[i-1][0] + y);
                    dp[i][1] = min(dp[i-1][0] + x, dp[i-1][1] + y); 
                }
            }
            printf("%lld\n",dp[n][0]/2);
        }
        else
        {
            long long sum = 0;
            long long ans = 0;
            for (i=0;i<n;i++)
            {
                if (c[i] == 1)
                {
                    sum ++;
                }
            }
            if (sum % 2 == 1)
            {
                puts("-1");
                continue;
            }
            if (sum == 2)
            {
                for (i=1;i<n;i++)
                {
                    if ((c[i] == 1) && (c[i-1] == 1))
                    {
                        ans = x;
                        break;
                    }
                }
                if (i==n)
                {
                    ans = y;
                }
                ans = min(ans, (long long)y*2); 
            }
            else
            {
                ans = y * sum / 2;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}