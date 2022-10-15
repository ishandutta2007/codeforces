#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int segtree[mxN<<2];
void upd(int idx,int l,int r,int x,int v){
    if(l>x||r<x)return;
    if(l==r){
        segtree[idx]=v;
        return;
    }
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,v);
    upd(idx<<1|1,mid+1,r,x,v);
    segtree[idx]=min(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 1e18;
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    return min(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
}
signed main(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    s="_"+s;
    int dp[n+1];
    memset(dp,0x7f,sizeof dp);
    memset(segtree,0x7f,sizeof segtree);
    dp[0]=0;
    upd(1,0,n,0,0);
    for(int i=1;i<=n;i++){
        int x=min(i+k,n);
        if(s[i]=='0')dp[i]=min(dp[i],dp[i-1]+i);
        else dp[x]=min(dp[x],qry(1,0,n,max(0ll,i-k-1),i)+i);
        upd(1,0,n,x,dp[x]);
        dp[i]=min(dp[i],qry(1,0,n,i+1,n));
        upd(1,0,n,i,dp[i]);
    }
    cout<<dp[n]<<"\n";
}