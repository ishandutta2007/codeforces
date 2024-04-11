#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 200005;

int n, m, k, cnt = 0, u[M], v[M], ans[M];
bool del[N];
vector<int> ve;
set<int> adj[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }
    for (int i = 1; i <= n; i++)
        if (adj[i].size() < k)
        {
            ve.push_back(i);
            del[i] = true;
            cnt++;
        }
    for (int i = m; i >= 1; i--)
    {
        while (!ve.empty())
        {
            int u = ve.back(); ve.pop_back();
            for (int v : adj[u])
            {
                adj[v].erase(u);
                if (adj[v].size() < k && !del[v])
                {
                    ve.push_back(v);
                    del[v] = true;
                    cnt++;
                }
            }
        }
        ans[i] = n - cnt;
        adj[u[i]].erase(v[i]);
        adj[v[i]].erase(u[i]);
        if (adj[u[i]].size() < k && !del[u[i]])
        {
            ve.push_back(u[i]);
            del[u[i]] = true;
            cnt++;
        }
        if (adj[v[i]].size() < k && !del[v[i]])
        {
            ve.push_back(v[i]);
            del[v[i]] = true;
            cnt++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}