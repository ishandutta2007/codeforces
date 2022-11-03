#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int a[maxn] , dist[maxn] , q[maxn] , t , h;
vector<int> adj[maxn];
void bfs(int src)
{
    fill(dist , dist + maxn , -1);
    q[h++] = src;
    dist[src] = 0;
    while(t < h)
    {
        int v = q[t];
        for(auto u : adj[v])
        {
            if(dist[u] != -1)
                continue;
            dist[u] = dist[v] + 1;
            q[h++] = u;
        }
        t++;
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        adj[i].pb(a[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        adj[i].pb(i + 1);
        adj[i + 1].pb(i);
    }
    bfs(0);
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
}