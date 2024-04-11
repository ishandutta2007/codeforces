#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[300005],ice[300005];
bool tak[300005];
int col[300005];
void dfs(int node,int p)
{
	for (int i:ice[node])
	tak[col[i]]=1;
	int cur=1;
	for (int i:ice[node])
	{
		if (!col[i])
		{
			while (tak[cur])
			cur++;
			col[i]=cur;
			tak[cur]=1;
		}
	}
	for (int i:ice[node])
	tak[col[i]]=0;
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	int n,m,r=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int a;
			scanf("%d",&a);
			ice[i].push_back(a);
		}
		if (ice[i].size()>ice[r].size())
		r=i;
	}
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(r,0);
	printf("%d\n",max((int)ice[r].size(),1));
	for (int i=1;i<=m;i++)
	printf("%d ",max(col[i],1));
}