#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=2e3+20;
vector<int>adj[maxn];
int k;
int a;
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
ll mm;
int main()
{
    int n , m;
    cin >> n >> m;
    ll cmp = 0;
    for(int i = 0 ; i < n ;i++)
    {
        cin >> k;
        for(int j =  0 ; j < k ; j++)
        {
            cin >> a;
            a+=n;
            mm+=k;
            adj[i].push_back(--a);
            adj[a].push_back(i);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cmp++;
        }
    }
    cout << ((mm == 0)?n:cmp-1);
}