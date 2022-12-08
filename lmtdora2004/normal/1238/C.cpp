#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[200005][2];
int a[200005];
signed main()
{
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        int h, n;
        cin>>h>>n;
        for(int i=1; i<=n; i++)
        {//hjfjoafdnjoafdnjoiafnfan
            cin>>a[i];
        }
        dp[1][1]=1000000000;
        for(int i=2; i<=n; i++)
        {
            if(a[i-1]-a[i]>1)
            {
                dp[i][0]=min(dp[i-1][0]+1, dp[i-1][1]+2);
                dp[i][1]=min(dp[i-1][0], dp[i-1][1]+1);
            }
            else
            {
                dp[i][0]=min(dp[i-1][1], dp[i-1][0]+1);
                dp[i][1]=min(dp[i-1][0], dp[i-1][1]+1);
            }
        }
        if(a[n]==1) cout<<min(dp[n][0], dp[n][1]);
        else cout<<min(dp[n][0], dp[n][1]+1);
        cout<<'\n';
    }
}