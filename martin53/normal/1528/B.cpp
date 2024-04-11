#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=998244353;

int n;

long long dp[nmax];
long long pref[nmax];

int dvd[nmax];

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j=j+i)
            dvd[j]++;

    dp[1]=1;
    pref[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dvd[i];

        dp[i]=(dp[i]+pref[i-1])%mod;

        pref[i]=(pref[i-1]+dp[i])%mod;
    }

    printf("%lld\n",dp[n]);

    return 0;
}