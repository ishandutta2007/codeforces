#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
int p[Maxn];
int sum[Maxn];
int h[Maxn];
vector <int> neigh[Maxn];
bool ok;

int Traverse(int v, int par)
{
    sum[v] = p[v];
    int bad = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == par) continue;
        bad += Traverse(u, v);
        if (!ok) return -1;
        sum[v] += sum[u];
    }
    int my = sum[v] - h[v];
    if (my % 2) { ok = false; return -1; }
    my /= 2;
    if (my < 0 || my - p[v] > bad) { ok = false; return -1; }
    return my;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
            neigh[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        ok = true;
        Traverse(1, 0);
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}