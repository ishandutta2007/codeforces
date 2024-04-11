#include <bits/stdc++.h>

using namespace std;
char v[503][503];
int dp[503][503];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,j,i,k;
    int t;
    cin>>t;
    while(t--)
    {
        int s=0;
        int m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                cin>>v[i][j];
                dp[i][j]=0;
            }
        for(i=0;i<=n+1;++i)
            for(j=0;j<=m+1;++j)
                dp[i][j]=0;
        for(i=n;i>=1;--i)
        {
            for(j=1;j<=m;++j)
            {
                if(v[i][j]!='.')
                {
                    dp[i][j]=min(min(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1])+1;
                    s+=dp[i][j];
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}