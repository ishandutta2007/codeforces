#include <iostream>
using namespace std;
bool occ[1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	m*=2;
	while (m--)
	{
		int a;
		scanf("%d",&a);
		occ[a]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (!occ[i])
		{
			printf("%d\n",n-1);
			for (int x=1;x<=n;x++)
			{
				if (i==x)
				continue;
				printf("%d %d\n",i,x);
			}
			return 0;
		}
	}
}