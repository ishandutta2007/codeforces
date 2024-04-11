// "there is a  array between failing w/o trying & while trying"
// - noob me trying to convince myself to not give up on OI

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,lg=18;
int dfn[mxN],idx[mxN],sz[mxN],dep[mxN],st[lg][mxN],cnt;
vector<int> adj[mxN];
void dfs(int u,int p){
    dfn[u]=++cnt;
    idx[cnt]=u;
    dep[u]=dep[p]+1;
    sz[u]=1;
    st[0][u]=p;
    for(int i=1;i<lg;i++)st[i][u]=st[i-1][st[i-1][u]];
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u);
            sz[u]+=sz[i];
        }
    }
}
int binlift(int u,int v){
    int x=dep[u]-dep[v]-1;
    for(int i=lg-1;i>=0;i--){
        if(x>>i&1)u=st[i][u];
    }
    return u;
}
signed main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    map<int,int> mp;
    int zz=0;
    for(int i=1;i<=n;i++){
        if(!mp.count(arr[i]))mp[arr[i]]=++zz;
        arr[i]=mp[arr[i]];
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    set<int> pp[n+1];
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=n;i++){
        adj[arr[i]].push_back(i);
        pp[arr[i]].insert(dfn[i]);
    }
    int delta[n+1]={};
    for(int i=1;i<=n;i++){
        if(pp[i].empty())continue;
        for(auto j:adj[i]){
            int lb=dfn[j],rb=dfn[j]+sz[j]-1;
            if(lb<rb){
                auto x=pp[i].lower_bound(lb+1);
                if(x!=pp[i].end()&&*(x)<rb){
                    int w=binlift(idx[*(x)],j);
                    delta[1]++;
                    delta[dfn[w]]--;
                    delta[dfn[w]+sz[w]]++;
                }
                auto y=pp[i].upper_bound(rb);
                if(y!=pp[i].begin()){
                    y--;
                    if(lb<*(y)&&*(y)<=rb){
                        int w=binlift(idx[*(y)],j);
                        delta[1]++;
                        delta[dfn[w]]--;
                        delta[dfn[w]+sz[w]]++;
                    }
                }
            }
            if(lb>1){
                auto it=pp[i].begin();
                if(it!=pp[i].end()&&*(it)<lb){
                    delta[dfn[j]]++;
                    delta[rb+1]--;
                }
            }
            if(rb<n){
                auto it=pp[i].lower_bound(rb+1);
                if(it!=pp[i].end()&&*(it)<=n){
                    delta[dfn[j]]++;
                    delta[rb+1]--;
                }
            }
        }
    }
    int ans=0,ps[n+1]={};
    for(int i=1;i<=n;i++){
        ps[i]=ps[i-1]+delta[i];
        ans+=(ps[i]==0);
    }
    cout<<ans<<"\n";
}