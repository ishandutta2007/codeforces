#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1000005];
int sz[1000005],cnt[1000005],ans[1000005],gen;
int pre(int node,int p)
{
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=pre(u,node);
	}
	return sz[node];
}
void add(int node,int p,int d,int no,bool a)
{
	if (a)
	{
		cnt[d]++;
		if (cnt[d]>cnt[gen] || (cnt[d]==cnt[gen] && d<gen))
		gen=d;
	}
	else
	cnt[d]--;
	for (int u:v[node])
	{
		if (u!=p && u!=no)
		add(u,node,d+1,no,a);
	}
}
void dfs(int node,int p,int d,bool keep)
{
	int big=-1;
	for (int u:v[node])
	{
		if (u!=p)
		{
			if (big==-1 || sz[u]>sz[big])
			big=u;
		}
	}
	for (int u:v[node])
	{
		if (u!=p && u!=big)
		dfs(u,node,d+1,0);
	}
	if (big!=-1)
	dfs(big,node,d+1,1);
	if (gen==-1)
	gen=d;
	add(node,p,d,big,1);
	ans[node]=gen-d;
	if (!keep)
	add(node,p,d,-1,0),gen=-1;
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
	pre(1,0);
	dfs(1,0,0,1);
	for (int i=1;i<=n;i++)
	printf("%d\n",ans[i]);
}