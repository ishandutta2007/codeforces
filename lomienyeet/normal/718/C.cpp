// i think i kinda need a matrix template
// ewwwwwww cant write *= i want to vomit

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,mod=1e9+7;
struct matrix{
    int a[2][2];
    matrix(int b,int c,int d,int e){
        a[0][0]=b;
        a[0][1]=c;
        a[1][0]=d;
        a[1][1]=e;
    }
    matrix(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)a[i][j]=0;
        }
    }
    void identity(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)a[i][j]=(i==j);
        }
    }
    matrix operator+(const matrix &mat)const{
        matrix ans;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)ans.a[i][j]=(a[i][j]+mat.a[i][j])%mod;
        }
        return ans;
    }
    matrix operator*(const matrix &mat)const{
        matrix ans;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++)(ans.a[i][j]+=(a[i][k]*mat.a[k][j])%mod)%=mod;
            }
        }
        return ans;
    }
};
matrix bm(matrix b,int p){
    matrix ans;
    ans.identity();
    while(p){
        if(p&1)ans=ans*b;
        b=b*b;
        p>>=1;
    }
    return ans;
}
struct node{
    matrix sum,lazy;
}segtree[mxN<<2];
void build(int idx,int l,int r){
    segtree[idx].lazy.identity();
    if(l==r){
        segtree[idx].sum.identity();
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
}
void pushdown(int idx,int l,int r){
    if(l>r)return;
    segtree[idx].sum=segtree[idx].sum*segtree[idx].lazy;
    if(l<r){
        segtree[idx<<1].lazy=segtree[idx<<1].lazy*segtree[idx].lazy;
        segtree[idx<<1|1].lazy=segtree[idx<<1|1].lazy*segtree[idx].lazy;
    }
    segtree[idx].lazy.identity();
}
void upd(int idx,int l,int r,int x,int y,matrix v){
    pushdown(idx,l,r);
    if(l>y||r<x||l>r)return;
    if(x<=l&&r<=y){
        segtree[idx].lazy=segtree[idx].lazy*v;
        pushdown(idx,l,r);
        return;
    }
    int mid=(l+r)>>1;
    upd(idx<<1,l,mid,x,y,v);
    upd(idx<<1|1,mid+1,r,x,y,v);
    segtree[idx].sum=segtree[idx<<1].sum+segtree[idx<<1|1].sum;
}
matrix qry(int idx,int l,int r,int x,int y){
    pushdown(idx,l,r);
    if(l>y||r<x||l>r)return matrix();
    if(x<=l&&r<=y)return segtree[idx].sum;
    int mid=(l+r)>>1;
    return qry(idx<<1,l,mid,x,y)+qry(idx<<1|1,mid+1,r,x,y);
}
signed main(){
    int n,m;
    cin>>n>>m;
    build(1,1,n);
    for(int i=1,x;i<=n;i++){
        cin>>x;
        upd(1,1,n,i,i,bm(matrix(1,1,1,0),x));
    }
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op&1){
            int x;
            cin>>x;
            upd(1,1,n,l,r,bm(matrix(1,1,1,0),x));
        }
        else{
            matrix ans=qry(1,1,n,l,r);
            cout<<ans.a[0][1]<<"\n";
        }
    }
}