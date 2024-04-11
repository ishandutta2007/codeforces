#include <bits/stdc++.h>
using namespace std;
int t[100005],x[100005],y[100005];
int dp[100005],mxp[100005];
bool check (int i, int j)
{
    int tc=t[j]-t[i];
    if(max(x[i]-x[j],x[j]-x[i])+max(y[i]-y[j],y[j]-y[i])<=tc)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,s=0,rz=0;
    cin>>n>>n;
    for(i=1;i<=n;++i)
    {
        cin>>t[i]>>x[i]>>y[i];
    }
    x[0]=y[0]=1;
    t[0]=0;
    for(i=1;i<=n;++i)
    {
        dp[i]=-1000000;
        if(i-1001>=0)
            dp[i]=1+mxp[i-1001];
        for(j=i-1;j>=max(0,i-1001);--j)
        {
            if(check(j,i))
                dp[i]=max(dp[i],1+dp[j]);
        }
        mxp[i]=max(mxp[i-1],dp[i]);
    }
    cout<<mxp[n];
}