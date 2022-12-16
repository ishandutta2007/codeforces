#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;
int given[2][nmax];

long long inp[nmax];

long long sum[2];

int colour[nmax];

vector<int> adj[nmax];

bool BIPAR;

void dfs(int node,int col)
{
    if(colour[node]==-1)
    {
        colour[node]=col;
        sum[col]+=inp[node];
    }
    else
    {
        if(colour[node]!=col)BIPAR=0;
        return;
    }

    for(auto w:adj[node])
        dfs(w,!col);
}

bool solve()
{
    scanf("%i%i",&n,&m);

    sum[0]=0;
    sum[1]=0;

    for(int i=1;i<=n;i++)adj[i]={},colour[i]=-1;

    for(int i=1;i<=n;i++)scanf("%i",&given[0][i]);
    for(int i=1;i<=n;i++)scanf("%i",&given[1][i]);

    for(int i=1;i<=n;i++)inp[i]=given[0][i]-given[1][i];

    //for(int i=1;i<=n;i++)printf("%lld ",inp[i]);printf("\n");

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BIPAR=1;
    dfs(1,0);

    return (BIPAR==0||sum[0]==sum[1])&&(sum[0]+sum[1])%2==0;
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