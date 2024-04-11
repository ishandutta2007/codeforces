#include <bits/stdc++.h>

using namespace std;
long long dp[100003];
long long a[100003],b[100003],c[100003];;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,k,s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>c[i];
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
            cin>>b[i];
        for(i=1;i<=n;++i)
        {
            if(a[i]>b[i])
                swap(a[i],b[i]);
        }
        long long mx=0;
        dp[1]=b[2]-a[2]+1;
        for(i=2;i<=n;++i)
        {
            mx=max(mx,dp[i-1]+c[i]);
            if(a[i+1]!=b[i+1])
                dp[i]=max(b[i+1]-a[i+1]+1,dp[i-1]+a[i+1]+(c[i]-b[i+1]+1));
            else
                dp[i]=1;
        }
        cout<<mx<<'\n';
    }
    return 0;
}