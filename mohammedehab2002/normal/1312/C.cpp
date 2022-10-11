#include <bits/stdc++.h>
using namespace std;
int cnt[65];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		bool ok=1;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++)
		{
			long long a;
			scanf("%I64d",&a);
			for (int j=0;a;j++)
			{
				ok&=(a%k<=1);
				if (a%k)
				{
					ok&=!cnt[j];
					cnt[j]++;
				}
				a/=k;
			}
		}
		puts(ok? "YES":"NO");
	}
}