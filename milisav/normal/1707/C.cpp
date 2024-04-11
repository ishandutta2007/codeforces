#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int p[maxn];
vector<pair<int,int> > eg;
int n,m;
int par(int u) {
    if(u==p[u]) return u;
    p[u]=par(p[u]);
    return p[u];
}
vector<int> a[maxn];
bool vis[maxn];
int lc[maxn][20];
int d[maxn];
int tot[maxn];
int pcalc[maxn];
void dfs(int u) {
    vis[u]=true;
    for(auto v:a[u]) {
        if(!vis[v]) {
            d[v]=d[u]+1;
            lc[v][0]=u;
            for(int k=1;k<20;k++) lc[v][k]=lc[lc[v][k-1]][k-1];
            dfs(v);
        }
    }
}
int lca(int u,int v) {
    if(d[u]<d[v]) {
        swap(u,v);
    }
    int k=0;
    while(d[u]>d[v]) {
        if((d[u]-d[v])&(1<<k)) u=lc[u][k];
        k++;
    }
    k=19;
    while(lc[u][0]!=lc[v][0]) {
        while(lc[u][k]==lc[v][k]) k--;
        u=lc[u][k];
        v=lc[v][k];
    }
    if(u==v) return u;
    else return lc[u][0];
}
int al=0;
int calc(int u,int sm=0) {
    int ret=sm+pcalc[u];
    for(auto v:a[u]) {
        if(v!=lc[u][0]) {
            calc(v,ret);
        }
    }
    //cout<<u<<" "<<ret<<endl;
    tot[u]=tot[u]+ret+al;
    return ret;
}
int step(int u,int de) {
    int k=0;
    while(d[u]>de) {
        if((d[u]-de)&(1<<k)) u=lc[u][k];
        k++;
    }
    return u;
}
char s[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        int x=par(u);
        int y=par(v);
        if(x!=y) {
            a[u].push_back(v);
            a[v].push_back(u);
            p[y]=x;
        }
        else {
            eg.push_back({u,v});
        }
    }
    int ki=2;
    dfs(ki);
    //cout<<"ok"<<endl;
    for(auto qr:eg) {
        int u=qr.first;
        int v=qr.second;
        int w=lca(u,v);
        //cout<<u<<" "<<v<<" "<<w<<endl;
        if(u==w || v==w) {
            if(u==w) swap(u,v);
            al++;
            pcalc[step(u,d[v]+1)]--;
            pcalc[u]++;
        }
        else {
            pcalc[u]++;
            pcalc[v]++;
        }
    }
    calc(ki);
    for(int i=1;i<=n;i++) {
        //cout<<tot[i]<<endl;
        if(tot[i]==eg.size()) s[i-1]='1';
        else s[i-1]='0';
    }
    printf("%s",s);
    return 0;
}