#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1111;
const int MAXM = 66666;
const int INF = 2e9+10;
int Dfn[MAXN],Low[MAXN];

struct Edge
{
    int to,next,w,id;
}edge[MAXM];
int head[MAXN];
bool cut[MAXM],vis[MAXN],isBridge[MAXM];
int s,t,n,m,cnt,tot;
vector<int> path,ans,opath;

void init()
{
    memset(head,-1,sizeof(head));
    tot = 1;
}

void addedge(int u, int v, int w, int id)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].id = id;
    edge[tot].next=  head[u];
    head[u] = tot++;
}

bool dfs(int u, int pre)
{
    if(u == t) return true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        int id = edge[i].id;
        if(vis[v] || cut[id] || id == pre) continue;
        vis[v] = true;
        if(dfs(v,id))
        {
            path.push_back(id);
            return true;
        }
    }
    return false;
}

bool findPath()
{
    memset(vis,false,sizeof(vis));
    path.clear();
    vis[s] = true;
    return dfs(s,0);
}

void Tarjan(int u, int pre)
{
    Dfn[u] = Low[u] = cnt++;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        int id = edge[i].id;
        if(cut[id]) continue;
        if(!Dfn[v])
        {
            Tarjan(v,id);
            Low[u] = min(Low[u],Low[v]);
            if(Dfn[u] < Low[v])
                isBridge[id] = true;

        }
        else if(id != pre)
            Low[u] = min(Low[u],Dfn[v]);
    }
}

void findBridge()
{
    memset(Dfn,0,sizeof(Dfn));
    memset(Low,0,sizeof(Low));
    memset(isBridge,false,sizeof(isBridge));
    cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(!Dfn[i])
            Tarjan(i,0);
}

void solve()
{
    memset(cut,false,sizeof(cut));
    int res = INF;
    ans.clear();
    //dfss-t
    if(!findPath())
    {
        puts("0\n0");
        return;
    }
    //
    findBridge();
    int nb;
    //s-ts-t
    for(int i = 0; i < path.size(); ++i)
    {
        nb = path[i];
        if(isBridge[nb] && edge[nb*2].w <= res)
        {
            ans.clear();
            ans.push_back(nb);
            res = edge[nb*2].w;
        }
    }
    opath.clear();
    opath.insert(opath.begin(),path.begin(),path.end());
    //
    //
    for(int i = 0; i < opath.size(); ++i)
    {
        nb = opath[i];
        cut[nb] = true;
        if(!findPath())
        {
            cut[nb] = false;
            continue;
        }

        findBridge();
        for(int j = 0; j < path.size(); ++j)
        {
            int onb = path[j];
            if(isBridge[onb] && (edge[onb*2].w + edge[nb*2].w) <= res)
            {
                ans.clear();
                ans.push_back(nb);
                ans.push_back(onb);
                res = edge[onb*2].w + edge[nb*2].w;
            }
        }
        cut[nb] = false;
    }
    //
    if(ans.size())
    {
        printf("%d\n%d\n",res,ans.size());
        for(int x : ans)
            printf("%d ",x);
    }
    else
        puts("-1");
}

int main()
{
    init();
    int u,v,w;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d %d %d",&u,&v,&w);
        addedge(u,v,w,i);
        addedge(v,u,w,i);
    }
    solve();
    return 0;
}