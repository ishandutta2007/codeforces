#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 75;
const long long INF = 1E18 + 7;

int n, m, a, b, u, v, w, cnt = 0, dsu[N], com[N];
long long dis[N][1 << (N / 4)];
vector<pair<int, int>> adj[N];

struct TNode
{
    int ver, msk;
    long long val;

    TNode(int _ver = 0, int _msk = 0, long long _val = 0)
    {
        ver = _ver;
        msk = _msk;
        val = _val;
    }

    inline bool operator>(const TNode &b) const
    {
        return val > b.val;
    }
};
priority_queue<TNode, vector<TNode>, greater<TNode>> pq;

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
        for (int msk = 0; msk < (1 << cnt); msk++)
            dis[i][msk] = INF;
    pq.push((TNode){1, com[1], dis[1][com[1]] = 0});
    while (!pq.empty())
    {
        TNode u = pq.top(); pq.pop();
        if (dis[u.ver][u.msk] > u.val)
            continue;
        for (pair<int, int> &v : adj[u.ver])
            if (v.se == a || (trace(u.ver) != trace(v.fi) && (com[v.fi] == 0 || (u.msk & com[v.fi]) != com[v.fi])))
            {
                TNode tmp = TNode(v.fi, u.msk | com[v.fi], u.val + v.se);
                if (tmp.val < dis[tmp.ver][tmp.msk])
                {
                    dis[tmp.ver][tmp.msk] = tmp.val;
                    pq.push(tmp);
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a >> b;
    fill(dsu + 1, dsu + n + 1, -1);
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (w == a)
            connect(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (dsu[i] < -3)
            com[i] = 1 << (cnt++);
    for (int i = 1; i <= n; i++)
        com[i] = com[trace(i)];
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        long long ans = INF;
        for (int msk = 0; msk < (1 << cnt); msk++)
            ans = min(ans, dis[i][msk]);
        cout << ans << " ";
    }
}