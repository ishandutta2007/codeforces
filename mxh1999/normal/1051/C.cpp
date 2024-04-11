#include<bits/stdc++.h>
using namespace std;

int n;
int a[210],num[210],ans[210];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	int m1=0,m3=0;
	for (int i=1;i<=100;i++)
	{
		if (num[i]==1)	m1++;
		if (num[i]>=3)	m3++;
	}
	if ((m1&1) && (m3==0))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (!(m1&1))
	{
		int ha=0;
		for (int i=1;i<=100;i++)
		{
			ans[i]=1;
			if (num[i]==1)
			{
				ha++;
				if (ha&1)	ans[i]=2;
			}
		}
		for (int i=1;i<=n;i++)
		if (ans[a[i]]==1)	printf("A");else printf("B");
		printf("\n");
		return 0;
	}
	int ha=0,sum=0;
	for (int i=1;i<=100;i++)
	{
		ans[i]=1;
		if (num[i]==1)
		{
			ha++;
			if (!(ha&1))	ans[i]=2;
		}
		if (num[i]>=3)	sum=i;
	}
	for (int i=1;i<=n;i++)
	if (a[i]==sum)
	{
		printf("B");
		sum=0;
	}	else
	{
		if (ans[a[i]]==1)	printf("A");else printf("B");
	}
	printf("\n");
	return 0;
}