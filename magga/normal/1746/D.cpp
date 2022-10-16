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
ll s[200001];
vector<ll>arr[200001];
pii dp[200001];
void dfs(int i,ll k){
    ll t = arr[i].size();
    dp[i] = {k*s[i],(k+1)*s[i]};
    for(auto to:arr[i]){
        dfs(to,k/t);
        dp[i].F += dp[to].F;
        dp[i].S += dp[to].F; 
    }
    vector<ll>v;
    for(auto to:arr[i]){
        v.push_back(dp[to].S - dp[to].F);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if(t>0){
        for(int j=0;j<(k%t);j++){
            dp[i].F += v[j];
        }
        for(int j=0;j<=(k%t);j++){
            dp[i].S += v[j];
        }
    }
}
void solve(){
    ll n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) arr[i].clear();
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        arr[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>s[i];
    dfs(1,k);
    cout<<dp[1].F<<"\n";
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