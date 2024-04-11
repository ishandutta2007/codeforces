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
int a[1005][1005];
int max_dp[1005][1005];
int min_dp[1005][1005];
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
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            int j;
            for (j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (i==0)
                {
                    if (j==0)
                    {
                        max_dp[i][j]=a[i][j];
                        min_dp[i][j]=a[i][j];
                    }
                    else
                    {
                        max_dp[i][j]=max_dp[i][j-1]+a[i][j];
                        min_dp[i][j]=min_dp[i][j-1]+a[i][j];
                    }
                }
                else
                {
                    if (j==0)
                    {
                        max_dp[i][j]=max_dp[i-1][j]+a[i][j];
                        min_dp[i][j]=min_dp[i-1][j]+a[i][j];
                    }
                    else
                    {
                        max_dp[i][j]=max(max_dp[i][j-1],max_dp[i-1][j])+a[i][j];
                        min_dp[i][j]=min(min_dp[i][j-1],min_dp[i-1][j])+a[i][j];
                    }
                }
            }
        }
        if ((min_dp[n-1][m-1]<=0)&&(0<=max_dp[n-1][m-1])&&((n+m)%2==1))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}