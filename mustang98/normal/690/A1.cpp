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
    int n;
    cin>>n;
    if(n%2==0) cout<<n/2;
    else cout<<n/2+1;
    return 0;
}