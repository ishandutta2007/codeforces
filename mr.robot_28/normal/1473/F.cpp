#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
int n;
struct edge{
    int a, b, cap, flow;
    edge(int a, int b, int cap):
        a(a),
        b(b),
        cap(cap),
        flow(0){};
    int other(int v)
    {
        return v == a ? b : a;
    }
    int capTo(int v)
    {
        return v == b ? cap - flow : flow;
    }
    int addFlow(int v, int fl)
    {
        if(v == b)
        {
            flow += fl;
        }
        else
        {
            flow -= fl;
        }
    }
};
const int N = 3010;
vector <edge> edges;
vector <int> g[N];
int h[N], p[N], it[N];
bool bfs(int st, int en)
{
    for(int i = 0; i < n + 2; i++)
    {
        it[i] = 0;
        h[i] = 1e9;
        p[i] = -1;
    }
    h[st] = 0;
    queue <int> q;
    q.push(st);
    while(q.size() != 0)
    {
        int v = q.front();
        q.pop();
        if(v == en)
        {
            return 1;
        }
        for(int i = 0; i < g[v].size(); i++)
        {
            int to = edges[g[v][i]].other(v);
            if(h[to] == 1e9 && edges[g[v][i]].capTo(to))
            {
                q.push(to);
                h[to] = h[v] + 1;
            }
        }
    }
    return 0;
}
bool dfs(int v, int en)
{
    if(v == en)
    {
        return 1;
    }
    while(it[v] < g[v].size())
    {
        int e = g[v][it[v]];
        int to = edges[e].other(v);
        if(h[to] == h[v] + 1 && edges[e].capTo(to) && dfs(to, en))
        {
            p[to] = e;
            return 1;
        }
        it[v]++;
    }
    return 0;
}
void add_edge(int a, int b, int cap)
{
    edges.push_back(edge(a, b, cap));
    g[a].push_back(edges.size() - 1);
    g[b].push_back(edges.size() - 1);
}
signed main()
{
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    cin >> n;
    vector <int> a(n), b(n);
    vector <int> last(101, -1);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(b[i] >= 0)
        {
            ans += b[i];
            add_edge(n, i, b[i]);
            for(int x = 1; x <= 100; x++)
            {
                if(a[i] % x == 0 && last[x] != -1)
                {
                    add_edge(i, last[x], 1e9);
                }
            }
        }
        else
        {
            if(last[a[i]] != -1)
            {
                add_edge(i, last[a[i]], 1e9);
            }
        last[a[i]] = i;
            add_edge(i, n + 1, -b[i]);
        }
    }
    int maxflow = 0;
    while(bfs(n, n + 1))
    {
        while(dfs(n, n + 1))
        {
          //  cout << "A\n";
            int flow = 1e9;
            for(int v = n + 1; v != n; v = edges[p[v]].other(v))
            {
                flow = min(flow, edges[p[v]].capTo(v));
            }
          //  cout << flow << "\n";
            maxflow += flow;
            int v;
            for(v = n + 1; v != n; v = edges[p[v]].other(v))
            {
            //    cout << edges[p[v]].capTo(v) << "\n";
                if(edges[p[v]].a == v)
                {
                    edges[p[v]].flow -= flow;
                }
                else
                {
                    edges[p[v]].flow += flow;
                }
           //     edges[p[v]].addFlow(v, flow);
              //  cout << v << "\n";
            }
            //cout << "B\n";
            //break;
        }
        //break;
    }
    cout << ans - maxflow;
    return 0;
}