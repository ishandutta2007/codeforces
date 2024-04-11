#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int p[200000];
int n,m;
bool in_mst[2000000];
bool o[200000];
int d[200000];
int lca[200000][20];
int max_edge[200000][20];
int ans[2000000];
vector<pair<int,int> > a[200000];
vector<pair<pair<int,int>,pair<int,int> > > e;
int par(int u) {
    if(u==p[u]) return u;
    p[u]=par(p[u]);
    return p[u];
}
void mst() {
    for(int i=1;i<=n;i++) p[i]=i;
    sort(e.begin(),e.end());
    for(int i=0;i<m;i++) {
        int u,v,w,id;
        w=e[i].fs.fs;
        id=e[i].fs.sc;
        u=e[i].sc.fs;
        v=e[i].sc.sc;
        u=par(u);
        v=par(v);
        if(u!=v) {
            p[v]=u;
            u=e[i].sc.fs;
            v=e[i].sc.sc;
            in_mst[id]=true;
            a[v].push_back({u,w});
            a[u].push_back({v,w});
        }
    }
}
void dfs(int u) {
    o[u]=true;
    int v,w;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i].fs;
        w=a[u][i].sc;
        if(!o[v]) {
            p[v]=u;
            d[v]=d[u]+1;
            lca[v][0]=u;
            max_edge[v][0]=w;
            int k=1;
            while(k<20) {
                lca[v][k]=lca[lca[v][k-1]][k-1];
                max_edge[v][k]=max(max_edge[v][k-1],max_edge[lca[v][k-1]][k-1]);
                k++;
            }
            dfs(v);
        }
    }
    o[u]=false;
}
int maximal_edge(int u,int v) {
    if(d[v]>d[u]) swap(u,v);
    int l=0;
    int mv=0;
    while(d[u]>d[v]) {
        if((d[u]-d[v])&(1<<l)) {
            mv=max(mv,max_edge[u][l]);
            u=lca[u][l];
        }
        l++;
    }
    l=19;
    while(u!=v) {
        while(lca[u][l]==lca[v][l] && l>0) l--;
        mv=max(mv,max_edge[u][l]);
        mv=max(mv,max_edge[v][l]);
        u=lca[u][l];
        v=lca[v][l];
    }
    return mv;
}
int main() {
    int u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d %d",&u,&v,&w);
        e.push_back({{w,i},{u,v}});
    }
    mst();
    p[1]=1;
    for(int i=0;i<20;i++) {
        lca[1][i]=1;
        max_edge[1][i]=0;
    }
    dfs(1);
    for(int i=0;i<m;i++) {
        if(!in_mst[e[i].fs.sc]) {
            ans[e[i].fs.sc]=maximal_edge(e[i].sc.fs,e[i].sc.sc);
        }
    }
    for(int i=0;i<m;i++) {
        if(!in_mst[i]) printf("%d\n",ans[i]);
    }
    return 0;
}