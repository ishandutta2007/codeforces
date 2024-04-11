#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;

vector<int> adj[nmax],all_edges[nmax];

int parent[nmax];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

vector<int> outp={},order={};

void dfs(int node,int par,int d)
{
    for(auto k:adj[node])
        if(k!=par)
            dfs(k,node,d+1);

    order.push_back(node);
}

bool on[nmax];

void solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)parent[i]=i,adj[i]={},all_edges[i]={},all_edges[i]={};

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        all_edges[u].push_back(v);
        all_edges[v].push_back(u);

        if(root(u)==root(v))continue;

        parent[root(u)]=root(v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int j=1;j<=n;j++)
        if(root(j)!=root(1))
        {
            printf("NO\n");
            return;
        }

    /*
    for(int i=1;i<=n;i++)
    {
        cout<<"adj: "<<i<<" -> ";for(auto j:adj[i])cout<<j<<" ";cout<<endl;
    }
    */

    order={};

    outp={};

    dfs(1,0,0);

    reverse(order.begin(),order.end());

    for(int i=1;i<=n;i++)on[i]=0;

    //cout<<"order: ";for(auto w:order)cout<<w<<" ";cout<<endl;

    for(auto w:order)
    {
        int sum=0;

        for(auto k:all_edges[w])
            sum+=on[k];

        if(sum==0)
        {
            on[w]=1;
            outp.push_back(w);
        }
    }
    printf("YES\n");
    printf("%i\n",outp.size());

    for(auto w:outp)printf("%i ",w);

    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}