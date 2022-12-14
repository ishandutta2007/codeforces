#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,c[111111],x,y,pa[111111],sum[111111],sm,cur[111111],mxi,ans;
bool used[111111];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	sum[ry]+=sum[rx];
	pa[rx]=ry;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
	}
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;
		sum[i]=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Union(x,y);
	}
	for (int i=1;i<=k;i++)
	{
		int rt=root(c[i]);
		if (used[rt])
		{
			printf("0\n");
			return 0;
		}
		used[rt]=1;
		cur[i]=sum[rt];
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[root(i)])
		{
			used[root(i)]=1;
			sm+=sum[root(i)];
		}
	}
	mxi=1;
	for (int i=2;i<=k;i++)
	{
		if (cur[i]>cur[mxi]) mxi=i;
	}
	cur[mxi]+=sm;
	for (int i=1;i<=k;i++) ans+=(cur[i]*(cur[i]-1)/2);
	printf("%d\n",ans-m);
	return 0;
}