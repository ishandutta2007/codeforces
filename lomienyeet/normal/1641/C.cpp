#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int ans[mxN],pos[mxN];
struct qr{
    int op,l,r,x,z;
}que[mxN];
struct node{
    int sum,maxi,lazy,len;
}segtree[mxN<<2];
void build(int idx,int l,int r){
    segtree[idx].len=r-l+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
}
void pushdown(int idx){
    if(segtree[idx].lazy){
        segtree[idx<<1].lazy=segtree[idx].lazy;
        segtree[idx<<1|1].lazy=segtree[idx].lazy;
        segtree[idx].lazy=0;
    }
}
void pushup(int idx,int l,int r){
    if(l==r){
        if(segtree[idx].lazy){
            segtree[idx].sum=1;
            segtree[idx].maxi=segtree[idx].lazy;
            ans[l]=-1;
            pos[l]=segtree[idx].lazy;
        }
        else segtree[idx].sum=segtree[idx].maxi=0;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    pushup(idx<<1,l,mid);
    pushup(idx<<1|1,mid+1,r);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
    segtree[idx].maxi=max(segtree[idx<<1].maxi,segtree[idx<<1|1].maxi);
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx].lazy=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
}
int qsum(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y)return segtree[idx].sum;
    int mid=(l+r)>>1;
    return qsum(idx<<1,l,mid,x,y)+qsum(idx<<1|1,mid+1,r,x,y);
}
int qmax(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y)return segtree[idx].maxi;
    int mid=(l+r)>>1;
    return max(qmax(idx<<1,l,mid,x,y),qmax(idx<<1|1,mid+1,r,x,y));
}
int qpos(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y){
        if(segtree[idx].sum==segtree[idx].len)return 0;
        if(l==r)return l;
        int mid=(l+r)>>1;
        if(segtree[idx<<1].sum!=segtree[idx<<1].len)return qpos(idx<<1,l,mid,x,y);
        else return qpos(idx<<1|1,mid+1,r,x,y);
    }
    int mid=(l+r)>>1,wao=qpos(idx<<1,l,mid,x,y);
    return (wao?wao:qpos(idx<<1|1,mid+1,r,x,y));
}
signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        cin>>que[i].op;
        if(!que[i].op)cin>>que[i].l>>que[i].r>>que[i].x;
        else cin>>que[i].z;
    }
    build(1,1,n);
    for(int i=q;i>0;i--){
        if(!que[i].op&&!que[i].x)upd(1,1,n,que[i].l,que[i].r,i);
    }
    for(int i=1;i<=n;i++)pos[i]=q+1;
    pushup(1,1,n);
    for(int i=1;i<=q;i++){
        if(!que[i].op&&que[i].x){
            if(qsum(1,1,n,que[i].l,que[i].r)!=que[i].r-que[i].l)continue;
            int d=qpos(1,1,n,que[i].l,que[i].r),t=qmax(1,1,n,que[i].l,que[i].r);
            ans[d]=1;
            pos[d]=min(pos[d],max(t,i));
        }
    }
    for(int i=1;i<=q;i++){
        if(que[i].op){
            int x=que[i].z;
            if(!ans[x]||pos[x]>i)cout<<"N/A\n";
            else cout<<((ans[x]^1)?"NO\n":"YES\n");
        }
    }
}