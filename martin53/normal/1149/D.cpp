#include<bits/stdc++.h>
using namespace std;

const int nmax=71;

int n,m,a,b;

vector< pair<int/*to*/,int/*cost*/> > adj[nmax];

int parent[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

int id_comp[nmax],pointer=0;

long long dist[1<<(nmax/4)][nmax];

priority_queue< pair<long long/*dist*/, pair<int/*mask*/,int/*node*/> > > pq;

long long outp[nmax];

int SZ[nmax];

int main()
{
    scanf("%i%i%i%i",&n,&m,&a,&b);

    for(int i=1;i<=n;i++)parent[i]=i;

    vector< pair<int,int> > heavy={};

    for(int i=1;i<=m;i++)
    {
        int u,v,c;

        scanf("%i%i%i",&u,&v,&c);

        if(c==a)
        {
            parent[root(u)]=root(v);
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        else heavy.push_back({u,v});
    }

    for(int i=1;i<=n;i++)parent[i]=root(i);

    for(auto k:heavy)
        if(root(k.first)!=root(k.second))
        {
            adj[k.first].push_back({k.second,b});
            adj[k.second].push_back({k.first,b});
        }

    for(int i=1;i<=n;i++)SZ[parent[i]]++;

    memset(id_comp,-1,sizeof(id_comp));

    for(int i=1;i<=n;i++)
        if(SZ[i]>=4)
        {
            id_comp[i]=pointer;
            pointer++;
        }

    memset(dist,-1,sizeof(dist));

    memset(outp,-1,sizeof(outp));

    pq.push({0,{0,1}});

    while(pq.size())
    {
        pair<long long/*dist*/, pair<int/*mask*/,int/*node*/> > tp=pq.top();

        pq.pop();

        long long d=-tp.first;

        int mask=tp.second.first;
        int node=tp.second.second;

        if(outp[node]==-1)
        {
            outp[node]=d;
        }

        if(dist[mask][node]!=-1)continue;

        dist[mask][node]=d;

        for(auto k:adj[node])
            if(id_comp[parent[k.first]]!=-1&&(mask&(1<<id_comp[parent[k.first]])))continue;
            else if(k.second==a||parent[node]==parent[k.first])pq.push({-(d+k.second),{mask,k.first}});//same component
            else pq.push({-(d+k.second),{mask|(1<<id_comp[parent[node]]),k.first}});
    }

    for(int i=1;i<=n;i++)
        printf("%lld ",outp[i]);
    printf("\n");

    return 0;
}