#include<bits/stdc++.h>
#define maxn 600000
using namespace std;
int n;
char s[maxn];
int pz[maxn];
long long segs[4*maxn];
long long segm[4*maxn];
long long lazy[4*maxn];
inline void propagate(int id,int l,int r) {
    segm[id]+=lazy[id];
    segs[id]+=lazy[id]*(r-l+1);
    if(l!=r) {
        lazy[2*id+1]+=lazy[id];
        lazy[2*id+2]+=lazy[id];
    }
    lazy[id]=0;
}
inline long long tots(int id,int l,int r) {
    propagate(id,l,r);
    return segs[id];
}
inline void add_from(int id,int l,int r,int x,int p) {
    propagate(id,l,r);
    if(l==r) {
        if(segm[id]<p) {
            lazy[id]++;
            propagate(id,l,r);
        }
        return;
    }
    else {
        int id1=id*2+1;
        int id2=id*2+2;
        int m=(l+r)>>1;
        propagate(id1,l,m);
        propagate(id2,m+1,r);
        if(segm[id2]<p) {
            if(r<=x) {
                lazy[id2]++;
                propagate(id2,m+1,r);
            }
            if(m<x && x<r) add_from(id2,m+1,r,x,p);
            add_from(id1,l,m,x,p);
        }
        else add_from(id2,m+1,r,x,p);
        segs[id]=segs[id1]+segs[id2];
        segm[id]=max(segm[id1],segm[id2]);
    }
}
int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    s[0]='0';
    n++;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') pz[i]=i;
        else pz[i]=pz[i-1];
    }
    long long ans=0;
    for(int i=1;i<n;i++) {
        add_from(0,1,n-1,i,i-pz[i]);
        ans+=tots(0,1,n-1);
    }
    printf("%lld",ans);
    return 0;
}