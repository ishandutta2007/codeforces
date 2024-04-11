#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005, M = 200005, D = 650;

int n, m, lst = 0, cnt = 0, it = 0, dsu[N], vis[N];
bool chk[2 * M], cur[2 * M];
pair<int, int> ed[2 * M];
map<pair<int, int>, int> ma;
vector<pair<int, int>> adj[N];

struct SQuery
{
    int typ, u, v;
} a[M];

int get_index(int u, int v)
{
    if (u > v)
        swap(u, v);
    if (ma[{u, v}] == 0)
    {
        ed[++cnt] = {u, v};
        ma[{u, v}] = cnt;
    }
    return ma[{u, v}];
}

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int ind)
{
    int u = ed[ind].fi, v = ed[ind].se;
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

void add_edge(int ind)
{
    int u = trace(ed[ind].fi), v = trace(ed[ind].se);
    adj[u].push_back({v, ind});
    adj[v].push_back({u, ind});
}

bool DFS(int u, int des)
{
    vis[u] = it;
    if (u == des)
        return true;
    for (pair<int, int> &v : adj[u])
        if (chk[v.se] && vis[v.fi] < it && DFS(v.fi, des))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].typ >> a[i].u >> a[i].v;
        a[i].u--; a[i].v--;
        if (a[i].typ == 1)
        {
            get_index(a[i].u, a[i].v);
            get_index((a[i].u + 1) % n, (a[i].v + 1) % n);
        }
    }
    for (int bl = 0; bl <= (m - 1) / D; bl++)
    {
        for (int i = 0; i < n; i++)
        {
            dsu[i] = -1;
            adj[i].clear();
        }
        fill(cur + 1, cur + cnt + 1, false);
        for (int i = bl * D; i < m && i < (bl + 1) * D; i++)
            if (a[i].typ == 1)
                cur[get_index(a[i].u, a[i].v)] = cur[get_index((a[i].u + 1) % n, (a[i].v + 1) % n)] = true;
        for (int i = 1; i <= cnt; i++)
            if (cur[i])
                add_edge(i);
            else if (chk[i])
                connect(i);
        for (int i = bl * D; i < m && i < (bl + 1) * D; i++)
            if (a[i].typ == 1)
                chk[get_index((a[i].u + lst) % n, (a[i].v + lst) % n)] ^= 1;
            else
            {
                it++;
                cout << (lst = DFS(trace((a[i].u + lst) % n), trace((a[i].v + lst) % n)));
            }
    }
}