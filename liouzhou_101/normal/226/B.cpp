#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n;
int a[MaxN];
unsigned long long s[MaxN];
unsigned long long ans[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	for (int k=1;k<=100000;++k)
	{
		unsigned long long get=0;
		long long i=n-1;
		unsigned long long p=0;
		long long kk=k;
		while (1)
		{
			++p;
			long long j=max(i-kk+1,1LL);
			get+=(s[i]-s[j-1])*p;
			i-=kk;
			if (i<=0) break;
			kk*=k;
		}
		ans[k]=get;
	}
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int k;
		scanf("%d",&k);
		cout<<ans[k];
		if (T) putchar(' ');
	}
}

int main()
{
	init();
	work();
	return 0;
}