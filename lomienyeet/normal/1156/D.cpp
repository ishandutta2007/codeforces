#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
vector<pair<int,int> > adj[mxN];
int n,res=0,f[mxN]={},g[mxN]={},dp[mxN]={},ans[mxN]={}; // f -> 0s, g -> 1s, dp -> 0-1s
void dfs(int u,int p=-1){
    for(auto i:adj[u]){
        if(i.ff!=p){
            dfs(i.ff,u);
            if(!i.ss){
                f[u]+=f[i.ff]+1;
                dp[u]+=dp[i.ff]+g[i.ff];
            }
            else g[u]+=g[i.ff]+1;
        }
    }
}
void reroot(int u,int p=-1){
    ans[u]+=f[u]+g[u]+dp[u];
    for(auto i:adj[u]){
        if(i.ff!=p){
            if(!i.ss){
                f[u]-=(f[i.ff]+1);
                dp[u]-=(dp[i.ff]+g[i.ff]);
                f[i.ff]+=f[u]+1;
                dp[i.ff]+=dp[u]+g[u];
                reroot(i.ff,u);
                f[i.ff]-=(f[u]+1);
                dp[i.ff]-=(dp[u]+g[u]);
                f[u]+=f[i.ff]+1;
                dp[u]+=dp[i.ff]+g[i.ff];
            }
            else{
                g[u]-=(g[i.ff]+1);
                g[i.ff]+=g[u]+1;
                reroot(i.ff,u);
                g[i.ff]-=(g[u]+1);
                g[u]+=g[i.ff]+1;
            }
        }
    }
}
signed main(){
    cin>>n;
    for(int i=0,u,v,w;i<n-1;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    reroot(1);
    for(int i=1;i<=n;i++)res+=ans[i];
    cout<<res<<"\n";
}