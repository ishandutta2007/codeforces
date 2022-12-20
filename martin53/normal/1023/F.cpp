#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

struct info
{
    int u,v,cost;
};
info inp[nmax];

pair<int,int> my[nmax];

int n,k,m;

int parent[nmax];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

long long outp;

set<int> seen[nmax];

vector<int> adj[nmax];

set< pair<int,int> > my_edge;

void solve(int node,int par)
{
    int biggest=-1;

    for(auto k:adj[node])
        if(k!=par)
        {
            solve(k,node);

            if(biggest==-1)biggest=k;
            else if(seen[biggest].size()<seen[k].size())biggest=k;
        }

    if(biggest!=-1)
    {
        swap(seen[biggest],seen[node]);

        for(auto w:seen[biggest])
            if(seen[node].count(w))seen[node].erase(w);
            else seen[node].insert(w);
    }

    for(auto k:adj[node])
        if(k!=par&&k!=biggest)
        {
            for(auto w:seen[k])
                if(seen[node].count(w))seen[node].erase(w);
                else seen[node].insert(w);
        }

    if(my_edge.count({node,par})||my_edge.count({par,node}))
    {
        if(seen[node].size()==0)
        {
            printf("-1\n");
            exit(0);
        }

        outp+=inp[*seen[node].begin()].cost;
    }

}
int main()
{
    scanf("%i%i%i",&n,&k,&m);

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=k;i++)
    {
        scanf("%i%i",&my[i].first,&my[i].second);
        adj[my[i].first].push_back(my[i].second);
        adj[my[i].second].push_back(my[i].first);

        parent[root(my[i].first)]=root(my[i].second);

        my_edge.insert({my[i].first,my[i].second});
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].cost);

        if(root(inp[i].u)!=root(inp[i].v))
        {
            parent[root(inp[i].u)]=root(inp[i].v);
            adj[inp[i].u].push_back(inp[i].v);
            adj[inp[i].v].push_back(inp[i].u);
        }
        else
        {
            seen[inp[i].u].insert(i);
            seen[inp[i].v].insert(i);
        }
    }

    solve(1,0);

    printf("%lld\n",outp);
    return 0;
}