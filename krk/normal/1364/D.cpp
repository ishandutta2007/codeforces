#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Inf = 1000000000;

int n, m, k;
vector <int> neigh[Maxn];
int tk[Maxn], par[Maxn];
int dist[Maxn];
vector <int> L[2];

void Solve(int a, int b)
{
    int i = 0;
    while (neigh[a][i] != b) i++;
    neigh[a].erase(neigh[a].begin() + i);
    i = 0;
    while (neigh[b][i] != a) i++;
    neigh[b].erase(neigh[b].begin() + i);
    vector <int> Q; Q.push_back(a);
    fill(dist, dist + Maxn, Inf); dist[a] = 0;
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                par[u] = v;
                Q.push_back(u);
            }
        }
    }
    vector <int> seq;
    seq.push_back(b);
    do {
        b = par[b];
        seq.push_back(b);
    } while (a != b);
    if (seq.size() <= k) {
        printf("2\n");
        printf("%d\n", int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    } else {
        int nd = (k + 1) / 2;
        printf("1\n");
        for (int i = 0; i < nd; i++)
            printf("%d%c", seq[2 * i], i + 1 < nd? ' ': '\n');
    }
}

bool Cycle(int v, int p)
{
    if (tk[v] == 2) return false;
    if (tk[v] == 1) {
        Solve(v, p);
        return true;
    }
    tk[v] = 1;
    par[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (Cycle(u, v)) return true;
    }
    tk[v] = 2;
    return false;
}

void Tree(int v, int p, int lvl)
{
    L[lvl].push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Tree(u, v, (lvl + 1) % 2);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    if (!Cycle(1, 0)) {
        Tree(1, 0, 0);
        if (L[0].size() < L[1].size()) swap(L[0], L[1]);
        int nd = (k + 1) / 2;
        printf("1\n");
        for (int i = 0; i < nd; i++)
            printf("%d%c", L[0][i], i + 1 < nd? ' ': '\n');
    }
    return 0;
}