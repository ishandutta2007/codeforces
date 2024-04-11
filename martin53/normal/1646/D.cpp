#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n;
vector<int> adj[nmax];

int depth[nmax];
int cnt[2];

void dfs(int node,int parent,int d)
{
    depth[node]=d;

    cnt[d%2]++;

    for(auto w:adj[node])
        if(w!=parent)
            dfs(w,node,d+1);
}

pair<int,int> dp[nmax][2];

pair<int,int> rec(int node,int parent,bool parent_colour)
{
    if(dp[node][parent_colour].first!=-1)return dp[node][parent_colour];

    if(parent_colour==1)
    {
        pair<int,int> ret={0,1};

        for(auto w:adj[node])
            if(w!=parent)
            {
                pair<int,int> cur=rec(w,node,0);

                ret.first+=cur.first;
                ret.second+=cur.second;
            }

        dp[node][parent_colour]=ret;
        return ret;
    }

    pair<int,int> ret=rec(node,parent,1);

    pair<int,int> score_use={1,adj[node].size()};

    for(auto w:adj[node])
        if(w!=parent)
        {
            pair<int,int> cur=rec(w,node,1);

            score_use.first+=cur.first;
            score_use.second+=cur.second;
        }

    if(ret.first<score_use.first)ret=score_use;
    else if(ret.first==score_use.first)ret=min(ret,score_use);

    dp[node][parent_colour]=ret;
    return ret;
}

int output[nmax];

void build(int node,int parent,bool parent_colour)
{
    if(parent_colour==1)
    {
        output[node]=1;

        for(auto w:adj[node])
            if(w!=parent)
            {
                build(w,node,0);
            }

        return;
    }

    if(rec(node,parent,0)==rec(node,parent,1))
    {
        build(node,parent,1);
        return;
    }

    output[node]=adj[node].size();

    for(auto w:adj[node])
        if(w!=parent)
        {
            build(w,node,1);
        }
}

int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n==2)
    {
        printf("2 2\n1 1\n");
        return 0;
    }

    pair<int,int> cur=rec(1,1,0);

    printf("%i %i\n",cur.first,cur.second);

    build(1,1,0);

    for(int i=1;i<=n;i++)
        printf("%i ",output[i]);

    printf("\n");

    return 0;
}