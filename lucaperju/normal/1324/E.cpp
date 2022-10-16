#include <bits/stdc++.h>

using namespace std;
int v[2003];
int dp[2003][2003];
bool verif (int a, int l, int r)
{
    if(a>=l && a<=r)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ok=0,i,j,cnt=4,h,l,r;
    cin>>n>>h>>l>>r;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=0;i<=n;++i)
        for(j=0;j<h;++j)
            dp[i][j]=-2003;
    dp[0][0]=0;
    for(i=0;i<n;++i)
        for(j=0;j<h;++j)
        {
            dp[i+1][(j+v[i+1])%h]=max(dp[i+1][(j+v[i+1])%h],dp[i][j]+verif((j+v[i+1])%h,l,r));
            dp[i+1][(j+v[i+1]-1)%h]=max(dp[i+1][(j+v[i+1]-1)%h],dp[i][j]+verif((j+v[i+1]-1)%h,l,r));
        }
    for(i=0;i<h;++i)
        ok=max(ok,dp[n][i]);
    cout<<ok;
    return 0;
}