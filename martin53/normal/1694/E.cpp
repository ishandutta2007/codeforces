#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;

vector<int> adj[nmax];

int deg[nmax];

int d[nmax];

bool been[nmax];

priority_queue< pair<int,int> > pq;

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[v].push_back(u);
        deg[u]++;
    }

    for(int i=1;i<=n;i++)
        d[i]=m+1;

    d[n]=0;

    pq.push({0,n});

    while(pq.size())
    {
        int node=pq.top().second;
        pq.pop();

        //cout<<node<<" -> "<<d[node]<<endl;

        if(been[node])continue;

        been[node]=1;

        for(auto w:adj[node])
        {
            if(d[node]+deg[w]<d[w])
            {
                d[w]=d[node]+deg[w];

                pq.push({-d[w],w});
            }

            deg[w]--;
        }
    }

    printf("%i\n",d[1]);

    return 0;
}