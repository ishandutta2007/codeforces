#include<bits/stdc++.h>
using namespace std;
const int nmax=800+5;

struct edge
{
    int from,to,flow;
    double cost;
};

vector<edge> all;
vector<int> adj[nmax];
void add_edge(int from,int to,int flow,double cost)
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
double min_cost[nmax];

int type[nmax];

deque<int> active;
void spfa(int from,int UP_TO)
{
    for(int i=1;i<=UP_TO;i++)
    {
        parent[i]=-1;
        min_cost[i]=1e9;
    }

    min_cost[from]=0;

    for(int i=0;i<=UP_TO;i++)type[i]=2;

    type[from]=1;

    active.push_front(from);
    while(active.size())
    {
        int current=active.front();
        active.pop_front();
        type[current]=0;

        for(auto k:adj[current])
            if(all[k].flow)
            {
                if(min_cost[all[k].from]+all[k].cost+1/1e6<min_cost[all[k].to])
                {
                    min_cost[all[k].to]=min_cost[all[k].from]+all[k].cost;
                    parent[all[k].to]=k;

                    if(type[all[k].to]==2)active.push_back(all[k].to);
                    else if(type[all[k].to]==0)active.push_front(all[k].to);
                    type[all[k].to]=1;
                }

            }
    }
}

pair<int/*flow*/,double/*cost*/> min_cost_max_flow(int from,int to)
{
    int total_flow=0;
    double total_cost=0;
    while(1)
    {
        spfa(from,2*n+1);
        if(parent[to]==-1)break;

        int node=to,current_flow=1e6;
        double current_cost=0;

        while(node!=from)
        {
            int used_path=parent[node];

            current_flow=min(current_flow,all[used_path].flow);
            current_cost+=all[used_path].cost;

            node=all[used_path].from;
        }

        total_cost+=current_flow*current_cost;

        node=to;
        while(node!=from)
        {
            int used_path=parent[node];
            all[used_path].flow-=current_flow;
            all[used_path^1].flow+=current_flow;

            node=all[used_path].from;
        }
        total_flow+=current_flow;

    }

    return {total_flow,total_cost};
}

pair<int,int> input[nmax];
int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
        scanf("%i%i",&input[i].first,&input[i].second);

    int source=0,sink=2*n+1;
    for(int i=1;i<=n;i++)
    {
        add_edge(source,i,2,0);
        add_edge(n+i,sink,1,0);
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(input[i].second>input[j].second)
                add_edge(i,j+n,1,sqrt(1.0*(input[i].first-input[j].first)*(input[i].first-input[j].first)+1.0*(input[i].second-input[j].second)*(input[i].second-input[j].second)));

    pair<int/*flow*/,double/*cost*/> current=min_cost_max_flow(source,sink);
    if(current.first<n-1)printf("-1\n");
    else printf("%.9f\n",current.second);
    return 0;
}