#include<bits/stdc++.h>
using namespace std;
int pa[111111],n,m,x,y,ans;
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
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Union(x,y);
	}
	ans=n;
	for (int i=1;i<=n;i++)
	{
		if (root(i)==i) ans--;
	}
	printf("%d\n",m-ans);
	return 0;
}