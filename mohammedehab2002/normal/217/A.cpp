#include <iostream>
#include <set>
using namespace std;
pair<int,int> arr[105];
int par[105];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
	par[x]=y;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	par[i]=i;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].first,&arr[i].second);
		for (int x=0;x<i;x++)
		{
			if (arr[i].first==arr[x].first || arr[i].second==arr[x].second)
			Union(i,x);
		}
	}
	set<int> s;
	for (int i=0;i<n;i++)
	s.insert(find(i));
	printf("%d",s.size()-1);
}