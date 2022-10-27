#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
#define ld long double
const int N = 600;
vector <int> g[N];
int dist[N][N];
ll Ans[N][N];
const int mod = 998244353;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + n, 1e9);
        queue <int> q;
        q.push(i);
        dist[i][i] = 0;
        while(sz(q) != 0)
        {
            int v = q.front();
            q.pop();
            for(auto to : g[v])
            {
                if(dist[i][to] == 1e9)
                {
                    dist[i][to]= dist[i][v] + 1;
                    q.push(to);
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j]++;
         //   cout << dist[i][j] << " ";
        }
       // cout << "\n";
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = x; y < n; y++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(dist[x][i] + dist[y][i] - 1 == dist[x][y])
                {
                    cnt++;
                }
            }
            ll ans = 1;
            if(cnt > dist[x][y])
            {
                Ans[x][y] = Ans[y][x] = 0;
                continue;
            }
            for(int i = 0; i < n; i++)
            {
                if(dist[x][i] + dist[y][i] - 1 == dist[x][y])
                {
                    continue;
                }
                int fl = 0;
                for(auto to : g[i])
                {
                    if(dist[x][to] == dist[x][i] - 1&& dist[y][to] == dist[y][i] - 1)
                    {
                        ++fl;
                    }
                }
                ans = ans * fl % mod;
            }
            Ans[x][y] = Ans[y][x] = ans;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << Ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}