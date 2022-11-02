#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
struct Edge
{
	int x,y;
}	a[maxn];
int du[maxn];
struct Edge2
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;e[tot].next=g[x];g[x]=tot;
}
int n,m;
int que[maxn];
bool check(int t)
{
	tot=0;
	for (int i=1;i<=n;i++)	du[i]=0,g[i]=0;
	for (int i=1;i<=t;i++)
	{
		int x=a[i].x,y=a[i].y;
		addedge(x,y);
		du[y]++;
	}
	int r=0;
	for (int i=1;i<=n;i++)
	if (du[i]==0)	que[++r]=i;
	int l=1;
	int num=0;
	while (l<=r)
	{
		if (l<r)	return false;
		int u=que[l++];
		num++;
		for (int i=g[u];i;i=e[i].next)
		{
			du[e[i].v]--;
			if (du[e[i].v]==0)	que[++r]=e[i].v;
		}
	}
	return (num==n);
}
int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)	read(a[i].x),read(a[i].y);
	if (!check(m))
	{
		printf("-1\n");
		return 0;
	}
	int l=1,r=m;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid))	r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}