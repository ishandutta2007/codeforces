#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn];
int par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int bi = 1;
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() > neigh[bi].size()) bi = i;
    for (int j = 0; j < neigh[bi].size(); j++) {
        int u = neigh[bi][j];
        if (unionSet(bi, u)) printf("%d %d\n", bi, u);
    }
    for (int i = 1; i <= n; i++) if (i != bi)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (unionSet(i, u)) printf("%d %d\n", i, u);
        }
    return 0;
}