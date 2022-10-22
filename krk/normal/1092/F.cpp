#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
ll bot[Maxn];
ll sum[Maxn];
ll res;

void Traverse1(int v, int p = 0)
{
    sum[v] = a[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        sum[v] += sum[u];
        bot[v] += bot[u] + sum[u];
    }
}

void Traverse2(int v, int p, ll tp, ll s)
{
    res = max(res, tp + bot[v]);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse2(u, v, tp + s + bot[v] - (bot[u] + sum[u]) + sum[v] - sum[u], s + sum[v] - sum[u]);
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
    Traverse1(1);
    Traverse2(1, 0, 0, 0);
    cout << res << endl;
    return 0;
}