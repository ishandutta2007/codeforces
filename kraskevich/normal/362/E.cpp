#include <bits/stdc++.h>

using namespace std;


struct MinCost
{
    struct edge
    {
        int from, to, cap, flow, cost;
        edge(int _from = 0, int _to = 0, int _cap = 0, int _cost = 0): from(_from), to(_to), cap(_cap), flow(0), cost(_cost) {}
        bool open()
        {
            return cap > flow;
        }
    };

    const static int INF = 1000 * 1000 * 1000;
    vector<edge> E;
    vector<vector<int> > g;
    vector<int> d;
    vector<int> par;
    vector<int> pe;
    vector<int> phi;
    vector<bool> u;
    int n, s, t;

    void init(int sz)
    {
        n = sz;
        g.assign(n, vector<int>(0));
        phi.assign(n, 0);
        par.resize(n);
        pe.resize(n);
    }

    void add_edge(int from, int to, int cap, int cost)
    {
        E.push_back(edge(from, to, cap, cost));
        E.push_back(edge(to, from, 0, -cost));
        g[from].push_back((int)E.size() - 2);
        g[to].push_back((int)E.size() - 1);
    }

    int rev(int i)
    {
        return (i ^ 1);
    }

    void find_path()
    {
        d.assign(n, INF);
        d[s] = 0;
        u.assign(n, 0);
        for (int rep = 0; rep < n; rep++)
        {
            int v = -1;
            for (int i = 0; i < n; i++)
                if (!u[i] && (v == -1 || d[v] > d[i]))
                    v = i;
            if (d[v] == INF)
                break;
            u[v] = true;
            for (int i = 0; i < g[v].size(); i++)
            {
                edge e = E[g[v][i]];
                if (!e.open())
                    continue;
                int w = d[v] + e.cost + phi[v] - phi[e.to];
                if (w < d[e.to])
                {
                    d[e.to] = w;
                    par[e.to] = v;
                    pe[e.to] = g[v][i];
                }
            }
        }
    }

    void FB()
    {
        d.assign(n, INF);
        d[s] = 0;
        for (int i = 0; i < n; i++)
            for (edge e: E)
                if (e.open() && d[e.from] + e.cost < d[e.to])
                    d[e.to] = d[e.from] + e.cost;
        for (int i = 0; i < n; i++)
            phi[i] = d[i];
    }

    int get_cost(int st, int to, int want)
    {
        s = st;
        t = to;
        int flow = 0;
        int cost = 0;
        FB();
        for (;;)
        {
            find_path();
            if (d[t] == INF)
                break;
            for (int i = 0; i < n; i++)
                phi[i] += (d[i] == INF ? 0 : d[i]);
            vector<int> path;
            for (int v = t; v != s; v = par[v])
                path.push_back(pe[v]);
            int add = want - flow;
            for (int i = 0; i < path.size(); i++)
                add = min(add, E[path[i]].cap - E[path[i]].flow);
            flow += add;
            for (int i = 0; i < path.size(); i++)
            {
                int c = path[i];
                E[c].flow += add;
                E[rev(c)].flow -= add;
                cost += E[c].cost * add;
            }
            if (flow == want)
                break;
        }
        if (flow < want)
            return INF;
        return cost;
    }
};


int n, k;
int c[55][55];

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    int l = 0;
    int r = 50 * 1000 * 1000 + 1111;
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        MinCost G;
        G.init(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][j])
                    G.add_edge(i, j, c[i][j], 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][j])
                    G.add_edge(i, j, G.INF, 1);
        int c = G.get_cost(0, n - 1, m);
        if (c <= k)
            l = m;
        else
            r = m - 1;
    }

    cout << l;

    return 0;
}