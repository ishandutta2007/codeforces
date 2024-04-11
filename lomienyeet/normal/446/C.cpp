// i am trash at data structures, how did this take an hour

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e5+5,mod=1e9+9;
int n,m,arr[mxN],fib[mxN<<1];
struct node{
    int sum,a,b;
}segtree[mxN<<4];
void pushup(int idx,int l,int r){
    segtree[idx].a%=mod;
    segtree[idx].b%=mod;
    segtree[idx].sum=((segtree[idx<<1].sum+segtree[idx<<1|1].sum)%mod+(segtree[idx].a*fib[r-l+1]+segtree[idx].b*fib[r-l+2]-segtree[idx].b)%mod)%mod;
}
void lazy(int idx,int l,int r,int x,int y){
    x%=mod;
    y%=mod;
    (segtree[idx].a+=x)%=mod;
    (segtree[idx].b+=y)%=mod;
    pushup(idx,l,r);
}
void pushdown(int idx,int l,int r){
    if(!segtree[idx].a&&!segtree[idx].b)return;
    int mid=(l+r)>>1;
    lazy(idx<<1,l,mid,segtree[idx].a,segtree[idx].b);
    lazy(idx<<1|1,mid+1,r,segtree[idx].a*fib[mid-l]+segtree[idx].b*fib[mid-l+1],segtree[idx].a*fib[mid-l+1]+segtree[idx].b*fib[mid-l+2]);
    segtree[idx].a=segtree[idx].b=0;
}
void upd(int idx,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        lazy(idx,l,r,fib[l-x+1],fib[l-x+2]);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(idx,l,r);
    if(x<=mid)upd(idx<<1,l,mid,x,y);
    if(mid<y)upd(idx<<1|1,mid+1,r,x,y);
    pushup(idx,l,r);
}
int qry(int idx,int l,int r,int x,int y){
    if(x<=l&&r<=y)return segtree[idx].sum;
    int mid=(l+r)>>1,ans=0;
    pushdown(idx,l,r);
    if(x<=mid)(ans+=qry(idx<<1,l,mid,x,y))%=mod;
    if(mid<y)(ans+=qry(idx<<1|1,mid+1,r,x,y))%=mod;
    return ans;
}
signed main(){
    cin>>n>>m;
    fib[1]=fib[2]=1;
    for(int i=3;i<n*2;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)(arr[i]+=arr[i-1])%=mod;
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op&1)upd(1,1,n,l,r);
        else cout<<(((arr[r]-arr[l-1]+qry(1,1,n,l,r))%mod+mod)%mod)<<"\n";
    }
}