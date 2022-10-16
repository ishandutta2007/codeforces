#include <bits/stdc++.h>
using namespace std;
int dp[75][75][75][75]; /// i,j, k alese, r
int v[75][75];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    for(i=0;i<=n;++i)
        for(j=0;j<=m;++j)
            for(int kc=0;kc<=m;++kc)
                for(int rc=0;rc<=k;++rc)
                    dp[i][j][kc][rc]=-999999999;
    dp[1][1][0][0]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            for(int kc=0;kc<=m/2;++kc)
                for(int rc=0;rc<k;++rc)
                {
                    if(j<m)
                    {
                        if(kc+1<=m/2)
                            dp[i][j+1][kc+1][(rc+v[i][j])%k]=max(dp[i][j+1][kc+1][(rc+v[i][j])%k],dp[i][j][kc][rc]+v[i][j]);
                        dp[i][j+1][kc][rc]=max(dp[i][j+1][kc][rc],dp[i][j][kc][rc]);
                    }
                    else
                    {
                        if(kc+1<=m/2)
                            dp[i+1][1][0][(rc+v[i][j])%k]=max(dp[i+1][1][0][(rc+v[i][j])%k],dp[i][j][kc][rc]+v[i][j]);
                        dp[i+1][1][0][rc]=max(dp[i+1][1][0][rc],dp[i][j][kc][rc]);
                    }
                }
    cout<<dp[n+1][1][0][0]<<'\n';
    return 0;
}