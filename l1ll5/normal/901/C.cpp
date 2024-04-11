#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
#define ll long long
using namespace std;
#define fstc __attribute__((optimize("-O3")))
#define IL __inline__ __attribute__((always_inline))
inline int Mn(int a,int b){return a<b?a:b;}
inline int Mx(int a,int b){return a>b?a:b;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define OUT 20000000
char Out[OUT],*ou=Out;
int Outn[30],Outcnt;
inline void write(ll x)
{
    if(!x)*ou++=48;
    else
    {
        for(Outcnt=0;x;x/=10)Outn[++Outcnt]=x%10+48;
        while(Outcnt)*ou++=Outn[Outcnt--];
    }
}
int n,m,q;
struct zgz
{
    int next,to;
}edge[N<<1];
int head[N],cnt=1;
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int nxt[N];
ll sum[N];
int fa[N],dep[N];
void solve(int x,int y)
{
    if(dep[x]<dep[y])return ;
    int mx=Mx(x,y),mn=Mn(x,y);
    while(x!=y)x=fa[x],mx=Mx(mx,x),mn=Mn(mn,x);
    nxt[mn]=Mn(nxt[mn],mx-1);
}
void dfs(int x,int f)
{
    fa[x]=f,dep[x]=dep[f]+1;
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==f)continue ;
        if(!dep[to])dfs(to,x);
        else solve(x,to);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        add(x,y),add(y,x);
    }
    for(int i=1;i<=n+1;i++)nxt[i]=n;
    for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
    for(int i=n;i;i--)nxt[i]=Mn(nxt[i+1],nxt[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+nxt[i]-i+1;
    q=read();
    while(q--)
    {
        int l=read(),r=read();
        int x=lower_bound(nxt+1,nxt+n+1,r)-nxt;
        x=Mx(x-1,l-1);
        write(sum[x]-sum[l-1]+1ll*(r-x)*(r-x+1)/2),*ou++='\n';
    }
    fwrite(Out,1,ou-Out,stdout);
}