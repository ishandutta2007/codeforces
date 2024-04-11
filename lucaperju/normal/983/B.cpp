#include <bits/stdc++.h>

using namespace std;
int v[5005];
int d[5005][5005],dp[5005][5005];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(int dst=0;dst<n;++dst)
        for(i=1;i+dst<=n;++i)
        {
            j=i+dst;
            if(i==j)
                d[i][j]=dp[i][j]=v[i];
            else
            {
                d[i][j]=d[i+1][j] xor d[i][j-1];
                dp[i][j]=max(d[i][j],max(dp[i+1][j],dp[i][j-1]));
            }
        }
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b]<<'\n';
    }
    return 0;
}