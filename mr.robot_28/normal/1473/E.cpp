#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int> > > g(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >>u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector <int> dist(n * 4, 1e18);
    dist[0] = 0;
    priority_queue <pair <int, int> > q;
    q.push({0, 0});
    while(q.size() != 0)
    {
        int y = q.top().second;
        int dist1 = -q.top().first;
        q.pop();
        //cout << y << " " << dist1 << "\n";
        if(dist1 != dist[y])
        {
            continue;
        }
        int v = y / 4;
        for(int i = 0;i < g[v].size(); i++)
        {
            int to = g[v][i].first;
            int w = g[v][i].second;
            if(dist[to * 4 + y % 4] > dist[y] + w)
            {
                dist[to * 4 + y % 4] = dist[y] + w;
                q.push({-dist[to * 4 + y % 4], to * 4 + y % 4});
            }
            if(y % 2 != 1)
            {
                if(dist[to * 4 + 1 + y % 4] > dist[y] + 2 * w)
                {
                    dist[to * 4 + 1 + y % 4] = dist[y] + 2 * w;
                    q.push({-dist[to * 4 + 1 + y % 4], to * 4 + 1 + y % 4});
                }
            }
            if(y % 4 < 2)
            {
                if(dist[to * 4 + 2 + y % 2] > dist[y])
                {
                    dist[to * 4 + 2 + y % 2] = dist[y];
                    q.push({-dist[to * 4 + 2 + y % 2], to * 4 + 2 + y % 2});
                }
            }
            if(y % 4 == 0)
            {
                if(dist[to * 4 + 3] > dist[y] +  w)
                {
                    dist[to * 4 + 3] = dist[y] + w;
                    q.push({-dist[to * 4 + 3], to * 4 + 3});
                }
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        cout << dist[i * 4 + 3] << " ";
    }
    return 0;
}