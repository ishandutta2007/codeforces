#include <iostream>
using namespace std;
#define n 500000
#define BU 700
int a[500005],sum[BU][BU];
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (t==1)
		{
			a[x]+=y;
			for (int i=1;i<BU;i++)
			sum[i][x%i]+=y;
		}
		else
		{
			if (x<BU)
			printf("%d\n",sum[x][y]);
			else
			{
				int ans=0;
				for (int i=y;i<=n;i+=x)
				ans+=a[i];
				printf("%d\n",ans);
			}
		}
	}
}