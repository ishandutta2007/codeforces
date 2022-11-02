/** Ithea best girl **/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,i,j;
    cin>>n>>m;
    string s[n];
    int dp[n][m];
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            dp[i][j] = 0;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<m;j++)
        {
            if(i==n-1 || j==0 || j==m-1)
            {
                if(s[i][j]=='*')
                    dp[i][j] = 1;
                continue;
            }

            if(s[i][j]=='*')
            {
                dp[i][j] = min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))+1;
            }
        }
    }
    long long sum = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            sum+=dp[i][j];
    }
    cout<<sum<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}