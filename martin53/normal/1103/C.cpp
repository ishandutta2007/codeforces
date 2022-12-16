#include<bits/stdc++.h>
using namespace std;

const int nmax=2.5e5+42;

int n,m,k;

int low;

int parent[nmax],depth[nmax];

vector<int> adj[nmax];

vector<int> leaves;

void dfs(int node,int par)
{
    parent[node]=par;

    depth[node]=depth[par]+1;

    if(depth[node]==low)
    {
        printf("PATH\n");
        printf("%i\n",depth[node]);
        while(node)
        {
            printf("%i ",node);
            node=parent[node];
        }

        exit(0);
    }

    bool gone=0;

    for(auto k:adj[node])
        if(depth[k]==0)
        {
            dfs(k,node);
            gone=1;
        }

    if(gone==0)leaves.push_back(node);
}

bool cmp(int a,int b)
{
    return depth[a]>depth[b];
}

void print(int from,int to)
{
    printf("%i ",from);
    while(from!=to)
    {
        from=parent[from];
        printf("%i ",from);
    }
    printf("\n");
}
int main()
{
    scanf("%i%i%i",&n,&m,&k);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    low=(n+k-1)/k;

    dfs(1,0);

    assert(leaves.size()>=k);

    printf("CYCLES\n");

    for(int i=0;i<k;i++)
    {
        int node=leaves[i];

        vector<int> higher={};
        for(auto p:adj[node])
            if(parent[node]!=p)
                higher.push_back(p);

        sort(higher.begin(),higher.end(),cmp);

        int p=higher[0];
        int q=higher[1];

        if((depth[node]-depth[p]+1)%3!=0)
        {
            printf("%i\n",depth[node]-depth[p]+1);
            print(node,p);
            continue;
        }

        if((depth[node]-depth[q]+1)%3!=0)
        {
            printf("%i\n",depth[node]-depth[q]+1);
            print(node,q);
            continue;
        }

        printf("%i\n",1+depth[p]-depth[q]+1);
        printf("%i ",node);
        print(p,q);
    }
    return 0;
}