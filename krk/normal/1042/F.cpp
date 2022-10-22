#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;
const int Inf = 1000000000;

int n, k;
vector <int> neigh[Maxn];
int par[Maxn];
vector <int> D[Maxn];
int mn[Maxn];
int res;

void Get(int v, int p = 0)
{
    if (int(neigh[v].size()) - (p != 0) == 0) {
        par[v] = v;
        D[par[v]].push_back(1); mn[v] = 0;
        return;
    }
    par[v] = v; mn[v] = Inf;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Get(u, v);
        while (mn[v] < D[par[v]].size() && mn[u] < D[par[u]].size() && 2 + mn[v] + mn[u] <= k)
            if (D[par[v]][int(D[par[v]].size()) - 1 - mn[v]] == 0) mn[v]++;
            else if (D[par[u]][int(D[par[u]].size()) - 1 - mn[u]] == 0) mn[u]++;
            else if (mn[v] <= mn[u]) { D[par[v]][int(D[par[v]].size()) - 1 - mn[v]] = 0; mn[v]++; }
            else { D[par[u]][int(D[par[u]].size()) - 1 - mn[u]] = 0; mn[u]++; }
        if (D[par[v]].size() < D[par[u]].size()) swap(par[v], par[u]);
        for (int j = 0; j < D[par[u]].size(); j++)
            D[par[v]][int(D[par[v]].size()) - 1 - j] += D[par[u]][int(D[par[u]].size()) - 1 - j];
        mn[v] = min(mn[v], mn[u]);
    }
    D[par[v]].push_back(0); mn[v]++;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int r = 1;
    while (neigh[r].size() == 1) r++;
    Get(r);
    for (int i = 0; i < D[par[r]].size(); i++)
        res += D[par[r]][i];
    printf("%d\n", res);
    return 0;
}