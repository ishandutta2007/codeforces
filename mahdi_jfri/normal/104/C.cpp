#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e3;
vector<int>adj[maxn];
int a, b;
bool visited[maxn];
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u);
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ;i++)
    {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0);
    for(int i = 0 ; i < n; i++)
    {
        if(!visited[i])
        {
            cout << "NO";
            return 0;
        }
    }
    if(n == m)
    {
        cout << "FHTAGN!";
        return 0;
    }
    cout << "NO";
    return 0;
}