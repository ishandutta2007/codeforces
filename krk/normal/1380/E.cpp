#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
int a[Maxn];
int par[Maxn];
vector <int> V[Maxn];
int res;

void Update(int ind, int val)
{
    if (ind > 0) res -= a[ind - 1] != a[ind];
    if (ind + 1 < n) res -= a[ind] != a[ind + 1];
    a[ind] = val;
    if (ind > 0) res += a[ind - 1] != a[ind];
    if (ind + 1 < n) res += a[ind] != a[ind + 1];
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (V[a].size() < V[b].size()) swap(a, b);
    for (int i = 0; i < V[b].size(); i++) {
        Update(V[b][i], a);
        V[a].push_back(V[b][i]);
    }
    V[b].clear();
    par[b] = a;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) res += a[i - 1] != a[i];
    }
    for (int i = 1; i <= m; i++)
        par[i] = i;
    for (int i = 0; i < n; i++)
        V[a[i]].push_back(i);
    printf("%d\n", res);
    for (int i = 0; i < m - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(a, b);
        printf("%d\n", res);
    }
    return 0;
}