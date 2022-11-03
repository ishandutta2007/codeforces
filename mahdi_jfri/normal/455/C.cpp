#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define find findd
const int maxn = 3e5 + 20;
vi adj[maxn];
int visited[maxn] , c = 2 , dist[maxn] , tool[maxn] , p[maxn] , color[maxn] , q[maxn] , h , t;
void bfs(int src)
{
    c--;
    int node = src , _max = 0;
    t = h = 0;
    q[h++] = src;
    dist[src] = 0;
    visited[src] = c;
    while(t < h)
    {
        int v = q[t];
        for(int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if(visited[u])
                continue;
            visited[u] = c;
            q[h++] = u;
            dist[u] = dist[v] + 1;
            if(dist[u] > _max)
            {
                _max = dist[u];
                node = u;
            }
        }
        t++;
    }
    h = t = 0;
    q[h++] = node;
    c++;
    visited[node] = c;
    dist[node] = 0;
    _max = 0;
    while(t < h)
    {
        int v = q[t];
        for(int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if(visited[u] == c)
                continue;
            p[u] = v;
            visited[u] = c;
            q[h++] = u;
            dist[u] = dist[v] + 1;
            if(dist[u] > _max)
            {
                _max = dist[u];
                node = u;
            }
        }
        t++;
    }
    tool[c] = _max;

}
int find(int a)
{
    return (color[a] == a? a : color[a] = find(color[a]));
}
int main()
{
    int n , m , q;
    scanf("%d%d%d", &n , &m , &q);
    for(int i = 0; i < maxn; i++) color[i] = i;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        scanf("%d%d", &a , &b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        if(!visited[i])
            bfs(i) , c++;
    for(int i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);
        if(query == 1)
        {
            int a;
            cin >> a;
            a--;
            printf("%d\n", tool[find(visited[a])]);
        }
        else
        {
            int a , b;
            scanf("%d%d", &a , &b);
            a--; b--;
            int c1 = find(visited[a]) , c2 = find(visited[b]);
            if(c1 == c2)
                continue;
            color[find(c2)] = c1;
            int k = (tool[c2]) / 2 + ((tool[c2]) % 2) + (tool[c1]) / 2 + ((tool[c1]) % 2) + 1;
            tool[c1] = max(tool[c1] , max(k , tool[c2]));
        }
    }
}