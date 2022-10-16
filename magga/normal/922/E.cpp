#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,W,B,X;cin>>n>>W>>B>>X;
    long long int dp[n+1][10001];
    long long int chick[n+1];
    for(int i=1;i<=n;i++) cin>>chick[i];
    long long int cost[n+1];
    for(int i=1;i<=n;i++) cin>>cost[i];
    dp[0][0]=W;
    for(int i=1;i<=10000;i++) dp[0][i]=-1e18;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){dp[i-1][j]=min(W+B*j,dp[i-1][j]+X);dp[i][j]=dp[i-1][j];}
        for(int j=0;j<=10000;j++){
            if(dp[i][j]<0){
                break;
            }
            for(int k=1;k<=chick[i];k++){
                if(dp[i-1][j]-cost[i]*k<0){
                    break;
                }
                dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]-cost[i]*k);
            }
        }
    }
    for(int i=10000;i>=0;i--){
        if(dp[n][i]>=0){
            cout<<i<<"\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}