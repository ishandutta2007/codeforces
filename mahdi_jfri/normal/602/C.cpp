#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 4e2 + 20;
vector<int> adj[maxn] , r[maxn];
bool x[maxn][maxn];
int q[maxn] , h , t , dist1[maxn] , dist2[maxn];
void bfs1(int src)
{
    fill(dist1 , dist1 + maxn , -1);
    q[h++] = src;
    dist1[src] = 0;
    while(t < h)
    {
        int v = q[t];
        for(int u : adj[v])
        {
            if(dist1[u] != -1)
                continue;
            dist1[u] = dist1[v] + 1;
            q[h++] = u;
        }
        t++;
    }
}
void bfs2(int src)
{
    h = t = 0;
    fill(dist2 , dist2 + maxn , -1);
    q[h++] = src;
    dist2[src] = 0;
    while(t < h)
    {
        int v = q[t];
        for(int u : r[v])
        {
            if(dist2[u] != -1)
                continue;
            dist2[u] = dist2[v] + 1;
            q[h++] = u;
        }
        t++;
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    while(m--)
    {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        x[a][b] = x[b][a] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            if(!x[i][j])
                r[i].pb(j) , r[j].pb(i);
        }
    bfs1(1);
    bfs2(1);
    if(dist1[n] == -1 || dist2[n] == -1)
    {
        cout << -1;
        return 0;
    }
    cout << max(dist1[n] , dist2[n]);
}