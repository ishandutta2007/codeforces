#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int N;
main()
{
	scanf("%d",&N);
	long long g=0;
	for(;N--;)
	{
		long long a;
		scanf("%lld",&a);
		g=gcd(g,a);
	}
	int cnt=0;
	for(long long i=1;i*i<=g;i++)if(g%i==0)
	{
		cnt++;
		if(g/i>i)cnt++;
	}
	printf("%d\n",cnt);
}