#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxb = 30;

int n, m;
int par[Maxb][Maxn], siz[Maxb][Maxn];
bool drop[Maxb][Maxn];

int getPar(int x, int par[]) { return par[x] == x? x: par[x] = getPar(par[x], par); }

void unionSet(int a, int b, int par[], int siz[], bool drop[])
{
    a = getPar(a, par), b = getPar(b, par);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    drop[a] |= drop[b];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int b = 0; b < Maxb; b++) {
            par[b][i] = i;
            siz[b][i] = 1;
            drop[b][i] = false;
        }
    for (int i = 0; i < m; i++) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        if (!(w & 1))
            for (int j = 0; j < Maxb; j++)
                drop[j][getPar(a, par[j])] = drop[j][getPar(b, par[j])] = true;
        for (int j = 0; j < Maxb; j++) if (w & 1 << j)
            unionSet(a, b, par[j], siz[j], drop[j]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        bool found = false;
        for (int j = 0; j < Maxb && !found; j++) if (getPar(u, par[j]) == getPar(v, par[j]))
            found = true;
        if (found) { printf("0\n"); continue; }
        for (int j = 1; j < Maxb && !found; j++) if (drop[j][getPar(u, par[j])])
            found = true;
        if (found) { printf("1\n"); continue; }
        printf("2\n");
    }
    return 0;
}