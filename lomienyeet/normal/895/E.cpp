#include <bits/stdc++.h>
#pragma GCC optimize("O3","inline","unroll-loops")
#pragma GCC option("arch=native","tune=native","no-zero-upper","D_GLIBCXX_PARALLEL")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx,bmi,bmi2,lzcnt")
using namespace std;
#define int long long
#define double long double
static char pbuf[1<<19],*p1=pbuf,*p2=pbuf,obuf[1<<19],*o=obuf;
#define gc() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1<<19,stdin),p1==p2)?EOF:*p1++
inline int read(){
    int x=0;register int c=gc();
    while(c<48||c>57)c=gc();
    while(c>=48&&c<=57){x=(x<<1)+(x<<3)+c-48;c=gc();}
    return x;
}
const int mxN=1e5+5;
double arr[mxN];
struct node{
    double sum,lazy,lazy2; // range sum, multiply tag, add tag
}segtree[mxN<<2];
void build(int idx,int l,int r){
    segtree[idx].lazy=1.0;
    segtree[idx].lazy2=0.0;
    if(l==r){
        segtree[idx].sum=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
}
void pushdown(int idx,int l,int r){
    int mid=(l+r)>>1;
    if(segtree[idx].lazy!=1.0){ // 
        segtree[idx<<1].lazy*=segtree[idx].lazy;
        segtree[idx<<1|1].lazy*=segtree[idx].lazy;
        segtree[idx<<1].lazy2*=segtree[idx].lazy;
        segtree[idx<<1|1].lazy2*=segtree[idx].lazy;
        segtree[idx<<1].sum*=segtree[idx].lazy;
        segtree[idx<<1|1].sum*=segtree[idx].lazy;
        segtree[idx].lazy=1.0;
    }
    if(segtree[idx].lazy2!=0.0){
        segtree[idx<<1].lazy2+=segtree[idx].lazy2;
        segtree[idx<<1|1].lazy2+=segtree[idx].lazy2;
        segtree[idx<<1].sum+=segtree[idx].lazy2*(mid-l+1);
        segtree[idx<<1|1].sum+=segtree[idx].lazy2*(r-mid);
        segtree[idx].lazy2=0.0;
    }
}
void upd(int type,int idx,int l,int r,int x,int y,double v){
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        if(type==1){ // add
            segtree[idx].sum+=v*(r-l+1);
            segtree[idx].lazy2+=v;
        }
        else if(type==2){ // multiply
            segtree[idx].sum*=v;
            segtree[idx].lazy*=v;
            segtree[idx].lazy2*=v;
        }
        return;
    }
    pushdown(idx,l,r);
    int mid=(l+r)>>1;
    upd(type,idx<<1,l,mid,x,y,v);
    upd(type,idx<<1|1,mid+1,r,x,y,v);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
}
double qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return 0.0;
    if(x<=l&&r<=y)return segtree[idx].sum;
    pushdown(idx,l,r);
    int mid=(l+r)>>1;
    return qry(idx<<1,l,mid,x,y)+qry(idx<<1|1,mid+1,r,x,y);
}
signed main(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++)arr[i]=(double)read()*1.0;
    build(1,1,n);
    while(q--){
        int op=read();        
        if(op&1){
            int l=read(),r=read(),lb=read(),rb=read();
            int wa=r-l+1,wb=rb-lb+1,wc=wa*wb;
            double s1=qry(1,1,n,l,r),s2=qry(1,1,n,lb,rb);
            // lets calculate how to do expected value??????????????
            upd(2,1,1,n,l,r,1.0*(wa-1)/wa);
            upd(1,1,1,n,l,r,1.0*s2/wc);
            upd(2,1,1,n,lb,rb,1.0*(wb-1)/wb);
            upd(1,1,1,n,lb,rb,1.0*s1/wc);
        }
        else{
            int l=read(),r=read();
            cout<<fixed<<setprecision(6)<<qry(1,1,n,l,r)<<"\n";
        }
    }
}