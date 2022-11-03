#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=4e3+20;
//vector<int>adj[maxn];
//bool visited[maxn];
//int cmp[maxn];
int _min=1e6;
/*void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u);
    }
}*/
bool adj[maxn][maxn];
int a,b;
vector<int>t[maxn];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[--a][--b] = 1;
        adj[b][a] = 1;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        if(t[i].size() > 1)
            for(int j = 0; j < t[a].size(); j++)
            {
                for(int jj = j; jj < t[i].size(); jj++)
                {
                    int x = t[i][jj];
                    int y = t[i][j];
                    if(adj[x][y] == 1)
                    {
                        _min=min((int)(t[x].size()+t[y].size()+t[i].size()-6),_min);
                    }
                }
            }
    }
    cout << (_min==1e6?-1:_min);
}