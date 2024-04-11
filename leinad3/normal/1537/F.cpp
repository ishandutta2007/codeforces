#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, i, j, a, b, m, t, A[200010], vis[200010], Par[200010], Dep[200010];
vector<int>adj[200010];
void dfs(int v, int par, int dep)
{
    Par[v]=par;Dep[v]=dep;
    for(int i=0;i<adj[v].size();i++)
    {
        int p=adj[v][i];
        if(vis[p]==0)
        {
            vis[p]=1;
            dfs(p, v, dep+1);
        }
    }
    if(par!=0)A[par]-=A[v],A[v]=0;
}
main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%lld %lld", &n, &m);
        for(i=0;i++<n;)adj[i].clear(),vis[i]=0;
        for(i=0;i++<n;)scanf("%lld", &A[i]);
        for(i=0;i++<n;)
        {
            scanf("%lld", &a);
            A[i]=a-A[i];
        }
        vector<pair<int, int> >v;
        for(i=0;i++<m;)
        {
            scanf("%lld %lld", &a, &b);v.push_back({a, b});
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vis[1]=1;
        dfs(1, 0, 1);
        if(A[1]%2)
        {
            puts("NO");
            continue;
        }
        if(A[1]==0)
        {
            puts("YES");
            continue;
        }
        for(i=0;i<v.size();i++)
        {
            a=v[i].first;b=v[i].second;
            if(Dep[a]>Dep[b])swap(a, b);
            if(Par[b]==a)continue;
            if(Dep[b]%2==Dep[a]%2)
            {
                puts("YES");
                goto w;
            }
        }
        puts("NO");
        w:;
    }
}