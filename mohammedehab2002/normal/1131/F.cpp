#include <iostream>
#include <vector>
using namespace std;
vector<int> v[150005];
int par[150005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		v[i].push_back(i);
		par[i]=i;
	}
	while (--n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(x);
		y=find(y);
		if (v[x].size()<v[y].size())
		swap(x,y);
		for (int i:v[y])
		v[x].push_back(i);
		par[y]=x;
	}
	for (int i:v[find(1)])
	printf("%d ",i);
}