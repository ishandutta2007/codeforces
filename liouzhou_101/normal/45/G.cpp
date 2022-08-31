#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=18003010;

bool F[MaxN];
int tot,p[MaxN];
int v[6010];

int main()
{
	int n;
	cin>>n;
	if (n==2)
	{
		puts("1 1");
		return 0;
	}
	int s=n*(n+1)/2;
	F[1]=1;
	for (int i=2;i<=s;++i)
	{
		if (!F[i])
			p[++tot]=i;
		int t;
		for (int j=1;(t=i*p[j])<=s;++j)
		{
			F[t]=1;
			if (i%p[j]==0) break;
		}
	}
	for (int i=1;i<=n;++i)
		v[i]=1;
	for (int i=2;i<s;++i)
		if (!F[i]&&!F[s-i])
		{
			for (int j=n;j>=1;--j)
				if (i>=j)
				{
					v[j]=2;
					i-=j;
				}
			for (int j=1;j<=n;++j)
			{
				if (j>1) putchar(' ');
				printf("%d",v[j]);
			}
			puts("");
			return 0;
		}
	v[3]=3;
	s-=3;
	for (int i=2;i<s;++i)
		if (!F[i]&&!F[s-i])
		{
			for (int j=n;j>=1;--j)
				if (v[j]==1&&i>=j)
				{
					v[j]=2;
					i-=j;
				}
			for (int j=1;j<=n;++j)
			{
				if (j>1) putchar(' ');
				printf("%d",v[j]);
			}
			puts("");
			return 0;
		}
	return 0;
}