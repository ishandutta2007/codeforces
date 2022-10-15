#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,t,z;
    cin>>n>>t>>z;
    int dp[n+5][n+5];
    for(int i=0;i<n+5;i++){
        for(int j=0;j<n+5;j++)dp[i][j]=1e18;
    }
    dp[n+1][0]=0;
    int d[n+2],v[n+1];
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++)cin>>v[i];
    d[n+1]=t;
    for(int i=n;i>0;i--){
        for(int j=0;i+j<=n;j++){
            for(int k=0;k<=j;k++)dp[i][j]=min(dp[i][j],dp[i+k+1][j-k]+v[i]*(d[i+k+1]-d[i]));
        }
    }
    int ans=1e18;
    for(int i=0;i<=z;i++)ans=min(ans,dp[1][i]);
    cout<<ans<<"\n";
}