#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[2][205][1005],arr[205];
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        int z=i&1; //  rolling 
        memset(dp[z],0,sizeof dp[z]);
        for(int j=0;j<i;j++){
            for(int k=0;k<=m;k++){
                if(!dp[z^1][j][k])continue;
                if(j*(arr[i]-arr[i-1])+k<=m){
                    (dp[z][j][j*(arr[i]-arr[i-1])+k]+=(dp[z^1][j][k]*(j+1))%mod)%=mod;
                    (dp[z][j+1][j*(arr[i]-arr[i-1])+k]+=dp[z^1][j][k])%=mod;
                    if(j>0)(dp[z][j-1][j*(arr[i]-arr[i-1])+k]+=(dp[z^1][j][k]*j)%mod)%=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)(ans+=dp[n&1][0][i])%=mod;
    cout<<ans<<"\n";
}
/*
cannot let motivation stop one day, otherwise will have bad trend
cannot let myself get satisfied for more than one day, otherwise will become self indulgent
cannot inch when i don't have the ability to

being seen as a  for all comps until tft is best
being underestimated is way better than overestimation
being good score in tft will let everyone regret looking down on me (hope can good score)

will not forgive myself if fry tft 2022
will always remember those "kind" people who laughed at me after tft 2021
will always seek revenge by improving myself
*/