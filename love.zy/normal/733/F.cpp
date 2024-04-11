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
  
const int maxn=200005;
const int maxm=200005;

struct edge
{
    int u,v,pos;
    LL disa,cost;
    edge(int u=0,int v=0,int pos=0,LL disa=0,LL cost=0):u(u),v(v),pos(pos),disa(disa),cost(cost){}
    bool operator < (const struct edge p)const
    {return disa<p.disa;}
}edg[maxn];

struct tree
{
    int fat,dep;
    vector<int> son;
}tr[maxn];

int i,j,k,l,m,n,bj,maxd,ans1,wow;
LL sum,tot,sum1;
int ans[maxn];
int a[maxn];
bool b[maxm];
bool ff=false;

LL dou[maxn][20];
int fat[maxn][20];
vector<int> g[maxn];

int find(int x)
{
    if(a[x]==x)return x;
    else return a[x]=find(a[x]);
}

inline int other(int now,int num)
{
    if(num==0)return 0;
    if(edg[num].u==now)return edg[num].v;else return edg[num].u;
}

void dfs(int now)
{
    if(a[now]>0)return;
    a[now]=1;
    tr[now].dep=tr[other(now,tr[now].fat)].dep+1;
    maxd=max(tr[now].dep,maxd);
    for(unsigned int i=0;i<g[now].size();i++)
    {
        int v=other(now,g[now][i]);
        if(a[v]>0)continue;
        tr[now].son.push_back(g[now][i]);
        tr[v].fat=g[now][i];
    }
    for(unsigned int i=0;i<tr[now].son.size();i++)
        dfs(other(now,tr[now].son[i]));
}

void mkd()
{
    for(int i=1;i<=n;i++)dou[i][0]=edg[tr[i].fat].disa,fat[i][0]=other(i,tr[i].fat);
    for(int step=1;(1<<(step))<=maxd;step++)
        for(int i=1;i<=n;i++)
        {
            dou[i][step]=max(dou[i][step-1],dou[fat[i][step-1]][step-1]);
            fat[i][step]=fat[fat[i][step-1]][step-1];
        }
}

LL search(int x,int y)
{
    if(tr[x].dep<tr[y].dep)
    {int o=x;x=y;y=o;}
    LL ma=0;int t;
    if(tr[x].dep>tr[y].dep)
    {
        while(tr[x].dep>tr[y].dep)
        {
            t=0;
            while(tr[fat[x][t]].dep>tr[y].dep)t++;
            if(tr[fat[x][t]].dep==tr[y].dep)
            {
                ma=max(ma,dou[x][t]);
                x=fat[x][t];
                break;
            }
            t--;
            ma=max(ma,dou[x][t]);
            x=fat[x][t];
        }
    }
    while(x!=y)
    {
        t=0;
        while(fat[x][t]!=fat[y][t])t++;
        if(t==0)
        {
            ma=max(ma,dou[x][t]);
            ma=max(ma,dou[y][t]);
            break;
        }
        t--;
        ma=max(ma,dou[x][t]);
        ma=max(ma,dou[y][t]);
        x=fat[x][t];
        y=fat[y][t];
    }
    if(x==y)wow=x;else wow=fat[x][0];
    return ma;
}

int main()
{
    scan2(n,m);
    for(i=1;i<=m;i++)scanf("%lld",&edg[i].disa);
    for(i=1;i<=m;i++)scanf("%lld",&edg[i].cost);
    for(i=1;i<=m;i++)
    {
        scan2(j,k);
        edg[i]=edge(min(j,k),max(j,k),i,edg[i].disa,edg[i].cost);
    }
    scanf("%lld",&tot);
    sort(edg+1,edg+m+1);
    memset(b,0,sizeof(b));
    for(i=1;i<=n;i++)a[i]=i;
    l=1;sum=0;
    for(i=1;i<=m;i++)
    {
        if(l>=n)break;
        j=find(edg[i].u);
        k=find(edg[i].v);
        if(j==k || a[j]==a[k])continue;
        sum+=edg[i].disa;
        a[k]=a[j];l++;
        g[edg[i].u].push_back(i);
        g[edg[i].v].push_back(i);
        ans[++ans1]=i;
        b[i]=true;
    }
    sum1=sum;bj=0;maxd=0;
    for(int t=1;t<=ans1;t++)
    {
        if(sum1-tot/edg[ans[t]].cost<sum){sum=sum1-tot/edg[ans[t]].cost;bj=ans[t];}
    }
    memset(a,0,sizeof(a));
    tr[1].fat=0;tr[0].dep=0;dfs(1);
    mkd();bool f=false;
    for(i=1;i<=m;i++)
    {
        if(b[i])continue;
        LL temp=edg[i].disa-tot/edg[i].cost;
        LL fuck=search(edg[i].u,edg[i].v);
        //if(n==50 && edg[i].disa==683)printf("%lld\n",fuck);
        if(sum1-fuck+temp<sum){f=true;sum=sum1-fuck+temp;l=i;}
    }
    if(!f)
    {
        printf("%lld\n",sum);
        for(i=1;i<=ans1;i++)
        {
            edge e=edg[ans[i]];
            if(bj==ans[i])
            {
                printf("%d %lld\n",e.pos,e.disa-tot/e.cost);
            }else
            {
                printf("%d %lld\n",e.pos,e.disa);
            }
        }
        return 0;
    }
    search(edg[l].u,edg[l].v);
    LL mm=0;int bbb;
    int x=edg[l].u,y=edg[l].v;
    while(x!=wow)
    {
        if(edg[tr[x].fat].disa>mm){mm=edg[tr[x].fat].disa;bbb=tr[x].fat;}
        x=fat[x][0];
    }
    while(y!=wow)
    {
        if(edg[tr[y].fat].disa>mm){mm=edg[tr[y].fat].disa;bbb=tr[y].fat;}
        y=fat[y][0];
    }
    for(i=1;i<=ans1;i++)if(ans[i]==bbb)ans[i]=l;
    printf("%lld\n",sum);
    for(i=1;i<=ans1;i++)
    {
        edge e=edg[ans[i]];
        if(l==ans[i])
        {
            printf("%d %lld\n",e.pos,e.disa-tot/e.cost);
        }else
        {
            printf("%d %lld\n",e.pos,e.disa);
        }
    }
    return 0;
}