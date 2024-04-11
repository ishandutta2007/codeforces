#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];
    ll dp[n+1][10001];
    for(auto &i:dp)
        for(auto &j:i)
            j = 1e17;
    dp[n][0]=0;
    ll pref = 0;
    ll sum = 0;
    for(int i=n-1;i>=0;i--){
        sum += (n-1)*arr[i]*arr[i] + (n-1)*brr[i]*brr[i];
        for(int j=0;j<=10000;j++){
            if(dp[i+1][j]==1e17) continue;
            dp[i][j+arr[i]] = min(dp[i][j+arr[i]],dp[i+1][j] + j*arr[i] + (pref-j)*brr[i] );
            dp[i][j+brr[i]] = min(dp[i][j+brr[i]],dp[i+1][j] + j*brr[i] + (pref-j)*arr[i] );
        }
        pref += arr[i] + brr[i];
    }
    ll ans = 1e17;
    for(int j=0;j<=10000;j++) ans = min(ans,dp[0][j]);  
    cout<<2*ans + sum<<"\n";
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