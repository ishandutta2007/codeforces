#include<bits/stdc++.h>
using namespace std;
const int nmax=50+5;

struct edge
{
    int from,to,flow,cost;
};

vector<edge> all;
vector<int> adj[nmax];
void add_edge(int from,int to,int flow,int cost)
{
    edge current;current.from=from;current.to=to;current.flow=flow;current.cost=cost;

    adj[from].push_back(all.size());
    all.push_back(current);

    adj[to].push_back(all.size());
    swap(current.from,current.to);
    current.flow=0;
    current.cost=-current.cost;
    all.push_back(current);
}
int n,k;

int parent[nmax];
int min_cost[nmax];

void bellman()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        min_cost[i]=1e9;
    }

    min_cost[1]=0;

    bool change=1;
    while(change)
    {
        change=0;
        for(int i=1;i<=n;i++)
            for(auto k:adj[i])
                if(all[k].flow)
                {
                    if(min_cost[all[k].from]+all[k].cost<min_cost[all[k].to])
                    {
                        change=1;
                        min_cost[all[k].to]=min_cost[all[k].from]+all[k].cost;
                        parent[all[k].to]=k;
                    }
                }
    }
}

int min_cost_max_flow()
{
    int total_flow=0,total_cost=0;
    while(1)
    {
        bellman();
        if(parent[n]==-1)break;

        int node=n,current_flow=1e6,current_cost=0;

        while(node!=1)
        {
            int used_path=parent[node];

            current_flow=min(current_flow,all[used_path].flow);
            current_cost+=all[used_path].cost;

            node=all[used_path].from;
        }

        if(total_cost+current_flow*current_cost>k)return total_flow+(k-total_cost)/current_cost;
        total_cost+=current_flow*current_cost;

        node=n;
        while(node!=1)
        {
            int used_path=parent[node];
            all[used_path].flow-=current_flow;
            all[used_path^1].flow+=current_flow;

            node=all[used_path].from;
        }
        total_flow+=current_flow;

    }

    return total_flow;
}

int main()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)
    {
        int current;
        for(int j=1;j<=n;j++)
        {
            scanf("%i",&current);
            if(current)
            {
                add_edge(i,j,current,0);
                add_edge(i,j,k,1);
            }
        }
    }

    printf("%i\n",min_cost_max_flow());
    return 0;
}