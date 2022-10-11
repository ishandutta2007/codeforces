#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
vector<int> v[200005],ans;
int deg[200005];
bool del[200005];
void add(int node,int p)
{
	assert(deg[node]%2==0);
	del[node]=1;
	ans.push_back(node);
	for (int u:v[node])
	deg[u]--;
	for (int u:v[node])
	{
		if (u!=p && !del[u])
		add(u,node);
	}
}
void dfs(int node,int p)
{
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
	if (deg[node]%2==0)
	add(node,p);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if (!a)
		continue;
		deg[i]++;
		deg[a]++;
		v[a].push_back(i);
		v[i].push_back(a);
	}
	dfs(1,0);
	if (ans.size()==n)
	{
		printf("YES\n");
		for (int i:ans)
		printf("%d\n",i);
	}
	else
	printf("NO");
}