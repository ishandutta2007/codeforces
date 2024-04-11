#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005, LG = 18;

vector<int> adj[N];
int n, u, v, cur = 1, h[N] = {-1}, lst[N], col[N], sub[N], par[N][LG];

int DFS(int u, int p = 0)
{
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (int i = 1; (1 << i) <= h[u]; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p)
            sub[u] += DFS(v, u);
    return sub[u];
}

void HLD(int u, int p = 0)
{
    col[u] = cur;
    lst[cur] = u;
    int mc = 0;
    for (int &v : adj[u])
        if (v != p && sub[v] > sub[mc])
            mc = v;
    if (mc != 0)
        HLD(mc, u);
    for (int &v : adj[u])
        if (v != p && v != mc)
        {
            ++cur;
            HLD(v, u);
        }
}

int ask(char c, int u)
{
    int ret;
    cout << c << " " << u << endl;
    cin >> ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    int st = 1, ta = ask('d', 1), cu = 0;
    while (ta != cu)
    {
        st = lst[col[st]];
        cu = h[st];
        int dis = ask('d', st);
        int nh = (ta + cu - dis) / 2;
        for (int i = 0; i < LG; i++)
            if ((cu - nh) >> i & 1)
            {
                st = par[st][i];
                cu = h[st];
            }
        if (nh != ta)
        {
            st = ask('s', st);
            cu = h[st];
        }
    }
    cout << "! " << st << endl;
}