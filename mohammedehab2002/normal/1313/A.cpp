#include <bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int ans=0;
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		for (int i=0;i<(1<<8);i++)
		{
			for (int j=0;j<8;j++)
			{
				if (i&(1<<j))
				{
					for (int k=0;k<3;k++)
					{
						if (j&(1<<k))
						a[k]--;
					}
				}
			}
			if (a[0]>=0 && a[1]>=0 && a[2]>=0)
			ans=max(ans,__builtin_popcount(i));
			for (int j=0;j<8;j++)
			{
				if (i&(1<<j))
				{
					for (int k=0;k<3;k++)
					{
						if (j&(1<<k))
						a[k]++;
					}
				}
			}
		}
		printf("%d\n",ans-1);
	}
}