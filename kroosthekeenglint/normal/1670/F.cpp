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
int n;
long long z;
const int modo=1000000007;
int c[2005][2005];
void calc_c()
{
    c[0][0]=1;
    int i;
    for (i=1;i<=1000;i++)
    {
        int j;
        c[i][0]=1;
        for (j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%modo;
        }
    }
}
int dp[105][1005];
int count(long long bound)
{
    memset(dp,0,sizeof(dp));
    int i;
    dp[63][0]=1;
    for (i=62;i>=0;i--)
    {
        int j;
        int checks = (bound >> i) & 1;
        int necc = (z >> i) & 1;
        for (j=0;j<=1000;j++)
        {
            int k;
            for (k=0;k<=j*2+checks;k++)
            {
                int t=k;
                if ((j*2+checks-k)%2 != necc)
                {
                    continue;
                }
                if (k>=1000)
                {
                    t=1000;
                }
                dp[i][t] = (dp[i][t] + (long long)c[n][j*2+checks-k] * dp[i+1][j])%modo;
            }
        }
    }
    int sum=0;
    for (i=0;i<=1000;i++)
    {
        sum=(sum+dp[0][i])%modo;
    }
    return sum;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    calc_c();
    long long l,r;
    cin>>n>>l>>r>>z;
    printf("%d\n",(count(r)-count(l-1)+modo)%modo);
    return 0;
}