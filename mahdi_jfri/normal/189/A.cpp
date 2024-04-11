#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
int dp[maxn];
int main()
{
    int n;
    cin>>n;
    dp[0] = 0;
    fill(dp+1,dp+(n+1),-maxn);
    for(int i=0; i<3; ++i)
    {
        int a;
        cin>>a;
        for(int j=a; j<=n; ++j)
        {
            dp[j] = max(dp[j-a]+1, dp[j]);
        }
    }
    cout<<dp[n];
    return 0;
}