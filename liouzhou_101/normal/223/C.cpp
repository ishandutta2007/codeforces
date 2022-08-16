#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=2010;
const long long MOD=1000000007LL;

int n;
long long k;
long long a[MaxN],F[MaxN];

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p>>1);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

void init()
{
	cin>>n>>k;
	for (int i=0;i<n;++i)
		cin>>a[i];
}

void work()
{
	if (k==0)
	{
		cout<<a[0];
		for (int i=1;i<n;++i)
			cout<<" "<<a[i];
		puts("");
		return;
	}
	F[0]=1;
	F[1]=k;
	for (int i=2;i<=n;++i)
		F[i]=F[i-1]*(k-1+i)%MOD*power(i,MOD-2)%MOD;
	for (int i=0;i<n;++i)
	{
		long long t=0;
		for (int j=0;j<=i;++j)
			(t+=F[j]*a[i-j])%=MOD;
		if (i) putchar(' ');
		cout<<t;
	}
	puts("");
}

int main()
{
	init();
	work();
	return 0;
}