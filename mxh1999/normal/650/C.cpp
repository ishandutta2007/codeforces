//meng meng da mjy >w<
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

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

#define maxn 1000010
int n,m;
struct Point
{
	int x,y,num,pos;
}	b[maxn];
struct Edge
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;e[tot].v=y;e[tot].next=g[x];g[x]=tot;
}
int a[maxn];
int f[maxn];
int mjy[maxn];

bool cmp_x(Point a,Point b)
{
	if (a.x!=b.x)	return a.x<b.x;
	return a.num<b.num;
}
bool cmp_y(Point a,Point b)
{
	if (a.y!=b.y)	return a.y<b.y;
	return a.num<b.num;
}
bool cmp(Point a,Point b)
{
	return a.num<b.num;
}
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
inline void Union(int x,int y)
{
	x=fa(x),y=fa(y);
	f[x]=y;
}
int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int x;
			int pos=(i-1)*m+j;
			read(x);
			a[pos]=x;
			b[pos].x=i;
			b[pos].y=j;
			b[pos].pos=(i-1)*m+j;
			b[pos].num=a[pos];
		}
	sort(b+1,b+n*m+1,cmp_x);
	for (int i=1;i<=n*m;i++)	f[i]=i;
	for (int i=1;i<=n;i++)
	{
		int pre=(i-1)*m+1;
		for (int j=2;j<=m;j++)
		{
			int qqq=(i-1)*m+j;
			if (b[qqq].num==b[pre].num)	Union(b[qqq].pos,b[pre].pos);
			pre=qqq;
		}
	}
	sort(b+1,b+n*m+1,cmp_y);
	for (int j=1;j<=m;j++)
	{
		int pre=(j-1)*n+1;
		for (int i=2;i<=n;i++)
		{
			int qqq=(j-1)*n+i;
			if (b[qqq].num==b[pre].num)	Union(b[qqq].pos,b[pre].pos);
			pre=qqq;
		}
	}
	sort(b+1,b+n*m+1,cmp_x);
	for (int i=1;i<=n;i++)
	{
		int pre=(i-1)*m+1;
		for (int j=2;j<=m;j++)
		{
			int qqq=(i-1)*m+j;
			if (b[pre].num<b[qqq].num)	addedge(fa(b[qqq].pos),fa(b[pre].pos));
			pre=qqq;
		}
	}
	sort(b+1,b+n*m+1,cmp_y);
	for (int j=1;j<=m;j++)
	{
		int pre=(j-1)*n+1;
		for (int i=2;i<=n;i++)
		{
			int qqq=(j-1)*n+i;
			if (b[pre].num<b[qqq].num)	addedge(fa(b[qqq].pos),fa(b[pre].pos));
			pre=qqq;
		}
	}
	sort(b+1,b+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		int pos=b[i].pos;
		if (f[pos]!=pos)	continue;
		int mxh=0;
		for (int j=g[pos];j;j=e[j].next)	mxh=max(mxh,mjy[e[j].v]);
		mjy[pos]=mxh+1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int pos=(i-1)*m+j;
			printf("%d ",mjy[fa(pos)]);
		}
		printf("\n");
	}
	return 0;
}