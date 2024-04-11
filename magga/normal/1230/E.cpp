#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int mod = 1e9+7;
long long int n,u,v;
long long int ans = 0;
long long int ret[100001];
vector<long long int>arr[100001];
void dfs(int a,int b,map<long long int,int>m){
    map<long long int,int>m1;
    ans+=ret[a];
    m1[ret[a]]++;
    for(auto i:m){
        ans+=((__gcd(ret[a],i.first)%mod)*(i.second))%mod;
        ans%=mod;
        m1[__gcd(ret[a],i.first)]+=i.second;
    }
    for(auto i:arr[a]){
        if(i!=b){
            dfs(i,a,m1);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ret[i];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    map<long long int,int>m;
    dfs(1,0,m);
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