// continue my trash ds journey...

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5;
int n,w,cur,arr[mxN],segtree[mxN<<2],st[mxN<<2];
void pushdown(int x){
    if(!segtree[x])return;
    segtree[x<<1]+=segtree[x];
    segtree[x<<1|1]+=segtree[x];
    segtree[x]=0;
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(x<=l&&r<=y){
        segtree[idx]+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    if(x<=mid)upd(idx<<1,l,mid,x,y,v);
    if(mid<y) upd(idx<<1|1,mid+1,r,x,y,v);
}
int qsum(int idx,int l,int r,int x){
    if(l==r)return segtree[idx];
    pushdown(idx);
    int mid=(l+r)>>1;
    if(x<=mid)return qsum(idx<<1,l,mid,x);
    else return qsum(idx<<1|1,mid+1,r,x);
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    if(arr[st[idx<<1]]>arr[st[idx<<1|1]])st[idx]=st[idx<<1];
    else st[idx]=st[idx<<1|1];
}
int qmax(int idx,int l,int r,int x,int y){
    if(x<=l&&r<=y)return st[idx];
    int mid=(l+r)>>1;
    if(y<=mid)return qmax(idx<<1,l,mid,x,y);
    else if(x>mid)return qmax(idx<<1|1,mid+1,r,x,y);
    else{
        int wa=qmax(idx<<1,l,mid,x,y),we=qmax(idx<<1|1,mid+1,r,x,y);
        if(arr[wa]>arr[we])return wa;
        else return we;
    }
}
void eat(int l,int r,int x,int y){
    if(l>r||x>y)return;
    int s=qmax(1,0,cur+1,l,r),lb=max(s,x),rb=min(w+s-cur,y);
    if(lb<=rb)upd(1,1,w,lb,rb,arr[s]);
    eat(l,s-1,x,lb-1);
    eat(s+1,r,rb+1,y);
}
signed main(){
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>cur;
        for(int j=1;j<=cur;j++)cin>>arr[j];
        arr[0]=arr[cur+1]=0;
        build(1,0,cur+1);
        eat(0,cur+1,1,w);
    }
    for(int i=1;i<=w;i++)cout<<qsum(1,1,w,i)<<" ";
}