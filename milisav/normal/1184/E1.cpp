#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int p[200000];
int n,m;
vector<pair<pair<int,int>,pair<int,int> > > e;
int par(int u) {
    if(u==p[u]) return u;
    p[u]=par(p[u]);
    return p[u];
}
bool pos(int t) {
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++) {
        if(e[i].fs.sc==0) e[i].fs.fs=t;
    }
    sort(e.begin(),e.end());
    for(int i=0;i<m;i++) {
        int u,v,w,id;
        w=e[i].fs.fs;
        id=e[i].fs.sc;
        u=e[i].sc.fs;
        v=e[i].sc.sc;
        u=par(u);
        v=par(v);
        if(id==0) {
            if(u==v) return false;
            else return true;
        }
        else p[v]=u;
    }
}
int main() {
    int u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d %d",&u,&v,&w);
        e.push_back({{w,i},{u,v}});
    }
    //sort(e.begin(),e.end());
    int l=0;
    int r=1000000000;
    int mid;
    while(l<r) {
        mid=(l+r+1)>>1;
        if(pos(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}