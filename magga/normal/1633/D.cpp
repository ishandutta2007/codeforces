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
int dp[1000001]{0};
void pre(){
    dp[1] = 0;
    int a = 0;
    for(int i=2;i<=1000;i++) dp[i]=1e9;
    for(int i=1;i<=1000;i++){
        a = max(a,dp[i]);
        for(int j=1;j<=i;j++){
            dp[i+i/j] = min(dp[i+i/j],dp[i]+1);
        }
    }
}
void solve(){
    int n,k;cin>>n>>k;
    int arr[n],c[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i] = dp[arr[i]]; 
    }
    for(int i=0;i<n;i++) cin>>c[i];
    k = min(k,13*n);
    ll p[n+1][k+1];
    for(auto &i:p) for(auto &j:i) j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++) p[i+1][j] = p[i][j];
        for(int j=0;j<=k;j++){
            if( j + arr[i] <=k ){
                p[i+1][j+arr[i]] = max(p[i+1][j+arr[i]],p[i][j]+c[i]);
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<=k;i++) ans=max(ans,p[n][i]);
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
/*
    each i is independent
    cost required to make ai = bi => dpable 1->ai   
    standard knacksap cost dp[bi] reward ci bag of k
    objects n 
    no of cost will be low = 12 


*/