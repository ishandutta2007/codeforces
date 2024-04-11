#include <bits/stdc++.h>
using namespace std;
int a[505],b[505];
long long dp[505][505],sp[505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,m,t;
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>a[i]>>b[i];
    for(i=1; i<=n; ++i)
        sp[i]=sp[i-1]+a[i]+b[i];
    for(j=0; j<=n; ++j)
        for(i=0; i<=m; ++i)
            dp[j][i]=-10000000;
    dp[0][0]=0;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            if(dp[i][j]<0)
                continue;
            long long catb=(sp[i]-j)%m;
            for(int y=1; y<=min(m-1,a[i+1]); ++y)
            {
                if(a[i+1]>=y && b[i+1]>=m-y)
                {
                    long long cat=dp[i][j]+1+(a[i+1]+j-y)/m+(b[i+1]+catb-(m-y))/m;
                    dp[i+1][(j+a[i+1]-y)%m]=max(cat,dp[i+1][(j+a[i+1]-y)%m]);
                }
            }
            long long cat=dp[i][j]+(a[i+1]+j)/m+(b[i+1]+catb)/m;
            dp[i+1][(j+a[i+1])%m]=max(dp[i+1][(j+a[i+1])%m],cat);
        }
    }
    long long mx=0;
    for(i=0; i<m; ++i)
        mx=max(mx,dp[n][i]);
    cout<<mx;
    return 0;
}