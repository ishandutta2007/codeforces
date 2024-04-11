#include <bits/stdc++.h>
using namespace std;
int a[85],b[85],dp[100005];
int main()
{
    int n,k,i,j,m;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    for(i=1;i<=m;++i)
        dp[i]=i;
    for(i=0;i<=m;++i)
    {
        dp[i]=min(dp[i],dp[i-1]+1);
        for(j=1;j<=n;++j)
        {
            if(a[j]-b[j]<=i+1 && a[j]+b[j]>i)
                dp[min(m,a[j]+b[j])]=min(dp[min(m,a[j]+b[j])],dp[i]);
            else
            if(a[j]+b[j]>i)
                dp[min(m,a[j]+b[j]+a[j]-b[j]-i-1)]=min(dp[min(m,a[j]+b[j]+a[j]-b[j]-i-1)],dp[i]+a[j]-b[j]-i-1);
        }
        if(dp[m]==0)
        {
            break;
        }
    }
    cout<<dp[m];
    return 0;
}