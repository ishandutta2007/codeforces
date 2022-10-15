#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5;
struct node{
    pair<int,int> val;
    int lazy;
}segtree[mxN<<2];
void pushdown(int idx){
    if(segtree[idx].lazy){
        segtree[idx<<1].val.first+=segtree[idx].lazy;
        segtree[idx<<1].lazy+=segtree[idx].lazy;
        segtree[idx<<1|1].val.first+=segtree[idx].lazy;
        segtree[idx<<1|1].lazy+=segtree[idx].lazy;
        segtree[idx].lazy=0;
    }
}
void build(int idx,int l,int r){
    segtree[idx].lazy=0;
    if(l==r){
        segtree[idx].val={0,l};
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx].val.first+=v;
        segtree[idx].lazy+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    if(x<=mid)upd(idx<<1,l,mid,x,y,v);
    if(mid<y)upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx].val=max(segtree[idx<<1].val,segtree[idx<<1|1].val);
}
pair<int,int> qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return {-1e18,0};
    if(x<=l&&r<=y)return segtree[idx].val;
    pushdown(idx);
    int mid=(l+r)>>1;
    pair<int,int> ans={-1e18,0};
    if(x<=mid)ans=max(ans,qry(idx<<1,l,mid,x,y));
    if(mid<y)ans=max(ans,qry(idx<<1|1,mid+1,r,x,y));
    return ans;
}
signed main(){
    int n;
    cin>>n;
    int a[n+1],b[n+1],c[n+1];
    vector<int> v,adj[n*2+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    v.push_back(v.back()+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin()+1;
        adj[max(a[i],b[i])].push_back(i);
    }
    int z=v.size(),ans=-1e18;
    pair<int,int> ee;
    build(1,1,z);
    for(int i=1;i<=z;i++){
        upd(1,1,z,1,i-1,-(v[i-1]-(i==1?0:v[i-2])));
        for(auto j:adj[i])upd(1,1,z,1,min(a[j],b[j]),c[j]);
        auto x=qry(1,1,z,1,i);
        if(x.first>ans){
            ans=x.first;
            ee={v[x.second-1],v[i-1]};
        }
    }
    cout<<ans<<"\n"<<ee.first<<" "<<ee.first<<" "<<ee.second<<" "<<ee.second<<"\n";
}