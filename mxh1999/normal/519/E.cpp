//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 100010
struct Edge
{
    int v,next;
}   e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
    tot++;
    e[tot].v=y;e[tot].next=g[x];g[x]=tot;
}

int fa[maxn],dep[maxn],size[maxn];
int p[maxn][20];
int n,m;

void dfs(int t)
{
    size[t]=1;
    dep[t]=dep[fa[t]]+1;
    p[t][0]=fa[t];
    int m=fa[t];
    for (int i=0;p[m][i]!=0;i++)
    {
        p[t][i+1]=p[m][i];
        m=p[m][i];
    }
    for (int i=g[t];i;i=e[i].next)
    if (e[i].v!=fa[t])
    {
        fa[e[i].v]=t;
        dfs(e[i].v);
        size[t]+=size[e[i].v];
    }
}
int lca(int x,int y)
{
    if (x==y) return x;
    if (dep[x]<dep[y])  swap(x,y);
    int m=dep[x]-dep[y];
    int k=0;
    while (m)
    {
        if (m&1)
            x=p[x][k];
        m>>=1;
        k++;
    }
    if (x==y) return x;
    k=0;
    while (x!=y)
    {
        if (p[x][k]!=p[y][k] || p[x][k]==p[y][k] && k==0)
        {
            x=p[x][k];
            y=p[y][k];
            k++;
        } else k--;
    }
    return x;
}
int grand(int x,int len)
{
    int m=0;
    while (len)
    {
        if (len&1)  x=p[x][m];
        len>>=1;
        m++;
    }
    return x;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(1);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==y)   {printf("%d\n",size[1]);continue;}
        if (dep[x]>dep[y])  swap(x,y);
        int tmp=lca(x,y);
        int len=dep[x]+dep[y]-2*dep[tmp];
        if (len%2==1)   {printf("0\n");continue;}
        len/=2;
        int xx=grand(y,len);
        if (xx==tmp)
        {
            int yy=grand(y,len-1);
            int zz=grand(x,len-1);
            printf("%d\n",size[1]-size[yy]-size[zz]);
        }   else
        {
            int yy=grand(y,len-1);
            printf("%d\n",size[xx]-size[yy]);
        }
    }
    return 0;
}