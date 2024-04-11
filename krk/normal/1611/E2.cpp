#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n, k;
vector <int> neigh[Maxn];
int L[Maxn];
bool has[Maxn];
int mn[Maxn];

int Solve(int v, int p)
{
    if (has[v]) {
        mn[v] = L[v];
        return 1;
    }
    int ch = int(neigh[v].size()) - (p != 0);
    if (ch == 0) return Inf;
    int res = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (p == u) continue;
        L[u] = L[v] + 1;
        res = min(Inf, res + Solve(u, v));
        mn[v] = min(mn[v], mn[u]);
    }
    if (mn[v] <= 2 * L[v]) res = 1;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            has[i] = false;
            mn[i] = Inf;
            neigh[i].clear();
        }
        for (int i = 0; i < k; i++) {
            int x; scanf("%d", &x);
            has[x] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        int res = Solve(1, 0);
        printf("%d\n", res >= Inf? -1: res);
    }
    return 0;
}