#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("trapv")
#pragma GCC target ("avx2")
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3+10;
ll dp[N][N];
ll maxi;
int n,m,i,j,l;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        ll sum = 0;
        for(j=0;j<=m;j++)
            dp[i][j] = dp[i-1][j];
        for(j=1;j<=t;j++)
        {
            cin>>l;
            sum+=l;
            for(int k=j;k<=m;k++)
                dp[i][k] = max(dp[i][k],dp[i-1][k-j]+sum);
        }
    }
    cout<<dp[n][m];
}