#include <iostream>
#include <algorithm>
using namespace std;
const int mod=1000000007;

long long dp[100005][4][2];
int main()
{
    int n,m,i;
    cin>>n>>m;
    dp[1][1][0]=dp[1][1][1]=1;
    for (i=2;i<=max(n,m);i++)
    {
        dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][2][0])%mod;
        dp[i][1][0]=(dp[i-1][1][1]+dp[i-1][2][1])%mod;
        dp[i][2][1]=(dp[i-1][1][1])%mod;
        dp[i][2][0]=(dp[i-1][1][0])%mod;
    }
    cout<<(dp[n][1][0]+dp[n][1][1]+dp[n][2][0]+dp[n][2][1]+dp[m][1][0]+dp[m][1][1]+dp[m][2][0]+dp[m][2][1]-2+mod)%mod;
    return 0;
}