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
  
#define LL long long
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

//fuck you tutorial

const int maxn=200005;

struct edge
{
    int v1,v2;
    LL p,w;
}edg[maxn];
struct nex
{
    int to,label;
    nex(int to=0,int label=0):to(to),label(label){};
};
vector<nex>son[maxn],g[maxn];
bool vis[maxn];
LL aw[maxn],ap[maxn],as[maxn];
int n;

void findson(int now)
{
    vis[now]=true;
    for(unsigned int i=0;i<g[now].size();i++)
    {
        int v=g[now][i].to;
        if(vis[v])continue;
        son[now].push_back(g[now][i]);
    }
    for(unsigned int i=0;i<son[now].size();i++)
        findson(son[now][i].to);
}

void cal(int now)
{
    if(son[now].size()==0)return;
    for(unsigned int i=0;i<son[now].size();i++)cal(son[now][i].to);
    for(unsigned int i=0;i<son[now].size();i++)
    {
        struct nex v=son[now][i];
        int id=v.label;
        ap[id]=as[v.to];
        aw[id]=edg[id].w+(ap[id]-edg[id].p);
        if(aw[id]<=0)
        {
            ap[id]+=1-aw[id];
            aw[id]=1;
        }
        if(ap[id]>edg[id].p){printf("-1");exit(0);}
        as[now]+=as[v.to]+aw[id];
    }
}

LL solve(int now,LL need)
{
    LL sum=0;
    for(unsigned int i=0;i<son[now].size();i++)
    {
        struct nex v=son[now][i];
        int id=v.label;
        if(need<=edg[id].p-ap[id])
        {
            ap[id]+=need;
            aw[id]+=need;
            sum+=need;
            need=0;
        }else
        {
            need-=(edg[id].p-ap[id]);
            aw[id]+=(edg[id].p-ap[id]);
            sum+=(edg[id].p-ap[id]);
            ap[id]=edg[id].p;
        }
        LL tmp=0;
        tmp=solve(v.to,min(need,ap[id]-as[v.to]));
        need-=tmp;
        sum+=tmp;
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%lld%lld",&edg[i].w,&edg[i].p);
        edg[i].v1=x;edg[i].v2=y;
        g[x].push_back(nex(y,i));
        g[y].push_back(nex(x,i));
    }
    memset(vis,0,sizeof(vis));
    findson(1);
    cal(1);solve(1,1e18);
    printf("%d\n",n);
    for(int i=1;i<=n-1;i++)
        printf("%d %d %lld %lld\n",edg[i].v1,edg[i].v2,aw[i],ap[i]);
    return 0;
}