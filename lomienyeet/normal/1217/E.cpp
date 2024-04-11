// resubmit

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,inf=1e18;
struct node{
    int sum,qwq[11];
}segtree[mxN<<2];
int arr[mxN],wa[11],ans;
void pushup(int idx){
    segtree[idx].sum=min(segtree[idx<<1].sum,segtree[idx<<1|1].sum);
    for(int i=1;i<=10;i++){
        segtree[idx].sum=min(segtree[idx].sum,segtree[idx<<1].qwq[i]+segtree[idx<<1|1].qwq[i]);
        segtree[idx].qwq[i]=min(segtree[idx<<1].qwq[i],segtree[idx<<1|1].qwq[i]);
    }
}
void build(int idx,int l,int r){
    segtree[idx].sum=inf;
    if(l==r){
        int z=arr[l];
        for(int i=1;i<=10;i++){
            segtree[idx].qwq[i]=(z%10?arr[l]:inf);
            z/=10;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    pushup(idx);
}
void upd(int idx,int l,int r,int x,int v){
    if(l>x||r<x||l>r)return;
    if(l==r){
        int z=v;
        for(int i=1;i<=10;i++){
            segtree[idx].qwq[i]=(z%10?v:inf);
            z/=10;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(idx<<1,l,mid,x,v);
    else upd(idx<<1|1,mid+1,r,x,v);
    pushup(idx);
}
void qry(int idx,int l,int r,int x,int y){ // wow first time writing void qry in a long time
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        ans=min(ans,segtree[idx].sum);
        for(int i=1;i<=10;i++){
            ans=min(ans,segtree[idx].qwq[i]+wa[i]);
            wa[i]=min(wa[i],segtree[idx].qwq[i]);
        }
        return;
    }
    int mid=(l+r)>>1;
    qry(idx<<1,l,mid,x,y);
    qry(idx<<1|1,mid+1,r,x,y);
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)upd(1,1,n,l,r);
        else{
            for(int i=1;i<=10;i++)wa[i]=ans=inf;
            qry(1,1,n,l,r);
            cout<<(ans==inf?-1:ans)<<"\n";
        }
    }
}