#include<bits/stdc++.h>
using namespace std;
//#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[y].push_back(x);
    }
    int k;
    cin >> k;
    vector <int> p(k);
    for(int i = 0; i  < k; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    queue <int> Q;
    vector <set <int> > nxt(n);
    vector <int> dist(n);
    vector <bool> used(n);
    dist[p[k - 1]] = 0;
    used[p[k - 1]] = true;
    Q.push(p[k - 1]);
    while(Q.size() != 0)
    {
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if(used[to] && dist[to] == dist[v] + 1)
            {
                nxt[to].insert(v);
            }
            else if(!used[to])
            {
                nxt[to].insert(v);
                dist[to] = dist[v] + 1;
                used[to] = true;
                Q.push(to);
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < k - 1; i++)
    {
        if(nxt[p[i]].find(p[i + 1]) == nxt[p[i]].end())
        {
            cnt1++;
            cnt2++;
        }
        else if(nxt[p[i]].size() > 1)
        {
            cnt2++;
        }
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}