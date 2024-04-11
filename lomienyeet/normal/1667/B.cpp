#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=5e5+5;
int segtree[3][mxN<<2];
void build(int idx,int l,int r){
    for(int i=0;i<3;i++)segtree[i][idx]=-1e18;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
}
void upd(int lvl,int idx,int l,int r,int x,int v){
    if(l>x||r<x||l>r)return;
    if(x<=l&&r<=x){
        segtree[lvl][idx]=max(segtree[lvl][idx],v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(lvl,idx<<1,l,mid,x,v);
    else upd(lvl,idx<<1|1,mid+1,r,x,v);
    segtree[lvl][idx]=max(segtree[lvl][idx<<1],segtree[lvl][idx<<1|1]);
}
int qry(int lvl,int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return -1e18;
    if(x<=l&&r<=y)return segtree[lvl][idx];
    int mid=(l+r)>>1;
    return max(qry(lvl,idx<<1,l,mid,x,y),qry(lvl,idx<<1|1,mid+1,r,x,y));
}
void eat(){
    int n,cnt=0;
    cin>>n;
    int arr[n+1],ps[n+1]={};
    pair<int,int> pp[n+1];
    pp[0]={0,0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ps[i]=ps[i-1]+arr[i];
        pp[i]={ps[i],i};
    }
    sort(pp,pp+n+1);
    ps[pp[0].second]=++cnt;
    for(int i=1;i<=n;i++){
        cnt+=(pp[i-1].first!=pp[i].first);
        ps[pp[i].second]=cnt;
    }
    build(1,1,cnt);
    for(int i=0;i<3;i++)upd(i,1,1,cnt,ps[0],0);
    for(int i=1;i<=n;i++){
        int z=max({qry(0,1,1,cnt,1,ps[i]-1)+i,qry(1,1,1,cnt,ps[i]+1,cnt)-i,qry(2,1,1,cnt,ps[i],ps[i])});
        upd(0,1,1,cnt,ps[i],z-i);
        upd(1,1,1,cnt,ps[i],z+i);
        upd(2,1,1,cnt,ps[i],z);
        if(i==n)cout<<z<<"\n";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}