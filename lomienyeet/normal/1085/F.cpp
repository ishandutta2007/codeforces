#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int n,q,arr[mxN],segtree[4][mxN<<2];
string s;
void upd(int z,int idx,int l,int r,int x,int v){
    segtree[z][idx]+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)upd(z,idx<<1,l,mid,x,v);
    else upd(z,idx<<1|1,mid+1,r,x,v);
}
int qry(int z,int idx,int l,int r,int x,int y){
    if(l==x&&r==y)return segtree[z][idx];
    int mid=(l+r)>>1;
    if(y<=mid)return qry(z,idx<<1,l,mid,x,y);
    else if(x>mid)return qry(z,idx<<1|1,mid+1,r,x,y);
    else return qry(z,idx<<1,l,mid,x,mid)+qry(z,idx<<1|1,mid+1,r,mid+1,y);
}
int ql(int z,int idx,int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(segtree[z][idx<<1])return ql(z,idx<<1,l,mid);
    else return ql(z,idx<<1|1,mid+1,r);
}
int qr(int z,int idx,int l,int r){
    if(l==r)return r;
    int mid=(l+r)>>1;
    if(segtree[z][idx<<1|1])return qr(z,idx<<1|1,mid+1,r);
    else return qr(z,idx<<1,l,mid);
}
int qql(int z,int idx,int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(segtree[z][idx<<1]!=mid-l+1)return qql(z,idx<<1,l,mid);
    else return qql(z,idx<<1|1,mid+1,r);
}
int qqr(int z,int idx,int l,int r){
    if(l==r)return r;
    int mid=(l+r)>>1;
    if(segtree[z][idx<<1|1]!=r-mid)return qqr(z,idx<<1|1,mid+1,r);
    else return qqr(z,idx<<1,l,mid);
}
void eat(){
    int sum=0;
    for(int i=1,uwu=3;i<6,uwu>0;i+=2,uwu--){ // R, S, P; S, P, R
        int ii=i-(i<=3?0:3),lb=ql(uwu,1,1,n),ub=qr(uwu,1,1,n);
        if(arr[lb]==uwu){
            int ppv1=qql(ii,1,1,n),ppv2=qqr(ii,1,1,n);
            sum+=qry(ii,1,1,n,lb,ub)+n+ppv1-ppv2-1;
        }
        else if(segtree[ii][1]==n)sum+=n;
    }
    cout<<sum<<"\n";
}
signed main(){
    cin>>n>>q>>s;
    s="_"+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='R')arr[i]=1;
        else if(s[i]=='P')arr[i]=2;
        else arr[i]=3;
    }
    for(int i=1;i<=n;i++)upd(arr[i],1,1,n,i,1);
    eat();
    while(q--){
        int x,zz=0;char c;
        cin>>x>>c;
        if(c=='R')zz=1;
        else if(c=='P')zz=2;
        else zz=3;
        upd(arr[x],1,1,n,x,-1);
        upd(zz,1,1,n,x,1);
        arr[x]=zz;
        eat();
    }
}