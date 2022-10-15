#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e3+5,mod=998244353;
int n,k,arr[mxN],dp[mxN][mxN<<1];
int eat(int u,int v){
    if(u==n)return (v>0);
    if(dp[u][v+mxN]!=-1)return dp[u][v+mxN];
    set<int> s;
    s.insert(arr[u]);
    s.insert(arr[(u+1)%n]);
    int ans=((k-s.size())*eat(u+1,v))%mod;
    for(auto i:s)(ans+=eat(u+1,v-(arr[u]==i)+(arr[(u+1)%n]==i)))%=mod;
    return dp[u][v+mxN]=ans;
}
signed main(){
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<eat(0,0)<<"\n";
}