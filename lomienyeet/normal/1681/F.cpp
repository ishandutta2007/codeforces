#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=5e5+5;
int sz[mxN];
pair<int,int> oo[mxN],ee[mxN];
vector<pair<int,int> > adj[mxN];
void eat(int u,int p){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i.ff!=p){
            eat(i.ff,u);
            sz[u]+=sz[i.ff];
        }
    }
}
void dfs(int u,int p){
    for(auto i:adj[u]){
        if(i.ff!=p){
            int aaa=ee[i.ss].ff;
            dfs(i.ff,u);
            oo[i.ff].ff=ee[i.ss].ff-aaa;
            ee[i.ss].ff=sz[i.ff]+aaa;
        }
    }
}
void dfs2(int u,int p){
    for(auto i:adj[u]){
        if(i.ff!=p){
            int aaa=ee[i.ss].ss;
            ee[i.ss].ss=sz[i.ff]-oo[i.ff].ff;
            dfs2(i.ff,u);
            oo[i.ff].ss=ee[i.ss].ss=aaa;
        }
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    eat(1,-1);
    dfs(1,-1);
    for(int i=1;i<=n;i++)ee[i].ss=n-ee[i].ff;
    dfs2(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++)ans+=(sz[i]-oo[i].ff)*oo[i].ss;
    cout<<ans<<"\n";
}