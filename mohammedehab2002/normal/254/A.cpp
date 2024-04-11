#include <iostream>
#include <vector>
using namespace std;
vector <int> v[5005];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i+1);
	}
	for (int i=0;i<5005;i++)
	{
		if (v[i].size()%2)
		{
			printf("-1");
			return 0;
		}
	}
	for (int i=0;i<5005;i++)
	{
		for (int x=0;x<v[i].size();x+=2)
		printf("%d %d\n",v[i][x],v[i][x+1]);
	}
}