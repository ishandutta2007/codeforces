#include <bits/stdc++.h>
using namespace std;
long long n,r1,r2,r3,d;
long long dp[1000006];
long long v[1000006];
long long total(int pz)
{
    return v[pz]*r1+r3;
}
long long partial (int pz)
{
    return min((v[pz]+1)*r1,r2);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    cin>>n>>r1>>r2>>r3>>d;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        dp[i]=1000000000000000000LL;
    }
    dp[n+1]=1000000000000000000LL;
    dp[1]=0;
    for(i=1;i<=n;++i)
    {
        if(i<=n-2)
        {
            dp[i+1]=min(dp[i+1],dp[i]+total(i)+d);
            dp[i+2]=min(dp[i+2],dp[i]+partial(i)+r1+4LL*d+min(total(i+1),partial(i+1)+r1));
        }
        if(i==n-1)
        {
            dp[n]=min(dp[n],dp[i]+total(i)+d);
            dp[n+1]=min(dp[n+1],dp[i]+partial(i)+r1+2LL*d+min(total(i+1),partial(i+1)+d+r1));
        }
        if(i==n)
        {
            dp[n+1]=min(dp[n+1],dp[i]+total(i));
            dp[n+1]=min(dp[n+1],dp[i]+2LL*d+partial(i)+r1);
        }
    }
    cout<<dp[n+1];
}