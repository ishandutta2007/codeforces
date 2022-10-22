#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int n,q;
int d[maxn];
int lc[maxn][20];
vector<int> a[maxn];
void dfs(int u,int p) {
    for(auto v:a[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            lc[v][0]=u;
            for(int i=1;i<20;i++) lc[v][i]=lc[lc[v][i-1]][i-1];
            dfs(v,u);
        }
    }
}
int lca(int u,int v) {
    if(d[u]>d[v]) swap(u,v);
    int k=0;
    while(d[v]>d[u]) {
        if((d[v]-d[u])&(1<<k)) v=lc[v][k];
        k++;
    }
    k=19;
    while(u!=v) {
        if(lc[u][0]==lc[v][0]) return lc[u][0];
        while(lc[u][k]==lc[v][k]) k--;
        u=lc[u][k];
        v=lc[v][k];
    }
    return u;
}
int dist(int u,int v) {
    return d[u]+d[v]-2*d[lca(u,v)];
}
int main() {
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++) {
        int p;
        scanf("%d",&p);
        a[i].push_back(p);
        a[p].push_back(i);
    }
    dfs(1,0);
    while(q--) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        int u=lca(x,y);
        int v=lca(x,z);
        int w=lca(y,z);
        int t;
        if(d[u]>=d[v] && d[u]>=d[w]) t=u;
        else {
            if(d[v]>=d[w]) t=v;
            else t=w;
        }
        printf("%d\n",max(dist(t,x),max(dist(t,y),dist(t,z)))+1);
    }
    return 0;
}