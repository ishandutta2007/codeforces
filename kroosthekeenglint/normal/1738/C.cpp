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
int dp[105][105][2];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i,j;
    dp[0][0][0] = 1;
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            if ((i==0) && (j==0))
            {
                continue;
            }
            int k,l;
            for (k=0;k<2;k++)
            {
                dp[i][j][k] = 0;
                for (l=0;l<2;l++)
                {
                    int a_i = i;
                    int a_j = j;
                    int a_k = k;
                    if (l == 0)
                    {
                        a_i --;
                        a_k^=1;
                    }
                    else
                    {
                        a_j --;
                    }
                    if ((a_i < 0) || (a_j < 0))
                    {
                        continue;
                    }
                    if ((a_i == 0) && (a_j == 0))
                    {
                        dp[i][j][k] = dp[0][0][a_k];
                        break;
                    }
                    int val = 1;
                    int ii;
                    for (ii=0;ii<2;ii++)
                    {
                        int b_i = a_i;
                        int b_j = a_j;
                        if (ii == 0)
                        {
                            b_i --;
                        }
                        else
                        {
                            b_j --;
                        }
                        if ((b_i < 0) || (b_j < 0))
                        {
                            continue;
                        }
                        val = min(val, dp[b_i][b_j][a_k]);
                    }
                    dp[i][j][k] = max(dp[i][j][k], val);
                }
            }
        }
    }
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        int i;
        int odd = 0;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x%2 != 0)
            {
                odd++;
            }
        }
        if (dp[odd][n-odd][0])
        {
            puts("Alice");
        }
        else
        {
            puts("Bob");
        }
    }
    return 0;
}