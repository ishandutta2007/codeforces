#include <iostream>
#include <vector>
using namespace std;
vector<int> v[105];
int ans[205],d[2],com;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	for (int i=10;i<100;i++)
	{
		if (v[i].size()>=2)
		{
			ans[v[i].back()]=1;
			v[i].pop_back();
			ans[v[i].back()]=2;
			v[i].pop_back();
			com++;
		}
		else if (v[i].size()==1)
		{
			int x=0;
			if (d[0]>d[1])
			x=1;
			d[x]++;
			ans[v[i].back()]=x+1;
			v[i].pop_back();
		}
	}
	int g=n-d[0]-com;
	for (int i=10;i<100;i++)
	{
		if (v[i].size())
		{
			int x=0;
			if (!g)
			x=1;
			ans[v[i].back()]=x+1;
			v[i].pop_back();
			if (g)
			g--;
			i--;
		}
	}
	printf("%d\n",(com+d[0])*(com+d[1]));
	for (int i=0;i<2*n;i++)
	printf("%d ",ans[i]);
}