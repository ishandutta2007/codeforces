#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
vector <int> neigh[Maxn];
ll BIT[Maxn];
vector <ii> my[Maxn];
ll res[Maxn];

void Add(int ind, int val)
{
    for (int i = ind; i > 0; i -= i & -i)
        BIT[i] += val;
}

ll Get(int ind)
{
    ll res = 0;
    for (int i = ind; i < Maxn; i += i & -i)
        res += BIT[i];
    return res;
}

void Solve(int v, int p, int lvl)
{
    for (int i = 0; i < my[v].size(); i++) {
        int addlvl = min(lvl + my[v][i].first, Maxn - 1);
        Add(addlvl, my[v][i].second);
    }
    res[v] = Get(lvl);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v, lvl + 1);
    }
    for (int i = 0; i < my[v].size(); i++) {
        int addlvl = min(lvl + my[v][i].first, Maxn - 1);
        Add(addlvl, -my[v][i].second);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int m; scanf("%d", &m);
    while (m--) {
        int v, d, x; scanf("%d %d %d", &v, &d, &x);
        my[v].push_back(ii(d, x));
    }
    Solve(1, 0, 1);
    for (int i = 1; i <= n; i++)
        printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}