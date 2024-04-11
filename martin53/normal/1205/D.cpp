#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n;

vector<int> adj[nmax];

int SZ[nmax];

void dfs_SZ(int node,int par)
{
    SZ[node]=1;
    for(auto k:adj[node])
        if(k!=par)
        {
            dfs_SZ(k,node);
            SZ[node]+=SZ[k];
        }
}

int centroid()
{
    dfs_SZ(1,0);

    int node=1;
    int req=SZ[node]/2;

    while(SZ[node]>req)
    {
        bool stop=1;

        for(auto k:adj[node])
            if(SZ[node]>SZ[k]&&SZ[k]>req)
            {
                node=k;
                stop=0;
                break;
            }

        if(stop)break;
    }
    return node;
}

int parent_comp[nmax];
int root(int node)
{
    if(parent_comp[node]==node)return node;
    parent_comp[node]=root(parent_comp[node]);
    return parent_comp[node];
}
int type[nmax];//0-> lower, 1-> upper

int parent[nmax];

int value[nmax],low;

void dfs_lower(int node,int par)
{
    //cout<<"dfs_lower "<<node<<" "<<par<<endl;

    parent[node]=par;

    low++;

    value[node]=low;

    for(auto k:adj[node])
        if(k!=par)dfs_lower(k,node);
}

int up;

void dfs_upper(int node,int par)
{
    parent[node]=par;

    up+=low+1;

    value[node]=up;

    for(auto k:adj[node])
        if(k!=par)dfs_upper(k,node);
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n==1)return 0;

    int cent=centroid();

    //cout<<"cent= "<<cent<<endl;

    for(int i=1;i<=n;i++)parent_comp[i]=i;

    for(int i=1;i<=n;i++)
        for(auto j:adj[i])
            if(i!=cent&&j!=cent)
            {
                parent_comp[root(i)]=root(j);
            }

    memset(SZ,0,sizeof(SZ));

    for(int i=1;i<=n;i++)
        if(i!=cent)SZ[root(i)]++;

    vector< pair<int/*size*/,int/*component*/> > active={};

    for(int i=1;i<=n;i++)
        if(SZ[i])active.push_back({SZ[i],i});

    sort(active.begin(),active.end());

    int wanted=n/3;

    if(active.back().first>=wanted)type[active.back().second]=1;
    else
    {
        for(auto k:active)
        {
            wanted=wanted-k.first;

            type[k.second]=1;

            if(wanted<=0)break;
        }
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<type[i]<<" "<<SZ[i]<<endl;
    */
    for(auto k:adj[cent])
        if(type[root(k)]==1)
            dfs_lower(k,cent);

    for(auto k:adj[cent])
        if(type[root(k)]==0)
            dfs_upper(k,cent);
    /*
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<parent[i]<<" "<<value[i]<<endl;
    */
    for(int i=1;i<=n;i++)
        if(i!=cent)
        {
            printf("%i %i %i\n",i,parent[i],value[i]-value[parent[i]]);
        }

    return 0;
}