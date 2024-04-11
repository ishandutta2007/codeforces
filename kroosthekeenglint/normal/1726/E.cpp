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
const int modo = 998244353;
int dp[300005];
int fact[300005];
int anti_fact[300005];
int power(int x,int y)
{
    if (y==0)
    {
        return 1;
    }
    int t = power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
int c(int n,int m)
{
    return (long long)fact[n] * anti_fact[m] % modo * anti_fact[n-m] % modo;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int n=300000;
    int i;
    dp[0] = 1;
    dp[1] = 1;
    for (i=2;i<=n;i++)
    {
        dp[i] = (dp[i-1] + (long long)dp[i-2] * (i - 1))%modo;
    }
    fact[0] = 1;
    anti_fact[0] = 1;
    for (i=1;i<=n;i++)
    {
        fact[i] = (long long)fact[i-1] * i % modo;
        anti_fact[i] = power(fact[i], modo - 2);
    }
    int zu;
    for (zu=0;zu<t;zu++)
    {
        scanf("%d",&n);
        int i;
        int ans = 0;
        for (i=0;i<=n/4;i++)
        {
            //Choose i * 2 pairs
            int j = c(n - i - i, i + i);
            //Choose i of them as left part
            j = (long long)j * c(i+i, i) % modo;
            j = (long long)j * fact[i] % modo;
            //And calc ans
            ans = (ans + (long long)j * dp[n-i*4]) % modo;
        }
        printf("%d\n",ans);
    }
    return 0;
}