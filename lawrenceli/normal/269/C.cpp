#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int node, flow, id;
    edge() {}
    edge(int node, int flow, int id) : node(node), flow(flow), id(id) {}
};

const int MAXN = 200100;

int n, m, flow[MAXN], a[MAXN], b[MAXN], c[MAXN], dir[MAXN];
bool vis[MAXN];
vector<edge> adj[MAXN];
queue<int> que;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        a[i]--; b[i]--;
        adj[a[i]].push_back(edge(b[i], c[i], i));
        adj[b[i]].push_back(edge(a[i], c[i], i));
        flow[a[i]] += c[i]; flow[b[i]] += c[i];
        dir[i] = -1;
    }
    for (int i=0; i<n; i++) flow[i] /= 2;
    que.push(0);
    while (!que.empty()) {
        int x = que.front(); que.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i=0; i<adj[x].size(); i++) {
            edge e = adj[x][i];
            if (dir[e.id] != -1) continue;
            dir[e.id] = x == a[e.id] ? 0 : 1;
            flow[adj[x][i].node] -= adj[x][i].flow;
            if (flow[adj[x][i].node] == 0 && adj[x][i].node != n-1) que.push(adj[x][i].node);
        }
    }
    for (int i=0; i<m; i++) printf("%d\n", dir[i]);
    return 0;
}