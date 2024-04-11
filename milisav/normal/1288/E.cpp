#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int ap[maxn],bp[maxn];
int pp[maxn];
int seg[8*maxn];
void update(int id,int l,int r,int x,int v) {
    if(l==r) {
        seg[id]=v;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(id*2+1,l,m,x,v);
    else update(id*2+2,m+1,r,x,v);
    seg[id]=seg[id*2+1]+seg[id*2+2];
}
int query(int id,int l,int r,int x,int y) {
    if(x<=l && r<=y) return seg[id];
    if(r<x) return 0;
    if(y<l) return 0;
    int m=(l+r)>>1;
    return query(id*2+1,l,m,x,y)+query(id*2+2,m+1,r,x,y);
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n;i>=1;i--) {
        ap[i]=bp[i]=i;
        update(0,0,n+m-1,n-i,1);
        pp[i]=n-i;
    }
    for(int j=0;j<m;j++) {
        int a;
        scanf("%d",&a);
        ap[a]=1;
        bp[a]=max(bp[a],query(0,0,n+m-1,pp[a],n+j));
        update(0,0,n+m-1,pp[a],0);
        update(0,0,n+m-1,n+j,1);
        pp[a]=n+j;
    }
    for(int i=1;i<=n;i++) {
        bp[i]=max(bp[i],query(0,0,n+m-1,pp[i],n+m-1));
        printf("%d %d\n",ap[i],bp[i]);
    }
    return 0;
}