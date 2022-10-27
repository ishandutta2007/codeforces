#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;
const int N = 2e5+ 100;
struct edge{
    int u, v, c;
    int flow;
    edge() : u(0), v(0), c(0), flow(1e9){};
    edge(int u, int v, int c):
        u(u),
        v(v),
        c(c){};
};
vector <edge> edges;
vector <int> g[N];
vector <int> dep;
vector <int> iter;
int n, S, T;
bool bfs()
{
    for(int j =0; j < n * 2 + 2; j++)
    {
        dep[j] = -1;
    }
    queue <int> q;
    dep[S] = 0;
    q.push(S);
    while(sz(q) != 0)
    {
        int v = q.front();
        q.pop();
        for(int id : g[v])
        {
            int to = edges[id].v;
            int c = edges[id].c;
            if(c > 0 && dep[to] == -1)
            {
                dep[to] = dep[v] + 1;
                q.push(to);
                if(to == T)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int dfs(int v, int flow)
{
    if(!flow)
    {
        return 0;
    }
    if(v == T)
    {
        return flow;
    }
    int res = 0;
    for(;iter[v] < sz(g[v]); iter[v]++)
    {
        int id = g[v][iter[v]];
        int to = edges[id].v;
        int c = edges[id].c;
        if(dep[to] == dep[v] + 1)
        {
            int t = dfs(to, min(flow, c));
            if(t)
            {
                edges[id].c -= t;
                edges[id ^ 1].c += t;
                res += t;
                flow -= t;
                if(!flow)
                {
                    break;
                }
            }
        }
    }
    if(!res)
    {
        dep[v] = -1;
    }
    return res;
}
void add_edge(int u, int v, int c)
{
    edges.push_back(edge(u, v, c));
    g[u].push_back(sz(edges) - 1);
    edges.push_back(edge(v, u, 0));
    g[v].push_back(sz(edges) - 1);
}

signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector <int> x(n), y(n), w(n), c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
        c[i] = (y[i] & 1) << 1 | ((x[i] & 1) == (y[i] & 1));
    }
    for(int i = 0; i < n; i++)
    {
        add_edge(i, i + n, w[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[i] + 1 == c[j] && abs(x[i] - x[j]) + abs(y[i] - y[j]) == 1)
            {
                add_edge(n + i, j, 1e9);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(c[i] == 0)
        {
            add_edge(2 * n, i, 1e9);
        }
        if(c[i] == 3)
        {
            add_edge(n + i, 2 * n + 1, 1e9);
        }
    }
    dep.resize(2 * n + 2);
    iter.resize(2 * n + 2, 0);
    int ans = 0;
    S = n * 2;
    T = n * 2 + 1;
    while(bfs())
    {
        fill(iter.begin(), iter.end(), 0);
        ans += dfs(n * 2, 1e9);
    }
    ans = -ans;
    for(int i = 0; i < n; i++)
    {
        ans += w[i];
    }
    cout << ans;
    return 0;
}