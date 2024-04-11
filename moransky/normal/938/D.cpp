#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 200005, M = 600005;
int n, m;
int head[N], numE = 0;
LL dis[N], a[N];
bool vis[N];
struct E{
    int next, v;
    LL w;
}e[M];
void inline add(int u, int v, LL w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}
priority_queue<PLI, vector<PLI>, greater<PLI> > q;
void dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0; q.push(make_pair(0, 0));
    while(!q.empty()) {
        PLI u = q.top(); q.pop();
        if(vis[u.second]) continue;
        vis[u.second] = true;
        for (int i = head[u.second]; ~i; i = e[i].next) {
            int v = e[i].v; 
            if(dis[u.second] + e[i].w < dis[v]) {
                dis[v] = dis[u.second] + e[i].w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}
int main() {
    memset(head, -1, sizeof head);
    scanf("%d%d", &n, &m);

    for (int i = 1, u, v; i <= m; i++) {
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, 2 * w);
        add(v, u, 2 * w);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        add(0, i, a[i]);
    }

    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
}