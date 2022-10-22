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
const int modo = 1000000007;
int power(int x,int y)
{
    if (y == 0)
    {
        return 1;
    }
    int t = power(x,y/2);
    t = (long long)t * t % modo;
    if (y % 2 == 1)
    {
        t = (long long)t * x % modo; 
    }
    return t;
}
int sum[1000005];
int sum2[1000005];
int ans[1000005];
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
        sum[n+1] = 0;
        sum[n+2] = 0;
        sum2[n+1] = 0;
        for (i=n;i>=1;i--)
        {
            // first, he should eat i/2 + 1 ~ i - 1. This shoule be RRRR..RL 
            int val1 = power(2, max(0, i/2 - 1));
            // second, no one after him could defeat him.
            int val2 = power(2, max(0, n - i - 1));
            if (i * 2 <= n)
            {
                val2 = (val2 - sum[i * 2] + modo) % modo;
            }
            ans[i] = (long long)val1 * val2 % modo;
            sum[i] = (sum[i+1] + val2) % modo;
            if (i % 2 == 0)
            {
                sum[i] = (sum[i] + sum[i+2]) % modo;
            }
        }
        for (i=1;i<=n;i++)
        {
            printf("%d\n", (int)((long long)ans[i] * power(2, modo - 1 - max(0, n - 2)) % modo));
        }
    }
    return 0;
}