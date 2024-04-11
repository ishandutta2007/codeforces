#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MX = 5500;
const long long INF = 1E9 + 7;

int n, m, k, c, d;
int u, v, mx, s = MX - 2, t = MX - 1, mf = 0, tr[MX];
long long ans = 0, dis[MX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

struct SEdge
{
    int v, c;
    int ind, cap;
};
vector<SEdge> adj[MX];

void add_edge(int u, int v, int c, int cap)
{
    int s1 = adj[u].size(), s2 = adj[v].size();
    adj[u].push_back((SEdge){v, c, s2, cap});
    adj[v].push_back((SEdge){u, -c, s1, 0});
}

void dijkstra()
{
    fill(dis, dis + MX, INF);
    pq.push({dis[s] = 0, s});
    while (!pq.empty())
    {
        pair<long long, int> u = pq.top();
        pq.pop();
        if (u.fi > dis[u.se])
            continue;
        for (SEdge &ed : adj[u.se])
        {
            if (ed.cap > 0 && dis[ed.v] > u.fi + ed.c)
            {
                tr[ed.v] = ed.ind;
                pq.push({dis[ed.v] = u.fi + ed.c, ed.v});
            }
        }
    }
}

void trace()
{
    int mx = k, v = t;
    while (v != s)
    {
        int u = adj[v][tr[v]].v, ind = adj[v][tr[v]].ind;
        mx = min(mx, adj[u][ind].cap);
        v = u;
    }
    mf += mx; ans += mx * dis[t];
    v = t;
    while (v != s)
    {
        int u = adj[v][tr[v]].v, ind = adj[v][tr[v]].ind;
        adj[v][tr[v]].cap += mx;
        adj[u][ind].cap -= mx;
        v = u;
    }
}

int at(int u, int t)
{
    return u + t * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> c >> d;
    mx = n + k;
    for (int i = 0; i < k; i++)
    {
        cin >> u;
        add_edge(s, at(u, 0), 0, 1);
    }
    for (int i = 0; i <= mx; i++)
        add_edge(at(1, i), t, c * i, k);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < mx; j++)
            add_edge(at(i, j), at(i, j + 1), 0, k);
    while (m--)
    {
        cin >> u >> v;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < mx; j++)
            {
                add_edge(at(u, j), at(v, j + 1), d * (2 * i - 1), 1);
                add_edge(at(v, j), at(u, j + 1), d * (2 * i - 1), 1);
            }
    }
    while (mf < k)
    {
        dijkstra();
        trace();
    }
    cout << ans;
}