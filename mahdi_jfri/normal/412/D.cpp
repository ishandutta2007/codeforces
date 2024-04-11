#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e4 + 20;
vector<int> adj[maxn];
bool visited[maxn];
int a , b;
void dfs(int v)
{
    visited[v] = 1;
    for(auto u : adj[v])
        if(!visited[u])
            dfs(u);
    printf("%d ", v);
}
int main()
{
    int n , m;
    scanf("%d%d", &n , &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a , &b);
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);
}