#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int t;
int n;
int a[maxn];
int pos[maxn];
int fl[maxn];
int fg[maxn];
int minseg[4*maxn];
int maxseg[4*maxn];
void cons_seg(int id,int l,int r) {
    if(l==r) {
        minseg[id]=maxseg[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    cons_seg(id*2+1,l,m);
    cons_seg(id*2+2,m+1,r);
    minseg[id]=min(minseg[id*2+1],minseg[id*2+2]);
    maxseg[id]=max(maxseg[id*2+1],maxseg[id*2+2]);
}
int find_min(int id,int l,int r,int x,int y) {
    if(r<x || y<l) return n+1;
    if(x<=l && r<=y) return minseg[id];
    int m=(l+r)/2;
    return min(find_min(id*2+1,l,m,x,y),find_min(id*2+2,m+1,r,x,y));
}
int find_max(int id,int l,int r,int x,int y) {
    if(r<x || y<l) return 0;
    if(x<=l && r<=y) return maxseg[id];
    int m=(l+r)/2;
    return max(find_max(id*2+1,l,m,x,y),find_max(id*2+2,m+1,r,x,y));
}
int nxmin(int u);
int nxmax(int u);

int nxmin(int u) {
    if(u==n) return 0;
    int p=fg[u];
    if(p==u+1) return 1e9;
    return 1+nxmax(pos[find_min(0,1,n,u+1,p-1)]);
}
int nxmax(int u) {
    if(u==n) return 0;
    int p=fl[u];
    if(p==u+1) return 1e9;
    return 1+nxmin(pos[find_max(0,1,n,u+1,p-1)]);
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        fg[n]=fl[n]=n+1;
        for(int i=n-1;i>=1;i--) {
            fg[i]=i+1;
            while(fg[i]!=n+1 && a[fg[i]]<a[i]) fg[i]=fg[fg[i]];
            fl[i]=i+1;
            while(fl[i]!=n+1 && a[fl[i]]>a[i]) fl[i]=fl[fl[i]];
        }
        cons_seg(0,1,n);
        printf("%d\n",min(nxmin(1),nxmax(1)));
    }
    return 0;
}