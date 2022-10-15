#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
int ans[mxN],in[mxN],out[mxN],vis[mxN];
signed main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n+1];
    set<pair<int,int> > elist;
    map<pair<int,int>,int> idx;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        elist.insert({u,v});
        idx[{u,v}]=i;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        out[u]+=w;
        out[v]+=w;
    }
    out[n]=1e18;
    queue<int> bfs;
    bfs.push(1);
    while(bfs.size()){
        auto x=bfs.front();
        bfs.pop();
        vis[x]=1;
        for(auto i:adj[x]){
            if(vis[i.ff])continue;
            if(elist.count({x,i.ff}))ans[idx[{x,i.ff}]]=0;
            else ans[idx[{i.ff,x}]]=1;
            in[i.ff]+=i.ss;
            out[i.ff]-=i.ss;
            if(in[i.ff]==out[i.ff])bfs.push(i.ff);
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
    return 0;
}