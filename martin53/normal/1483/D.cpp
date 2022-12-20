#include<bits/stdc++.h>
using namespace std;

const int nmax=600+42;
int n,m,q;

struct edge
{
    int u,v,l;
};
edge queries[nmax*nmax];

edge edges[nmax*nmax];

long long dist[nmax][nmax],allow[nmax][nmax];

bool been[nmax][nmax],valid[nmax*nmax];

priority_queue< pair<int, pair<int,int> > > pq;

void go()
{
    for(int i=1;i<=q;i++)
    {
        allow[queries[i].u][queries[i].v]=queries[i].l;
        allow[queries[i].v][queries[i].u]=queries[i].l;

        pq.push({queries[i].l,{queries[i].u,queries[i].v}});
        pq.push({queries[i].l,{queries[i].v,queries[i].u}});
    }

    while(pq.size())
    {
        pair<int, pair<int,int> > tp=pq.top();

        pq.pop();

        int u=tp.second.first;
        int v=tp.second.second;

        if(been[u][v])continue;

        been[u][v]=1;

        //cout<<"gaz "<<u<<" "<<v<<" "<<allow[u][v]<<endl;

        for(int p=1;p<=n;p++)
        {
            if(allow[u][v]-dist[u][p]>allow[p][v])
            {
                allow[p][v]=allow[u][v]-dist[u][p];
                allow[v][p]=allow[p][v];

                //cout<<"extend "<<p<<" "<<v<<" "<<allow[p][v]<<endl;

                pq.push({allow[p][v],{p,v}});
                pq.push({allow[v][p],{v,p}});
            }

            /*
            if(allow[u][v]-dist[p][v]>allow[u][p])
            {
                allow[u][p]=allow[u][v]-dist[p][v];

                cout<<"extend "<<u<<" "<<p<<" "<<allow[u][p]<<endl;

                pq.push({allow[u][p],{u,p}});
            }
            */
        }

        //cout<<"---"<<endl;
    }

    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<i<<" "<<j<<" -> "<<allow[i][j]<<endl;
    }
    */

    for(int i=1;i<=m;i++)
        if(allow[edges[i].u][edges[i].v]>=edges[i].l)valid[i]=1;
}

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)dist[i][j]=1e18;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&edges[i].u,&edges[i].v,&edges[i].l);

        dist[edges[i].u][edges[i].v]=edges[i].l;
        dist[edges[i].v][edges[i].u]=edges[i].l;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    /*
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<i<<" "<<j<<" -> "<<dist[i][j]<<endl;
    */

    scanf("%i",&q);

    for(int i=1;i<=q;i++)
        scanf("%i%i%i",&queries[i].u,&queries[i].v,&queries[i].l);

    go();

    int outp=0;
    for(int i=1;i<=m;i++)
        outp+=valid[i];

    printf("%i\n",outp);

    return 0;
}