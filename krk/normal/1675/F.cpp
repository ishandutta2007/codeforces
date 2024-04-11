#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int x, y;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
bool tk[Maxn];
int res;

void Traverse(int v, int p)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        tk[v] |= tk[u];
    }
    rig[v] = cur;
}

void Add(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (tk[u]) {
            res += 2;
            Add(u, v);
        }
    }
}

void Solve(int v, int p)
{
    if (v == y) Add(v, p);
    else {
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            if (lef[u] <= lef[y] && lef[y] <= rig[u]) {
                res++;
                Solve(u, v);
            } else if (tk[u]) {
                res += 2;
                Add(u, v);
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%d %d", &x, &y);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            tk[i] = false;
        }
        for (int i = 0; i < k; i++) {
            int v; scanf("%d", &v);
            tk[v] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res = 0;
        cur = 0;
        Traverse(x, 0);
        Solve(x, 0);
        printf("%d\n", res);
    }
    return 0;
}