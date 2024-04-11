#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll dist[maxn] , s , t;
bool is[maxn];
vector<int> adj[maxn];
bool bfs(int x)
{
    fill(dist , dist + maxn , -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty())
    {
        int v = q.front();
        if(is[v])
            dist[v] = 0;
        q.pop();
        if(dist[v] > x)
            continue;
        for(auto u : adj[v])
        {
            if(dist[u] == -1 || dist[u] > dist[v] + 1)
            {
                if(dist[v] + 1 > x)
                    continue;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return (dist[t] != -1);
}
ll bs(ll l , ll r)
{
    if(r - l == 1)
    {
        return (bfs(l)? l : r);
    }
    ll mid = (l + r) / 2;
    if(bfs(mid))
        return bs(l , mid);
    return bs(mid , r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        is[--a] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    cin >> s >> t;
    s--;
    t--;
    if(!bfs(n))
    {
        cout << -1;
        return 0;
    }
    int z = bs(1 , n);
    cout << z << endl;
    bfs(z);
  //  cout << dist[t] << endl;
}