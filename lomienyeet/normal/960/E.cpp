#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5,mod=1e9+7;
int arr[mxN],dep[mxN],sz[2][mxN],ans;
vector<int> adj[mxN];
void dfs(int u,int p,int w){
    sz[0][u]=1;
    sz[1][u]=0;
    dep[u]=w;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u,w+1);
            (sz[0][u]+=sz[1][i])%=mod;
            (sz[1][u]+=sz[0][i])%=mod;
        }
    }
}
void calc(int u,int p){
    pair<int,int> a={1,0},b={1,0};
    for(auto i:adj[u]){
        if(i!=p){
            calc(i,u);
            (a.ff+=sz[1][i])%=mod;
            (a.ss+=sz[0][i])%=mod;
            (b.ff+=(sz[1][i]*sz[1][i])%mod)%=mod;
            (b.ss+=(sz[0][i]*sz[0][i])%mod)%=mod;
        }
    }
    if(u!=p){
        pair<int,int> c={sz[(dep[u]+1)&1][0]-sz[1][u],sz[dep[u]&1][0]-sz[0][u]};
        (a.ff+=c.ss)%=mod;
        (a.ss+=c.ff)%=mod;
        (b.ff+=(c.ss*c.ss)%mod)%=mod;
        (b.ss+=(c.ff*c.ff)%mod)%=mod;
    }
    (ans+=(((a.ff*a.ff)%mod-b.ff+mod)%mod*arr[u])%mod+mod)%=mod;
    ((ans-=(((a.ss*a.ss)%mod-b.ss+mod)%mod*arr[u])%mod)+=mod)%=mod;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0,0);
    calc(0,0);
    for(int i=0;i<n;i++)(ans+=(arr[i]>0)?arr[i]:((mod-((-arr[i])%mod))%mod))%=mod;
    cout<<ans<<"\n";
}