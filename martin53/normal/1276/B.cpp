#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,m,a,b;

vector<int> adj[nmax];

int colour[nmax][2];
int col;

int blocked;

void dfs(int node,bool which)
{
    if(node==blocked)return;
    if(colour[node][which])return;

    colour[node][which]=1;
    for(auto k:adj[node])
        dfs(k,which);
}
long long solve()
{
    scanf("%i%i%i%i",&n,&m,&a,&b);

    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        colour[i][0]=0;
        colour[i][1]=0;
    }
    int u,v;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    blocked=b;
    dfs(a,0);

    blocked=a;
    dfs(b,1);

    int not_a=0,not_b=0;

    for(int i=1;i<=n;i++)
    {
        if(colour[i][0]==0)not_a++;
        if(colour[i][1]==0)not_b++;
    }

    //cout<<"not_a "<<not_a<<" not_b "<<not_b<<endl;
    return 1LL*(not_a-1)*(not_b-1);
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        printf("%lld\n",solve());

    return 0;
}