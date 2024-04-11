//good luck
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

#define maxn 2000010
struct Edge
{
	int v,id,next;
}	e[maxn];
int g[maxn],tot;
void add(int x,int y,int id)
{
	e[++tot].v=y;e[tot].id=id;e[tot].next=g[x];g[x]=tot;
}
int fa[maxn],dep[maxn],num[maxn];
bool vis[maxn];
int god[maxn],bad[maxn];
int ngo,nba;
int mxh[maxn];//1=good 2=bad 3=tree
int n,m;
int mjy[maxn];

void dfs(int t)
{
	dep[t]=dep[fa[t]]+1;
	vis[t]=true;
	for (int i=g[t];i;i=e[i].next)
	if (!mxh[e[i].id])
	{
		if (dep[e[i].v]!=0 && dep[e[i].v]<dep[t])
		{
			if ((dep[t]-dep[e[i].v])&1)
			{
				mxh[e[i].id]=1;
				ngo++;
				god[t]++;
				god[e[i].v]--;
			}	else
			{
				mxh[e[i].id]=2;
				nba++;
				bad[t]++;
				bad[e[i].v]--;
			}
		}	else
		if (!vis[e[i].v])
		{
			mxh[e[i].id]=3;
			fa[e[i].v]=t;
			num[e[i].v]=e[i].id;
			dfs(e[i].v);
		}
	}
}
void dfs2(int t)
{
	vis[t]=true;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t] && !vis[e[i].v])
	{
		dfs2(e[i].v);
		god[t]+=god[e[i].v];
		bad[t]+=bad[e[i].v];
	}
}
int main()
{
	read(n),read(m);
	int meng=0;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		if (x==y)	meng++;else	add(x,y,i),add(y,x,i);
	}
	for (int i=1;i<=n;i++)
	if (!vis[i])	dfs(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	if (!vis[i])	dfs2(i);
	nba+=meng;
	if (nba==0)
	{
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
		{
			printf("%d",i);
			if (i!=m)	printf(" ");else printf("\n");
		}
		return 0;
	}
	int sum=0;
	if (nba==1)
	{
		for (int i=1;i<=m;i++)
		if (mxh[i]==2)	mjy[++sum]=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (god[i]==0 && bad[i]==nba)	mjy[++sum]=num[i];
	}
	sort(mjy+1,mjy+sum+1);
	printf("%d\n",sum);
	for (int i=1;i<=sum;i++)
	{
		printf("%d",mjy[i]);
		if (i==sum)	printf("\n");else printf(" ");
	}
	return 0;
}