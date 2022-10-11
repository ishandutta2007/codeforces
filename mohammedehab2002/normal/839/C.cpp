#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
double dfs(int node,int pnode,int d)
{
	int vis=0;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		vis++;
	}
	if (!vis)
	return d;
	double ret=0.0,den=vis;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		ret+=dfs(v[node][i],node,d+1)/vis;
	}
	return ret;
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
	printf("%.15lf",dfs(1,0,0));
}