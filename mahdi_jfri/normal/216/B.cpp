#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=1e2+20;
vector<int>adj[maxn];
int a,b;
int n , m;
bool visited[maxn];
int cmp[maxn];
int res;
deque<int>dq;
bool searchi(int a)
{
    for(int i = 0; i < dq.size(); i++)
    {
        if(dq[i] == a)
            return 1;
    }
    return 0;
}
void dfs(int v,int c)
{
    visited[v] = 1;
    cmp[v] = c;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(searchi(u))
            continue;
        if(!visited[u])
            dfs(u,1-c);
        else if(cmp[u] != 1-c)
        {
            dq.push_back(u);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && !searchi(i))
            dfs(i,0);
    }
    int x = dq.size()/2;
    if((n-x)&1)
        x++;
    cout << x;
}