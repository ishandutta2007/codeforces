#include <bits/stdc++.h>
using namespace std;
int n,m;
char v[3003],b[3003];
const int mod=998244353;
long long dp[3003][3003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok,n;
    long long k=0,t,d,rz=0;
    cin>>(v+1)>>(b+1);
    n=strlen(v+1);
    m=strlen(b+1);
    for(i=1;i<=m+1;++i)
        dp[i][i-1]=1;
    for(d=0;d<m;++d)
    {
        for(i=1;i+d<=m;++i)
        {
            j=i+d;
            if(j!=m)
                dp[i][j]=dp[i+1][j]*(v[d+1]==b[i])+dp[i][j-1]*(v[d+1]==b[j]);
            else
                dp[i][j]=dp[i][j-1]*(v[d+1]==b[j]);
            if(dp[i][j]>=mod)
                dp[i][j]-=mod;
        }
      //  dp[m+1][m]=dp[m+1][m]*2LL%mod;
    }
  //  rz+=dp[1][m];
    for(i=1;i<=n;++i)
    {
        for(j=max(2LL,m-i+2);j<=m+1;++j)
        {
            if(v[i]==b[j-1])
                dp[j-1][m]=(dp[j-1][m]+dp[j][m])%mod;
        }
        dp[m+1][m]=dp[m+1][m]*2LL%mod;
        if(i>=m)
            rz+=dp[1][m];
    }
    cout<<rz%mod;
    return 0;
}