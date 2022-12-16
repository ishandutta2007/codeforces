#include<bits/stdc++.h>
using namespace std;

const int nmax=2e2+42;
int n,m;

vector< pair<int/*to*/,int/**/> > adj[nmax];

void wrong()
{
    printf("NO\n");
    exit(0);
}

int colour[nmax];

void dfs(int node,int col)
{
    if(colour[node])
    {
        if(colour[node]!=col)wrong();
        return;
    }

    colour[node]=col;
    for(auto k:adj[node])
        dfs(k.first,3-col);
}

int dist[nmax];

bool run()
{
    bool upd=0;

    for(int i=1;i<=n;i++)
        for(auto w:adj[i])
            if(dist[w.first]>dist[i]+w.second)
            {
                upd=1;
                dist[w.first]=dist[i]+w.second;
            }
    return upd;
}

int best=-1,outp[nmax];

void go(int start)
{
    for(int i=1;i<=n;i++)dist[i]=1e9;

    dist[start]=0;

    for(int i=1;i<=n+5;i++)
        run();

    if(run())wrong();

    int add=0;
    for(int i=1;i<=n;i++)add=max(add,-dist[i]);

    for(int i=1;i<=n;i++)dist[i]+=add;

    int maxi=0;
    for(int i=1;i<=n;i++)
        maxi=max(maxi,dist[i]);

    if(maxi>best)
    {
        best=maxi;
        for(int i=1;i<=n;i++)outp[i]=dist[i];
    }
}
void solve()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%i%i%i",&u,&v,&c);

        if(c==1)
        {
            adj[u].push_back({v,1});
            adj[v].push_back({u,-1});
        }
        else
        {
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }
    }

    dfs(1,1);

    best=-1;

    for(int i=1;i<=n;i++)
        go(i);

    printf("YES\n");
    printf("%i\n",best);
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
    printf("\n");
}

int main()
{
    int t;
    //scanf("%i",&t);
    t=1;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}