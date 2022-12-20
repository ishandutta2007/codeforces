#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n;

vector<int> adj[nmax];

int dp[nmax],SZ[nmax];

void rec(int node,int parent)
{
    SZ[node]=1;

    vector< pair<int,int> > seen={};

    for(auto w:adj[node])
        if(w!=parent)
        {
            rec(w,node);
            seen.push_back({dp[w],SZ[w]});
            SZ[node]+=SZ[w];
        }

    if(seen.size()==0)dp[node]=0;
    else if(seen.size()==1)dp[node]=seen[0].second-1;
    else dp[node]=max(seen[0].first+seen[1].second-1,seen[0].second+seen[1].first-1);
}

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        adj[i]={};
        dp[i]=0;
        SZ[i]=0;
    }

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rec(1,1);

    return dp[1];
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }


    return 0;
}