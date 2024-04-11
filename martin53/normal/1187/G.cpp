#include<bits/stdc++.h>
using namespace std;
const int nmax=6000;

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

int n,m,c,d;

int parent[nmax];
long long cost[nmax];

int type[nmax];

deque<int> active;

int MX;

void spfa()
{
    for(int i=source;i<=MX;i++)
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

long long min_cost_max_flow(int wanted)
{
    int total_flow=0;
    long long total_cost=0;
    while(total_flow<wanted)
    {
        spfa();
        if(parent[sink]==-1)
        {
            cout<<"?"<<endl;
            break;
        }

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

int k;

int MX_time;
int hsh(int node,int t)
{
    //cout<<node<<" "<<t<<endl;
    assert(t<MX_time);

    MX=max(MX,node*MX_time+t);
    return node*MX_time+t;
}
void make_street(int from,int to)
{
    for(int t=0;t<MX_time-1;t++)
        for(int i=1;i<=k;i++)
            add_edge(hsh(from,t),hsh(to,t+1),1,c+(2*i-1)*d);
}
int main()
{
    scanf("%i%i%i%i%i",&n,&m,&k,&c,&d);

    MX_time=n+k+2;

    source=0;
    sink=1;

    int current;
    for(int i=1;i<=k;i++)
    {
        scanf("%i",&current);
        add_edge(source,hsh(current,0),1,0);
    }

    for(int t=1;t<MX_time;t++)
        add_edge(hsh(1,t),sink,k,0);

    for(int node=1;node<=n;node++)
        for(int t=0;t<MX_time-1;t++)
            add_edge(hsh(node,t),hsh(node,t+1),k,c);

    int u,v;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);
        make_street(u,v);
        make_street(v,u);
    }

    printf("%lld\n",min_cost_max_flow(k));
    return 0;
}