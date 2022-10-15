// resubmission from practice mashup

// idea: use property of elements being <= 300 at start
// then you can just write a (normal?) segment tree, but lots of implementation

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=4e5+5,mod=1e9+7,mxE=3e2+5;
struct node{
    int os,ms,lazy,lazy2; // or sum, prod, or lazy, mult lazy
}segtree[mxN<<2];
int arr[mxN],ft[mxE],idx[mxE],inv[mxE],bits[mxE];
vector<int> pp;
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
void build(int idx,int l,int r){
    segtree[idx].lazy2=1;
    if(l==r){
        segtree[idx].os=bits[arr[l]];
        segtree[idx].ms=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx].os=(segtree[idx<<1].os|segtree[idx<<1|1].os);
    segtree[idx].ms=(segtree[idx<<1].ms*segtree[idx<<1|1].ms)%mod;
}
void pushdown(int idx,int v){
    segtree[idx].os|=segtree[idx].lazy;
    (segtree[idx].ms*=bm(segtree[idx].lazy2,v))%=mod;
    if(v>1){
        segtree[idx<<1].lazy|=segtree[idx].lazy;
        segtree[idx<<1|1].lazy|=segtree[idx].lazy;
        (segtree[idx<<1].lazy2*=segtree[idx].lazy2)%=mod;
        (segtree[idx<<1|1].lazy2*=segtree[idx].lazy2)%=mod;
    }
    segtree[idx].lazy=0;
    segtree[idx].lazy2=1;
}
void upd(int idx,int l,int r,int x,int y,int v){
    pushdown(idx,r-l+1);
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx].lazy|=bits[v];
        (segtree[idx].lazy2*=v)%=mod;
        pushdown(idx,r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx].os=(segtree[idx<<1].os|segtree[idx<<1|1].os);
    segtree[idx].ms=(segtree[idx<<1].ms*segtree[idx<<1|1].ms)%mod;
}
pair<int,int> qry(int idx,int l,int r,int x,int y){
    pushdown(idx,r-l+1);
    if(l>y||r<x||l>r)return {0,1};
    if(x<=l&&r<=y)return {segtree[idx].os,segtree[idx].ms};
    int mid=(l+r)>>1;
    auto lc=qry(idx<<1,l,mid,x,y),rc=qry(idx<<1|1,mid+1,r,x,y);
    return {lc.ff|rc.ff,(lc.ss*rc.ss)%mod};
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=2;i<=300;i++){
        if(!ft[i]){
            ft[i]=i;
            idx[i]=pp.size();
            pp.push_back(i);
            for(int j=i*2;j<=300;j+=i)ft[j]=i;
        }
    }
    for(int i=2;i<=300;i++){
        for(int j=2;j<=i;j++){
            if(!(i%j)&&ft[j]==j)bits[i]|=(1ll<<idx[j]);
        }
        inv[i]=bm(i,mod-2);
    }
    build(1,1,n);
    while(q--){
        string s;
        cin>>s;
        if(s=="MULTIPLY"){
            int l,r,x;
            cin>>l>>r>>x;
            upd(1,1,n,l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            auto ans=qry(1,1,n,l,r);
            for(int i=0;i<pp.size();i++){
                if(ans.ff&(1ll<<i))(ans.ss*=(1-inv[pp[i]]))%=mod;
            }
            while(ans.ss<0)ans.ss+=mod;
            cout<<ans.ss<<"\n";
        }
    }
}