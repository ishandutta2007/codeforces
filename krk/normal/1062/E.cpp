#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;

int n, q;
int P[Maxn][Maxm], L[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int inlef[Maxn];
int mn[Maxn][Maxm], mx[Maxn][Maxm];

void Traverse(int v)
{
    lef[v] = ++cur; inlef[lef[v]] = v;
    mn[v][0] = mx[v][0] = lef[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        P[u][0] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
    rig[v] = cur;
}

int getMin(int l, int r)
{
    int res = Maxn;
    for (int i = Maxm - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = min(res, mn[l][i]);
            l += 1 << i;
        }
    return res;
}

int getMax(int l, int r)
{
    int res = -Maxn;
    for (int i = Maxm - 1; i >= 0; i--)
        if (l + (1 << i) <= r + 1) {
            res = max(res, mx[l][i]);
            l += 1 << i;
        }
    return res;
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int getDoubleMin(int l, int r, int av)
{
    int lef = Maxn;
    if (l < av) lef = min(lef, getMin(l, av - 1));
    if (av < r) lef = min(lef, getMin(av + 1, r));
    return lef;
}

int getDoubleMax(int l, int r, int av)
{
    int rig = -Maxn;
    if (l < av) rig = max(rig, getMax(l, av - 1));
    if (av < r) rig = max(rig, getMax(av + 1, r));
    return rig;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
            if (i + (1 << j) <= n + 1) {
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
            }
        }
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int lef = getMin(l, r), rig = getMax(l, r);
        int a1 = inlef[lef], b1 = L[getLCA(inlef[getDoubleMin(l, r, inlef[lef])], inlef[rig])];
        int a2 = inlef[rig], b2 = L[getLCA(inlef[lef], inlef[getDoubleMax(l, r, inlef[rig])])];
        if (b1 < b2) swap(a1, a2), swap(b1, b2);
        printf("%d %d\n", a1, b1);
    }
    return 0;
}