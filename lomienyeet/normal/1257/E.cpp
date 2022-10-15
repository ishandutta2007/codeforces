// sorry, i do not know how to do anything other than segment tree
// also i gave up using 2 space because it was too ugly

#include <bits/stdc++.h>   
using namespace std;
#define int long long
const int mxN=2e5+5;
int n,a,b,c,las,sum[mxN],colour[mxN],segtree[mxN<<2],lazy[mxN<<2];
void pushdown(int x){
    if(!lazy[x])return;
    lazy[x<<1]+=lazy[x];
    lazy[x<<1|1]+=lazy[x];
    segtree[x<<1]+=lazy[x];
    segtree[x<<1|1]+=lazy[x];
    lazy[x]=0;
}
void upd(int idx,int l,int r,int x,int y,int v){
    if(x>y||x>r||l>y)return;
    if(x<=l&&r<=y){
        segtree[idx]+=v;
        lazy[idx]+=v;
        return;
    }
    pushdown(idx);
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx]=min(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    if(x>y||x>r||l>y)return 122690412;
    if(x<=l&&r<=y)return segtree[idx];
    pushdown(idx);
    int mid=(l+r)>>1,ans=122690412;
    if(x<=mid)ans=min(ans,qry(idx<<1,l,mid,x,y));
    if(mid<y)ans=min(ans,qry(idx<<1|1,mid+1,r,x,y));
    return ans;
}
signed main(){
    cin>>a>>b>>c;
    n=a+b+c;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(i<=a)colour[x]=1;
        else if(i<=a+b)colour[x]=2;
        else colour[x]=3;
    }
    for(int i=n;i>0;i--){
        sum[i]=sum[i+1];
        if(colour[i]!=3)sum[i]++;
        upd(1,1,n+1,i,i,sum[i]);
    }
    for(int i=1;i<=n+1;i++){
        upd(1,1,n+1,i,i,las);
        if(colour[i]!=2)las++;
    }
    int cnt=0,ans=122690412;
    for(int i=1;i<=n;i++){
        ans=min(ans,cnt+qry(1,1,n+1,i,n+1));
        if(colour[i]!=1)cnt++;
        int wao=qry(1,1,n+1,i+1,i+1)-sum[i+1];
        if(wao==1)upd(1,1,n+1,i,n+1,-1);
    }
    cout<<min(ans,cnt)<<"\n";
}