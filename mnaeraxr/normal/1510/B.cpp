#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <queue>

using namespace std;

vector<int> f(vector<int> &a, vector<int> &b)
{
    vector<int> c(a.size());

    for (int i = 0; i < a.size(); ++i)
        c[i] = a[b[i]];

    return c;
}

void show(vector<int> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

template <typename T, typename C = T>
struct min_cost_flow
{
    struct edge
    {
        int src, dst;
        T cap, flow;
        C cost;
        int rev;
    };

    int n;
    vector<vector<edge> > adj;

    min_cost_flow(int n) : n(n), adj(n) {}

    void add_edge(int src, int dst, T cap, C cost)
    {
        adj[src].push_back({src, dst, cap, 0, cost, (int)adj[dst].size()});
        if (src == dst)
            adj[src].back().rev++;
        adj[dst].push_back({dst, src, 0, 0, -cost, (int)adj[src].size() - 1});
    }

    const C oo = numeric_limits<C>::max();

    vector<C> dist, pot;
    vector<edge *> prev;
    vector<T> curflow;

    void bellman_ford(int s, int t)
    {
        pot.assign(n, oo);
        pot[s] = 0;

        for (int it = 0, change = true; it < n && change; ++it)
        {
            change = false;
            for (int u = 0; u < n; ++u)
                if (pot[u] != oo)
                {
                    for (auto &e : adj[u])
                        if (e.flow < e.cap && pot[e.dst] > pot[u] + e.cost)
                        {
                            pot[e.dst] = pot[u] + e.cost;
                            change = true;
                        }
                }
        }
    }

    bool dijkstra(int s, int t)
    {
        dist.assign(n, oo);
        prev.assign(n, nullptr);
        dist[s] = 0;
        curflow[s] = numeric_limits<T>::max();

        using pci = pair<C, int>;
        priority_queue<pci, vector<pci>, greater<pci> > pq;
        pq.push({0, s});

        while (!pq.empty())
        {
            C d;
            int u;
            tie(d, u) = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto &e : adj[u])
                if (e.flow < e.cap && dist[e.dst] > dist[u] + e.cost + pot[u] - pot[e.dst])
                {
                    dist[e.dst] = dist[u] + e.cost + pot[u] - pot[e.dst];
                    prev[e.dst] = &e;
                    curflow[e.dst] = min(curflow[u], e.cap - e.flow);
                    pq.push({dist[e.dst], e.dst});
                }
        }

        return dist[t] < oo;
    }

    pair<T, C> max_flow(int s, int t, bool neg_edges = true)
    {
        T flow = 0;
        C cost = 0;
        curflow.assign(n, 0);

        if (neg_edges)
            bellman_ford(s, t);
        else
            pot.assign(n, 0);

        while (dijkstra(s, t))
        {
            for (int u = 0; u < n; ++u)
                if (dist[u] < oo)
                    pot[u] += dist[u];

            T delta = curflow[t];
            flow += delta;
            for (edge *e = prev[t]; e != nullptr; e = prev[e->src])
            {
                e->flow += delta;
                adj[e->dst][e->rev].flow -= delta;
                cost += delta * e->cost;
            }
        }

        return {flow, cost};
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a, cc;

    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        int mask = 0;
        int c = 0;

        for (int j = 0; j < n; ++j)
            if (s[j] == '1')
            {
                mask |= 1 << j;
                c++;
            }

        if (mask)
        {
            a.push_back(mask);
            cc.push_back(c);
        }
    }

    m = a.size();

    min_cost_flow<int, int> g(2 * m + 2);

    for (int i = 0; i < m; ++i)
    {
        // cout << "here: " << i << " " << cc[i] << endl;
        g.add_edge(0, i + 2, 1, 0);
        g.add_edge(i + 2 + m, 1, 1, 0);

        for (int j = 0; j < m; ++j)
        {
            if (i != j && (a[i] & a[j]) == a[i])
                g.add_edge(i + 2, j + 2 + m, 1, -cc[i]);
        }
    }

    auto res = g.max_flow(0, 1);
    // cout << res.second << endl;

    vector<int> prev(m, -1);
    vector<int> nxt(m, -1);

    for (int i = 0; i < m; ++i)
        for (auto e : g.adj[i + 2])
        {
            if (e.flow == 1)
            {
                int u = i;
                int v = e.dst - m - 2;
                prev[v] = u;
                nxt[u] = v;
                // cout << u << "->" << v << endl;
                // cout << bitset<3>(a[u]) << "->" << bitset<3>(a[v]) << endl;
                // cout << e.dst << " " << e.flow << endl;
            }
        }

    bool first = true;

    vector<int> ans;

    for (int i = 0; i < m; ++i)
    {
        if (nxt[i] != -1)
            continue;

        if (first)
            first = false;
        else
            ans.push_back(-1);

        int u = i;

        vector<int> path;

        while (true)
        {
            path.push_back(a[u]);
            if (prev[u] != -1)
                u = prev[u];
            else
                break;
        }

        path.push_back(0);
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); ++i)
        {
            int mask = path[i] ^ path[i - 1];
            for (int i = 0; i < n; ++i)
                if (mask >> i & 1)
                    ans.push_back(i);
        }
    }

    cout << ans.size() << endl;

    for (auto x : ans)
    {
        if (x == -1)
            cout << "R ";
        else
            cout << x << " ";
    }
    cout << endl;
}