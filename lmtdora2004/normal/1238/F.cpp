#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[300005];
vector<int> child[300005];
int f[300005];
int quay[300005], quaylen[300005];
int ans;

void dfs(int node, int fa)
{
    for(auto i:adj[node])
    {
        if(i==fa) continue;
        dfs(i, node);
        child[node].push_back(i);
    }
}

void solve(int node)
{
    quay[node]++;
    int okfine=0;
    for(auto i:child[node])
    {
        solve(i);
        okfine=max(okfine, quay[i]);
    }
    // if(node==2) cout<<okfine<<" bug"<<endl;
    quay[node]+=max((int)child[node].size()-1, 0)+okfine;
}

void solve1(int node)
{
    vector<int> check={};
    if(node!=1) check.push_back(quaylen[node]);
    for(auto i:child[node])
    {
        check.push_back(quay[i]);
    }
    sort(check.begin(), check.end());
    if(check.size()>2)
    {
        ans=max(ans, check[check.size()-1]+check[check.size()-2]-2+(int)check.size()+1);
    }
    else
    {
        ans=max(ans, check[0]+1);
    }
    // cout<<node<<" "<<ans<<endl;
    int take=0, val=0;
    for(auto i:child[node])
    {
        if(quay[i]-1>take)
        {
            take=quay[i]-1;
            val=i;
        }
    }
    if(quaylen[node]-1>take)
    {
        take=quaylen[node]-1;
        val=n+1;
    }
    for(auto i:child[node])
    {
        if(i!=val)
        {
            quaylen[i]=check.size()+take;
        }
    }
    take=0;
    int val1=0;
    for(auto i:child[node])
    {
        if(quay[i]-1>take&&i!=val)
        {
            take=quay[i]-1;
            val1=i;
        }
    }
    quaylen[val]=max(quaylen[val], (int)check.size()+take);
    for(auto i:child[node])
    {
        solve1(i);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        ans=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            quay[i]=0;
            quaylen[i]=0;
            adj[i].clear();
            child[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 1);
        solve(1);
        solve1(1);
        cout<<ans<<endl;
    }
}