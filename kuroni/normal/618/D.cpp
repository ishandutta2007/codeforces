#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, x, y, u, v, f[N][2];
vector<int> adj[N];

void add(pair<int, int> &cur, int val)
{
    if (cur.first < val)
        swap(cur.first, val);
    if (cur.second < val)
        swap(cur.second, val);
}

void DFS(int u, int p = 0)
{
    int sum = 0;
    pair<int, int> cur = {0, 0};
    for (int &v : adj[u])
        if (v != p)
        {
            DFS(v, u);
            sum += f[v][0];
            add(cur, f[v][1] + 1 - f[v][0]);    
        }
    f[u][0] = sum + cur.first + cur.second;
    f[u][1] = sum + cur.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> y >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (y >= x)
    {
        for (int i = 1; i <= n; i++)
            if (adj[i].size() == n - 1)
                return cout << 1LL * x * (n - 2) + y, 0;
        cout << 1LL * x * (n - 1);
    }
    else
    {
        DFS(1);
        int tmp = max(f[1][0], f[1][1]);
        cout << 1LL * y * tmp + 1LL * x * (n - 1 - tmp);
    }
}