#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n,m;

long long t=1;
vector<int> outp={};

bool alone[nmax];

vector<int> adj[nmax];

void update_alone(int cur)
{
    if(alone[cur])return;

    alone[cur]=1;

    for(auto w:adj[cur])
        update_alone(w);
}

int parent[nmax];

int root(int u)
{
    if(u==parent[u])return u;

    parent[u]=root(parent[u]);

    return parent[u];
}
bool extend(int i)
{
    int sz;

    scanf("%i",&sz);

    if(sz==1)
    {
        int cur;

        scanf("%i",&cur);

        if(alone[cur])return 0;

        update_alone(cur);

        return 1;
    }

    int u,v;

    scanf("%i%i",&u,&v);

    if(alone[u]&&alone[v])return 0;

    if(alone[u])
    {
        update_alone(v);

        return 1;
    }

    if(alone[v])
    {
        update_alone(u);

        return 1;
    }

    if(root(u)==root(v))return 0;

    adj[u].push_back(v);
    adj[v].push_back(u);

    parent[root(u)]=root(v);

    return 1;
}

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)parent[i]=i;

    for(int i=1;i<=n;i++)
    {
        if(extend(i))
        {
            t=t*2%mod;
            outp.push_back(i);
        }
    }

    printf("%lld %i\n",t,outp.size());

    for(auto w:outp)printf("%i ",w);

    printf("\n");

    return 0;
}