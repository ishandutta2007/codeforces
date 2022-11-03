#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
vector<int>adj[maxn];
int a , b;
int t[maxn];
int temp = -1;
int temp2 = -1;
bool visited[maxn];
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u);
    }
}
int main()
{
    int n;
    cin >> n;
    int m = n*(n-1)/2 -1;
    while( m-- )
    {
        cin >> a >> b;
        adj[--a].push_back(--b);
        t[a]++;
        t[b]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(temp == -1 && t[i] < n-1)
            temp = i;
        else if(temp != -1 && t[i] < n-1)
        {
            temp2 = i;
            break;
        }
    }
    dfs(temp);
    if(visited[temp2])
        cout << temp+1 << " " << temp2+1;
    else
        cout << temp2+1 << " " << temp+1;
    return 0;
}