#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long int
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define other(x,y) ((edg[x].u==y)?(edg[x].v):(edg[x].u))
#define pii pair<LL,int>

const int maxn=1005;
const int maxm=10005;
const LL inf=1e11+7;

struct edge
{
    int u,v;
    LL cost;
    bool f;
}edg[maxm];
priority_queue<pii,vector<pii>,greater<pii> >heap;
vector<int> g[maxn];
bool vis[maxn];
int side[maxn];
LL dis[maxn];
LL dist,tot;
int n,m;

void dij(int now,int en)
{
    if(now==en)return;
    vis[now]=true;
    for(unsigned int i=0;i<g[now].size();i++)
    {
        int p=g[now][i];
        int q=other(p,now);
        if(vis[q])continue;
        if(dis[q]>dis[now]+edg[p].cost)
        {
            dis[q]=dis[now]+edg[p].cost;
            heap.push(make_pair(dis[q],q));
            side[q]=p;
        }
    }
    while(!heap.empty() && vis[heap.top().second])heap.pop();
    if(heap.empty())return;
    dij(heap.top().second,en);
}

LL Dijkstra(int st,int en)
{
    while(!heap.empty())heap.pop();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)dis[i]=inf+100;
    dis[st]=0;
    dij(st,en);
    return dis[en];
}

void cl(int x)
{
    int temp=0;
    for(int i=1;i<=m;i++)
        if(edg[i].f)
        {
            temp++;
            if(temp<=x)edg[i].cost=1;
            else edg[i].cost=inf+1;
        }
}

int ff(int st,int en)
{
    int t=0;
    for(int i=1;i<=m;i++)if(edg[i].f)t++;
    int l,r,mid;
    l=1;r=t;
    while(r-l>1)
    {
        mid=(l+r)>>1;
        cl(mid);
        LL tot=Dijkstra(st,en);
        if(tot<=dist)r=mid;else l=mid;
    }
    cl(l);
    tot=Dijkstra(st,en);
    if(tot>dist)
    {
        cl(l+1);
        return l+1;
    }else return l;
}

void find(int t,int st,int en)
{
    LL l,r,mid,tot;
    l=1,r=dist;
    while(r-l>1)
    {
        mid=(l+r)>>1;
        edg[t].cost=mid;
        tot=Dijkstra(st,en);
        if(tot==dist)return;
        if(tot>dist)r=mid;else l=mid;
    }
    edg[t].cost=l;
    tot=Dijkstra(st,en);
    if(tot<dist)edg[t].cost=l+1;
}

int main()
{
    int i,j,k,st,en;
    scanf("%d%d%I64d%d%d",&n,&m,&dist,&st,&en);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&edg[i].u,&edg[i].v,&edg[i].cost);
        if(edg[i].cost==0)
        {
            edg[i].f=true;
            edg[i].cost=inf+1;
        }else edg[i].f=false;
        g[edg[i].u].push_back(i);
        g[edg[i].v].push_back(i);
    }
    tot=Dijkstra(st,en);
    if(tot<dist)
    {
        printf("NO");
        return 0;
    }
    if(tot==dist)
    {
        printf("YES\n");
        for(i=1;i<=m;i++)printf("%d %d %I64d\n",edg[i].u,edg[i].v,edg[i].cost);
        return 0;
    }
    for(i=1;i<=m;i++)if(edg[i].f)edg[i].cost=1;
    tot=Dijkstra(st,en);
    if(tot>dist)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    int u=ff(st,en);j=0;
    for(i=1;i<=m;i++)
    {
        if(!edg[i].f)continue;
        j++;
        if(j==u){k=i;break;}
    }
    LL p1=min(dis[edg[k].u],dis[edg[k].v]);
    tot=Dijkstra(en,st);
    LL p2=min(dis[edg[k].u],dis[edg[k].v]);
    edg[k].cost=dist-p1-p2;
    for(i=1;i<=m;i++)printf("%d %d %I64d\n",edg[i].u,edg[i].v,edg[i].cost);
    return 0;
}