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
char a[200005];
int b[200005];
int dp[200005][2];
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
        int n;
        scanf("%d",&n);
        int i;
        scanf("%s",a);
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for (i=0;i<n;i++)
        {
            if (a[i] == '1')
            {
                if (i == 0)
                {
                    dp[i][0] = 0;
                    dp[i][1] = b[i];
                }
                else
                {
                    dp[i][0] = dp[i-1][0] + b[i-1];
                    dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + b[i];
                }
            }
            else
            {
                if (i == 0)
                {
                    dp[i][0] = 0;
                    dp[i][1] = 0;
                }
                else
                {
                    dp[i][0] = max(dp[i-1][0], dp[i-1][1]); 
                    dp[i][1] = 0;
                }
            }
        }
        printf("%d\n",max(dp[n-1][0], dp[n-1][1]));
    }
    return 0;
}