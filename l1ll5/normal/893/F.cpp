#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
#define inf 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
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
int deep[N],tim[N],dfn,sz[N];
void dfs(int x,int fa)
{
    sz[x]=1;
    tim[x]=++dfn;
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa)continue ;
        deep[to]=deep[x]+1;
        dfs(to,x);
        sz[x]+=sz[to];
    }
}
ll ans;
int Testcase;
int n,c,q,D;
struct node
{
    int d[2],mn[2],mx[2],l,r;
    int val,v_mn;
    int& operator [](int x)
    {return d[x];}
    friend bool operator <(node a,node b)
    {return a[D]==b[D]?(a[D^1]<b[D^1]):(a[D]<b[D]);}
}tr[N],p[N],T;
int root,a[N];
void pushup(int x)
{
    node l=tr[tr[x].l],r=tr[tr[x].r];
    for(int i=0;i<2;i++)
    {
        if(tr[x].l)tr[x].mn[i]=min(tr[x].mn[i],l.mn[i]),tr[x].mx[i]=max(tr[x].mx[i],l.mx[i]);
        if(tr[x].r)tr[x].mn[i]=min(tr[x].mn[i],r.mn[i]),tr[x].mx[i]=max(tr[x].mx[i],r.mx[i]);
    }
    tr[x].v_mn=min(tr[x].val,min(l.v_mn,r.v_mn));
}
int build(int l,int r,int now)
{
    if(l>r)return 0;
    int mid=(l+r)>>1;
    D=now;
    nth_element(p+l,p+mid,p+r+1);
    tr[mid]=p[mid];
    tr[mid].v_mn=tr[mid].val;
    for(int i=0;i<2;i++)
    tr[mid].mn[i]=tr[mid].mx[i]=p[mid][i];
    tr[mid].l=build(l,mid-1,now^1);
    tr[mid].r=build(mid+1,r,now^1);
    pushup(mid);
    return mid;
}
bool sqr_inside(node x,node y)//y inside x
{
    for(int i=0;i<2;i++)
    if(!(x.mn[i]<=y.mn[i]&&y.mx[i]<=x.mx[i]))return 0;
    return 1;
}
bool outside(node x,node y)
{
    for(int i=0;i<2;i++)
    if(x.mn[i]>y.mx[i]||x.mx[i]<y.mn[i])return 1;
    return 0;
}
bool pt_inside(node x,node y)
{
    for(int i=0;i<2;i++)
    if(!(x.mn[i]<=y[i]&&y[i]<=x.mx[i]))return 0;
    return 1;
}
int ask(int x)
{
    if(!x)return inf;
    if(outside(T,tr[x]))return inf;
    if(sqr_inside(T,tr[x]))
    return tr[x].v_mn;
    int mn=inf;
    if(pt_inside(T,tr[x]))mn=tr[x].val;
    node l=tr[tr[x].l],r=tr[tr[x].r];
    if(l.v_mn<r.v_mn)
    {
        if(l.v_mn<mn)mn=min(mn,ask(tr[x].l));
        if(r.v_mn<mn)mn=min(mn,ask(tr[x].r));
    }
    else
    {
        if(r.v_mn<mn)mn=min(mn,ask(tr[x].r));
        if(l.v_mn<mn)mn=min(mn,ask(tr[x].l));
    }
    return mn;
}
int main()
{
    n=read();int tr_rt=read();
    tr[0].v_mn=inf;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=2;i<=n;i++)
    {
        int x=read(),y=read();
        add(x,y),add(y,x);
    }
    q=read();
    dfs(tr_rt,tr_rt);
    for(int i=1;i<=n;i++)p[i][0]=tim[i],p[i][1]=deep[i],p[i].val=a[i];
    root=build(1,n,0);
    int lastans=0;
    for(int i=1;i<=q;i++)
    {
        int a=read(),l=read();
        a=(a+lastans)%n+1,l=(l+lastans)%n;

        T.mn[0]=tim[a],T.mx[0]=tim[a]+sz[a]-1;
        T.mn[1]=deep[a],T.mx[1]=deep[a]+l;
        lastans=ask(root);
        printf("%d\n",lastans);
    }
}