#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long dp[2000006][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m,k;
    cin>>t;
    dp[3][1]=4;
    for(i=4;i<=2000000;++i)
    {
        dp[i][0]=(max(dp[i-1][0],dp[i-1][1])+2LL*max(dp[i-2][0],dp[i-2][1]))%mod;
        dp[i][1]=(4LL+dp[i-1][0]+2LL*dp[i-2][0])%mod;
    }
    while(t--)
    {
        cin>>n;
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}