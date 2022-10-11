#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[1000005],cop[1000005],c;
vector<pair<int,int> > e;
bool vis[2000005],ans[2000005];
void dfs(int node)
{
	while (!v[node].empty())
	{
		int idx=v[node].back();
		v[node].pop_back();
		if (vis[idx])
		continue;
		vis[idx]=1;
		dfs(node^e[idx].first^e[idx].second);
		c.push_back(idx);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(i);
		v[b].push_back(i);
		e.push_back({a,b});
	}
	for (int i=1;i<=n;i++)
	{
		cop[i]=v[i];
		if (v[i].size()%2)
		{
			v[i].push_back(m);
			v[n+1].push_back(m);
			e.push_back({i,n+1});
			m++;
		}
	}
	vector<int> pend;
	for (int i=1;i<=n;i++)
	{
		dfs(i);
		for (int j=0;j<c.size();j+=2)
		{
			if (e[c[j]].second!=n+1)
			ans[c[j]]=1;
			else
			pend.push_back(e[c[j]].first);
		}
		c.clear();
	}
	for (int i:pend)
	{
		for (int j:cop[i])
		{
			if (!ans[j])
			{
				ans[j]=1;
				break;
			}
		}
	}
	printf("%d\n",count(ans,ans+m,1));
	for (int i=0;i<m;i++)
	{
		if (ans[i])
		printf("%d %d\n",e[i].first,e[i].second);
	}
}