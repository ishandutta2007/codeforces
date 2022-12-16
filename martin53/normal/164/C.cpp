#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,inf=2e9+42;

int n,k;
struct task
{
    int s,t,c;
};
task inp[nmax];
int source,sink;

struct edge
{
    int from,to,flow,cost;
};
vector< edge > all;
vector<int> adj[nmax];

void add_edge(int from,int to,int flow,int cost)
{
    edge current;current.from=from;current.to=to;current.flow=flow;current.cost=cost;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);current.flow=0;current.cost=-current.cost;
    adj[to].push_back(all.size());
    all.push_back(current);
}
int to_check[nmax];

void build()
{
    set<int> active={1,inf};
    for(int i=1;i<=n;i++)
    {
        active.insert(inp[i].s);
        active.insert(inp[i].s+inp[i].t);
    }

    map<int,int> mem={};
    int current=0;
    for(auto k:active)
    {
        current++;
        mem[k]=current;
    }

    source=1;
    sink=current;

    for(int i=1;i<sink;i++)
        add_edge(i,i+1,k,0);

    for(int i=1;i<=n;i++)
    {
        int s=mem[inp[i].s];
        int t=mem[inp[i].s+inp[i].t];

        to_check[i]=all.size();

        add_edge(s,t,1,-inp[i].c);
    }
}

int dist[nmax];
int parent[nmax];
int type[nmax];

void spfa()
{
    for(int i=1;i<=sink;i++)
    {
        parent[i]=0;
        dist[i]=inf;
        type[i]=2;
    }

    dist[source]=0;
    type[source]=1;

    deque<int> active={};
    active.push_back(source);

    while(active.size())
    {
        int current=active.front();
        active.pop_front();

        type[current]=0;
        for(auto k:adj[current])
            if(all[k].flow&&dist[current]+all[k].cost<dist[all[k].to])
            {
                dist[all[k].to]=dist[current]+all[k].cost;
                parent[all[k].to]=k;

                if(type[all[k].to]==2)active.push_back(all[k].to);
                if(type[all[k].to]==0)active.push_front(all[k].to);
                type[all[k].to]=1;
            }
    }

}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%i%i%i",&inp[i].s,&inp[i].t,&inp[i].c);

    build();

    for(int i=1;i<=k;i++)
    {
        spfa();
        if(dist[sink]==inf)break;

        int node=sink;

        while(node!=source)
        {
            int which_edge=parent[node];
            all[which_edge].flow--;
            all[which_edge^1].flow++;

            node=all[which_edge].from;
        }

    }

    for(int i=1;i<=n;i++)
        printf("%i ",1-all[to_check[i]].flow);
    return 0;
}