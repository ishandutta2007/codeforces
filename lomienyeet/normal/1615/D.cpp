#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops")
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
vector<int> adj[mxN];
vector<pair<int,int> > adj2[mxN];
map<pair<int,int>,int> mp;
int val[mxN];
bool ans;
bool chk(int x){
    bool z=0;
    for(int i=0;i<30;i++)z^=((x&(1<<i))>0);
    return z;
}
void dfs(int u,int v){
    if(val[u]!=-1){
        if(val[u]!=v)ans=0;
        return;
    }
    val[u]=v;
    for(auto i:adj2[u])dfs(i.ff,i.ss^v);
}
void dfs2(int u,int p){
    if(p!=-1)cout<<u<<" "<<p<<" "<<(mp[{u,p}]!=-1?mp[{u,p}]:val[u]^val[p])<<"\n";
    for(auto i:adj[u]){
        if(i!=p)dfs2(i,u);
    }
}
void eat(){
    int n,m;
    cin>>n>>m;
    ans=1;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        adj2[i].clear();
        val[i]=-1;
    }
    mp.clear();
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=mp[{v,u}]=w;
        if(w!=-1){
            w=chk(w);
            adj2[u].push_back({v,w});
            adj2[v].push_back({u,w});
        }
    }
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        adj2[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(val[i]==-1)dfs(i,0);
    }
    cout<<(ans?"YES\n":"NO\n");
    if(!ans)return;
    dfs2(1,-1);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}