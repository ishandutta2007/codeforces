#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn], sum[Maxn];
vector <int> neigh[Maxn];
set <int> S[Maxn];
int par[Maxn];
int res;

bool Union(int a, int b, int val)
{
    if (S[par[a]].size() < S[par[b]].size()) swap(a, b);
    for (auto el: S[par[b]])
        if (S[par[a]].find(el ^ val) != S[par[a]].end())
            return false;
    for (auto el: S[par[b]])
        S[par[a]].insert(el);
    S[par[b]].clear(); par[b] = par[a];
    return true;
}

void Traverse(int v, int p, int prv)
{
    sum[v] = (prv ^ a[v]);
    par[v] = v;
    bool ch = a[v] == 0;
    S[par[v]].insert(sum[v]);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, sum[v]);
        if (!ch)
            if (!Union(v, u, a[v]))
                ch = true;
    }
    if (ch) {
        res++;
        S[par[v]].clear();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0, 0);
    printf("%d\n", res);
    return 0;
}