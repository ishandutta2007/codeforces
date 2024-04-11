#include <iostream>
#include <algorithm>
using namespace std;
int f[105];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for (int i=1;i<105;i++)
		{
			if (!(i*b>=a && i*(b-1)<a))
			f[i]=1;
		}
	}
	int ans=0;
	for (int i=1;i<105;i++)
	{
		if (!f[i])
		{
			if (!ans)
			ans=i;
			else
			{
				if ((n-1)/ans+1==(n-1)/i+1)
				continue;
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d",(n-1)/ans+1);
}