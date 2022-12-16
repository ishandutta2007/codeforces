#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+5,inf=1e9;

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

                if(type[all[k].to]==1)continue;

                if(active.size()&&cost[all[k].to]<cost[active.front()])active.push_front(all[k].to);
                else active.push_back(all[k].to);

                type[all[k].to]=1;
            }

        type[current]=0;
    }

}

long long min_cost_max_flow(int wanted)
{
    int total_flow=0;
    long long total_cost=0;
    while(total_flow<wanted)
    {
        spfa();
        if(parent[sink]==-1)break;
        if(cost[sink]>=0)break;

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

int arr[nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

    source=0;
    sink=2*n+1;

    for(int i=1;i<=n;i++)
        add_edge(source,2*i-1,1,0);

    for(int j=1;j<=n;j++)
        add_edge(2*j,sink,1,0);

    for(int i=1;i<=n;i++)
        add_edge(2*i-1,2*i,1,-1);

    for(int j=1;j<=n;j++)
        for(int i=j+1;i<=n;i++)
            if(arr[i]%7==arr[j]%7||abs(arr[i]-arr[j])==1)
                add_edge(2*j,2*i-1,1,0);

    printf("%lld\n",-min_cost_max_flow(4));
    return 0;
}