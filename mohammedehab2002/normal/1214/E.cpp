#include <bits/stdc++.h>
using namespace std;
vector<int> v;
pair<int,int> d[100005];
int par[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i].first);
		d[i].second=i;
	}
	sort(d+1,d+n+1);
	reverse(d+1,d+n+1);
	for (int i=1;i<=n;i++)
	{
		par[2*d[i].second]=2*d[i-1].second;
		v.push_back(2*d[i].second);
	}
	for (int i=1;i<=n;i++)
	{
		par[2*d[i].second-1]=v[i+d[i].first-2];
		if (i+d[i].first-1==v.size())
		v.push_back(2*d[i].second-1);
	}
	for (int i=1;i<=2*n;i++)
	{
		if (par[i])
		printf("%d %d\n",i,par[i]);
	}
}