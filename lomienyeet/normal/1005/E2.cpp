#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,cao=mxN-2;
int segtree[2][mxN<<3];
void upd(int lvl,int idx,int l,int r,int x,int y,int v){ // l,r,idx,x,y,v,lvl
    if(l>r||l>y||r<x)return;
    if(x<=l&&r<=y){
        segtree[lvl][idx]+=v;
        return;
    }
    int mid=(l+r)>>1;
    upd(lvl,idx<<1,l,mid,x,y,v);
    upd(lvl,idx<<1|1,mid+1,r,x,y,v);
    segtree[lvl][idx]=segtree[lvl][idx<<1]+segtree[lvl][idx<<1|1];
}
int qry(int lvl,int idx,int l,int r,int x,int y){ // l,r,idx,x,y,lvl
    if(l>r||l>y||r<x)return 0;
    if(x<=l&&r<=y)return segtree[lvl][idx];
    int mid=(l+r)>>1;
    return qry(lvl,idx<<1,l,mid,x,y)+qry(lvl,idx<<1|1,mid+1,r,x,y);
}
signed main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int ans=0,lb=0,ub=0;
    for(int i=1;i<=n;i++){
        if(arr[i]<=m)lb--;
        else lb++;
        if(arr[i]<m)ub--;
        else ub++;
        if(lb<1){
            upd(0,1,0,cao<<1,lb+cao,lb+cao,1);
            ans+=qry(0,1,0,cao<<1,lb+cao,cao<<1);
        }
        else{
            ans+=qry(0,1,0,cao<<1,lb+cao,cao<<1);
            upd(0,1,0,cao<<1,lb+cao,lb+cao,1);
        }
        if(ub<1){
            upd(1,1,0,cao<<1,ub+cao,ub+cao,1);
            ans-=qry(1,1,0,cao<<1,ub+cao,cao<<1);
        }
        else{
            ans-=qry(1,1,0,cao<<1,ub+cao,cao<<1);
            upd(1,1,0,cao<<1,ub+cao,ub+cao,1);
        }
    }
    cout<<ans<<"\n";
}