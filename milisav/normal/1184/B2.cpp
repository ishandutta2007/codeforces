#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
struct flow {
    int v,c,ir;
};
int inf=1e9+1;
int dist[300][300];
long long s,b,k,h;
int n,m;
vector<pair<int,pair<int,int> > > spaceships;
vector<pair<int,int> > bases;
int p,q;
vector<flow> g[5000];
int lvl[5000];
pair<int,int> par[5000];
void bfs() {
    vector<int> qu;
    qu.push_back(p);
    int id=0;
    int u,v;
    while(id<qu.size()) {
        u=qu[id];
        for(int i=0;i<g[u].size();i++) {
            v=g[u][i].v;
            if(g[u][i].c>0 && lvl[v]==-1) {
                lvl[v]=lvl[u]+1;
                par[v]={u,i};
                qu.push_back(v);
            }
        }
        id++;
    }
}
void augment(int v) {
    if(v==p) return;
    int u=par[v].fs;
    int id=par[v].sc;
    g[u][id].c=0;
    g[v][g[u][id].ir].c=1;
    augment(u);
}
int match() {
    for(int i=0;i<=q;i++) lvl[i]=-1;
    lvl[p]=0;
    bfs();
    int rt=0;
    while(lvl[q]!=-1) {
        augment(q);
        rt++;
        for(int i=0;i<=q;i++) lvl[i]=-1;
        lvl[p]=0;
        bfs();
    }
    return rt;
}
int main() {
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) dist[i][j]=inf;
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        if(u!=v) dist[u][v]=dist[v][u]=1;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    scanf("%lld %lld %lld %lld",&s,&b,&k,&h);
    int x,a,f,d;
    p=0;
    q=s+b+1;
    for(int i=1;i<=s;i++) {
        scanf("%d %d %d",&x,&a,&f);
        spaceships.push_back({x,{a,f}});
        g[p].push_back({i,1,0});
        g[i].push_back({p,0,i-1});
    }
    for(int i=1;i<=b;i++) {
        scanf("%d %d",&x,&d);
        bases.push_back({x,d});
        g[q].push_back({i+s,0,0});
        g[i+s].push_back({q,1,i-1});
    }
    for(int i=0;i<s;i++) {
        for(int j=0;j<b;j++) {
            if(spaceships[i].sc.sc>=dist[spaceships[i].fs][bases[j].fs] && spaceships[i].sc.fs>=bases[j].sc) {
                g[i+1].push_back({j+1+s,1,g[j+1+s].size()});
                g[j+1+s].push_back({i+1,0,g[i+1].size()-1});
            }
        }
    }
    long long t=match();
    printf("%lld",min(t*k,s*h));
    return 0;
}