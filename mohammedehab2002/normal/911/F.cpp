#include <iostream>
#include <vector>
using namespace std;
long long len=0;
int a,b,dep[2][200005];
vector<int> v[200005],d;
vector<pair<int,int> > ans;
pair<int,int> far(int node,int p)
{
	pair<int,int> mx={-1,node};
	for (int u:v[node])
	{
		if (u!=p)
		mx=max(mx,far(u,node));
	}
	mx.first++;
	return mx;
}
void dfs(int node,int p,int a)
{
	for (int u:v[node])
	{
		if (u!=p)
		{
			dep[a][u]=dep[a][node]+1;
			dfs(u,node,a);
		}
	}
}
bool dfs2(int node,int p)
{
	bool no=(node==b);
	for (int u:v[node])
	{
		if (u!=p)
		no|=dfs2(u,node);
	}
	if (no)
	d.push_back(node);
	else
	{
		if (dep[0][node]>dep[1][node])
		ans.push_back({node,a});
		else
		ans.push_back({node,b});
		len+=max(dep[0][node],dep[1][node]);
	}
	return no;
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
	a=far(1,0).second;
	b=far(a,0).second;
	dfs(a,0,0);
	dfs(b,0,1);
	dfs2(a,0);
	for (int i=0;i<d.size()-1;i++)
	{
		ans.push_back({d[i],a});
		len+=d.size()-i-1;
	}
	printf("%I64d\n",len);
	for (auto p:ans)
	printf("%d %d %d\n",p.first,p.second,p.first);
}