#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;
vector<int> adj[nmax];

int parent[nmax],cnt[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

int seen[2],colour[nmax];

bool WRONG=0;

void dfs(int node,int col)
{
    if(colour[node]!=-1)
    {
        if(colour[node]!=col)WRONG=1;

        return;
    }

    colour[node]=col;
    seen[col]+=cnt[node];

    for(auto w:adj[node])
        dfs(w,!col);
}

int solve()
{
    WRONG=0;

    cin>>n>>m;

    for(int i=1;i<=n;i++)parent[i]=i,colour[i]=-1;

    for(int i=1;i<=n;i++)adj[i]={};

    vector< pair<int,int> > edges={};

    for(int i=1;i<=m;i++)
    {
        int u,v;
        string type;

        cin>>u>>v>>type;

        if(type=="crewmate")parent[root(u)]=root(v);
        else edges.push_back({u,v});
    }

    for(int i=1;i<=n;i++)cnt[i]=0;

    for(int i=1;i<=n;i++)cnt[root(i)]++;

    for(auto w:edges)
    {
        int u=root(w.first);
        int v=root(w.second);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int outp=0;

    for(int i=1;i<=n;i++)
        if(colour[i]==-1)
        {
            seen[0]=0;
            seen[1]=0;

            dfs(i,0);

            outp+=max(seen[0],seen[1]);
        }

    if(WRONG)return -1;
    return outp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}