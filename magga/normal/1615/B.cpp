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

int dp[20][200001]{0};
void pre(){
    for(int i=1;i<=2e5;i++){
        for(int j=0;j<20;j++){
            if( i&(1<<j) ){
                dp[j][i] = dp[j][i-1] + 1;
            }else{
                dp[j][i] = dp[j][i-1];
            }
        }
    }
}
void solve(){
    int l,r;cin>>l>>r;
    int ans = r-l+1;
    for(int i=0;i<20;i++){
        ans = min(ans,r-l+1-(dp[i][r] - dp[i][l-1]));
    }
    cout<<ans<<"\n";
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