#include <bits/stdc++.h>
using namespace std;
int cnt[105];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			cnt[a]++;
		}
		for (int i=0;cnt[i];i++)
		{
			printf("%d ",i);
			cnt[i]--;
		}
		for (int i=0;i<=100;i++)
		{
			while (cnt[i])
			{
				printf("%d ",i);
				cnt[i]--;
			}
		}
		printf("\n");
	}
}