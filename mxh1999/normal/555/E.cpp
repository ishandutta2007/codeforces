#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define maxn 200010
string a[maxn];
int n,m,q;
struct Edge
{
	int v,id,next;
}	e[maxn<<1];
pair<int,int> st[maxn];
int g[maxn],tot;
void addedge(int x,int y,int id)
{
	tot++;
	e[tot].v=y;
	e[tot].id=id;
	e[tot].next=g[x];
	g[x]=tot;
}
int fa[maxn];
int f[maxn];
bool vis[maxn];
void fail()
{
	printf("No\n");
	exit(0);
}
int find(int t)
{
	if (f[t]==t)	return t;
	return f[t]=find(f[t]);
}
void Union(int x,int y)
{
	x=find(x),y=find(y);
	f[x]=y;
}
bool used[maxn];
void dfs(int t,int pre)
{
	vis[t]=true;
	for (int i=g[t];i;i=e[i].next)
	if (!used[e[i].id])
	{
		used[e[i].id]=true;
		if (vis[e[i].v])
		{
			while (find(t)!=find(e[i].v))
			{
				int now=find(fa[find(t)]);
				Union(t,now);
			}
		}	else
		{
			fa[e[i].v]=t;
			dfs(e[i].v,e[i].id);
		}
	}
}
int son[maxn],size[maxn],dep[maxn];
int pos[maxn],cnt,top[maxn];
vector<int>	root;
int color[maxn];
struct Seg
{
	int tag;
	bool num[3];
}	seg[maxn<<2];
void _dfs(int t,int col)
{
	size[t]=1;
	dep[t]=dep[fa[t]]+1;
	color[t]=col;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		fa[e[i].v]=t;
		_dfs(e[i].v,col);
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
void update(int t)
{
	for (int _=1;_<=2;_++)	seg[t].num[_]=seg[t<<1].num[_]|seg[t<<1|1].num[_];
}
void insert(int t,int l,int r,int ql,int qr,int val)
{
	if (seg[t].tag)
	{
		if (seg[t].tag!=val)	fail();
		return;
	}
	if (l==ql && r==qr)
	{
		if (val==1 && seg[t].num[2])	fail();
		if (val==2 && seg[t].num[1])	fail();
		seg[t].tag=val;
		seg[t].num[val]=true;
		return;
	}
	int mid=(l+r)>>1;
	if (qr<=mid)	insert(t<<1,l,mid,ql,qr,val);else
	if (ql>mid)	insert(t<<1|1,mid+1,r,ql,qr,val);else
	insert(t<<1,l,mid,ql,mid,val),insert(t<<1|1,mid+1,r,mid+1,qr,val);
	update(t);
}
void change(int x,int y)
{
	pair<int,int>	ha1=mp(x,1),ha2=mp(y,2);
	while (top[ha1.fi]!=top[ha2.fi])
	{
		if (dep[top[ha1.fi]]<dep[top[ha2.fi]])	swap(ha1,ha2);
		insert(1,1,n,pos[top[ha1.fi]],pos[ha1.fi],ha1.se);
		ha1.fi=fa[top[ha1.fi]];
	}
	if (dep[ha1.fi]<dep[ha2.fi])	swap(ha1,ha2);
	if (ha1.fi!=ha2.fi)	insert(1,1,n,pos[ha2.fi]+1,pos[ha1.fi],ha1.se);
}
int main()
{
	read(n),read(m),read(q);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		st[i].fi=x;
		st[i].se=y;
		addedge(x,y,i);
		addedge(y,x,i);
	}
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=n;i++)
	if (!vis[i])	root.pb(i),dfs(i,0);
	tot=0;
	memset(g,0,sizeof(g));
	memset(fa,0,sizeof(fa));
	for (int i=1;i<=m;i++)
	{
		st[i].fi=find(st[i].fi),st[i].se=find(st[i].se);
		if (st[i].fi>st[i].se)	swap(st[i].fi,st[i].se);
	}
	sort(st+1,st+m+1);
	m=unique(st+1,st+m+1)-(st+1);
	for (int i=1;i<=m;i++)
	if (st[i].fi!=st[i].se)
	{
		addedge(st[i].fi,st[i].se,i);
		addedge(st[i].se,st[i].fi,i);
	}
	for (int i=0;i<root.size();i++)	_dfs(find(root[i]),i+1);
	top[1]=1;
	for (int i=0;i<root.size();i++)	dfs2(find(root[i]));
	for (int i=1;i<=q;i++)
	{
		int x,y;
		read(x),read(y);
		x=find(x),y=find(y);
		if (x==y)	continue;
		if (color[x]!=color[y])	fail();
		change(x,y);
	}
	printf("Yes\n");
	return 0;
}