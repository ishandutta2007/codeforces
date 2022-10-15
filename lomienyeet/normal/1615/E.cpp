// this is such a fucking nightmare
//  2400

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
struct node{
    int a,b,lazy;
}segtree[mxN<<2];
int tin[mxN],tout[mxN],up[mxN],timer=0;
vector<int> adj[mxN],adj2[mxN],et;
void dfs(int u,int p){
    et.push_back(u);
    tin[u]=timer++;
    for(auto i:adj[u]){
        if(i!=p){
            adj2[u].push_back(i);
            up[i]=u;
            dfs(i,u);
        }
    }
    tout[u]=timer;
}
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx].a=segtree[idx].lazy=0;
        segtree[idx].b=l;
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx].a=segtree[idx].lazy=0;
    segtree[idx].b=l;
}
void pushdown(int idx){
    segtree[idx<<1].a+=segtree[idx].lazy;
    segtree[idx<<1|1].a+=segtree[idx].lazy;
    segtree[idx<<1].lazy+=segtree[idx].lazy;
    segtree[idx<<1|1].lazy+=segtree[idx].lazy;
    segtree[idx].lazy=0;
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(x>y)return;
    if(x==l&&r==y){
        segtree[idx].a+=v;
        segtree[idx].lazy+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,min(y,mid),v);
    upd(idx<<1|1,mid+1,r,max(x,mid+1),y,v);
    pair<int,int> e={segtree[idx<<1].a,segtree[idx<<1].b},f={segtree[idx<<1|1].a,segtree[idx<<1|1].b};
    pair<int,int> g=max(e,f);
    segtree[idx].a=g.ff;
    segtree[idx].b=g.ss;
}
pair<int,int> qry(int idx,int l,int r,int x,int y){
    if(x>y)return {-1e18,-1};
    if(x<=l&&r<=y)return {segtree[idx].a,segtree[idx].b};
    pushdown(idx);
    int mid=(l+r)>>1;
    return max(qry(idx<<1,l,mid,x,min(y,mid)),qry(idx<<1|1,mid+1,r,max(x,mid+1),y));
}
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    build(1,0,n-1);
    int cnt=0;
    for(int i=0;i<n;i++)cnt+=adj2[i].empty();
    if(cnt<=k){ // special case
        int ans=-1e18;
        for(int i=cnt;i<=k;i++)ans=max(ans,i*(n-i));
        cout<<ans<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++)upd(1,0,n-1,tin[i],tout[i]-1,1);
    for(int i=0;i<n;i++){
        if(adj2[i].size())upd(1,0,n-1,tin[i],tin[i],-1e18);
    }
    int ans=0,vis[n+1]={};
    for(int i=1;i<=k;i++){
        pair<int,int> e=qry(1,0,n-1,0,n-1);
        e.ss=et[e.ss];
        upd(1,0,n-1,tin[e.ss],tout[e.ss]-1,-1e18);
        while(!vis[e.ss]){
            vis[e.ss]=1;
            upd(1,0,n-1,tin[e.ss],tout[e.ss]-1,-1);
            e.ss=up[e.ss];
            ans++;
        }
    }
    int mini=1e18;
    for(int i=0;i<=n-ans;i++)mini=min(mini,(k-i)*(n-k-i));
    cout<<mini<<"\n";
}