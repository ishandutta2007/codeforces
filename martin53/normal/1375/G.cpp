#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;
int n;
vector<int> adj[nmax];

int seen[2];

void dfs(int node,int par,int depth)
{
    seen[depth%2]++;
    for(auto k:adj[node])
        if(k!=par)dfs(k,node,depth+1);
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    printf("%i\n",min(seen[0],seen[1])-1);
    return 0;
}