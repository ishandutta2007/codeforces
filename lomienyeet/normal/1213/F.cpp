#include <bits/stdc++.h>
using namespace std;
#define int long long
// standard SCC operations: run kosaraju
const int mxN=2e5+5;
vector<int> adj[mxN],rever[mxN],meta;
int sccid[mxN];
bool vis[mxN];
void dfs(int u){
    vis[u]=1;
    for(auto i:adj[u]){
        if(!vis[i])dfs(i);
    }
    meta.push_back(u);
}
void rdfs(int u,int cnt){
    sccid[u]=cnt;
    vis[u]=1;
    for(auto i:rever[u]){
        if(!vis[i])rdfs(i,cnt);
    }
}
signed main(){
    int n,k;
    cin>>n>>k;
    int p[n+1],q[n+1];
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=2;i<=n;i++){
        adj[p[i-1]].push_back(p[i]);
        rever[p[i]].push_back(p[i-1]);
    }
    for(int i=2;i<=n;i++){
        adj[q[i-1]].push_back(q[i]);
        rever[q[i]].push_back(q[i-1]);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    reverse(meta.begin(),meta.end());
    memset(vis,0,sizeof vis);
    int fuck=0;
    for(auto i:meta){
        if(!vis[i])rdfs(i,++fuck);
    }
    if(fuck<k)cout<<"NO\n";
    else{
        cout<<"YES\n";
        string s,t="_";
        for(int i=1;i<=fuck;i++)t+=(char)('a'+min(i,26ll)-1);
        for(int i=1;i<=n;i++)s+=t[sccid[i]];
        cout<<s<<"\n";
    }
}