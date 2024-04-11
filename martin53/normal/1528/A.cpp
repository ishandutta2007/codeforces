#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

pair<int,int> inp[nmax];

long long dp[nmax][2];

vector<int> adj[nmax];

long long rec(int node,int par,int type)
{
    if(dp[node][type]!=-1)return dp[node][type];

    int me=(type==0?inp[node].first:inp[node].second);

    long long ret=0;

    for(auto w:adj[node])
        if(w!=par)
        {
            ret=ret+max(rec(w,node,0)+abs(me-inp[w].first),rec(w,node,1)+abs(me-inp[w].second));
        }

    dp[node][type]=ret;
    return ret;
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<n;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=-1;
        dp[i][1]=-1;
    }


    long long outp=max(rec(1,0,0),rec(1,0,1));

    printf("%lld\n",outp);
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