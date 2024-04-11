#include<cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	int mA=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		if(mA<A[i])mA=A[i];
	}
	int g=0;
	for(int i=0;i<N;i++)
	{
		A[i]=mA-A[i];
		g=gcd(g,A[i]);
	}
	long long Y=0;
	for(int i=0;i<N;i++)Y+=A[i]/g;
	printf("%lld %d\n",Y,g);
}