#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n,m,a[100005],b[100005],c[100005],pos[100005],cur;
vector<int> v[100005],e;
void dfs(int node)
{
	pos[node]=1;
	for (int u:v[node])
	{
		if (!pos[u])
		dfs(u);
	}
	pos[node]=++cur;
}
bool check(int x)
{
	for (int i=1;i<=n;i++)
	v[i].clear();
	e.clear();
	for (int i=1;i<=m;i++)
	{
		if (c[i]>x)
		v[a[i]].push_back(b[i]);
	}
	cur=0;
	memset(pos,0,sizeof(pos));
	for (int i=1;i<=n;i++)
	{
		if (!pos[i])
		dfs(i);
	}
	for (int i=1;i<=m;i++)
	{
		if (pos[a[i]]<pos[b[i]])
		{
			if (c[i]>x)
			return 0;
			e.push_back(i);
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	int st=0,en=1e9;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid+1;
	}
	check(st);
	printf("%d %d\n",st,e.size());
	for (int i:e)
	printf("%d ",i);
}