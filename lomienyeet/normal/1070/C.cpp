#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5;
vector<pair<int,int> > op[mxN];
int n,m,k,ans=0,segtree[mxN<<2],sum[mxN<<2];
void upd(int idx,int l,int r,int x,int a){
    if(a<l||a>r)return;
    segtree[idx]+=x;
    sum[idx]+=x*a;
    if(l==r)return;
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,a);
    upd(idx<<1|1,mid+1,r,x,a);
}
void eat(int idx,int l,int r,int k){
    if(k>=segtree[idx]){
        ans+=sum[idx];
        return;
    }
    if(k<1)return;
    if(l==r){
        ans+=l*k;
        return;
    }
    int mid=(l+r)>>1;
    eat(idx<<1,l,mid,k);
    eat(idx<<1|1,mid+1,r,k-segtree[idx<<1]);
}
signed main(){
    cin>>n>>k>>m;
    for(int i=0,a,b,c,d;i<m;i++){
        cin>>a>>b>>c>>d;
        op[a].push_back({c,d});
        op[b+1].push_back({-c,d});
    }
    for(int i=1;i<=n;i++){
        for(auto j:op[i])upd(1,1,mxN,j.first,j.second);
        eat(1,1,mxN,k);
    }
    cout<<ans<<"\n";
}