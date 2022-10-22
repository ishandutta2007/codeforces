#include<bits/stdc++.h>
using namespace std;
int p[300000];
int a[300000];
int pos[300000];
int n;
long long seg[1500000];
long long lazy[1500000];
void propagate(int id,int l,int r) {
    seg[id]+=lazy[id];
    if(l!=r) {
        lazy[id*2+1]+=lazy[id];
        lazy[id*2+2]+=lazy[id];
    }
    lazy[id]=0;
}
long long query() {
    if(lazy[0]!=0) {
        propagate(0,1,n-1);
    }
    return seg[0];
}
void update(int id,int l,int r,int x,int y,long long val) {
    propagate(id,l,r);
    if(x<=l && r<=y) {
        lazy[id]+=val;
        propagate(id,l,r);
        return;
    }
    if(y<l || r<x) return;
    int m=(l+r)>>1;
    update(id*2+1,l,m,x,y,val);
    update(id*2+2,m+1,r,x,y,val);
    seg[id]=min(seg[2*id+1],seg[2*id+2]);
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    long long ans=0,tot=0;
    for(int i=n-1;i>=1;i--) {
        tot+=a[i];
        update(0,1,n-1,i,i,tot);
    }
    ans=query();
    for(int i=n-1;i>=0;i--) {
        int t=pos[i+1];
        if(t!=0) update(0,1,n-1,1,t,-a[t]);
        if(t!=n-1) update(0,1,n-1,t+1,n-1,a[t]);
        ans=min(ans,query());
    }
    printf("%lld",ans);
    return 0;
}