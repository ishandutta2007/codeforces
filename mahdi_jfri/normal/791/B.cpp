#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
vector<int> adj[maxn];
ll e , vertex;
bool visited[maxn];
void dfs(int v)
{
    vertex++;
    e += adj[v].size();
    visited[v] = 1;
    for(auto u : adj[v])
        if(!visited[u])
            dfs(u);
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
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vertex = 0;
            e = 0;
            dfs(i);
            if(e != vertex * (vertex - 1))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}