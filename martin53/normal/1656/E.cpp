#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
vector<int> adj[nmax];

int col[nmax];

void dfs(int node,int par,int cur)
{
    col[node]=cur;

    for(auto w:adj[node])
        if(w!=par)dfs(w,node,-cur);
}

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<=n;i++)col[i]=-1;

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1,1);

    for(int i=1;i<=n;i++)
        printf("%i ",col[i]*adj[i].size());
    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}