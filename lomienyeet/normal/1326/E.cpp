#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e5+5;
int n,a[mxN],b[mxN],pos[mxN],segtree[mxN<<2],lazy[mxN<<2]; // try if this way of writing faster (not run time, write time)
void pushdown(int idx){
    if(lazy[idx]){
        segtree[idx<<1]+=lazy[idx];
        segtree[idx<<1|1]+=lazy[idx];
        lazy[idx<<1]+=lazy[idx];
        lazy[idx<<1|1]+=lazy[idx];
        lazy[idx]=0;
    }
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx]+=v;
        lazy[idx]+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx]=max(segtree[idx<<1],segtree[idx<<1|1]);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    upd(1,1,n,1,pos[n],1);
    int z=n;
    cout<<z<<" ";
    for(int i=1;i<n;i++){
        upd(1,1,n,1,b[i],-1);
        while(z&&segtree[1]<=0)upd(1,1,n,1,pos[--z],1);
        cout<<z<<" ";
    }
}