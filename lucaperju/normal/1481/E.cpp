#include <bits/stdc++.h>
using namespace std;
int v[500005];
int fv[500005];
int st[500005],dr[500005];
int dp[500005];
int bst[500005];
int main()
{
    long long t,n,i,j,m,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        if(fv[v[i]]==1)
            st[v[i]]=i;
        dr[v[i]]=i;
    }
    for(i=1;i<=n;++i)
        fv[i]=0;
    for(i=n;i>=1;--i)
    {
        ++fv[v[i]];
        bst[i]=max(bst[i+1],fv[v[i]]);
    }
    long long rz=n;
    for(i=1;i<=n;++i)
    {
        dp[i]=dp[i-1];
        if(dr[v[i]]==i)
        {
            int stc=st[v[i]];
            dp[i]=max(dp[i],fv[v[i]]+dp[stc-1]);
        }
        rz=min(rz,n-dp[i]-bst[i+1]);
    }
    cout<<rz;
    return 0;
}