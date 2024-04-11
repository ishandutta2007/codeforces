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
ll dp[251][251][251]{0};
ll prefMin[251][251];
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    for(auto &i:dp){
        for(auto &j:i){
            for(auto &k:j) 
                k = 1e17;
        }
    }
    for(auto &i:prefMin)
        for(auto &j:i)
            j = 1e17;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    reverse(arr,arr+n);
    dp[0][0][0]=0;
    int pref=0;
    for(int tillNow=1;tillNow<=n;tillNow++){
        int t = arr[tillNow-1];
        pref+=t;
        int prevIndex = tillNow - 1;
        for(int x=0;x<=m;x++){
            for(int y=0;y<=m;y++){
                if(x<=y) prefMin[x][y] = dp[prevIndex][x][y];
                else prefMin[x][y] = 1e17;
                if(x>0) prefMin[x][y] = min(prefMin[x][y],prefMin[x-1][y]);
            }
        }
        for(int x=0;x<=m;x++){
            for(int y=x;y<=m;y++){
                dp[tillNow][x][y] = prefMin[x][y-x] + abs(pref - t - y + x);
            }
        }
    }
    ll ans = 1e18;
    for(int i=0;i<=m;i++) ans = min(ans,dp[n][i][m]);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
// pref[tillNow] - y is excess previous excess = () + 
//  ai and items used  first tillNow items x is current val and y is sum until now 
//  dp[till_now][x][y] = min(dp[till_now-1][i][j] + pref[tillNow] - a[tillNow] - y + x) i<=x and y-x = j