#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9;

int n, m, d;
vector<int> adj[MAXN];
bool dam[MAXN], vis[MAXN];
int dist[MAXN];
int num;

void dfs1(int cur) {
    if (!dam[cur]) dist[cur]=-INF;
    vis[cur]=1;
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i]]) continue;
        dfs1(adj[cur][i]);
        dist[cur]=max(dist[cur], dist[adj[cur][i]]+1);
    }
}

void dfs2(int cur, int d1, int d2) {
    vis[cur]=1;
    if (d1<=d && d2<=d) num++;
    int maxd=-INF, numd=0, max2d=-INF;
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i]]) continue;
        if (dist[adj[cur][i]]>maxd) {
            maxd=dist[adj[cur][i]];
            numd=1;
        }
        else if (dist[adj[cur][i]]==maxd) numd++;
    }
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i]]) continue;
        if (dist[adj[cur][i]]<maxd) max2d=max(max2d, dist[adj[cur][i]]);
    }
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i]]) continue;
        int nd=d1+1;
        if (dam[cur]) nd=max(nd, 1);
        if (dist[adj[cur][i]]!=maxd || numd>1) nd=max(nd, maxd+2);
        else nd=max(nd, max2d+2);
        dfs2(adj[cur][i], nd, dist[adj[cur][i]]);
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &m, &d);
    for (int i=0; i<m; i++) {
        int p;
        scanf("%d", &p);
        p--;
        dam[p]=1;
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0);
    for (int i=0; i<n; i++) vis[i]=0;
    if (dam[0]) dfs2(0, 0, dist[0]);
    else dfs2(0, -INF, dist[0]);
    printf("%d\n", num);
}