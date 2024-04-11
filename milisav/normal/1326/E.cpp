#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
pair<int,int> seg[maxn];
int p[maxn];
int q[maxn];
int fipos[maxn];
int n;
void add(int id,int l,int r,int x,int v) {
    if(l==r) {
        if(v==-1) {
            seg[id].second++;
        }
        else {
            seg[id].first++;
        }
        if(seg[id].first==seg[id].second && seg[id].first==1) {
            seg[id].first=0;
            seg[id].second=0;
        }
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) add(id*2+1,l,m,x,v);
    else add(id*2+2,m+1,r,x,v);
    int t=seg[id*2+2].second-seg[id*2+1].first;
    if(t>=0) {
        seg[id].first=seg[id*2+2].first;
        seg[id].second=seg[id*2+1].second+t;
    }
    else {
        seg[id].first=seg[id*2+2].first-t;
        seg[id].second=seg[id*2+1].second;
    }
}
int query() {
    return seg[0].first;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        fipos[p[i]]=i;
    }
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    add(0,1,n,fipos[n],1);
    printf("%d ",n);
    int b=n;
    for(int i=1;i<n;i++) {
        add(0,1,n,q[i],-1);
        while(query()==0) {
            b--;
            add(0,1,n,fipos[b],1);
        }
        printf("%d ",b);
    }
    return 0;
}