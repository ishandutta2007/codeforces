#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;

vector<int> adj[nmax];

int depth[nmax];

void dfs_test(int node,int parent)
{
    depth[node]=depth[parent]+1;
    for(auto k:adj[node])
        if(k!=parent)dfs_test(k,node);
}
int ask_min()
{
    for(int i=1;i<=n;i++)
        if(adj[i].size()>=2)
        {
            dfs_test(i,0);

            bool in[2]={0,0};

            for(int j=1;j<=n;j++)
                if(adj[j].size()==1)in[depth[j]%2]=1;

            if(in[0]&&in[1])return 3;
            return 1;
        }

    return 3;
}

bool is_parent[nmax];

int ask_max()
{
    int output=n-1;
    for(int i=1;i<=n;i++)
        if(adj[i].size()==1)
        {
            int other=adj[i][0];
            if(is_parent[other])output--;
            is_parent[other]=1;
        }
    return output;
}
int main()
{
    scanf("%i",&n);

    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("%i %i\n",ask_min(),ask_max());
    return 0;
}