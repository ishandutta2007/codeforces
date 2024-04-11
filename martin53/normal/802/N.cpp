#include<bits/stdc++.h>
using namespace std;
const int nmax=2200*2+42,inf=1e5;

struct edge
{
    int from,to,flow,cost;
};

vector<int> adj[nmax];
vector<edge> all;

void add_edge(int from,int to,int flow,int cost)
{
    edge current;current.from=from;current.to=to;current.flow=flow;current.cost=cost;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);
    current.flow=0;
    current.cost=-cost;
    adj[to].push_back(all.size());
    all.push_back(current);
}

int source,sink;

int n,k;

int parent[nmax];
long long cost[nmax];

int type[nmax];

deque<int> active;

void spfa()
{
    for(int i=source;i<=sink;i++)
    {
        parent[i]=-1;
        cost[i]=1e18;
        type[i]=2;
    }

    parent[source]=0;
    cost[source]=0;
    type[source]=1;

    active.push_back(source);

    while(active.size())
    {
        int current=active.front();
        active.pop_front();

        for(auto k:adj[current])
            if(all[k].flow&&cost[all[k].from]+all[k].cost<cost[all[k].to])
            {
                cost[all[k].to]=cost[all[k].from]+all[k].cost;
                parent[all[k].to]=k;

                if(type[all[k].to]==2)active.push_back(all[k].to);
                else if(type[all[k].to]==0)active.push_front(all[k].to);
                type[all[k].to]=1;
            }
        type[current]=0;
    }
}
long long min_cost_max_flow()
{
    int total_flow=0;
    long long total_cost=0;
    while(total_flow<k)
    {
        spfa();

        int node=sink;
        long long cost_now=0;

        while(node!=source)
        {
            int used_edge=parent[node];

            all[used_edge].flow--;
            all[used_edge^1].flow++;
            cost_now+=all[used_edge].cost;

            node=all[used_edge].from;
        }
        total_flow++;
        total_cost=total_cost+cost_now;
    }
    return total_cost;
}

int a[nmax];
int b[nmax];

int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%i",&b[i]);

    source=0;
    sink=n+1;

    for(int i=1;i<=n;i++)
        add_edge(source,i,1,a[i]);

    for(int j=1;j<=n;j++)
        add_edge(j,sink,1,b[j]);

    for(int i=1;i<n;i++)
        add_edge(i,i+1,k,0);

    printf("%lld\n",min_cost_max_flow());
    return 0;
}