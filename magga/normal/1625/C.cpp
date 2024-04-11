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
typedef int ll;
using namespace std;
// Please write the recurances once :(
int dp[2][500+1][500+1];
void solve(){
    int n,l,k;cin>>n>>l>>k;
    int arr[n+1];
    int sped[n+1];
    arr[n]=l;
    for(int i=0;i<n;i++) cin>>arr[i];
    sped[n]=0;
    for(int i=0;i<n;i++) cin>>sped[i];
    for(auto &i:dp) for(auto &j:i) for(auto &k:j) k = 1.5e9;
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++)
            for(int p=0;p<=n;p++)
                dp[i%2][j][p] = 1.5e9;
        for(int j=0;j<=n;j++){
            for(int p=0;p<n;p++){
                dp[i%2][j][p+1] = min(dp[i%2][j][p+1],dp[(i-1)%2][j][p] + (arr[i] - arr[i-1])*sped[j]);
            }
        }
        for(int j=0;j<=n;j++){
            for(int p=0;p<n;p++){
                dp[i%2][i][p] = min(dp[i%2][i][p],dp[(i-1)%2][j][p] + (arr[i] - arr[i-1])*sped[j]);
            }
        }
    }
    ll ans = 2e9 ;
    for(int i=0;i<=n;i++){
        for(int p=0;p<=k;p++){
            ans = min(ans,dp[n%2][i][p]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}