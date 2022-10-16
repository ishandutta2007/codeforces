#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
ll dp[501][1501];
ll dp2[501][1501];
ll arr[512];
void solve(){
    ll n;cin>>n;
    for(auto &i:dp) 
        for(auto &j:i)
            j = -1e18;
    for(auto &i:dp2) 
        for(auto &j:i)
            j = -1e18;
    dp[0][0] = 0;
    dp2[0][0]= 0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    arr[n+1] = -1e6; 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            ll mlast = -1e10;
            ll acost = 0;
            for(int k=i;k>=1;k--){
                dp[i][j] = max(dp[i][j],max(dp2[k-1][max(j+acost,0ll)],dp[k-1][max(j+acost,0ll)]) + (i-k+1)*mlast);
                if(arr[k]>=mlast){
                    mlast = arr[k];
                    acost = -1;
                }
                dp[i][j] = max(dp[i][j],dp[k-1][max(j+acost,0ll)] + (i-k+1)*mlast);
                acost++;
            }
        }
        for(int j=0;j<=n;j++){
            ll mlast = arr[i+1];
            ll acost = 0;
            for(int k=i;k>=1;k--){
                dp2[i][j] = max(dp2[i][j],max(dp2[k-1][max(j+acost,0ll)],dp[k-1][max(j+acost,0ll)]) + (i-k+1)*mlast);
                acost++;
            }
        }
        for(int j=n;j>=0;j--){
            dp[i][j] = max(dp[i][j],dp[i][j+1]);
            dp2[i][j] = max(dp2[i][j],dp2[i][j+1]);
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"========================"<<i<<"\n";
    }   
    cout<<dp[n][0]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();  
}