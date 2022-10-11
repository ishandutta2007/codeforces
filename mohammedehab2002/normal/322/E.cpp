#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
bool del[100005];
int sz[100005];
void pre(int node,int p)
{
	sz[node]=1;
	for (int u:v[node])
	{
		if (!del[u] && u!=p)
		{
			pre(u,node);
			sz[node]+=sz[u];
		}
	}
}
int find(int node,int p,int n)
{
	for (int u:v[node])
	{
		if (!del[u] && u!=p && sz[u]>n/2)
		return find(u,node,n);
	}
	return node;
}
char ans[100005];
void dfs(int node,char r)
{
	pre(node,0);
	int c=find(node,0,sz[node]);
	ans[c]=r;
	del[c]=1;
	for (int u:v[c])
	{
		if (!del[u])
		dfs(u,r+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,'A');
	for (int i=1;i<=n;i++)
	printf("%c ",ans[i]);
}