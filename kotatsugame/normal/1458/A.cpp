#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int N,M;
long long A[2<<17],B[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	sort(A,A+N);
	long long g=0;
	for(int i=1;i<N;i++)g=gcd(g,A[i]-A[0]);
	for(int i=0;i<M;i++)
	{
		long long b;scanf("%lld",&b);
		long long now=gcd(g,A[0]+b);
		printf("%lld%c",now,i+1==M?10:32);
	}
}