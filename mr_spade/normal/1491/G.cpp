#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using std::swap;
using std::vector;
const int N=2e5+5;
int n,m;
int dis[N],c[N];
int suc[N],pre[N];
int cnt;
int ans[N][2];
vector<int> V;
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y)
{
	if((x=find(x))==(y=find(y)))
		return;
	dis[x]=y;m--;
	return;
}
inline void Mr_swap(int x,int y)
{
	if(x==y)
		return;
	ans[++cnt][0]=x;ans[cnt][1]=y;
	pre[suc[x]]=y;pre[suc[y]]=x;
	swap(suc[x],suc[y]);
	swap(c[x],c[y]);
	c[x]^=1;c[y]^=1;
	return;
}
inline void solve(int x)
{
	int sum=1,y,b1=0,b2=0;
	if(c[x])
		b1=x;
	for(y=suc[x];y!=x;y=suc[y])
	{
		sum++;
		if(c[y])
		{
			if(b1&&b2)
				exit(998244353);
			if(b1)
				b2=y;
			else
				b1=y;
		}
	}
	if(b2==0)
		exit(998244353);
	while(sum>2)
	{
		if(!c[suc[b1]])
		{
			y=suc[b1];
			Mr_swap(b1,suc[b1]);
		}
		else
		{
			y=suc[b2];
			Mr_swap(b2,suc[b2]);
		}
		sum--;
	}
	Mr_swap(b1,b2);
	return;
}
signed main()
{
	int x,y,z;
	register int i;
	scanf("%d",&n);m=n;
	for(i=1;i<=n;i++)
		dis[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&suc[i]);
		pre[suc[i]]=i;
		merge(i,suc[i]);
	}
	if(m==1)
	{
		x=pre[1];y=suc[1];
		Mr_swap(1,x);Mr_swap(1,y);
		solve(1);
	}
	else
	{
		for(i=1;i<=n;i++)
			if(dis[i]==i)
				V.push_back(i);
		if(m&1)
		{
			for(i=1;i<=m-3;i+=2)
			{
				x=V[i-1];y=V[i];
				Mr_swap(x,y);
				solve(x);
			}
			x=V[m-3];y=V[m-2];z=V[m-1];
			Mr_swap(x,y);Mr_swap(y,z);
			solve(x);
		}
		else
		{
			for(i=1;i<=m;i+=2)
			{
				x=V[i-1];y=V[i];
				Mr_swap(x,y);
				solve(x);
			}
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}