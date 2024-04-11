#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxk = 21;
const int Maxm = 1048576;

int n, q;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int P[Maxn][Maxk], L[Maxn];
int st[Maxm], wh[Maxm];
set <ii> S;

void Traverse(int v)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        P[u][0] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
    rig[v] = cur;
}

int Get(int v)
{
    if (st[v] > 0) return 0;
    return wh[v];
}

void Create(int v, int l, int r)
{
    st[v] = 0; wh[v] = r - l + 1;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) st[v] += delt;
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        wh[v] = Get(2 * v) + Get(2 * v + 1);
    }
}

int goUp(int a, int b)
{
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) > L[b])
            a = P[a][i];
    return a;
}

void Update(int a, int b, int delt)
{
    if (lef[a] > lef[b]) swap(a, b);
    if (lef[a] <= lef[b] && lef[b] <= rig[a]) {
        int u = goUp(b, a);
        if (lef[u] < lef[b])
            Update(1, 1, n, lef[u], lef[b] - 1, delt);
        if (rig[b] < rig[u])
            Update(1, 1, n, rig[b] + 1, rig[u], delt);
    } else {
        if (1 < lef[a])
            Update(1, 1, n, 1, lef[a] - 1, delt);
        if (rig[a] + 1 < lef[b])
            Update(1, 1, n, rig[a] + 1, lef[b] - 1, delt);
        if (rig[b] < n)
            Update(1, 1, n, rig[b] + 1, n, delt);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    Create(1, 1, n);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        if (S.find(ii(u, v)) != S.end()) {
            S.erase(ii(u, v));
            Update(u, v, -1);
        } else {
            S.insert(ii(u, v));
            Update(u, v, 1);
        }
        printf("%d\n", Get(1));
    }
    return 0;
}