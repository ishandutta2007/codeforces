#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
#define maxn 100010
int f[maxn];
int n,m;
struct Store
{
	int x,y,pos;
	int w;
}	st[maxn];
bool cmp(Store a,Store b)
{
	return a.w>b.w;
}
struct Edge
{
	int v,id,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,int id)
{
	tot++;
	e[tot].v=y;
	e[tot].id=id;
	e[tot].next=g[x];
	g[x]=tot;
}
struct Ques
{
	int x,y,z,pos;
}	ques[maxn];
bool cmp2(Ques a,Ques b)
{
	return a.z>b.z;
}
int mjy[maxn];
int size[maxn],son[maxn],dep[maxn];
int top[maxn],fa[maxn],pos[maxn];
int cnt;
void dfs(int t)
{
	size[t]=1;
	dep[t]=dep[fa[t]]+1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		st[e[i].id].pos=e[i].v;
		fa[e[i].v]=t;
		dfs(e[i].v);
		size[t]+=size[e[i].v];
		if (size[e[i].v]>size[son[t]])	son[t]=e[i].v;
	}
}
void dfs2(int t)
{
	pos[t]=++cnt;
	if (son[t])
	{
		top[son[t]]=top[t];
		dfs2(son[t]);
	}	else return;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t] && e[i].v!=son[t])
	{
		top[e[i].v]=e[i].v;
		dfs2(e[i].v);
	}
}
struct Seg
{
	int l,r;
	bool is;
	int all;
	void clear()
	{
		l=r=is=all=0;
	}
}	seg[maxn<<2];
Seg operator*(Seg a,Seg b)
{
	Seg c;
	if (a.is && b.is)
	{
		c.is=true;c.l=a.l+b.l;c.r=a.r+b.r;c.all=f[c.l];
	}	else
	if (a.is && !b.is)
	{
		c.is=false,c.l=b.l+a.l,c.r=b.r,c.all=b.all-f[b.l]+f[b.l+a.l];
	}	else
	if (!a.is && b.is)
	{
		c.is=false,c.l=a.l,c.r=b.r+a.r,c.all=a.all-f[a.r]+f[a.r+b.r];
	}	else
	{
		c.is=false;c.l=a.l;c.r=b.r;c.all=a.all+b.all-f[a.r]-f[b.l]+f[a.r+b.l];
	}
	return c;
}
void insert(int t,int l,int r,int pos)
{
	if (l==r)
	{
		seg[t].l=seg[t].r=1;
		seg[t].all=f[1];
		seg[t].is=true;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid)	insert(t<<1,l,mid,pos);else insert(t<<1|1,mid+1,r,pos);
	seg[t]=seg[t<<1]*seg[t<<1|1];
}
Seg query(int t,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)	return seg[t];
	int mid=(l+r)>>1;
	if (qr<=mid)	return query(t<<1,l,mid,ql,qr);
	if (ql>mid)	return query(t<<1|1,mid+1,r,ql,qr);
	return query(t<<1,l,mid,ql,mid)*query(t<<1|1,mid+1,r,mid+1,qr);
}
int ask(int x,int y)
{
	Seg zxo1,zxo2;
	zxo1.clear(),zxo2.clear();
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]])	swap(x,y),swap(zxo1,zxo2);
		zxo1=query(1,1,n,pos[top[x]],pos[x])*zxo1;
		x=fa[top[x]];
	}
	if (dep[x]<dep[y])	swap(x,y),swap(zxo1,zxo2);
	if (x!=y)	zxo1=query(1,1,n,pos[y]+1,pos[x])*zxo1;
	swap(zxo1.l,zxo1.r);
	zxo1=zxo1*zxo2;
	return zxo1.all;
}
int main()
{
	read(n),read(m);
	for (int i=1;i<n;i++)	read(f[i]);
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		st[i].x=x,st[i].y=y;st[i].w=z;
		addedge(x,y,i);
		addedge(y,x,i);
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		ques[i].x=x;ques[i].y=y;ques[i].z=z;ques[i].pos=i;
	}
	dfs(1);
	top[1]=1;
	dfs2(1);
	for (int i=1;i<n;i++)	st[i].pos=pos[st[i].pos];
	sort(st+1,st+n,cmp);
	sort(ques+1,ques+m+1,cmp2);
	int now=1;
	for (int i=1;i<=m;i++)
	{
		while (now<n && st[now].w>=ques[i].z)	insert(1,1,n,st[now].pos),now++;
		mjy[ques[i].pos]=ask(ques[i].x,ques[i].y);
	}
	for (int i=1;i<=m;i++)	printf("%d\n",mjy[i]);
	return 0;
}