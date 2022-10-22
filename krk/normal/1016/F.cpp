#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 300005;

int n, m;
vector <ii> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
ll mydist[Maxn];
ll D;
ll mx = -Inf;

void Traverse(int v, int p, ll dist)
{
    mydist[v] = dist;
    if (v == n) D = dist;
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        Traverse(u.first, v, dist + u.second);
    }
    rig[v] = cur;
}

int Count(int v, int p)
{
    int res = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || lef[u] <= lef[n] && lef[n] <= rig[u]) continue;
        res += Count(u, v);
    }
    return res;
}

void getRight(int v, int p, ll cur, bool can = false)
{
    if (can) mx = max(mx, cur);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || lef[u] <= lef[n] && lef[n] <= rig[u]) continue;
        getRight(u, v, cur + neigh[v][i].second, true);
    }
}

void getLeft(int v, int p, ll cur, ll &best, bool can = false)
{
    if (can) best = max(best, cur);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || lef[u] <= lef[n] && lef[n] <= rig[u]) continue;
        getLeft(u, v, cur + neigh[v][i].second, best, true);
    }
}

void Solve(int v, int p, ll best)
{
    if (Count(v, p) > 2) { mx = Inf; return; }
    getRight(v, p, best + D - mydist[v], true);
    if (p) best = max(best, mydist[p]);
    getRight(v, p, best + D - mydist[v]);
    getLeft(v, p, mydist[v], best);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p || lef[n] < lef[u] || rig[u] < lef[n]) continue;
        Solve(u, v, best);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    Traverse(1, 0, 0);
    Solve(1, 0, -Inf);
    while (m--) {
        ll x; scanf("%I64d", &x);
        ll ans = min(D, mx + x);
        printf("%I64d\n", ans);
    }
    return 0;
}