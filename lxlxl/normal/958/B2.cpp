#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct Node{
	int y,next;
}a[200010];int len=0,last[100010];
int Fa[100010],n,root=0,d[100010],f[100010],to[100010];
int deg[100010];
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=last[x];last[x]=len;
}
void find_root(int x,int fa)
{
	d[x]=d[fa]+1;
	if(!root||d[root]<d[x]) root=x;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		find_root(y,x);
	}
}
int ys[100010],z=0,la[100010],lef[100010];
int findfa(int x) {return Fa[x]==x?Fa[x]:Fa[x]=findfa(Fa[x]);}
struct node{
	int x,c,u;
	node() {}
	node(int a,int b,int _u) {x=a;c=b;u=_u;}
};
struct trnode{
	int lc,rc,num,u;
	node c;
}tr[200010];int tot=0;
node update(node lc,node rc) {return lc.c-lc.u>rc.c-rc.u?lc:rc;}
inline void write(int x)
{
    if (!x) return (void)puts("0");
    if (x < 0) putchar('-'), x = -x;
    static short s[12], t;
    while (x) s[++t] = x % 10, x /= 10;
    while (t) putchar('0' + s[t--]);
    putchar(' ');
}
void dfs(int x,int fa)
{
	ys[x]=la[x]=++z;Fa[x]=x;d[z]=d[ys[fa]]+1;f[x]=fa;
	to[z]=x;
	bool flag=true;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		dfs(y,x);la[x]=la[y];flag=false;
	}
	if(flag) lef[ys[x]]=1;
}
int bt(int l,int r)
{
	int x=++tot;
	if(l!=r)
	{
		int mid=(l+r)/2;
		tr[x].lc=bt(l,mid);
		tr[x].rc=bt(mid+1,r);
		tr[x].num=tr[tr[x].lc].num+tr[tr[x].rc].num;
		tr[x].c=update(tr[tr[x].lc].c,tr[tr[x].rc].c);
	}
	else if(lef[l]) tr[x].c.c=d[l],tr[x].c.x=l,tr[x].num=1;
	return x;
}
void pushdown(int x)
{
	int lc=tr[x].lc,rc=tr[x].rc,c=tr[x].u;
	if(tr[lc].num) tr[lc].c.u=max(tr[lc].c.u,c),tr[lc].u=max(tr[lc].u,c);
	if(tr[rc].num) tr[rc].c.u=max(tr[rc].c.u,c),tr[rc].u=max(tr[rc].u,c);
	//tr[x].u=0;
}
void change(int x,int l,int r,int fl,int fr,int c)
{
	if(tr[x].num==0) return;
	if(l==fl&&r==fr)
	{
		tr[x].u=max(tr[x].u,c);
		tr[x].c.u=max(tr[x].c.u,c);
		return;
	}
	int mid=(l+r)>>1;
	if(tr[x].u) pushdown(x);
	if(fr<=mid) change(tr[x].lc,l,mid,fl,fr,c);
	else if(fl>mid) change(tr[x].rc,mid+1,r,fl,fr,c);
	else change(tr[x].lc,l,mid,fl,mid,c),change(tr[x].rc,mid+1,r,mid+1,fr,c);
	tr[x].num=tr[tr[x].lc].num+tr[tr[x].rc].num;
	tr[x].c=update(tr[tr[x].lc].c,tr[tr[x].rc].c);
}
void del(int x,int l,int r,int k)
{
	if(l==r) {tr[x].c.c=tr[x].c.x=0;tr[x].num=0;return;}
	int mid=(l+r)/2;
	if(tr[x].u) pushdown(x);
	if(k<=mid) del(tr[x].lc,l,mid,k);
	else del(tr[x].rc,mid+1,r,k);
	tr[x].num=tr[tr[x].lc].num+tr[tr[x].rc].num;
	tr[x].c=update(tr[tr[x].lc].c,tr[tr[x].rc].c);
}
int tim=0,check[100010];
void solve(int x)
{
	int last=0;
	while(x!=root)
	{
		if(Fa[x]==x)
		{
			Fa[x]=0;
			if(!last) change(1,1,n,ys[x],la[x],d[ys[x]]);
			else
			{
				if(ys[x]<ys[last])change(1,1,n,ys[x],ys[last]-1,d[ys[x]]);
				if(la[last]<la[x])change(1,1,n,la[last]+1,la[x],d[ys[x]]);
			}
		}
		else break;
		last=x;x=f[x];
	}
}
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	{
		int x,y;x=read();y=read();
		ins(x,y);ins(y,x);
	}
	find_root(1,0);
	d[0]=-1;dfs(root,0);bt(1,n);
	write(1);int Ans=1; 
	for(int i=2;i<=n;i++)
	{
		node ans=tr[1].c;
		if(ans.x) Ans+=tr[1].c.c-tr[1].c.u;
		write(Ans);
		if(ans.x==0) continue;
		del(1,1,n,ans.x);
		solve(to[ans.x]);
	}
}