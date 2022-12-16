#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int nmax=5e4+42;

int n,q;

vector<int> adj[nmax];

int in[nmax],out[nmax];

int t;
int depth[nmax];
int order[nmax];
int grow[nmax];
int lst[nmax];

int help_grow[nmax],help_depth[nmax];

void dfs(int node,int par,int h)
{
    t++;
    in[node]=t;
    depth[node]=h;
    order[t]=node;

    for(auto k:adj[node])
        if(k!=par)dfs(k,node,h+1);

    out[node]=t;
}
int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)scanf("%i",&grow[i]);

    for(int i=2;i<=n;i++)
    {
        int u,v=i;

        scanf("%i",&u);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    for(int i=1;i<=n;i++)
    {
        help_grow[i]=grow[order[i]];
        help_depth[i]=depth[order[i]];
    }

    for(int i=1;i<=q;i++)
    {
        int cur;
        scanf("%i",&cur);

        int cnt=0,sum=0;

        for(int j=in[cur];j<=out[cur];j++)
            if(lst[j]<=i)
            {
                cnt++;
                sum+=help_depth[j];

                lst[j]=i+help_grow[j];
            }

        sum=sum-cnt*depth[cur];

        printf("%i %i\n",sum,cnt);
    }
    return 0;
}