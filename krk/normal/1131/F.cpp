#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, cur;
int par[Maxn], siz[Maxn], col[Maxn];
vector <int> neigh[Maxn];
vector <int> res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    cur++;
    neigh[cur].push_back(col[a]);
    neigh[cur].push_back(col[b]);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a; col[a] = cur;
}

void Print(int v)
{
    if (v <= n) res.push_back(v);
    else for (int i = 0; i < neigh[v].size(); i++)
            Print(neigh[v][i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1, col[i] = i;
    cur = n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(a, b);
    }
    Print(cur);
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}