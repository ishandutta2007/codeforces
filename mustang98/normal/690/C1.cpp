#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[10000];

void DFS(int a)
{
    visited[a] = true;
    for(int i = 0; i < v[a].size() ;i++)
    {
        if (!visited[v[a][i]]) DFS(v[a][i]);
    }
}

int main()
{
    int n, m, a, b;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(0);
    for(int i = 0; i < n; i++) if(visited[i] == false) {cout<<"no";return 0;}
    if (m == n-1) {cout<<"yes";}
    else cout<<"no";
    return 0;
}