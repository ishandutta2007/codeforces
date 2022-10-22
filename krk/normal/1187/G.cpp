#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxt = 105;
const int Maxn = 52;
const int MaxN = Maxt * Maxn + 2;
const int Inf = 1000000000;

struct edge {
    int a, b, cap, cost;
};

int n, m, k, c, d;
int N;
vector <edge> E;
vector <int> neigh[MaxN];
int dist[MaxN], par[MaxN];

void addEdge(int a, int b, int cap, int cost)
{
    neigh[a].push_back(E.size());
    E.push_back(edge{a, b, cap, cost});
    neigh[b].push_back(E.size());
    E.push_back(edge{b, a, 0, -cost});
}

int getId(int t, int v)
{
    return t * n + v;
}

int getFlow()
{
    fill(dist, dist + N, Inf); dist[0] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
    while (!Q.empty()) {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int e = neigh[v][i];
            if (E[e].cap > 0 && d + E[e].cost < dist[E[e].b]) {
                dist[E[e].b] = d + E[e].cost;
                par[E[e].b] = e;
                Q.push(ii(-dist[E[e].b], E[e].b));
            }
        }
    }
    int v = N - 1;
    int res = dist[v];
    while (v) {
        int e = par[v];
        E[e].cap--; E[e ^ 1].cap++;
        v = E[e].a;
    }
    return res;
}

int main()
{
    scanf("%d %d %d %d %d", &n, &m, &k, &c, &d);
    N = Maxt * n + 2;
    for (int i = 0; i < k; i++) {
        int a; scanf("%d", &a);
        addEdge(0, getId(0, a), 1, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + 1 < Maxt; j++)
            addEdge(getId(j, i), getId(j + 1, i), k, 0);
    for (int j = 0; j < Maxt; j++)
        addEdge(getId(j, 1), N - 1, k, c * j);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        for (int j = 0; j < k; j++)
            for (int t = 0; t + 1 < Maxt; t++) {
                addEdge(getId(t, a), getId(t + 1, b), 1, d * (2 * j + 1));
                addEdge(getId(t, b), getId(t + 1, a), 1, d * (2 * j + 1));
            }
    }
    int res = 0;
    for (int i = 0; i < k; i++)
        res += getFlow();
    printf("%d\n", res);
    return 0;
}