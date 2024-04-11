#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int arr[100005],cnt[100005],sz[100005],mx;
long long a[100005],ans;
bool dont[100005];
void pre(int node,int pnode)
{
	sz[node]=1;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		{
			pre(v[node][i],node);
			sz[node]+=sz[v[node][i]];
		}
	}
}
void add(int node,int pnode,int x)
{
	cnt[arr[node]]+=x;
	if (cnt[arr[node]]>mx)
	{
		ans=arr[node];
		mx=cnt[arr[node]];
	}
	else if (cnt[arr[node]]==mx)
	ans+=arr[node];
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode && !dont[v[node][i]])
		add(v[node][i],node,x);
	}
}
void dfs(int node,int pnode,bool keep)
{
	int big=-1;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		{
			if (big==-1)
			big=v[node][i];
			else if (sz[v[node][i]]>sz[big])
			big=v[node][i];
		}
	}
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode && v[node][i]!=big)
		dfs(v[node][i],node,0);
	}
	if (big!=-1)
	{
		dfs(big,node,1);
		dont[big]=1;
	}
	add(node,pnode,1);
	a[node]=ans;
	if (big!=-1)
	dont[big]=0;
	if (!keep)
	{
		add(node,pnode,-1);
		mx=0;
		ans=0;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pre(1,0);
	dfs(1,0,1);
	for (int i=1;i<=n;i++)
	printf("%I64d ",a[i]);
}