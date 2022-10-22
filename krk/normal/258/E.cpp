#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

int all[Maxm], cnt[Maxm];
int n, m;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
vector <ii> quer[Maxn];
int res[Maxn];

int Get(int v, int l, int r)
{
    if (all[v] > 0) return r - l + 1;
    return cnt[v];
}

void Add(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) all[v] += delt;
    else {
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        cnt[v] = Get(2 * v, l, m) + Get(2 * v + 1, m + 1, r);
    }
}

void Traverse(int v, int p = 0)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
    }
    rig[v] = cur;
}

void Solve(int v, int p = 0)
{
    for (int i = 0; i < quer[v].size(); i++)
        Add(1, 1, n, quer[v][i].first, quer[v][i].second, 1);
    Add(1, 1, n, lef[v], lef[v], 1);
    res[v] = Get(1, 1, n) - 1;
    Add(1, 1, n, lef[v], lef[v], -1);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
    }
    for (int i = 0; i < quer[v].size(); i++)
        Add(1, 1, n, quer[v][i].first, quer[v][i].second, -1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        quer[a].push_back(ii(lef[a], rig[a]));
        quer[a].push_back(ii(lef[b], rig[b]));
        quer[b].push_back(ii(lef[a], rig[a]));
        quer[b].push_back(ii(lef[b], rig[b]));
    }
    Solve(1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}