#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,MX=5e6+42;

int n,inp[nmax];

int cnt[MX];
long long dp[MX];

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        for(int j=1;j*j<=inp[i];j++)
            if(inp[i]%j==0)
            {
                cnt[j]++;
                if(j*j<inp[i])cnt[inp[i]/j]++;
            }
    }

    for(int i=MX-1;i>=1;i--)
    {
        dp[i]=cnt[i];

        for(int j=i*2;j<MX;j+=i)
            dp[i]=max(dp[i],j/i*dp[j]+cnt[i]-cnt[j]);
    }

    printf("%lld\n",dp[1]);

    return 0;
}