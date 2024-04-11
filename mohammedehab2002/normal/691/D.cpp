#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[1000005],pos;
bool vis[1000005];
int p[1000005];
void dfs(int i)
{
	vis[i]=1;
	pos.push_back(i);
	for (int u:v[i])
	{
		if (!vis[u])
		dfs(u);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			pos.clear();
			dfs(i);
			vector<int> tmp;
			for (int x:pos)
			tmp.push_back(p[x]);
			sort(pos.begin(),pos.end());
			sort(tmp.begin(),tmp.end(),greater<int>());
			for (int i=0;i<pos.size();i++)
			p[pos[i]]=tmp[i];
		}
	}
	for (int i=1;i<=n;i++)
	printf("%d ",p[i]);
}