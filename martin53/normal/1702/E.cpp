#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n;
vector<int> adj[nmax];

bool been[nmax];
int cnt;

void dfs(int node)
{
    if(been[node])return;

    been[node]=1;

    cnt++;

    for(auto w:adj[node])
        dfs(w);
}

bool solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<=n;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        if(adj[i].size()!=2)
            return 0;

    for(int i=1;i<=n;i++)been[i]=0;

    for(int i=1;i<=n;i++)
    {
        cnt=0;

        dfs(i);

        if(cnt%2)return 0;
    }

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}