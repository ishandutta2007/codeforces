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
const int n = 120;
long long dp[125][125];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int q;
    scanf("%d",&q);
    int tt;
    for (tt=0;tt<q;tt++)
    {
        int a,b;
        long long t;
        scanf("%lld%d%d",&t,&a,&b);
        t = t-a-b;
        if (t<0)
        {
            puts("No");
            continue;
        }
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0]=t;
        for (i=0;i<=a;i++)
        {
            for (j=0;j<=b;j++)
            {
                dp[i+1][j] += dp[i][j] / 2;
                dp[i][j+1] += (dp[i][j] + 1) / 2;
            }
        }
        int nowx = 0, nowy = 0;
        for (;;)
        {
            if ((nowx == a) && (nowy == b))
            {
                puts("Yes");
                break;
            }
            if ((nowx > a) || (nowy > b))
            {
                puts("No");
                break;
            }
            if (dp[nowx][nowy] % 2 == 1)
            {
                nowx++;
            }
            else
            {
                nowy++;
            }
        }
    }
    
    return 0;
}