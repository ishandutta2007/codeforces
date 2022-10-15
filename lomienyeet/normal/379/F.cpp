// thanks to nicholask for inspiring me to do tree decomposition
// sadly i am so fucking trash...
// should just quit oi, not like i can get to noi this year

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=1e6+5; // i forgot every qry adds 2 children.
int chain[mxN],pos[mxN],fro[mxN],sz[mxN],pp[mxN],cnt=1;
vector<int> adj[mxN];
void dfs(int u,int p){
    pp[u]=p;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u);
            sz[u]+=sz[i]+1;
        }
    }
}
void hld(int u,int p){ // will be very happy if this works first try, have not written in a few months
    chain[u]=cnt;
    pos[u]=p;
    if(fro[cnt]==-1)fro[cnt]=u;
    int maxi=-1,ptr=-1;
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i]!=pp[u]){
            if(sz[adj[u][i]]>maxi){
                maxi=sz[adj[u][i]];
                ptr=i;
            }
        }
    }
    if(ptr!=-1){
        hld(adj[u][ptr],p+1);
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]!=pp[u]&&ptr!=i){
                cnt++;
                hld(adj[u][i],1);
            }
        }
    }
}
int calc(int u,int v){
    int ans=0;
    while(chain[u]!=chain[v]){
        if(chain[u]>chain[v]){
            ans+=pos[u];
            u=pp[fro[chain[u]]];
        }
        else{
            ans+=pos[v];
            v=pp[fro[chain[v]]];
        }
    }
    if(pos[u]>pos[v])swap(u,v);
    return ans+pos[v]-pos[u];
}
signed main(){
    int q;
    cin>>q;
    for(int i=1;i<=4;i++){
        if(i==1){
            adj[i].push_back(2);
            adj[i].push_back(3);
            adj[i].push_back(4);
        }
        else adj[i].push_back(1);
    }
    int ptr=5;
    vector<pair<int,int> > qry;
    while(q--){
        int x;
        cin>>x;
        adj[ptr].push_back(x);
        adj[ptr+1].push_back(x);
        adj[x].push_back(ptr);
        adj[x].push_back(ptr+1);
        qry.push_back({ptr,ptr+1});
        ptr+=2;
    }
    memset(fro,-1,sizeof fro);
    dfs(1,-1);
    hld(1,-1);
    int ans=2,lb=2,ub=3;
    for(auto i:qry){
        int x=calc(i.ff,lb),y=calc(i.ff,ub);
        if(x>ans){
            ans=x;
            ub=i.ff;
        }
        if(y>ans){
            ans=y;
            lb=i.ff;
        }
        cout<<ans<<"\n";
    }
}