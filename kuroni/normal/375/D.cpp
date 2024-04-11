#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005, MX = 100005, M = 100005;

int n, m, u, v, a[N], cnt[MX], bit[MX], sub[N], ans[M];
bool chk[N];
vector<int> adj[N];
vector<pair<int, int>> que[N];

void upd(int u, int v)
{
    for (; u > 0; u -= u & -u)
        bit[u] += v;
}

int get(int u)
{
    int ret = 0;
    for (; u < MX; u += u & -u)
        ret += bit[u];
    return ret;
}

int DFS(int u, int p = 0)
{
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p)
            sub[u] += DFS(v, u);
    return sub[u];
}

void add(int u, int p, int val)
{
    upd(cnt[a[u]], -1);
    upd(cnt[a[u]] += val, 1);
    for (int &v : adj[u])
        if (v != p && !chk[v])
            add(v, u, val);
}

void find_ans(int u, bool keep = false, int p = 0)
{
    chk[u] = keep;
    int mc = 0;
    for (int &v : adj[u])
        if (v != p && sub[v] > sub[mc])
            mc = v;
    for (int &v : adj[u])
        if (v != p && v != mc)
            find_ans(v, false, u);
    if (mc != 0)
        find_ans(mc, true, u);
    add(u, p, 1);
    for (pair<int, int> &v : que[u])
        ans[v.second] = get(v.first);
    chk[mc] = false;
    if (!keep)
        add(u, p, -1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        que[u].push_back(make_pair(v, i));
    }
    find_ans(1, true);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
}