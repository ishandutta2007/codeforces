#include<bits/stdc++.h>
using namespace std;
const int nmax=4e3+42;

struct edge
{
    int from,to,flow,id_original;
};

vector<int> adj[nmax];
vector<edge> all;

void add_edge(int from,int to,int flow,int id_original)
{
    edge current;current.from=from;current.to=to;current.flow=flow;current.id_original=id_original;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);
    current.flow=0;
    adj[to].push_back(all.size());
    all.push_back(current);
}
int le,ri,m;

int deg[nmax];

bool on[nmax];

int source,sink;

bool been[nmax];

int dfs(int node)
{
    if(node==sink)return 1;
    if(been[node])return 0;
    been[node]=1;

    for(auto k:adj[node])
        if(all[k].flow&&dfs(all[k].to))
        {
            all[k].flow--;
            all[k^1].flow++;

            on[all[k].id_original]=!on[all[k].id_original];
            return 1;
        }
    return 0;
}
int max_flow()
{
    while(1)
    {
        for(int j=source;j<=sink;j++)
            been[j]=0;

        int current=dfs(source);
        if(current==0)break;
    }
}

vector<int> output[nmax];
int main()
{
    scanf("%i%i%i",&le,&ri,&m);

    source=0;
    sink=le+ri+1;

    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);
        add_edge(u,le+v,1,i);
        deg[u]++;
        deg[le+v]++;
    }

    int mini=deg[1];
    for(int j=1;j<=le+ri;j++)
        mini=min(mini,deg[j]);

    for(int i=1;i<=le;i++)
        add_edge(source,i,deg[i]-mini,0);

    for(int j=1;j<=ri;j++)
        add_edge(le+j,sink,deg[le+j]-mini,0);

    for(int k=mini;k>=0;k--)
    {
        max_flow();
        for(int j=1;j<=m;j++)
            if(on[j]==0)output[k].push_back(j);

        for(auto &p:all)
            if(p.from==source||p.to==sink)p.flow++;
    }

    for(int k=0;k<=mini;k++)
    {
        printf("%i",output[k].size());
        for(auto w:output[k])printf(" %i",w);
        printf("\n");
    }
    return 0;
}