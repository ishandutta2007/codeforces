#include<bits/stdc++.h>
using namespace std;
const int nmax=1200+42;

struct edge
{
    int from,to,flow;
};

int n,m,k;

int source,sink;

vector<int> adj[nmax];
vector<edge> all;

int deg[nmax];

int output[nmax];

void add_edge(int from,int to,int flow)
{
    edge current;current.from=from;current.to=to;current.flow=flow;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);
    current.flow=0;
    adj[to].push_back(all.size());
    all.push_back(current);
}

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
            return 1;
        }
    return 0;
}
int max_flow()
{
    int flow=0;
    while(1)
    {
        memset(been,0,sizeof(been));
        int current=dfs(source);
        if(current==0)break;
        flow=flow+current;
    }
    return flow;
}

pair<int,int> edges[nmax];

vector<int> group[2*nmax];

int colour[nmax],hsh[50*nmax];
void solve()
{
    scanf("%i%i%i",&n,&m,&k);
    source=0;
    sink=m+n+1;
    for(int i=source;i<=sink;i++)
        group[i]={};

    all={};
    for(int j=source;j<=sink;j++)
        adj[j].clear();

    for(int i=1;i<=n;i++)deg[i]=0;

    int u,v;

    for(int i=1;i<=m;i++)
        add_edge(source,i,1);

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);

        hsh[all.size()]=i;

        edges[i]={u,v};
        add_edge(i,u+m,1);

        hsh[all.size()]=i;

        add_edge(i,v+m,1);
        deg[u]++;
        deg[v]++;

        colour[i]=i;
    }

    int wanted=0;
    for(int j=1;j<=n;j++)
    {
        int current=2*max(0,deg[j]-k);
        add_edge(j+m,sink,current);
        wanted=wanted+current;
    }

    if(max_flow()!=wanted)
    {
        for(int i=1;i<=m;i++)printf("0 ");
        printf("\n");
        return;
    }

    for(int i=1;i<=m;i++)
        for(auto k:adj[i])
            if(m+1<=all[k].to&&all[k].to<=m+n&&all[k].flow==0)
                group[all[k].to-m].push_back(hsh[k]);


    int c_now=m+1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<group[i].size();j=j+2)
        {
            colour[group[i][j-1]]=c_now;
            colour[group[i][j]]=c_now;
            c_now++;
        }
    }

    for(int i=1;i<=m;i++)
        printf("%i ",colour[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        solve();
    return 0;
}