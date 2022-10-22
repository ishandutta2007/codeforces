#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxk = 20;

int n, m;
vector <int> neigh[Maxn];
int par[Maxn], siz[Maxn];
vector <ii> seq;
int cur, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxk];
int BIT[Maxn];
int G;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void Traverse(int v, int p)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        L[u] = L[v] + 1; P[u][0] = v;
        Traverse(u, v);
    }
    rig[v] = cur;
}

void Add(int x, int delt)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] += delt;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int goUp(int a, int b)
{
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) > L[b])
            a = P[a][i];
    return a;
}

void addAll(int a, int b, int lca)
{
    if (a == lca) {
        G++;
        int u = goUp(b, a);
        Add(lef[u], -1);
        Add(rig[u] + 1, 1);
    } else {
        Add(lef[a], 1);
        Add(rig[a] + 1, -1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (unionSet(a, b)) {
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        } else seq.push_back(ii(a, b));
    }
    Traverse(1, 0);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    for (int i = 0; i < seq.size(); i++) {
        int a = seq[i].first, b = seq[i].second;
        int lca = getLCA(a, b);
        addAll(a, b, lca);
        addAll(b, a, lca);
    }
    for (int i = 1; i <= n; i++)
        printf("%d", int(G + Get(lef[i]) == seq.size()));
    printf("\n");
    return 0;
}