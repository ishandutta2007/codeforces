#include<bits/stdc++.h>
using namespace std;
int n,x;
long long sum,diff,cr;
bool f[111111];
int main()
{
	scanf("%d",&n);
	if (n<4) 
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (n==4)
	{
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		return 0;
	}
	if (n==5)
	{
		printf("1 * 2 = 2\n");
		printf("3 + 4 = 7\n");
		printf("7 + 5 = 12\n");
		printf("2 * 12 = 24\n");
		return 0;
	}
	if (n==6)
	{
		printf("5 * 6 = 30\n");
		printf("30 - 3 = 27\n");
		printf("27 - 4 = 23\n");
		printf("23 - 1 = 22\n");
		printf("22 + 2 = 24\n");
		return 0;
	}
	sum=1ll*n*(n+1)/2;
	if (sum&1)
	{
		sum--;
		diff=(sum-24)/2;
		for (int i=n;i>=2;i--)
		{
			if (diff>=i && diff-i!=1)
			{
				diff-=i;
				f[i]=1;
			}
		}
		for (int i=2;i<=n;i++)
		{
			if (!f[i]) 
			{
				x=i;
				break;
			}
		}
		cr=x;
		for (int i=2;i<=n;i++)
		{
			if (i==x) continue;
			if (!f[i])
			{
				printf("%lld + %d = %lld\n",cr,i,(long long)cr+i);
				cr+=i;
			}
			else
			{
				printf("%lld - %d = %lld\n",cr,i,(long long)cr-i);
				cr-=i;
			}
		}
		printf("24 * 1 = 24\n");
	}
	else
	{
		diff=(sum-24)/2;
		for (int i=n;i>=1;i--)
		{
			if (diff>=i)
			{
				diff-=i;
				f[i]=1;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (!f[i]) 
			{
				x=i;
				break;
			}
		}
		cr=x;
		for (int i=1;i<=n;i++)
		{
			if (i==x) continue;
			if (!f[i])
			{
				printf("%lld + %d = %lld\n",cr,i,(long long)cr+i);
				cr+=i;
			}
			else
			{
				printf("%lld - %d = %lld\n",cr,i,(long long)cr-i);
				cr-=i;
			}
		}
	}
	return 0;
}