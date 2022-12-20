#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

struct edge
{
    int u,v,c;
};
edge inp[nmax];

int n,m;

set<int> adj[nmax];

vector<int> in={};

bool been[nmax];

set<int> active={};

void dfs(int node)
{
    //cout<<"dfs "<<node<<endl;

    if(been[node])return;

    been[node]=1;
    in.push_back(node);

    active.erase(node);

    int cur=0;
    while(active.size())
    {
        set<int>::iterator it=active.upper_bound(cur);

        if(it==active.end())break;

        int to=*it;

        cur=to;

        if(adj[node].count(to))continue;

        dfs(to);
    }

}

int parent[nmax];

int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
long long take_all()
{
    for(int i=1;i<=n;i++)active.insert(i);

    for(int i=1;i<=n;i++)
        if(been[i]==0)
        {
            in={};

            dfs(i);

            for(auto w:in)
                parent[w]=in[0];
        }

    long long ret=0;
    for(int i=1;i<=m;i++)
    {
        int u=root(inp[i].u);
        int v=root(inp[i].v);

        if(u==v)continue;

        ret+=inp[i].c;

        parent[u]=v;
    }

    return ret;
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

const int n_small=1000;
int cost[n_small][n_small];

int pointer_help=0;
edge help[n_small*n_small];

pair< vector< pair<int,int> >,long long> go(pair<int,int> blocked)
{
    if(blocked.first>blocked.second)swap(blocked.first,blocked.second);

    //cout<<"block "<<blocked.first<<" "<<blocked.second<<endl;

    if(cost[blocked.first][blocked.second]!=0)return {{},1e18};

    vector< pair<int,int> > ret={};

    long long val=0;

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=pointer_help;i++)
    {
        if(blocked==make_pair(help[i].u,help[i].v))continue;

        int u=root(help[i].u);
        int v=root(help[i].v);

        if(u==v)continue;

        ret.push_back({help[i].u,help[i].v});

        val+=help[i].c;

        parent[u]=v;
    }

    return {ret,val};
}
long long solve_small()
{
    //cout<<"! solve small"<<endl;

    for(int i=1;i<=m;i++)
    {
        int u=inp[i].u;
        int v=inp[i].v;

        cost[u][v]=inp[i].c;
        cost[v][u]=inp[i].c;
    }

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            pointer_help++;
            help[pointer_help].u=i;
            help[pointer_help].v=j;
            help[pointer_help].c=cost[i][j];
        }

    sort(help+1,help+pointer_help+1,cmp);

    pair< vector< pair<int,int> >,long long> info=go({help[1].u,help[1].v});

    long long ret=info.second;

    for(auto w:info.first)
        ret=min(ret,go(w).second);

    return ret;
}

int main()
{
    int x_all=0;

    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].c);

        adj[inp[i].u].insert(inp[i].v);
        adj[inp[i].v].insert(inp[i].u);

        x_all^=inp[i].c;
    }

    sort(inp+1,inp+m+1,cmp);

    long long other=take_all();

    long long outp=x_all+other;

    //cout<<"outp= "<<outp<<" "<<x_all<<" "<<other<<endl;

    if(1LL*n*(n-1)/2-m>n-1)outp=other;//some 0 edge is missing
    else
    {
        //n<=700
        outp=min(outp,solve_small());
    }

    printf("%lld\n",outp);

    return 0;
}