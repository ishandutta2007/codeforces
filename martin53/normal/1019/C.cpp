#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;
vector<int> adj[nmax],trav[nmax];

bool take[nmax],in[nmax];

void solve(int node)
{
    if(node>n)return;

    if(in[node])
    {
        solve(node+1);
        return;
    }

    in[node]=1;

    vector<int> other={};
    for(auto k:adj[node])
        if(in[k]==0)
        {
            in[k]=1;
            other.push_back(k);
        }

    solve(node+1);

    bool edge=0;
    for(auto k:trav[node])
        if(take[k])edge=1;

    if(edge==0)
    {
        take[node]=1;
    }

}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        trav[v].push_back(u);
    }

    solve(1);

    vector<int> outp={};
    for(int i=1;i<=n;i++)
        if(take[i])outp.push_back(i);

    printf("%i\n",outp.size());
    for(auto k:outp)printf("%i ",k);

    return 0;
}