#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=4000010;
typedef long long LL;
struct Edge
{
    int f,t;
    LL w;
    Edge(){}
    Edge(int _f,int _t,LL _w):f(_f),t(_t),w(_w){}
    friend bool operator<(const Edge &p,const Edge &q)
    {
        return p.w<q.w;
    }
}E[MAXN];
int n,m,k,w,tot;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
char str[1010][20][20];
int fa[MAXN];
LL res;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline void uni(int i,int j){fa[find(i)]=find(j);}
void DFS(int x)
{
    if(x!=k+1)
    {
        printf("%d %d\n",x,(fa[x]==k+1)?0:fa[x]);
    }
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]) fa[to[i]]=x,DFS(to[i]);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int i=1;i<=k+1;i++) fa[i]=i;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
            scanf("%s",str[i][j]+1);
    }
    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++)
        {
            LL con=0;
            for(int p=1;p<=n;p++)
                for(int q=1;q<=m;q++)
                    if(str[i][p][q]!=str[j][p][q]) con++;
            E[++tot]=Edge(i,j,con*(LL)w);
        }
    for(int i=1;i<=k;i++) E[++tot]=Edge(k+1,i,n*m);
    sort(E+1,E+tot+1);
    for(int i=1;i<=tot;i++)
    {
        if(find(E[i].f)==find(E[i].t)) continue;
        res+=E[i].w;
        adde(E[i].f,E[i].t),uni(E[i].f,E[i].t);
    }
    fa[k+1]=0;
    printf("%I64d\n",res);
    DFS(k+1);
    return 0;
}