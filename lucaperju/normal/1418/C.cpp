#include <bits/stdc++.h>
using namespace std;
int v[200005];
int dp[200005][2];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        dp[0][0]=0;
        dp[0][1]=9999999;
        for(i=1;i<=n;++i)
            dp[i][0]=dp[i][1]=9999999;
        for(i=0;i<n;++i)
        {
            dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
            dp[i+2][0]=min(dp[i+2][0],dp[i][1]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+v[i+1]);
            dp[i+2][1]=min(dp[i+2][1],dp[i][0]+v[i+1]+v[i+2]);
        }
        cout<<min(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}