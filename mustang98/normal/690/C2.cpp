#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];

int maxd = -10, resver;

void DFS(int a, int depth)
{
    if (depth > maxd) {maxd = depth; resver = a;}
    visited[a] = true;
    for(int i = 0; i < v[a].size() ;i++)
    {
        if (!visited[v[a][i]]) DFS(v[a][i], depth+1);
    }
}

int main()
{
    int a,b,n, m;
    cin>>n>>m;
    for(int i = 0; i < m;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(0, 0);
    for(int i = 0;i < n;i++) visited[i] = false;
    maxd = -10;
    DFS(resver, 0);
    cout<<maxd;
    return 0;
}