#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int arr[mxN],idx[mxN],dist[mxN],cc;
vector<int> adj[mxN],meta[mxN];
void dfs(int u){
    idx[u]=cc;
    for(auto i:adj[u]){
        if(arr[u]==arr[i]&&idx[i]==-1)dfs(i);
    }
}
void dfs2(int u){
    for(auto i:meta[u]){
        if(dist[i]>dist[u]+1){
            dist[i]=dist[u]+1;
            dfs2(i);
        }
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(idx,-1,sizeof idx);
    for(int i=1;i<=n;i++){
        if(idx[i]!=-1)continue;
        cc++;
        dfs(i);
    }
    for(int i=1;i<=n;i++){
        for(auto j:adj[i]){
            if(idx[i]!=idx[j])meta[idx[i]].push_back(idx[j]);
        }
    }
    for(int i=1;i<=cc;i++)dist[i]=1e18;
    dist[1]=0;
    dfs2(1);
    int rt=1,maxi=0;
    for(int i=1;i<=cc;i++){
        if(dist[i]>maxi){
            maxi=dist[i];
            rt=i;
        }
    }
    for(int i=1;i<=cc;i++)dist[i]=1e18;
    dist[rt]=0;
    dfs2(rt);
    int ans=0;
    for(int i=1;i<=cc;i++)ans=max(ans,dist[i]);
    cout<<((ans+1)>>1)<<"\n";
}