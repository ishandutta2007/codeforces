#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10015;

struct edge {
    int a, b, cap;
    edge(int a = 0, int b = 0, int cap = 0): a(a), b(b), cap(cap) {}
};

int n, m;
int p[Maxn];
int c[Maxn];
bool rem[Maxn];
int D;
vector <int> seq[Maxn];
int res[Maxn];
int N;
vector <edge> E;
vector <int> neigh[Maxn];
int flow[Maxn], par[Maxn];

void addEdge(int a, int b, int cap)
{
    neigh[a].push_back(E.size());
    E.push_back(edge(a, b, cap));
    neigh[b].push_back(E.size());
    E.push_back(edge(b, a, 0));
}

bool getFlow()
{
    vector <int> Q; Q.push_back(0);
    fill(flow, flow + N, 0); flow[0] = 1;
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        if (v == N - 1) break;
        for (int i = 0; i < neigh[v].size(); i++) {
            int e = neigh[v][i];
            if (E[e].cap > 0 && !flow[E[e].b]) {
                flow[E[e].b] = 1;
                par[E[e].b] = e;
                Q.push_back(E[e].b);
            }
        }
    }
    int v = N - 1;
    if (!flow[v]) return false;
    while (v) {
        int e = par[v];
        E[e].cap--;
        E[e ^ 1].cap++;
        v = E[e].a;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m); N = m + 5003 + 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    scanf("%d", &D);
    for (int i = 0; i < D; i++) {
        int k; scanf("%d", &k);
        seq[i].push_back(k);
        rem[k] = true;
    }
    for (int i = 1; i <= m; i++)
        addEdge(0, i, 1);
    for (int i = 1; i <= n; i++) if (!rem[i])
        addEdge(c[i], m + 1 + p[i], 1);
    int cur = 0;
    addEdge(m + 1 + cur, N - 1, 1);
    while (getFlow()) {
        cur++;
        addEdge(m + 1 + cur, N - 1, 1);
    }
    for (int i = D - 1; i >= 0; i--) {
        res[i] = cur;
        for (int j = 0; j < seq[i].size(); j++) {
            int v = seq[i][j];
            rem[v] = false;
            addEdge(c[v], m + 1 + p[v], 1);
        }
        while (getFlow()) {
            cur++;
            addEdge(m + 1 + cur, N - 1, 1);
        }
    }
    for (int i = 0; i < D; i++)
        printf("%d\n", res[i]);
    return 0;
}