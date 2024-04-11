#include <bits/stdc++.h>
using namespace std;
char v[2003][2003];
int dp[2003][2003];
int main()
{
    long long t,n,s,m,i,j,x,y,l,r;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>(v[i]+1);
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            dp[i][j]=1;
    long long rz=0;
    for(i=2;i<=n;++i)
    {
        for(j=2;j<m;++j)
        {
            if(v[i][j]!=v[i-1][j] || v[i][j]!=v[i-1][j-1] || v[i][j]!=v[i-1][j+1])
            {
                dp[i][j]=1;
                rz+=dp[i][j];
                continue;
            }
            int mn=dp[i-1][j-1];
            mn=min(mn,dp[i-1][j]);
            mn=min(mn,dp[i-1][j+1]);
            dp[i][j]=mn;
            ++mn;
            int cat=(mn-1)*2;
            if(i>cat && v[i-cat][j]==v[i][j])
                dp[i][j]=mn;
            rz+=dp[i][j];
        }
    }
    cout<<rz+m+n+n-2;
    return 0;
}