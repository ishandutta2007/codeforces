#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,k;
int inp[nmax];

bool can=0;
int XOR_ALL;

vector<int> adj[nmax];

int dfs(int node,int par)
{
    int cnt=0;

    for(auto w:adj[node])
        if(w!=par)
        {
            cnt+=dfs(w,node);

            inp[node]=inp[node]^inp[w];
        }

    if(cnt>=2)can=1;
    if(inp[node]==0&&cnt>=1)can=1;

    if(inp[node]==XOR_ALL)return 1;
    return cnt;
}

bool solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    XOR_ALL=0;
    for(int i=1;i<=n;i++)XOR_ALL=XOR_ALL^inp[i];

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    can=0;

    dfs(1,0);

    if(inp[1]==0)return 1;

    if(k==2)return 0;

    return can;
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