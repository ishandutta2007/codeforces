#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 251234
#define M 501234
struct Edge {
    int to, last;
};
Edge map[M<<1];
int top, last[N];
void addEdge(int u, int v) {
    map[++top].to = v;
    map[top].last = last[u];
    last[u] = top;
}
int vis[N];
int sta[N], dep[N], fa[N];
int stop;
int leaves[N], leavtop;
int maxdep, maxid;
void dfs(int w) {
    vis[w] = 1;
    sta[++stop] = w;
    int cnt = 0;
    for (int i = last[w]; i; i = map[i].last) {
        int to = map[i].to;
        if (!vis[to]) {
            dep[to] = dep[w] + 1;
            fa[to] = w;
            dfs(to);
            ++cnt;
        }
    }
    if (cnt == 0) {
        //????
        leaves[++leavtop] = w;
        if (dep[w] > maxdep) {
            maxdep = dep[w];
            maxid = w;
        }
    }
}
void gogogo(int id) {
    printf("PATH\n");
    printf("%d\n", dep[id]);
    while (id) {
        printf("%d ", id);
        id = fa[id];
    }
    printf("\n");
}
void circle(int id) {
    int g1 = 0, g2 = 0;
    for (int i = last[id]; i; i = map[i].last) {
        int to = map[i].to;
        if (dep[to] < dep[id] - 1) {
            if (g1 == 0)
                g1 = to;
            else if (g2 == 0)
                g2 = to;
            else
                break;
        }
    }
    if (dep[g1] > dep[g2])
        swap(g1, g2);
    int l1 = dep[id] - dep[g1] + 1;
    int l2 = dep[id] - dep[g2] + 1;
    int l3 = dep[g2] - dep[g1] + 1 + 1;
    int g = 0;
    if (l1 % 3 != 0) g = g1;
    if (l2 % 3 != 0) g = g2;
    if (g) {
        printf("%d\n", dep[id] - dep[g] + 1);
        while (id != g) {
            printf("%d ", id);
            id = fa[id];
        }
        printf("%d\n", g);
    }
    else {
        printf("%d\n", l3);
        printf("%d\n", id);
        id = g2;
        while (id != g1) {
            printf("%d ", id);
            id = fa[id];
        }
        printf("%d\n", g1);
    }
    //[id, g1]
    //[id, g2]
    //id, [g1,g2]
}
int main() {
    int n, m, k, u, v;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    fa[1] = 0;
    dep[1] = 1;
    dfs(1);
    if (maxdep * k >= n) {
        gogogo(maxid);
    }
    else {
        printf("CYCLES\n");
        for (int i = 1; i <= k; ++i) {
            circle(leaves[i]);
        }
    }
    return 0;
}