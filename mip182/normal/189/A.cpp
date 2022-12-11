#include<bits/stdc++.h>
using namespace std;
const int mx=4*1000+100;
int dp[mx];
int main()
{
    int n;
    cin>>n;
    fill(dp,dp+n+1, -1667457892);
    dp[0]=0;
    for(int i=0; i<3; i++)
    {
        int a; cin>>a;
        for(int j=a; j<=n; j++)
            dp[j]=max(dp[j],dp[j-a]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}