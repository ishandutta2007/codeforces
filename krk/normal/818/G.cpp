#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 6005;
const int Inf = 1000000000;

struct edge {
    int a, b, cap, cost;
    edge(int a = 0, int b = 0, int cap = 0, int cost = 0): a(a), b(b), cap(cap), cost(cost) {}
};

int n;
int a[Maxn];
int N;
vector <edge> E;
vector <int> neigh[Maxn];
int val[Maxn], par[Maxn];

void addEdge(int a, int b, int cap, int cost)
{
    neigh[a].push_back(E.size());
    E.push_back(edge(a, b, cap, cost));
    neigh[b].push_back(E.size());
    E.push_back(edge(b, a, 0, -cost));
}

int Flow()
{
    fill(val, val + Maxn, -Inf); val[0] = 0;
    priority_queue <ii> Q; Q.push(ii(val[0], -0));
    while (!Q.empty()) {
        int v = -Q.top().second;
        int d = Q.top().first; Q.pop();
        if (val[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int e = neigh[v][i];
            if (E[e].cap > 0 && d + E[e].cost > val[E[e].b]) {
                val[E[e].b] = d + E[e].cost;
                par[E[e].b] = e;
                Q.push(ii(val[E[e].b], -E[e].b));
            }
        }
    }
    int v = N - 1;
    int res = val[v];
    while (v) {
        int e = par[v];
        E[e].cap--;
        E[e ^ 1].cap++;
        v = E[e].a;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    N = 2 * n + 2;
    for (int i = 1; i <= n; i++) {
        addEdge(0, 2 * i - 1, 1, 0);
        addEdge(2 * i, N - 1, 1, 0);
        addEdge(2 * i - 1, 2 * i, 1, 1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] % 7 == a[j] % 7 || abs(a[i] - a[j]) == 1)
                addEdge(2 * i, 2 * j - 1, 1, 0);
    int res = 0;
    for (int i = 0; i < 4; i++)
        res += Flow();
    printf("%d\n", res);
    return 0;
}