#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
vector<pair<int,int> > qu[100005];
int n,ans[100005],sz[100005],cnt[100005],col[100005],tree[100005];
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
void update(int idx,int val)
{
	while (idx<=n)
	{
		tree[idx]+=val;
		idx+=(idx&(-idx));
	}
}
int query(int idx)
{
	if (idx<=0)
	return 0;
	int ans=0;
	while (idx)
	{
		ans+=tree[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
void add(int node,int p,int big,int a)
{
	update(n-cnt[col[node]]+1,-1);
	cnt[col[node]]+=a;
	update(n-cnt[col[node]]+1,1);
	for (int u:v[node])
	{
		if (u!=p && u!=big)
		add(u,node,big,a);
	}
}
void dfs(int node,int p,bool keep)
{
	int big=-1;
	for (int u:v[node])
	{
		if (u!=p && (big==-1 || sz[u]>sz[big]))
		big=u;
	}
	for (int u:v[node])
	{
		if (u!=p && u!=big)
		dfs(u,node,0);
	}
	if (big!=-1)
	dfs(big,node,1);
	add(node,p,big,1);
	for (auto q:qu[node])
	ans[q.second]=query(n-q.first+1);
	if (!keep)
	add(node,p,-1,-1);
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	scanf("%d",&col[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=0;i<q;i++)
	{
		int v,k;
		scanf("%d%d",&v,&k);
		qu[v].push_back({k,i});
	}
	pre(1,0);
	dfs(1,0,1);
	for (int i=0;i<q;i++)
	printf("%d\n",ans[i]);
}