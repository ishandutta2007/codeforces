#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=1e9+7;

int n,inp[nmax];

long long dp[nmax];

vector<int> seen[nmax],adj[nmax];

int depth[nmax];

int mini[nmax],maxi[nmax];

void dfs(int node,int h)
{
    depth[node]=h;

    mini[depth[node]]=min(mini[depth[node]],inp[node]);
    maxi[depth[node]]=max(maxi[depth[node]],inp[node]);

    seen[h].push_back(node);
    for(auto w:adj[node])
        dfs(w,h+1);
}

long long maxi_sum_plus[nmax],maxi_sum_minus[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n+1;i++)
    {
        depth[i]=0;
        adj[i]={};
        seen[i]={};
    }

    for(int i=2;i<=n;i++)
    {
        int v;
        scanf("%i",&v);

        adj[v].push_back(i);
    }

    for(int i=2;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        mini[i]=1e9;
        maxi[i]=0;
    }

    dfs(1,1);

    for(int i=n+1;i>=1;i--)
    {
        for(auto u:seen[i])
        {
            dp[u]=0;

            for(auto v:adj[u])
            {
                dp[u]=max(dp[u],dp[v]+inp[v]-mini[i+1]);
                dp[u]=max(dp[u],dp[v]+maxi[i+1]-inp[v]);

                dp[u]=max(dp[u],maxi_sum_minus[i+1]-inp[v]);
                dp[u]=max(dp[u],maxi_sum_plus[i+1]+inp[v]);
            }
        }

        maxi_sum_plus[i]=-1e18;
        maxi_sum_minus[i]=-1e18;

        for(auto u:seen[i])
        {
            maxi_sum_plus[i]=max(maxi_sum_plus[i],dp[u]-inp[u]);
            maxi_sum_minus[i]=max(maxi_sum_minus[i],dp[u]+inp[u]);
        }
    }

    printf("%lld\n",dp[1]);
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