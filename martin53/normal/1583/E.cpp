#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n,m;

int parent[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

vector<int> adj[nmax];

int q;
pair<int,int> inp[nmax];
int cnt[nmax];

int depth[nmax],UP[nmax];

void dfs(int node,int par,int h)
{
    depth[node]=h;
    UP[node]=par;

    for(auto w:adj[node])
        if(w!=par)dfs(w,node,h+1);
}

void add_path(int u,int v)
{
    vector<int> seen[2];
    seen[0]={};
    seen[1]={};

    while(u!=v)
    {
        if(depth[u]>depth[v])
        {
            seen[0].push_back(u);
            u=UP[u];
        }
        else
        {
            seen[1].push_back(v);
            v=UP[v];
        }
    }

    seen[0].push_back(u);

    reverse(seen[1].begin(),seen[1].end());
    for(auto w:seen[1])seen[0].push_back(w);

    printf("%i\n",seen[0].size());
    for(auto w:seen[0])printf("%i ",w);
    printf("\n");
}

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        if(root(u)!=root(v))
        {
            parent[root(u)]=root(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int q;
    scanf("%i",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);
        cnt[inp[i].first]++;
        cnt[inp[i].second]++;
    }

    dfs(1,0,0);

    int sum=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]%2)sum++;

    if(sum)
    {
        printf("NO\n");
        printf("%i\n",sum/2);
        return 0;
    }

    printf("YES\n");
    for(int i=1;i<=q;i++)
        add_path(inp[i].first,inp[i].second);

    return 0;
}