#include <iostream>
using namespace std;
int cnt[5000005];
int main()
{
	for (int i=2;i<5000005;i++)
	{
		if (!cnt[i])
		{
			for (int x=i;x<5000005;x+=i)
			{
				int tmp=x;
				while (tmp%i==0)
				{
					cnt[x]++;
					tmp/=i;
				}
			}
		}
	}
	for (int i=2;i<5000005;i++)
	cnt[i]+=cnt[i-1];
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",cnt[a]-cnt[b]);
	}
}