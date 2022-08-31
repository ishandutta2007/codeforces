#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=110;

int n,w;
int v[MaxN],p[MaxN];

void init()
{
	cin>>n>>w;
	for (int i=1;i<=n;++i)
		cin>>v[i];
}

void work()
{
	int sum=0;
	for (int i=1;i<=n;++i)
		sum+=v[i];
	if (w<1||w>sum)
	{
		puts("No");
		return;
	}
	if (n==1)
	{
		if (w!=sum)
		{
			puts("No");
			return;
		}
		puts("Yes");
		for (int i=1,flag=0;i<=v[1]*2;++i)
		{
			if (flag) putchar(' ');
			printf("%d",1);
			flag=1;
		}
		puts("");
		return;
	}
	if (w==1)
	{
		int get=0;
		for (int i=1;i<=n;++i)
			if (v[i]==1) get=i;
		if (!get)
		{
			puts("No");
			return;
		}
		puts("Yes");
		printf("%d",get);
		for (int i=1;i<=n;++i)
			if (get!=i)
				for (int j=1;j<=v[i]*2;++j)
					printf(" %d",i);
		printf(" %d\n",get);
		return;
	}
	puts("Yes");
	for (int i=n;i>=1;--i)
		while (w>2)
		{
			if (i<=2&&v[i]==1) break;
			if (!v[i]) break;
			--w;
			--v[i];
			++p[i];
		}
	printf("1");
	for (int i=3;i<=n;++i)
		for (int j=1;j<=v[i]*2;++j)
			printf(" %d",i);
	for (int j=3;j<=v[2]*2;++j)
		printf(" 2");
	printf(" 1 2");
	for (int j=3;j<=v[1]*2;++j)
		printf(" 1");
	printf(" 2");
	for (int i=1;i<=n;++i)
		for (int j=1;j<=p[i]*2;++j)
			printf(" %d",i);
	puts("");
}

int main()
{
	init();
	work();
	return 0;
}