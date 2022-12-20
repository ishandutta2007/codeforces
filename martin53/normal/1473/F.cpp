#include<bits/stdc++.h>
using namespace std;
const int nmax=12000;
const long long inf=1e18,MX=1e12;

struct edge
{
    int from,to;
    long long flow;
};

vector<int> adj[nmax];
vector<edge> all;

int n,m;

void add_edge(int from,int to,long long flow)
{
    edge current;current.from=from;current.to=to;current.flow=flow;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);
    current.flow=0;
    adj[to].push_back(all.size());
    all.push_back(current);
}

int source,sink;

long long bfs_dist[nmax];

queue< pair<int/*node*/,int/*cost*/> > active,idle;
void bfs()
{
    for(int i=source;i<=sink;i++)bfs_dist[i]=inf;

    active=idle;
    active.push({source,0});

    while(active.size())
    {
        pair<int/*node*/,int/*cost*/> current=active.front();
        active.pop();

        if(bfs_dist[current.first]!=inf)continue;

        bfs_dist[current.first]=current.second;

        if(current.first==sink)return;

        for(auto k:adj[current.first])
            if(all[k].flow&&bfs_dist[all[k].to]==inf)active.push({all[k].to,current.second+1});
    }
}

bool been[nmax];

long long dfs(int node,long long cap)
{
    if(node==sink)return cap;
    if(been[node])return 0;
    been[node]=1;
    for(auto k:adj[node])
    {
        if(bfs_dist[node]<bfs_dist[all[k].to]&&all[k].flow)
        {
            long long current=dfs(all[k].to,min(cap,all[k].flow));
            if(current==0)continue;

            been[node]=0;
            all[k].flow-=current;
            all[k^1].flow+=current;
            return current;
        }
    }
    return 0;
}
long long max_flow()
{
    long long total_flow=0;

    while(1)
    {
        bfs();

        if(bfs_dist[sink]==inf)break;

        memset(been,0,sizeof(been));
        while(1)
        {
            long long current=dfs(source,inf);
            if(current==0)break;
            total_flow+=current;
        }
    }
    return total_flow;
}

int lst[nmax],a[nmax],b[nmax];

int main()
{
    scanf("%i",&n);
    source=0;
    sink=n+1;

    for(int i=1;i<=n;i++)
        scanf("%i",&a[i]);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&b[i]);

        if(b[i]>0)add_edge(source,i,b[i]);
        else add_edge(i,sink,-b[i]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=100;j++)
            if(a[i]%j==0&&lst[j])
                add_edge(i,lst[j],inf);

        lst[a[i]]=i;
    }

    long long sum=0;

    for(int i=1;i<=n;i++)
        if(b[i]>0)sum+=b[i];

    sum=sum-max_flow();

    printf("%lld\n",sum);
    return 0;
}