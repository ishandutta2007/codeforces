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
int dp[200005];
int last_dp[200005];
int ans[200005];
const int modo=998244353;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d%d",&n,&k);
    last_dp[0] = 1;
    int i;
    bool flag = true;
    for (;flag;)
    {
        flag = false;
        for (i=0;i<=n-k;i++)
        {
            dp[i+k] = dp[i+k] + dp[i];
            if (dp[i+k] >= modo) dp[i+k] -= modo;
            dp[i+k] = dp[i+k] + last_dp[i];
            if (dp[i+k] >= modo) dp[i+k] -= modo;
        }
        for (i=0;i<=n;i++)
        {
            ans[i] += dp[i];
            if (ans[i] >= modo)
            {
                ans[i] -= modo;
            }
            last_dp[i] = dp[i];
            if (dp[i] != 0)
            {
                flag = true;
            }
            dp[i] = 0;
        }
        k++;
    }
    for (i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}