#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int n,tag[nmax],s[nmax];

long long dp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&tag[i]);

    for(int i=1;i<=n;i++)scanf("%i",&s[i]);

    for(int i=1;i<=n;i++)dp[i]=0;

    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=1;j--)
            if(tag[i]!=tag[j])
            {
                long long LHS=dp[j]+abs(s[i]-s[j]);
                long long RHS=dp[i]+abs(s[i]-s[j]);

                dp[i]=max(dp[i],LHS);
                dp[j]=max(dp[j],RHS);
            }

    long long ret=0;
    for(int i=1;i<=n;i++)ret=max(ret,dp[i]);

    printf("%lld\n",ret);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}