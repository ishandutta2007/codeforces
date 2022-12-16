#include <bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,k;

int depth[nmax],SZ[nmax];

int add[nmax];

vector< int >adj[nmax];

void dfs(int node,int par)
{
    depth[node]=depth[par]+1;
    SZ[node]=1;

    for(auto p:adj[node])
        if(p!=par)
        {
            dfs(p,node);
            SZ[node]+=SZ[p];
        }

    add[node]=depth[node]-SZ[node];

    //cout<<node<<" -> "<<add[node]<<endl;
}
int main()
{
    scanf("%i%i",&n,&k);

    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    long long output=0;

    sort(add+1,add+n+1);

    for(int i=n;i>=n-k+1;i--)
        output=output+add[i];

    printf("%lld\n",output);
    return 0;
}