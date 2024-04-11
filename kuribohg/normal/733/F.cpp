#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,m,budget,anse,ansc;
LL mst,ans;
struct Edge
{
    int x,y,w,c,id,used;
    friend bool operator<(const Edge &p,const Edge &q)
    {
        return p.w<q.w;
    }
}E[MAXN];
int head[MAXN],to[MAXN<<1],next[MAXN<<1],id[MAXN<<1],w[MAXN<<1],cnt=1;
inline void adde(int f,int t,int ww,int no)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww,id[cnt]=no;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww,id[cnt]=no;
}
int fa[MAXN];
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
inline void uni(int i,int j)
{
    fa[find(i)]=find(j);
}
int Log[MAXN];
int anc[MAXN][20],f[MAXN][20],p[MAXN][20],dep[MAXN];
void DFS(int x)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=anc[x][0])
        {
            anc[to[i]][0]=x;
            f[to[i]][0]=w[i];
            p[to[i]][0]=id[i];
            dep[to[i]]=dep[x]+1;
            DFS(to[i]);
        }
}
int LCA(int p,int q)
{
    if(dep[p]<dep[q]) swap(p,q);
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) p=anc[p][i];
    for(int i=Log[n];i>=0;i--)
        if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
    if(p!=q) return anc[p][0];
    else return p;
}
void change(int i)
{
    int lca=LCA(E[i].x,E[i].y);
    int o=E[i].x,now=0;
    int d=dep[o]-dep[lca];
    for(int j=Log[d];j>=0;j--)
        if(d&(1<<j))
        {
            if(f[o][j]>E[now].w) now=p[o][j];
            o=anc[o][j];
        }
    o=E[i].y;
    d=dep[o]-dep[lca];
    for(int j=Log[d];j>=0;j--)
        if(d&(1<<j))
        {
            if(f[o][j]>E[now].w) now=p[o][j];
            o=anc[o][j];
        }
    if(now==0) return;
    if(mst-E[now].w+E[i].w-budget/E[i].c<ans)
        ans=mst-E[now].w+E[i].w-budget/E[i].c,anse=i,ansc=now;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&E[i].w);
    for(int i=1;i<=m;i++) scanf("%d",&E[i].c);
    for(int i=1;i<=m;i++) scanf("%d%d",&E[i].x,&E[i].y),E[i].id=i;
    scanf("%d",&budget);
    sort(E+1,E+m+1);
    int minc=1000000001;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
        if(find(E[i].x)!=find(E[i].y))
        {
            uni(E[i].x,E[i].y);
            adde(E[i].x,E[i].y,E[i].w,i);
            if(E[i].c<minc) minc=E[i].c,ansc=i;
            E[i].used=1;
            mst+=E[i].w;
        }
    ans=mst-budget/minc,anse=0;
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    DFS(1);
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
        {
            anc[j][i]=anc[anc[j][i-1]][i-1];
            if(f[j][i-1]<f[anc[j][i-1]][i-1]) p[j][i]=p[anc[j][i-1]][i-1],f[j][i]=f[anc[j][i-1]][i-1];
            else p[j][i]=p[j][i-1],f[j][i]=f[j][i-1];
        }
    for(int i=1;i<=m;i++)
    {
        if(E[i].used) continue;
        change(i);
    }
    printf("%I64d\n",ans);
    if(anse==0)
    {
        for(int i=1;i<=m;i++)
        {
            if(!E[i].used) continue;
            if(i==ansc) printf("%d %d\n",E[i].id,E[i].w-budget/E[i].c);
            else printf("%d %d\n",E[i].id,E[i].w);
        }
    }
    else
    {
        E[ansc].used=0;
        E[anse].used=1;
        for(int i=1;i<=m;i++)
        {
            if(!E[i].used) continue;
            if(i==anse) printf("%d %d\n",E[i].id,E[i].w-budget/E[i].c);
            else printf("%d %d\n",E[i].id,E[i].w);
        }
    }
    return 0;
}