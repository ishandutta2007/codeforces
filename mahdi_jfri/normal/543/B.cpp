#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef vector<int> vi;
const int maxn = 3e3 + 20;
int dist[maxn][maxn] , q[maxn] , h , t , s1 , s2 , t1 , t2 , l1 , l2 , res;
vi adj[maxn];
void bfs(int src)
{
    fill(dist[src] , dist[src] + maxn , -1);
    dist[src][src] = h = t = 0;
    q[h++] = src;
    while(t < h)
    {
        int v = q[t];
        for(int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if(dist[src][u] != -1)
                continue;
            dist[src][u] = dist[src][v] + 1;
            q[h++] = u;
        }
        t++;
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--;
    s2--;
    t1--;
    t2--;
    for(int i = 0; i < n; i++)
        bfs(i);
    res = m - dist[s1][t1] - dist[s2][t2];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int a = min(dist[i][j] + dist[s1][i] + dist[j][t1] , dist[i][j] + dist[t1][i] + dist[j][s1]) , b = min(dist[i][j] + dist[s2][i] + dist[j][t2] , dist[i][j] + dist[t2][i] + dist[j][s2]);
            if(a > l1 || b > l2)
                continue;
            res = max(res , m - a - b + dist[i][j]);
        }
    }
    if(dist[s1][t1] > l1 || dist[s2][t2] > l2)
    {
        cout << -1;
        return 0;
    }
    cout << res;
}