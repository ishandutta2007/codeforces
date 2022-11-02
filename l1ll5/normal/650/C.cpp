#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000010
#define ll long long
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int Mx(int a,int b)
{return a>b?a:b;}
struct zgz
{
    int val;
    int x,y;
}b[N];
int n,m,cnt=1;
int cmp(const zgz &a,const zgz &b)
{return a.val<b.val;}
int fa[N],r[N],l[N],R[N],L[N],c[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
void Union(int x,int y)
{if(find(x)!=find(y))fa[find(x)]=find(y);}
void solve()
{
    int i=1,k;
    for(int i=1;i<=n*m;i=k)
    {
        k=i;
        while(k<=n*m&&b[k].val==b[i].val)k++;
        for(int j=i;j<=k-1;j++)
        {
            int X=b[j].x,Y=b[j].y;
            if(!r[X])r[X]=(X-1)*m+Y;
            else Union(r[X],(X-1)*m+Y);
            if(!l[Y])l[Y]=(X-1)*m+Y;
            else Union(l[Y],(X-1)*m+Y);
        }
        for(int j=i;j<=k-1;j++)
        {
            int X=b[j].x,Y=b[j].y;
            c[find((X-1)*m+Y)]=Mx(c[find((X-1)*m+Y)],Mx(R[X],L[Y])+1);
        }
        for(int j=i;j<=k-1;j++)
        {
            int X=b[j].x,Y=b[j].y;
            c[(b[j].x-1)*m+Y]=c[find((X-1)*m+Y)],R[X]=c[find((X-1)*m+Y)],L[Y]=c[find((X-1)*m+Y)],r[X]=0,l[Y]=0;
        }
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b[cnt].x=i,b[cnt++].y=j,b[(i-1)*m+j].val=read();
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)fa[i]=i;
    solve();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)printf("%d ",c[(i-1)*m+j]);
        puts("");
    }
}