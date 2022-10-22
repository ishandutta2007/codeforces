#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int q;
int n;
vector <int> neigh[Maxn];
int best[Maxn][2];
int res;

void Traverse(int v, int p = 0)
{
    best[v][0] = best[v][1] = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        if (best[u][0] > best[v][0])
            best[v][1] = best[v][0], best[v][0] = best[u][0];
        else if (best[u][0] > best[v][1])
            best[v][1] = best[u][0];
    }
    res = max(res, best[v][0] + 1 + best[v][1] + max(0, int(neigh[v].size()) - 2));
    res = max(res, best[v][0] + 1 + max(0, int(neigh[v].size()) - 1));
    best[v][0]++;
    best[v][0] += max(0, int(neigh[v].size()) - int(p != 0) - 1);
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res = 0;
        Traverse(1);
        printf("%d\n", res);
    }
    return 0;
}