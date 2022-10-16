#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    string arr[2];
    cin>>arr[0]>>arr[1];
    int count = 0;
    for(auto i:arr) for(auto j:i) count+=(j=='*');
    vector<vector<ll>>dp(2,vector<ll>(n+1));
    int encounters = 0; 
    for(int i=0;i<n;i++){
        if(arr[0][i]=='*' && arr[1][i]=='*'){
            dp[0][i+1] = min(dp[0][i],dp[1][i]) + 2 - (encounters==0);
            dp[1][i+1] = min(dp[0][i],dp[1][i]) + 2 - (encounters==0);
            encounters+=2;
        }else if(arr[0][i]=='*'){
            dp[0][i+1] = min(dp[0][i]+1,dp[1][i]+2) - (encounters==0);
            dp[1][i+1] = min(dp[0][i]+2,dp[1][i]+2) - (encounters==0);
            encounters++;
        }else if(arr[1][i]=='*'){
            dp[1][i+1] = min(dp[1][i]+1,dp[0][i]+2) - (encounters==0);
            dp[0][i+1] = min(dp[1][i]+2,dp[0][i]+2) - (encounters==0);
            encounters++;
        }else{
            dp[0][i+1] = dp[0][i] + 1 - (encounters==0);
            dp[1][i+1] = dp[1][i] + 1 - (encounters==0);
        }
        if(encounters==count){
            cout<<min(dp[0][i+1],dp[1][i+1])<<"\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}