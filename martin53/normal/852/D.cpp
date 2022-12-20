#include<bits/stdc++.h>
using namespace std;
const int nmax=6e2+42,inf=1731311;
int v,e,n,k;
int dist[nmax][nmax];
int teams[nmax];
vector<int> adj[nmax];
int matched[nmax*2];
bool been[nmax*2];
bool dfs(int node)
{
    if(been[node])return 0;
    been[node]=1;
    for(auto k:adj[node])
        if(matched[k]==0||dfs(matched[k]))
        {
            matched[k]=node;
            return 1;
        }
    return 0;
}
int kuhn()
{
    for(int i=1;i<=v+n;i++)
        matched[i]=0;
    for(int i=1;i<=n;i++)
    {
        memset(been,0,sizeof(been));
        dfs(i);
    }

    int ret=0;
    for(int i=1;i<=v;i++)
        if(matched[i+n])ret++;
    return ret;
}
bool test(int d)
{
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=v;j++)
            if(dist[teams[i]][j]<=d)
                {
                adj[i].push_back(j+n);
                }
    return kuhn()>=k;
}
int main()
{
scanf("%i%i%i%i",&v,&e,&n,&k);
for(int i=1;i<=v;i++)
    for(int j=1;j<=v;j++)
    dist[i][j]=inf+1;

for(int i=1;i<=v;i++)
    dist[i][i]=0;
for(int i=1;i<=n;i++)
    scanf("%i",&teams[i]);
int a,b,t;
for(int i=1;i<=e;i++)
{
    scanf("%i%i%i",&a,&b,&t);
    dist[a][b]=min(dist[a][b],t);
    dist[b][a]=min(dist[b][a],t);
}
for(int k=1;k<=v;k++)
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
        dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
if(test(inf)==0)
{
    printf("-1\n");
    return 0;
}
int ok=inf,not_ok=-1;
while(ok-not_ok>1)
{
    int av=(ok+not_ok)/2;
    if(test(av))ok=av;
    else not_ok=av;
}
printf("%i\n",ok);
return 0;
}