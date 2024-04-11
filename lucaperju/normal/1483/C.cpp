#include <bits/stdc++.h>

using namespace std;
long long dp[300003];
long long v[300003],h[300003],mx[300003],st[300003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,t,i,j,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>h[i];
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        long long mxc=-1000000000000000LL;
        while(k>0 && h[st[k]]>h[i])
        {
            mxc=max(mxc,mx[k]);
            --k;
        }
        mxc=max(mxc,dp[st[k]]);
        if(k==0)
        {
            dp[i]=max(v[i],v[i]+mxc);
        }
        else
        {
            dp[i]=max(v[i]+mxc,dp[st[k]]);
        }
        st[++k]=i;
        mx[k]=max(mxc,dp[i]);
    }
    cout<<dp[n];
    return 0;
}