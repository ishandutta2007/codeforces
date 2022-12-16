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

int hsh(int node,int val)
{
    return node*207+val+104;
}
struct f
{
    int a,b,c;
};

f func[nmax];
int le[nmax],ri[nmax];

int eval(int which,int x)
{
    return x*x*func[which].a+x*func[which].b+func[which].c;
}
int main()
{
    scanf("%i%i",&n,&m);
    source=0;
    sink=hsh(51,-101);

    for(int i=1;i<=n;i++)
        scanf("%i%i%i",&func[i].a,&func[i].b,&func[i].c);

    for(int i=1;i<=n;i++)
        scanf("%i%i",&le[i],&ri[i]);

    for(int i=1;i<=n;i++)
    {
        add_edge(source,hsh(i,le[i]),inf);

        for(int j=le[i];j<=ri[i];j++)
            add_edge(hsh(i,j),hsh(i,j+1),MX-eval(i,j));

        add_edge(hsh(i,ri[i]+1),sink,inf);
    }

    int u,v,d;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&u,&v,&d);

        for(int xu=le[u];xu<=ri[u];xu++)
        {
            int xv=xu-d;
            if(le[v]<=xv&&xv<=ri[v]+1)
                add_edge(hsh(u,xu),hsh(v,xv),inf);
        }
    }

    printf("%lld\n",MX*n-max_flow());
    return 0;
}