// tree dee pee !! ! ! oh my god

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,mod=1e9+7;
int sz[mxN];
vector<int> adj[mxN];
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
int dfs(int u,int p){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i!=p)sz[u]+=dfs(i,u);
    }
    return sz[u];
}
signed main(){
    int n,k;
    cin>>n>>k;
    int ans=bm(n,k);
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        if(w)continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(sz[i])continue;
        ((ans-=bm(dfs(i,-1),k))+=mod)%=mod;
    }
    cout<<ans<<"\n";
}