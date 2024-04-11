#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v[100005];
int dfs(int node,int pnode)
{
	int ans=0;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode)
		ans=max(ans,dfs(v[node][i].first,node)+v[node][i].second);
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	printf("%d",dfs(0,0));
}