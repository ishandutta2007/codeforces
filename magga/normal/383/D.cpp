#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int mod = 1e9+7;
void solve(){
    long long int n;cin>>n;
    long long int dp[n+1][20001];
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<=20000;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=20000;j++) dp[i][j]=0;
        dp[i-1][10000]++;
        for(int j=0;j<=20000;j++){
            if(dp[i-1][j]==0){
                continue;
            }
            dp[i][j+arr[i]]+=dp[i-1][j];
            dp[i][j+arr[i]]%=mod;
            dp[i][j-arr[i]]+=dp[i-1][j];
            dp[i][j+arr[i]]%=mod;
        }
    }
    long long int ans = -1*n;
    for(int i=0;i<=n;i++){
        ans+=dp[i][10000];
        ans%=mod;
    }
    cout<<ans<<"\n";
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