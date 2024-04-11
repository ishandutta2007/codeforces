#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int mxN=1e5+5;
string s;
struct matrix{
    int a[4][4];
}segtree[mxN<<2];
void nom(int idx,char c){
    memset(segtree[idx].a,63,sizeof segtree[idx].a);
    for(int i=0;i<4;i++)segtree[idx].a[i][i]=0;
    int z=c-'a';
    segtree[idx].a[z][z]=1;
    segtree[idx].a[z][z+1]=0;
}
void pushup(int idx){
    memset(segtree[idx].a,63,sizeof segtree[idx].a);
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            for(int k=i;k<=j;k++)segtree[idx].a[i][j]=min(segtree[idx].a[i][j],segtree[idx<<1].a[i][k]+segtree[idx<<1|1].a[k][j]);
        }
    }
}
void build(int idx,int l,int r){
    if(l==r){
        nom(idx,s[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    pushup(idx);
}
void upd(int idx,int l,int r,int x,char v){
    if(l>x||r<x||l>r)return;
    if(x<=l&&r<=x){
        nom(idx,v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)upd(idx<<1,l,mid,x,v);
    else upd(idx<<1|1,mid+1,r,x,v);
    pushup(idx);
}
signed main(){
    int n,m;
    cin>>n>>m>>s;
    s="_"+s;
    build(1,1,n);
    while(m--){
        int x;char v;
        cin>>x>>v;
        s[x]=v;
        upd(1,1,n,x,v);
        int ans=1e18;
        for(int i=0;i<3;i++){
            for(int j=i;j<3;j++)ans=min(ans,segtree[1].a[i][j]);
        }
        cout<<ans<<"\n";
    }
}