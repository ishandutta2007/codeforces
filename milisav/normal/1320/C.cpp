#include<bits/stdc++.h>
#define maxn 3000000
typedef long long int lld;
using namespace std;
struct pts {
    int x,y,z;
};
int n,m,p;
pair<int,int> a[maxn];
pair<int,int> b[maxn];
pts c[maxn];
lld seg[4*maxn];
lld laz[4*maxn];
lld inf=1e15;
bool operator < (pts g,pts h) {
    return g.x<h.x;
}
void prop(int id,int l,int r) {
    if(l==r) {
        seg[id]+=laz[id];
        laz[id]=0;
        return;
    }
    seg[id]+=laz[id];
    laz[2*id+1]+=laz[id];
    laz[2*id+2]+=laz[id];
    laz[id]=0;
}
void update(int id,int l,int r,int x,int y,lld v) {
    prop(id,l,r);
    if(r<x) return;
    if(y<l) return;
    if(x<=l && r<=y) {
        laz[id]+=v;
        prop(id,l,r);
        return;
    }
    int m=(l+r)>>1;
    update(id*2+1,l,m,x,y,v);
    update(id*2+2,m+1,r,x,y,v);
    seg[id]=max(seg[id*2+1],seg[id*2+2]);
    //cout<<l<<" "<<r<<" "<<seg[id]<<" "<<v<<endl;
}
lld query(int id,int l,int r,int x) {
    prop(id,l,r);
    if(l>=x) return seg[id];
    if(r<x) return -inf;
    int m=(l+r)>>1;
    return max(query(id*2+1,l,m,x),query(id*2+2,m+1,r,x));
}
int maxv=1500000;
int main() {
    scanf("%d %d %d",&n,&m,&p);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(int i=0;i<m;i++) {
        scanf("%d %d",&b[i].first,&b[i].second);
    }
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<=maxv;i++) {
        //cout<<-inf<<endl;
        update(0,0,maxv,i,i,-inf);
    }
    for(int i=0;i<m;i++) {
        if(i==0 || b[i-1].first!=b[i].first) {
            update(0,0,maxv,b[i].first,b[i].first,inf-b[i].second);
        }
    }
    for(int i=0;i<p;i++) {
        scanf("%d %d %d",&c[i].x,&c[i].y,&c[i].z);
    }
    sort(c,c+p);
    int k=0;
    lld ans=-inf;
    for(int i=0;i<n;i++) {
        while(k<p && c[k].x<a[i].first) {
            update(0,0,maxv,c[k].y+1,maxv,c[k].z);
            k++;
        }
        //cout<<a[i].second<<" "<<query(0,0,maxv,0)<<endl;
        ans=max(ans,-a[i].second+query(0,0,maxv,0));
    }
    printf("%lld",ans);
    return 0;
}