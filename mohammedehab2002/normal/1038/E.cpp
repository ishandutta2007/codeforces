#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
bool deg[5],vis[105];
vector<int> v[5];
int a[105],b[105],c[105];
int dfs(int node,int no)
{
	int ret=0;
	for (int i:v[node])
	{
		if (i!=no && !vis[i])
		{
			vis[i]=1;
			ret+=dfs(a[i]^b[i]^node,no)+c[i];
		}
	}
	return ret;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i],&c[i],&b[i]);
		v[a[i]].push_back(i);
		v[b[i]].push_back(i);
		deg[a[i]]^=1;
		deg[b[i]]^=1;
	}
	if (count(deg+1,deg+5,1)==4)
	{
		for (int i=1;i<=4;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (a[j]!=b[j])
				{
					memset(vis,0,sizeof(vis));
					ans=max(ans,dfs(i,j));
				}
			}
		}
	}
	else
	{
		for (int i=1;i<=4;i++)
		{
			memset(vis,0,sizeof(vis));
			ans=max(ans,dfs(i,-1));
		}
	}
	printf("%d\n",ans);
}