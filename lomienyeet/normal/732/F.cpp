// 
// 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=4e5+5;
int rt,timer,maxi,tin[mxN],low[mxN],go[mxN];
stack<int> st;
vector<pair<int,int> > adj[mxN];
pair<int,int> pp[mxN];
void dfs(int u,int p){
    tin[u]=low[u]=++timer;
    st.push(u);
    go[u]=1;
    for(auto i:adj[u]){
        if(i.ff==p)continue;
        pp[i.ss]={i.ff,u};
        if(!tin[i.ff]){
            dfs(i.ff,u);
            low[u]=min(low[u],low[i.ff]);
        }
        else if(go[i.ff]){
            low[u]=min(low[u],tin[i.ff]);
            swap(pp[i.ss].ff,pp[i.ss].ss);
        }
    }
    if(tin[u]==low[u]){
        int z=0;
        while(st.size()){
            auto x=st.top();
            st.pop();
            go[x]=0;
            z++;
            if(x==u)break;
        }
        if(z>maxi){
            maxi=z;
            rt=u;
        }
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        pp[i]={u,v};
    }
    dfs(1,-1);
    memset(tin,0,sizeof tin);
    dfs(rt,-1);
    cout<<maxi<<"\n";
    for(int i=1;i<=m;i++)cout<<pp[i].ff<<" "<<pp[i].ss<<"\n";
}