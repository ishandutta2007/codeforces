#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v[100005];
int arr[100005],ans;
void dfs(int node,int pnode,long long d,bool er)
{
	if (d>arr[node])
	er=1;
	ans+=er;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode)
		dfs(v[node][i].first,node,max(d,0LL)+v[node][i].second,er);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=2;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[i].push_back(make_pair(a,b));
		v[a].push_back(make_pair(i,b));
	}
	dfs(1,0,0,0);
	printf("%d",ans);
}