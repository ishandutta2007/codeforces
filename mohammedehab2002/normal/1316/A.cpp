#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m,sum=0;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",min(m,sum));
	}
}