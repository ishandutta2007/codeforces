#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
static char pbuf[1<<19],*p1=pbuf,*p2=pbuf,obuf[1<<19],*o=obuf;
#define gc() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1<<19,stdin),p1==p2)?EOF:*p1++
#define pc(x) (o-obuf<1<<19)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int read(){
    int x=0;register int c=gc();
    while(c<48||c>57)c=gc();
    while(c>=48&&c<=57){x=(x<<1)+(x<<3)+c-48;c=gc();}
    return x;
}
inline void write(int x){
    if(x>9)write(x/10);
    pc(x%10+48);
}
#define ff first
#define ss second
const int mxN=5e5+5,inf=9e18;
int n,q,timer=0,v[mxN],l[mxN],r[mxN],tin[mxN],tout[mxN],dist[mxN],ans[mxN],segtree[mxN<<2],lazy[mxN<<2];
vector<pair<int,int> > adj[mxN];
vector<int> wao;
deque<int> queries[mxN];
void dfs(int u,int p){ // fun
    wao.push_back(u);
    tin[u]=timer++;
    for(auto i:adj[u]){
        if(i.ff!=p){
            dist[i.ff]=dist[u]+i.ss;
            dfs(i.ff,u);
            wao.push_back(u);
        }
    }
    tout[u]=timer-1;
}
void pushdown(int idx,int l,int r){
    if(lazy[idx]){
        segtree[idx]+=lazy[idx];
        if(l<r){
            lazy[idx<<1]+=lazy[idx];
            lazy[idx<<1|1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
}
void upd(int idx,int l,int r,int x,int y,int v){
    pushdown(idx,l,r);
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        lazy[idx]=v;
        pushdown(idx,l,r);
        return;
    }
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx]=min(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    pushdown(idx,l,r);
    if(l>y||r<x||l>r)return inf;
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    return min(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
}
signed main(){
    n=read();q=read();
    for(int i=1,v,w;i<n;i++){
        v=read()-1;w=read();
        adj[i].push_back({v,w});
        adj[v].push_back({i,w});
    }
    for(int i=0;i<n;i++)sort(adj[i].begin(),adj[i].end());
    dfs(0,-1);
    for(int i=0;i<q;i++){
        v[i]=read()-1;
        l[i]=read()-1;
        r[i]=read()-1;
        queries[v[i]].push_back(i);
    }
    // do some stupid shit here.
    for(int i=0;i<n;i++){
        if(i>0&&adj[i].size()==1)upd(1,0,n-1,i,i,dist[i]);
        else upd(1,0,n-1,i,i,inf);
    }
    for(int i=0;i<wao.size();i++){
        if(i>0){
            if(tin[wao[i]]<=tin[wao[i-1]]&&tout[wao[i]]>=tout[wao[i-1]])upd(1,0,n-1,tin[wao[i-1]],tout[wao[i-1]],2*(dist[wao[i-1]]-dist[wao[i]])); // standard calculations lol
            else upd(1,0,n-1,tin[wao[i]],tout[wao[i]],2*(dist[wao[i-1]]-dist[wao[i]]));
        }
        while(queries[wao[i]].size()){
            auto e=queries[wao[i]].back();
            queries[wao[i]].pop_back();
            ans[e]=qry(1,0,n-1,l[e],r[e])+dist[v[e]];
        }
    }
    for(int i=0;i<q;i++){
        write(ans[i]);
        pc(10);
    }
    fwrite(obuf,o-obuf,1,stdout);
}