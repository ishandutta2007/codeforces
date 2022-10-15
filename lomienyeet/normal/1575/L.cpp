// this is so sad, only capable of brainless standard task mashing

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
int n,arr[mxN],c[mxN],dp[mxN],segtree[mxN<<2];
pair<int,int> p[mxN];
void eat(int idx,int l,int r,int x,int v){
    if(l+1==r){
        segtree[idx]=max(segtree[idx],v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<mid)eat(idx<<1,l,mid,x,v);
    else eat(idx<<1|1,mid,r,x,v);
    segtree[idx]=max(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    if(x>=r||l>=y)return -1e9;
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    return max(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid,r,x,y));
}
signed main(){
    cin>>n;
    if(n==1){
        int x;
        cin>>x;
        cout<<(x==1)<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
        c[i]=i-arr[i]+1;
        p[i]={arr[i],i};
    }
    sort(p,p+n);
    for(int i=1;i<mxN<<2;i++)segtree[i]=-1e9;
    int ni=-1;
    stack<pair<int,int> > upd;
    for(int i=0;i<n;i++){
        if(c[p[i].ss]<0){
            dp[p[i].ss]=-1e9;
            continue;
        }
        if(arr[p[i].ss]<=p[i].ss+1)dp[p[i].ss]=1;
        if(ni!=p[i].ff){
            ni=p[i].ff;
            while(upd.size()){
                auto e=upd.top();
                upd.pop();
                eat(1,0,n-1,e.ff,e.ss);
            }
        }
        dp[p[i].ss]=max(dp[p[i].ss],qry(1,0,n-1,0,c[p[i].ss]+1)+1);
        upd.push({c[p[i].ss],dp[p[i].ss]});
    }
    while(upd.size()){
        auto e=upd.top();
        upd.pop();
        eat(1,0,n-1,e.ff,e.ss);
    }
    cout<<max(segtree[1],0ll)<<"\n";
}