#include <bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int ans[mxN],vis[mxN];
vector<int> adj[mxN];
void dfs(int u,int z){
    vis[u]=1;
    ans[u]=adj[u].size()*z;
    for(auto i:adj[u]){
        if(!vis[i])dfs(i,-z);
    }
}
void eat(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        vis[i]=ans[i]=0;
        adj[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}