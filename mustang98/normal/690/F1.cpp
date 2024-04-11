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
    int m[10005] = {0};
    int n, a,b;
    cin>>n;
    for(int i =0; i < n -1;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        m[a]++;
        m[b]++;
    }
  //  for(int i = 0; i < n; i++) cout<<m[i]<<' ';
    int res = 0;
    for(int i = 0; i < n;i++)
    if(m[i] > 1) res += m[i]*(m[i] - 1)/2;
    cout<<res;
    return 0;
}