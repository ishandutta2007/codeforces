#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct tree
{
	int l,r,minn,mpos;
}a[800004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].minn=1000000000;
	a[k].mpos=l;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
	if(a[k].l==a[k].r)
	{
		a[k].minn=y;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	if(a[k<<1].minn<a[k<<1|1].minn)
	{
		a[k].minn=a[k<<1].minn;
		a[k].mpos=a[k<<1].mpos;
	}
	else
	{
		a[k].minn=a[k<<1|1].minn;
		a[k].mpos=a[k<<1|1].mpos;
	}
	return;
}
struct bbian
{
	int u,v,w,nex;
}b[800004];
int head[200005],tmp;
void addb(int x,int y,int z)
{
	b[++tmp].u=x;
	b[tmp].v=y;
	b[tmp].w=z;
	b[tmp].nex=head[x];
	head[x]=tmp;
}
int dis[200001];
bool vis[300005];
int rd[300005];
int main()
{
	int n,m,s,x,y,z;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		z=0;
		addb(y,x,z);
		rd[x]++;
	}
	build(1,n,1);
	for(int i=1;i<=n;i++)dis[i]=1000000000;
	dis[n]=0;
	change(n,1,0);
	while(a[1].minn!=1000000000)
	{
		x=a[1].mpos;
		//printf("%d %d\n",x,dis[x]);
		change(x,1,1000000000);
		vis[x]=true;
		for(int i=head[x];i;i=b[i].nex)
		{
			if(vis[b[i].v])continue;
			rd[b[i].v]--;
			dis[b[i].v]=min(dis[b[i].v],dis[x]+rd[b[i].v]+1);
			change(b[i].v,1,dis[b[i].v]);
		}
	}
	printf("%d\n",dis[1]);
	//for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
	return 0;
}