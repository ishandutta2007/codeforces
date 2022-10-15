#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,lg=20;
struct node{
    int sum,lazy;
}segtree[lg][mxN<<2];
int arr[mxN];
void pushdown(int lvl,int idx,int l,int r){
    if(segtree[lvl][idx].lazy){
        segtree[lvl][idx].sum=r+1-l-segtree[lvl][idx].sum;
        if(l!=r){
            segtree[lvl][idx<<1].lazy^=1;
            segtree[lvl][idx<<1|1].lazy^=1;
        }
        segtree[lvl][idx].lazy=0;
    }
}
void build(int lvl,int idx,int l,int r){
    if(l==r){
        segtree[lvl][idx].sum=((arr[l]&(1<<lvl))>0);
        return;
    }
    int mid=(l+r)>>1;
    build(lvl,idx<<1,l,mid);
    build(lvl,idx<<1|1,mid+1,r);
    segtree[lvl][idx].sum=segtree[lvl][idx<<1].sum+segtree[lvl][idx<<1|1].sum;
}
void upd(int lvl,int idx,int l,int r,int x,int y){
    pushdown(lvl,idx,l,r);
    if(x<=l&&r<=y){
        segtree[lvl][idx].lazy=1;
        pushdown(lvl,idx,l,r);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(lvl,idx<<1,l,mid,x,y);
    if(mid<y)upd(lvl,idx<<1|1,mid+1,r,x,y);
    pushdown(lvl,idx<<1,l,mid);
    pushdown(lvl,idx<<1|1,mid+1,r);
    segtree[lvl][idx].sum=segtree[lvl][idx<<1].sum+segtree[lvl][idx<<1|1].sum;
}
int qry(int lvl,int idx,int l,int r,int x,int y){
    pushdown(lvl,idx,l,r);
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y)return segtree[lvl][idx].sum;
    int mid=(l+r)>>1,ans=0;
    if(x<=mid)ans+=qry(lvl,idx<<1,l,mid,x,y);
    if(mid<y)ans+=qry(lvl,idx<<1|1,mid+1,r,x,y);
    return ans;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<lg;i++)build(i,1,1,n);
    int m;
    cin>>m;
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int ans=0;
            for(int i=0;i<lg;i++)ans+=qry(i,1,1,n,l,r)*(1<<i);
            cout<<ans<<"\n";
        }
        else{
            int x;
            cin>>x;
            for(int i=0;i<lg;i++){
                if(x&(1<<i))upd(i,1,1,n,l,r);
            }
        }
    }
}