#include <iostream>
#include <vector>
using namespace std;
int mat[505][505],dist[505][505];
long long ans[505];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=n;x++)
		{
			scanf("%d",&mat[i][x]);
			dist[i][x]=mat[i][x];
		}
	}
	vector<int> v;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	for (int i=v.size()-1;i>=0;i--)
	{
		for (int x=i+1;x<v.size();x++)
		{
			for (int j=1;j<=n;j++)
			{
				dist[v[i]][j]=min(dist[v[i]][j],dist[v[i]][v[x]]+dist[v[x]][j]);
				dist[j][v[i]]=min(dist[j][v[i]],dist[j][v[x]]+dist[v[x]][v[i]]);
			}
		}
		for (int x=1;x<=n;x++)
		{
			for (int j=1;j<=n;j++)
			dist[x][j]=min(dist[x][j],dist[x][v[i]]+dist[v[i]][j]);
		}
		for (int x=i;x<v.size();x++)
		{
			for (int j=i;j<v.size();j++)
			ans[i]+=dist[v[x]][v[j]];
		}
	}
	for (int i=0;i<n;i++)
	printf("%I64d ",ans[i]);
}