#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,inf=1e18;
struct node{
    int sum,mini;
}segtree[mxN<<2];
int arr[mxN],ok;
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx].sum=1;
        segtree[idx].mini=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
    segtree[idx].mini=min(segtree[idx<<1].mini,segtree[idx<<1|1].mini);
}
void upd(int op,int idx,int l,int r,int x,int v){
    if(l==r){
        if(!op)segtree[idx].sum=v;
        else segtree[idx].mini=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(op,idx<<1,l,mid,x,v);
    else upd(op,idx<<1|1,mid+1,r,x,v);
    if(!op)segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
    else segtree[idx].mini=min(segtree[idx<<1].mini,segtree[idx<<1|1].mini);
}
int eat(int idx,int l,int r,int v){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(segtree[idx<<1].mini==v)return eat(idx<<1,l,mid,v);
    else return eat(idx<<1|1,mid+1,r,v);
}
int qmin(int idx,int l,int r,int x,int y,int v){
    // does this count as parallel binary search? idk haven't written in a long time
    if(l>y||r<x||l>r)return -1;
    if(x<=l&&r<=y){
        if(segtree[idx].mini==v){
            ok=1;
            return eat(idx,l,r,v);
        }
        return -1;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        int lc=qmin(idx<<1,l,mid,x,y,v);
        if(ok)return lc;
    }
    if(mid<r){
        int rc=qmin(idx<<1|1,mid+1,r,x,y,v);
        if(ok)return rc;
    }
    return -1;
}
int qsum(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y)return segtree[idx].sum;
    int mid=(l+r)>>1,ret=0;
    if(x<=mid)ret+=qsum(idx<<1,l,mid,x,y);
    if(mid<r)ret+=qsum(idx<<1|1,mid+1,r,x,y);
    return ret;
}
signed main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        pq.push(arr[i]);
    }
    build(1,1,n);
    int ans=0,ptr=1;
    for(int i=1;i<=n;i++){
        auto x=pq.top();
        pq.pop();
        ok=0;
        int go=qmin(1,1,n,ptr,n,x);
        if(ok)ans+=qsum(1,1,n,ptr,go);
        else{
            go=qmin(1,1,n,1,n,x);
            ans+=qsum(1,1,n,ptr,n)+qsum(1,1,n,1,go);
        }
        upd(0,1,1,n,go,0);
        upd(1,1,1,n,go,inf);
        ptr=go;
    }
    cout<<ans<<"\n";
}