#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n;

char a[nmax][nmax],b[nmax][nmax];

int diff[nmax][nmax];

vector< pair<int,int> > adj[2*nmax];

int colour[2*nmax];

bool ok;

void dfs(int node,int cur)
{
    if(colour[node]!=-1)
    {
        if(colour[node]!=cur)ok=0;

        return;
    }

    colour[node]=cur;

    for(auto w:adj[node])
        dfs(w.first,cur^w.second);
}

bool solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>a[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>b[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            diff[i][j]=(a[i][j]-'0')^(b[i][j]-'0');

    for(int i=1;i<=2*n;i++)adj[i]={};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            adj[i].push_back({j+n,diff[i][j]});
            adj[j+n].push_back({i,diff[i][j]});
        }

    for(int i=1;i<=2*n;i++)colour[i]=-1;

    ok=1;

    dfs(1,0);

    return ok;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}