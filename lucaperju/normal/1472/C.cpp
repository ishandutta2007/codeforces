#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int v[200003];
int dp[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2,rz=1;
    cin>>t;
    while(t--)
    {
        long long w,h;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int mx=v[n];
        dp[n]=v[n];
        for(i=n-1;i>=1;--i)
        {
            if(i+v[i]<=n)
                dp[i]=v[i]+dp[i+v[i]];
            else
                dp[i]=v[i];
            mx=max(mx,dp[i]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}