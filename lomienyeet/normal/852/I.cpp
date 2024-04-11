#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,rt=447,lg=17;
int n,q,timer,ptr,tin[mxN],tout[mxN],euler[mxN],ans[mxN],idx[mxN],arr[mxN],st[lg][mxN],ee[mxN],oo[mxN];
bool wa[mxN],need[mxN];
vector<int> adj[mxN];
void dfs(int u,int p){
    tin[u]=++timer;
    euler[timer]=u;
    for(auto i:adj[u]){
        if(i!=p){
            st[0][i]=u;
            dfs(i,u);
        }
    }
    tout[u]=++timer;
    euler[timer]=u;
}
bool eat(int u,int v){
    return tin[u]<=tin[v]&&tout[v]<=tout[u];
}
int lca(int u,int v){
    if(eat(u,v))return u;
    if(eat(v,u))return v;
    for(int i=lg-1;i>=0;i--){
        if(st[i][u]&&!eat(st[i][u],v))u=st[i][u];
    }
    return st[0][u];
}
struct query{
    int l,r,sz,pp,idx;
    query(){};
    query(int a,int b,int c,int d,int e){l=a,r=b,sz=c,pp=d,idx=e;}
}queries[mxN];
bool cmp(query one,query two){
    if(one.sz==two.sz)return one.r<two.r;
    return one.sz<two.sz;
}
void nom(int x){
    if(wa[x]){
        ptr+=oo[idx[x]];
        ee[idx[x]]++;
    }
    else{
        ptr+=ee[idx[x]];
        oo[idx[x]]++;
    }
}
void uwu(int x){
    if(wa[x]){
        ptr-=oo[idx[x]];
        ee[idx[x]]--;
    }
    else{
        ptr-=ee[idx[x]];
        oo[idx[x]]--;
    }
}
void qwq(int x){
    if(!need[euler[x]])nom(euler[x]);
    else uwu(euler[x]);
    need[euler[x]]^=1;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>wa[i];
    for(int i=1;i<=n;i++){
        cin>>idx[i];
        arr[i]=idx[i];
    }
    sort(arr+1,arr+n+1);
    int weeee=unique(arr+1,arr+n+1)-arr-1;
    for(int i=1;i<=n;i++)idx[i]=lower_bound(arr+1,arr+weeee+1,idx[i])-arr;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=1;i<lg;i++){
        for(int j=1;j<=n;j++){
            if(st[i-1][j]&&st[i-1][st[i-1][j]])st[i][j]=st[i-1][st[i-1][j]];
        }
    }
    cin>>q;
    for(int i=1,u,v;i<=q;i++){
        cin>>u>>v;
        if(tin[u]>tin[v])swap(u,v);
        if(eat(u,v))queries[i]=query(tin[u],tin[v],tin[u]/rt,lca(u,v),i);
        else queries[i]=query(tout[u],tin[v],tout[u]/rt,lca(u,v),i);
    }
    sort(queries+1,queries+q+1,cmp);
    int lb=queries[1].l,rb=queries[1].l-1;
    for(int i=1;i<=q;i++){
        int x=queries[i].l,y=queries[i].r;
        while(x<lb)qwq(--lb);
        while(lb<x)qwq(lb++);
        while(rb<y)qwq(++rb);
        while(y<rb)qwq(rb--);
        if(euler[queries[i].l]!=queries[i].pp)qwq(tin[queries[i].pp]);
        ans[queries[i].idx]=ptr;
        if(euler[queries[i].l]!=queries[i].pp)qwq(tin[queries[i].pp]);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
}