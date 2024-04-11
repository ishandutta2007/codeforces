#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n,m,k;
int d[maxn];
vector<int> a[maxn];
vector<pair<int,bool> > g[maxn];
int p[maxn];
queue<int> q;
void bfs(int t) {
    for(int i=1;i<=n;i++) d[i]=n+5;
    d[t]=0;
    q.push(t);
    int u;
    while(!q.empty()) {
        u=q.front();
        q.pop();
        for(auto v:a[u]) {
            if(d[v]>d[u]+1) {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void rebuild() {
    for(int u=1;u<=n;u++) {
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i].first;
            if(d[u]==d[v]+1) g[u][i].second=true;
        }
    }
}
int main() {
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        a[v].push_back(u);
        g[u].push_back({v,false});
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) scanf("%d",&p[i]);
    bfs(p[k]);
    rebuild();
    int mn=0,mx=0;
    for(int i=1;i<k;i++) {
        int a=p[i];
        int b=p[i+1];
        if(d[a]!=d[b]+1) {
            mn++;
            mx++;
        }
        else {
            int c=0;
            for(auto t:g[a]) if(t.second) c++;
            if(c>1) mx++;
        }
    }
    printf("%d %d",mn,mx);
    return 0;
}