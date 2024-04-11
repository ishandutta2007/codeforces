#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=2e3+20;
vector<int>adj[maxn];
int cmp[maxn];
int a[maxn];
bool visited[maxn];
void dfs(int v,int c)
{
    visited[v] = 1;
    cmp[v] = c;
    c++;
    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u,c);
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
        if(a[i] != -1)
        {
            adj[--a[i]].push_back(i);
            adj[i].push_back(a[i]);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == -1)
            dfs(i,1);
    }
    cout << *max_element(cmp,cmp+n);
}