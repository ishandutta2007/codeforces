#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5,noob=727727727; // special inf for arvindf232
// lets play spfa! (twice)
int n,m,k,fro[mxN<<1],nxt[mxN<<1],to[mxN<<1],cnt=0;
void link(int u,int v){
    cnt++;
    nxt[cnt]=fro[u];
    fro[u]=cnt;
    to[cnt]=v;
}
pair<int,int> segtree[mxN<<2];
void pushup(int x){
    segtree[x].ff=max(segtree[x<<1].ff,segtree[x<<1|1].ff);
    segtree[x].ss=max(segtree[x<<1].ss,segtree[x<<1|1].ss);
}
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx]={-noob,-noob};
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    pushup(idx);
}
void upd(int idx,int l,int r,int x,int a,int b){
    if(l==r){
        segtree[idx].ff=max(segtree[idx].ff,a);
        segtree[idx].ss=max(segtree[idx].ss,b);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(idx<<1,l,mid,x,a,b);
    else upd(idx<<1|1,mid+1,r,x,a,b);
    pushup(idx);
}
int qry(int idx,int l,int r,int x,int y,int op){
    if(l>y||r<x)return -noob;
    if(x<=l&&r<=y)return (op==0?segtree[idx].ff:segtree[idx].ss);
    int mid=(l+r)>>1;
    return max(qry(idx<<1,l,mid,x,y,op),qry(idx<<1|1,mid+1,r,x,y,op));
}
signed main(){
    cin>>n>>m>>k;
    int arr[k+1];
    for(int i=1;i<=k;i++)cin>>arr[i];
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        link(u,v);
        link(v,u);
    }
    queue<int> q;
    int dist[n+1],dist2[n+1];
    for(int i=1;i<=n;i++)dist[i]=dist2[i]=noob;
    dist[1]=0;
    q.push(1);
    while(q.size()){
        auto e=q.front();
        q.pop();
        for(int i=fro[e];i;i=nxt[i]){
            int x=to[i];
            if(dist[x]>dist[e]+1){
                dist[x]=dist[e]+1;
                q.push(x);
            }
        }
    }
    dist2[n]=0;
    q.push(n);
    while(q.size()){
        auto e=q.front();
        q.pop();
        for(int i=fro[e];i;i=nxt[i]){
            int x=to[i];
            if(dist2[x]>dist2[e]+1){
                dist2[x]=dist2[e]+1;
                q.push(x);
            }
        }
    }
    build(1,-n,n);
    int maxi=0;
    for(int i=k;i>0;i--){
        int delta=dist2[arr[i]]-dist[arr[i]],tot=max(qry(1,-n,n,delta,n,0)+delta,qry(1,-n,n,-n,delta,1));
        maxi=max(maxi,tot+dist[arr[i]]);
        upd(1,-n,n,delta,dist[arr[i]],dist2[arr[i]]);
    }
    cout<<min(dist[n],maxi+1)<<"\n";
}