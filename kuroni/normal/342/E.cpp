#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 100005;

vector<int> adj[N];
vector<pair<int, int>> que[N];
int n, m, t, u, v, sub[N], h[N], ans[N];
bool chk[N];

struct SQuery
{
    int ind, typ, u;
};
vector<SQuery> ve;

int DFS(int u, int p = 0)
{
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p && !chk[v])
            sub[u] += DFS(v, u);
    return sub[u];
}

void init(int u, int p = 0, int dep = 0)
{
    h[u] = dep;
    for (pair<int, int> &q : que[u])
        ve.push_back((SQuery){q.fi, q.se, u});
    for (int &v : adj[u])
        if (v != p && !chk[v])
            init(v, u, dep + 1);
}

void solve(int u, int sz)
{
    ve.clear();
    DFS(u);
    bool cen = false;
    int pre = 0, mi = N;
    while (!cen)
    {
        cen = true;
        for (int &v : adj[u])
            if (v != pre && !chk[v] && sub[v] > sz / 2)
            {
                cen = false;
                pre = u;
                u = v;
                break;
            }
    }
    init(u);
    sort(ve.begin(), ve.end(), [](const SQuery &a, const SQuery &b) {
        return a.ind < b.ind;
    });
    for (SQuery &v : ve)
        if (v.typ == 1)
            mi = min(mi, h[v.u]);
        else
            ans[v.ind] = min(ans[v.ind], h[v.u] + mi);
    chk[u] = true;
    for (int &v : adj[u])
        if (!chk[v])
            solve(v, v == pre ? sz - sub[u] : sub[v]);
}

int main()
{
    scanf("%d%d", &n, &m);
    que[1].push_back(make_pair(0, 1));
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &t, &u);
        que[u].push_back(make_pair(i, t));
        ans[i] = (t == 1 ? -1 : N);
    }
    solve(1, n);
    for (int i = 1; i <= m; i++)
        if (ans[i] > -1)
            printf("%d\n", ans[i]);
}