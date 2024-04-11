#include<iostream>
#include<cstdio>
using namespace std;
int N,M;
long long X[3<<17];
long long P[3<<17];
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%lld",&X[i]);
	for(int i=0;i<M;i++)scanf("%lld",&P[i]);
	long long now=0;
	for(int i=1;i<N;i++)now=gcd(now,X[i]-X[i-1]);
	for(int i=0;i<M;i++)
	{
		if(now%P[i]==0)
		{
			printf("YES\n%lld %d\n",X[0],i+1);
			return 0;
		}
	}
	puts("NO");
}