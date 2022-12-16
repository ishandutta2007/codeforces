#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,inf=1e5;

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

int n,m;

int parent[nmax];
int cost[nmax];

void bellman()
{
    for(int i=source;i<=sink;i++)
    {
        parent[i]=-1;
        cost[i]=1e9;
    }

    parent[source]=0;
    cost[source]=0;

    bool change=1;
    while(change)
    {
        change=0;
        for(int i=source;i<=sink;i++)
            for(auto k:adj[i])
                if(all[k].flow&&cost[all[k].from]+all[k].cost<cost[all[k].to])
                {
                    cost[all[k].to]=cost[all[k].from]+all[k].cost;
                    parent[all[k].to]=k;
                    change=1;
                }
    }
}
int min_cost_max_flow()
{
    int total_flow=0,total_cost=0;
    while(1)
    {
        bellman();
        if(parent[sink]==-1)break;

        if(total_flow>=n-m&&cost[sink]>=0)break;

        int node=sink,cost_now=0;

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

int bits[nmax];

int cnt(int num)
{
    int ret=0;
    while(num)
    {
        ret=ret+num%2;
        num=num/2;
    }
    return ret;
}

int which[nmax];

vector< pair<int,int> > edges;

void solve(int lines,int current,int cst)
{
    if(current==0)
    {
        printf("%i %i\n",lines,cst);
        return;
    }

    int prv=-1;
    for(int j=current-1;j>=1;j--)
        if(which[j]==which[current])
        {
            prv=j;
            break;
        }

    if(prv==-1)
    {
        solve(lines+2,current-1,cst);
        printf("%c=%i\n",char(which[current]-1+'a'),arr[current]);
        printf("print(%c)\n",char(which[current]-1+'a'));
    }
    else
    {
        if(arr[prv]==arr[current])solve(lines+1,current-1,cst);
        else
        {
            solve(lines+2,current-1,cst);
            printf("%c=%i\n",char(which[current]-1+'a'),arr[current]);
        }
        printf("print(%c)\n",char(which[current]-1+'a'));
    }
}
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&arr[i]);
        bits[i]=cnt(arr[i]);
    }

    source=0;
    sink=2*n+1;

    for(int i=1;i<=n;i++)
        add_edge(source,i,1,0);

    for(int j=1;j<=n;j++)
        add_edge(j+n,sink,1,0);

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            add_edge(i,j+n,1,(arr[i]==arr[j]?-bits[j]:0));

    int sum=0;
    for(int i=1;i<=n;i++)
        sum=sum+bits[i];

    sum=sum+min_cost_max_flow();

    for(auto k:all)
        if(1<=k.from&&k.from<=n&&n+1<=k.to&&k.to<=n+n&&k.flow==0)
            edges.push_back({k.from,k.to-n});

    int current=0;
    for(int i=1;i<=n;i++)
    {
        if(which[i]==0)
        {
            current++;
            which[i]=current;
        }

        for(auto k:edges)
            if(k.first==i)which[k.second]=which[i];
    }

    solve(0,n,sum);

    return 0;
}