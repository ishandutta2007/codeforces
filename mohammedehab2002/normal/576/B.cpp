#include <bits/stdc++.h>
using namespace std;
int p[100005];
bool vis[100005];
vector<int> c;
vector<pair<int,int> > e;
void dfs(int i)
{
	c.push_back(i);
	vis[i]=1;
	if (!vis[p[i]])
	dfs(p[i]);
}
bool cmp(vector<int> a,vector<int> b)
{
	return a.size()<b.size();
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	vector<vector<int> > cyc;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			c.clear();
			dfs(i);
			cyc.push_back(c);
		}
	}
	sort(cyc.begin(),cyc.end(),cmp);
	if (cyc[0].size()>2)
	{
		printf("NO");
		return 0;
	}
	if (cyc[0].size()==2)
	e.push_back({cyc[0][0],cyc[0][1]});
	for (int i=1;i<cyc.size();i++)
	{
		if (cyc[i].size()%cyc[0].size())
		{
			printf("NO");
			return 0;
		}
		for (int j=0;j<cyc[i].size();j++)
		e.push_back({cyc[i][j],cyc[0][j%cyc[0].size()]});
	}
	printf("YES\n");
	for (auto p:e)
	printf("%d %d\n",p.first,p.second);
}