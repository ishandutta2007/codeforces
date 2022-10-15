#include <iostream>
#include <set>
#include <cmath>
using namespace std;
#define int long long
const int mxN=1e6+5;
struct node{
    int sum,lazy;
}segtree[mxN<<2];
void pushdown(int idx){
    if(segtree[idx].lazy){
        segtree[idx<<1].sum+=segtree[idx].lazy;
        segtree[idx<<1].lazy+=segtree[idx].lazy;
        segtree[idx<<1|1].sum+=segtree[idx].lazy;
        segtree[idx<<1|1].lazy+=segtree[idx].lazy;
        segtree[idx].lazy=0;
    }
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx].sum+=v;
        segtree[idx].lazy+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx].sum=min(segtree[idx<<1].sum,segtree[idx<<1|1].sum);
}
int qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0;
    if(x<=l&&r<=y)return segtree[idx].sum;
    pushdown(idx);
    int mid=(l+r)>>1;
    return min(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
}
signed main(){
    int n,k,m;
    cin>>n>>k>>m;
    set<pair<int,int> > s;
    multiset<int,greater<int> > ms;
    for(int i=1;i<=mxN;i++)upd(1,1,mxN,i,i,-i+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        y+=abs(k-x);
        int pp;
        if(s.find({x,y})==s.end()){
            s.insert({x,y});
            pp=-1;
            ms.insert(y);
        }
        else{
            s.erase(s.find({x,y}));
            pp=1;
            ms.erase(ms.find(y));
        }
        upd(1,1,mxN,1,y,pp);
        int l=*ms.begin(),r=mxN,bruh=0;
        while(l<r){
            int mid=(l+r)>>1;
            upd(1,1,mxN,1,mxN,mid-bruh);
            bruh=mid;
            if(qry(1,1,mxN,1,mid)>=0)r=mid;
            else l=mid+1;
        }
        upd(1,1,mxN,1,mxN,-bruh);
        cout<<max(l-n,0ll)<<"\n";
    }
}