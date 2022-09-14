#include<cstdio>
using namespace std;
int N,M;
long long A[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	long long sum=0;
	int id=0;
	for(;M--;)
	{
		long long b;
		scanf("%lld",&b);
		while(sum+A[id]<b)sum+=A[id++];
		printf("%d %lld\n",id+1,b-sum);
	}
}