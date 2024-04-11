#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=4e5+5;
int n,sz[mxN],mx[mxN],fir[mxN],sec[mxN];
bool ans[mxN];
vector<int> adj[mxN];
void dfs(int u,int p){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u);
            sz[u]+=sz[i];
            if(mx[i]>mx[u]){
                mx[u]=mx[i];
                sec[u]=fir[u];
                fir[u]=i;
            }
            else if(mx[i]>mx[sec[u]])sec[u]=i;
        }
    }
    if(sz[u]<=(n>>1))mx[u]=sz[u];
}
void calc(int u,int p,int v){
    ans[u]=1;
    for(auto i:adj[u]){
        if(i!=p){
            if(sz[i]-mx[i]>(n>>1))ans[u]=0;
            if(n-sz[i]<=(n>>1))calc(i,u,n-sz[i]);
            else if(i==fir[u])calc(i,u,max(v,mx[sec[u]]));
            else calc(i,u,max(v,mx[fir[u]]));
        }
        else if(n-sz[u]-v>(n>>1))ans[u]=0;
    }
}
signed main(){
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    calc(1,-1,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}