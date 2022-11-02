#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
#define maxn 300010
int fa[maxn];
int n,m;
int size[maxn];
int seg[maxn<<2];
struct Edge
{
	int v,next;
}	e[maxn];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int dfn[maxn];
int pos[maxn];
int cnt;
void dfs(int t)
{
	cnt++;
	dfn[cnt]=t;
	pos[t]=cnt;
	size[t]=1;
	for (int i=g[t];i;i=e[i].next)
	{
		dfs(e[i].v);
		size[t]+=size[e[i].v];
	}
}
void build(int t,int l,int r)
{
	if (l==r)
	{
		seg[t]=size[dfn[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	seg[t]=max(seg[t<<1],seg[t<<1|1]);
}
int query(int t,int l,int r,int ql,int qr,int num)
{
	if (ql<=l && qr>=r)
	{
		if (seg[t]<num)	return 0;
		if (l==r)	return l;
		int mid=(l+r)>>1;
		if (seg[t<<1|1]>=num)	return query(t<<1|1,mid+1,r,mid+1,qr,num);
		return query(t<<1,l,mid,ql,mid,num);
	}
	int mid=(l+r)>>1;
	if (qr<=mid)	return query(t<<1,l,mid,ql,qr,num);
	if (ql>mid)	return query(t<<1|1,mid+1,r,ql,qr,num);
	return max(query(t<<1,l,mid,ql,mid,num),query(t<<1|1,mid+1,r,mid+1,qr,num));
}
int main()
{
	read(n),read(m);
	for (int i=2;i<=n;i++)
	{
		read(fa[i]);
		addedge(fa[i],i);
	}
	dfs(1);
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int x;
		read(x);
		int zxo=pos[x];
		int mjy=query(1,1,n,zxo,zxo+size[x]-1,(size[x]+1)/2);
		mjy=dfn[mjy];
		printf("%d\n",mjy);
	}
	return 0;
}