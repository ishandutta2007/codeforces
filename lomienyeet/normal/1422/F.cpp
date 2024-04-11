#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5,mod=1e9+7,rt=450;
int n,cnt,arr[mxN],inv[mxN],wa[mxN],ps[rt/2][mxN],ee[mxN],pp[mxN];
struct node{
    int lc,rc,val;
}segtree[mxN<<5];
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
void upd(int &a,int b,int l,int r,int x,int v){
    a=++cnt;
    segtree[a]=segtree[b];
    (segtree[a].val*=v)%=mod;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)upd(segtree[a].lc,segtree[b].lc,l,mid,x,v);
    else upd(segtree[a].rc,segtree[b].rc,mid+1,r,x,v);
}
int qry(int idx,int l,int r,int x,int y){
    if(!idx||x<=l&&r<=y)return segtree[idx].val;
    int mid=(l+r)>>1,ans=1;
    if(x<=mid)(ans*=qry(segtree[idx].lc,l,mid,x,y))%=mod;
    if(mid<y)(ans*=qry(segtree[idx].rc,mid+1,r,x,y))%=mod;
    return ans;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    inv[0]=1;
    for(int i=1;i<mxN;i++)inv[i]=bm(i,mod-2);
    for(int i=0;i<mxN;i++)wa[i]=1;
    for(int i=2;i<mxN;i++){
        if(wa[i])wa[++cnt]=i;
        for(int j=1;j<=cnt&&i*wa[j]<mxN;j++){
            wa[i*wa[j]]=0;
            if(!(i%wa[j]))break;
        }
    }
    vector<pair<int,int> > weeee;
    for(int i=1;i<=cnt;i++){
        if(wa[i]<=rt){
            int z=wa[i];
            while(z<2e5){
                weeee.push_back({z,wa[i]});
                z*=wa[i];
            }
        }
    }
    for(int i=0;i<weeee.size();i++){
        for(int j=1;j<=n;j++)ps[i][j]=ps[i][j-1]+(!(arr[j]%weeee[i].ff));
    }
    segtree[0].val=1;
    for(int i=1;i<=n;i++){
        ee[i]=ee[i-1];
        int w=arr[i];
        for(int j=2;j*j<=w;j++){
            if(!(w%j)){
                while(!(w%j))w/=j;
                if(j<rt)continue;
                if(pp[j])upd(ee[i],ee[i],1,n,pp[j],inv[j]);
                pp[j]=i;
                upd(ee[i],ee[i],1,n,pp[j],j);
            }
        }
        if(w>rt){
            if(pp[w])upd(ee[i],ee[i],1,n,pp[w],inv[w]);
            pp[w]=i;
            upd(ee[i],ee[i],1,n,pp[w],w);
        }
    }
    int q;
    cin>>q;
    for(int i=1,l,r,ans=0;i<=q;i++){
        cin>>l>>r;
        ((l+=ans)%=n)+=1;
        ((r+=ans)%=n)+=1;
        if(l>r)swap(l,r);
        ans=qry(ee[r],1,n,l,r);
        for(int j=0;j<weeee.size();j++){
            if(ps[j][r]>ps[j][l-1])(ans*=weeee[j].ss)%=mod;
        }
        cout<<ans<<"\n";
    }
}