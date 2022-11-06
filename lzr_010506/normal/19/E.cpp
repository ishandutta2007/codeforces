#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 300010
#define GET (ch>='0'&&ch<='9')
#define MAXINT 0x3f3f3f3f
#define is_root(x)  (tree[tree[x].fa].ch[0]!=x&&tree[tree[x].fa].ch[1]!=x)
using namespace std;
int n,m,T,Top,cnt;
int ans[MAXN<<1];
int sta[MAXN<<1],top;
int In[MAXN<<1],on[MAXN<<1];
struct splay
{
    int ch[2],fa,minn,st,sum,val;
    bool rev;
}tree[MAXN<<1];
inline void in(int &x)
{
    char ch=getchar();x=0;
    while (!GET)    ch=getchar();
    while (GET) x=x*10+ch-'0',ch=getchar();
}
struct edge {   int u,v,w;  }e[MAXN];
struct Edge
{
    int to;
    Edge *next;
}E[MAXN<<1],*prev1[MAXN],*prev2[MAXN];
void insert1(int u,int v)   {   E[++Top].to=v;E[Top].next=prev1[u];prev1[u]=&E[Top];    }
void insert2(int u,int v)   {   E[++Top].to=v;E[Top].next=prev2[u];prev2[u]=&E[Top];    }
void push_down(int x)
{
    if (tree[x].rev)
    {
        tree[tree[x].ch[0]].rev^=1,tree[tree[x].ch[1]].rev^=1;
        swap(tree[x].ch[0],tree[x].ch[1]);tree[x].rev^=1;
    }
}
void push_up(int x)
{
    tree[x].minn=tree[x].val;tree[x].st=x;tree[x].sum=x>n;
    if (tree[x].ch[0])
    {
        if (tree[tree[x].ch[0]].minn<tree[x].minn)  tree[x].minn=tree[tree[x].ch[0]].minn,tree[x].st=tree[tree[x].ch[0]].st;
        tree[x].sum+=tree[tree[x].ch[0]].sum;
    }
    if (tree[x].ch[1])
    {
        if (tree[tree[x].ch[1]].minn<tree[x].minn)  tree[x].minn=tree[tree[x].ch[1]].minn,tree[x].st=tree[tree[x].ch[1]].st;
        tree[x].sum+=tree[tree[x].ch[1]].sum;
    }
}
void rot(int x)
{
    int y=tree[x].fa,z=tree[y].fa,l,r;
    l=(tree[y].ch[1]==x);r=l^1;
    if (!is_root(y))    tree[z].ch[tree[z].ch[1]==y]=x;
    tree[tree[x].ch[r]].fa=y;tree[y].fa=x;tree[x].fa=z;
    tree[y].ch[l]=tree[x].ch[r];tree[x].ch[r]=y;
    push_up(y);push_up(x);
}
void Splay(int x)
{
    top=0;sta[++top]=x;
    for (int i=x;!is_root(i);i=tree[i].fa)  sta[++top]=tree[i].fa;
    while (top) push_down(sta[top--]);
    while (!is_root(x))
    {
        int y=tree[x].fa,z=tree[y].fa;
        if (!is_root(y))
        {
            if ((tree[y].ch[0]==x)^(tree[z].ch[0]==y))  rot(x);
            else    rot(y);
        }
        rot(x);
    }
}
void access(int x)  {   for (int i=0;x;i=x,x=tree[x].fa)    Splay(x),tree[x].ch[1]=i,push_up(x);    }
void make_root(int x)   {   access(x);Splay(x);tree[x].rev^=1;  }
void link(int x,int y)  {   make_root(x);tree[x].fa=y;  }
void cut(int x,int y)   {   make_root(x);access(y);Splay(y);tree[y].ch[0]=tree[x].fa=0;push_up(y);  }
void split(int x,int y) {   make_root(x);access(y);Splay(y);    }
int find_root(int x)    {   for (access(x),Splay(x);tree[x].ch[0];x=tree[x].ch[0]); return x;   }
void ins(int x)
{
    int u=e[x].u,v=e[x].v;
    if (u==v)   {   In[x]=1;cnt++;return;   }
    if (find_root(u)!=find_root(v)) on[x]=1,link(u,x+n),link(v,x+n);
    else
    {
        split(u,v);int y=tree[v].st-n;
        if (e[y].w<e[x].w)
        {
            if (tree[v].sum&1^1)    In[y]=1,cnt++;
            cut(e[y].u,y+n);cut(e[y].v,y+n);link(u,x+n);link(v,x+n);
            on[y]=0;on[x]=1;
        }
        else
        if (tree[v].sum&1^1)    In[x]=1,cnt++;
    }
}
void del(int x)
{
    if (on[x])  cut(e[x].u,x+n),cut(e[x].v,x+n);
    else    if (In[x])  cnt--;
}
int main()
{
    in(n);in(m);int s,t;
    for (int i=1;i<=n;i++)  tree[i].val=tree[i].minn=MAXINT,tree[i].st=i;
    for (int i=1;i<=m;i++)
    {
        in(e[i].u);in(e[i].v);
        s=0;t=i;e[i].w=t;
        insert1(s,i);insert2(t,i);
        tree[i+n].val=tree[i+n].minn=t;tree[i+n].st=i+n;tree[i+n].sum=1;

        e[i+m].u=e[i].u;e[i+m].v=e[i].v;
        s=i+1;t=m+2;e[i+m].w=t;
        insert1(s,i+m);insert2(t,i+m);
        tree[i+m+n].val=tree[i+m+n].minn=t;tree[i+m+n].st=i+m+n;tree[i+m+n].sum=1;
    }
    for (int x=0;x<=m+1;x++)
    {
        for (Edge *i=prev1[x];i;i=i->next)  ins(i->to);
        for (Edge *i=prev2[x];i;i=i->next)  del(i->to);
        if (!cnt)   {   for (Edge *i=prev2[x];i;i=i->next)  ans[++ans[0]]=i->to;    }
    }
    sort(ans+1,ans+ans[0]+1);printf("%d\n",ans[0]);
    for (int i=1;i<=ans[0];i++) printf(i==ans[0]?"%d\n":"%d ",ans[i]);
}