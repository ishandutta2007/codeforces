#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v[100005];
bool vis[100005];
int cum[100005],bas[35];
void dfs(int node)
{
	vis[node]=1;
	for (auto p:v[node])
	{
		if (!vis[p.first])
		{
			cum[p.first]=(cum[node]^p.second);
			dfs(p.first);
		}
	}
}
void add(int x)
{
	for (int i=29;i>=0;i--)
	{
		if (x&(1<<i))
		x^=bas[i];
	}
	for (int i=29;i>=0;i--)
	{
		if (x&(1<<i))
		{
			bas[i]=x;
			return;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		for (auto p:v[i])
		add(cum[i]^cum[p.first]^p.second);
	}
	for (int i=29;i>=0;i--)
	{
		if (cum[n]&(1<<i))
		cum[n]^=bas[i];
	}
	printf("%d",cum[n]);
}