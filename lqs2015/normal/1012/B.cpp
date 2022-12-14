#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,q,x[222222],y[222222],ans,pa[444444];
vector<int> r[222222],c[222222];
bool used[444444];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		r[x[i]].push_back(y[i]);
		c[y[i]].push_back(x[i]);  
	}
	for (int i=1;i<=n+m;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<c[i].size();j++) Union(c[i][0],c[i][j]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<r[i].size();j++) Union(r[i][0]+n,r[i][j]+n);
	}
	for (int i=1;i<=q;i++)
	{
		Union(x[i],y[i]+n);
	}
	for (int i=1;i<=n+m;i++)
	{
		if (!used[root(i)])
		{
			used[root(i)]=1;
			ans++;
		}
	}
	printf("%d\n",ans-1);
	return 0;
}