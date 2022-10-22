#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn];
int in[Maxn];
bool tk[Maxn];
int res[Maxn];

int Get(int v)
{
    if (tk[v]) return res[v];
    tk[v] = true;
    res[v] = 1;
    if (neigh[v].size() == 1) return res[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (in[u] > 1) res[v] = max(res[v], Get(u) + 1);
    }
    return res[v];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        in[b]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, Get(i));
    printf("%d\n", res);
    return 0;
}