#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAXN=600010;
const LL INF=1000000000000000000LL;
struct Edge
{
    int x,y;
    LL w;
}E[MAXN];
int n,m,S;
int head[MAXN],to[MAXN],next[MAXN],w[MAXN],cnt=1;
inline void adde(int f,int t,int ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
bool used[MAXN];
LL dis[MAXN];
priority_queue<PLI,vector<PLI>,greater<PLI> > q;
void Dijkstra(int S)
{
    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[S]=0,q.push(make_pair(dis[S],S));
    while(!q.empty())
    {
        PLI tmp=q.top();q.pop();
        if(used[tmp.second]) continue;
        int x=tmp.second;
        used[x]=true;
        for(int i=head[x];i;i=next[i])
            if(dis[to[i]]>dis[x]+w[i])
            {
                dis[to[i]]=dis[x]+w[i];
                q.push(make_pair(dis[to[i]],to[i]));
            }
    }
}
LL inw[MAXN],ans;
int insub[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&E[i].x,&E[i].y,&E[i].w);
        if(E[i].x>E[i].y) swap(E[i].x,E[i].y);
        adde(E[i].x,E[i].y,E[i].w);
    }
    scanf("%d",&S);
    Dijkstra(S);
    for(int i=1;i<=n;i++) inw[i]=INF;
    for(int i=1;i<=m;i++)
    {
        if(dis[E[i].x]+E[i].w==dis[E[i].y])
        {
            if(E[i].w<inw[E[i].y])
                inw[E[i].y]=E[i].w,insub[E[i].y]=i;
        }
        else if(dis[E[i].y]+E[i].w==dis[E[i].x])
        {
            if(E[i].w<inw[E[i].x])
                inw[E[i].x]=E[i].w,insub[E[i].x]=i;
        }
    }
    for(int i=1;i<=n;i++)
        if(i!=S) ans+=inw[i];
    printf("%I64d\n",ans);
    for(int i=1;i<=n;i++)
        if(i!=S) printf("%d ",insub[i]);
    puts("");
    return 0;
}