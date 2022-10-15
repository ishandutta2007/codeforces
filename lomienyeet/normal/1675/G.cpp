#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1],ps[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ps[i]=ps[i-1]+arr[i];
    }
    int dp[n+1][m+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m;k++)dp[i][j][k]=1e18;
        }
    }
    dp[0][0][m]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m;k++){
                if(i>1&&j<k)break;
                for(int l=0;l<=k&&j+l<=m;l++)dp[i][j+l][l]=min(dp[i][j+l][l],dp[i-1][j][k]+abs(ps[i]-j-l));
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<=m;i++)ans=min(ans,dp[n][m][i]);
    cout<<ans<<"\n";
}