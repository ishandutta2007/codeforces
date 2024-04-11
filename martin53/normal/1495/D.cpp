#include<bits/stdc++.h>
using namespace std;

const int nmax=4e2+42,mod=998244353;

int n,m;

int dist[nmax][nmax];

int cnt[nmax];

int outp[nmax][nmax];

vector< int > adj[nmax];

int solve(int u,int v)
{
    memset(cnt,0,sizeof(cnt));

    for(int i=1;i<=n;i++)
        if(dist[u][i]+dist[i][v]==dist[u][v])cnt[dist[u][i]]++;

    for(int d=0;d<=dist[u][v];d++)
        if(cnt[d]!=1)return 0;

    long long ret=1;

    for(int i=1;i<=n&&ret;i++)
        if(i!=u&&i!=v&&dist[u][i]+dist[i][v]!=dist[u][v])
        {
            int cur=0;

            for(auto j:adj[i])
                if(dist[i][u]==dist[j][u]+1&&dist[i][v]==dist[j][v]+1)cur++;

            ret=ret*cur%mod;
        }
    return ret;
}

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)dist[i][j]=1e9;

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);

        dist[u][v]=1;
        dist[v][u]=1;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int u=1;u<=n;u++)
        for(int v=u;v<=n;v++)
        {
            outp[u][v]=solve(u,v);
            outp[v][u]=outp[u][v];
        }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%i ",outp[i][j]);
        printf("\n");
    }

    return 0;
}