#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int to,val,rev;
};
int n,m,w[222222],x,y,dfn[222222],low[222222],s,cnt,cc,col[222222],sz[222222],sub[222222];
long long ff[222222],dp0[222222],dp1[222222];
vector<edge> g[222222];
vector<int> ng[222222];
bool used[222222];
map<pair<int,int>,int> mp;
void dfs(int i,int fa)
{
    dfn[i]=++cnt;low[i]=dfn[i];
    for (int j=0;j<g[i].size();j++)
    {
        int to=g[i][j].to;
        if (to==fa) continue;
        if (!dfn[to])
        {
            dfs(to,i);
            if (low[to]>dfn[i]) 
            {
                g[i][j].val=g[to][g[i][j].rev].val=1;
            }
            low[i]=min(low[i],low[to]);
        }
        else low[i]=min(low[i],dfn[to]);
    }
}
void dft(int i)
{
    used[i]=1;col[i]=cc;sz[cc]++;
    for (int j=0;j<g[i].size();j++)
    {
        int to=g[i][j].to,val=g[i][j].val;
        if (val || used[to]) continue;
        dft(to);
    }
}
void treedp(int i,int fa)
{
    dp0[i]=dp1[i]=ff[i];sub[i]=sz[i];
    long long gg=ff[i];bool ft=0;
    for (int j=0;j<ng[i].size();j++)
    {
        int to=ng[i][j];
        if (to==fa) continue;
        treedp(to,i);
        if (sub[to]>1 && dp0[to]>=0) dp0[i]+=dp0[to];
        if (sub[to]>1 && dp0[to]>=0) gg+=dp0[to];
        if (sub[to]>1 && dp0[to]>=0) ft=1; 
        sub[i]+=sub[to];
    }
    if (sz[i]==1 && !ft) dp0[i]=-1e9;
    dp1[i]=gg;
    for (int j=0;j<ng[i].size();j++)
    {
        int to=ng[i][j];
        if (to==fa) continue;
        if (sub[to]>1 && dp0[to]>=0) dp1[i]=max(dp1[i],gg-dp0[to]+dp1[to]);
        else dp1[i]=max(dp1[i],gg+dp1[to]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back((edge){y,0,(int)g[y].size()});
        g[y].push_back((edge){x,0,(int)g[x].size()-1});
    }
    scanf("%d",&s);
    dfs(s,0);
    for (int i=1;i<=n;i++)
    {
        if (!used[i]) 
        {
            ++cc;
            dft(i);
        }
    }
    for (int i=1;i<=n;i++) ff[col[i]]+=w[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<g[i].size();j++)
        {
            int to=g[i][j].to,val=g[i][j].val;
            if (val && mp.find(make_pair(col[i],col[to]))==mp.end())
            {
                ng[col[i]].push_back(col[to]);
                ng[col[to]].push_back(col[i]);
                mp[make_pair(col[i],col[to])]=mp[make_pair(col[to],col[i])]=1;
            }
        }
    }
    treedp(col[s],0);
    printf("%lld\n",dp1[col[s]]);
    return 0;
}