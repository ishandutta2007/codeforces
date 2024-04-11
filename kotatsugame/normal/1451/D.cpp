#include<cstdio>
using namespace std;
int T;
long long D,K;
long long msq(long long N)
{
	long long L=0,R=1e5;
	while(R-L>1)
	{
		long long M=(L+R)/2;
		if(M*M<=N)L=M;
		else R=M;
	}
	return L;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld",&D,&K);
		long long u=msq(D*D/(2*K*K));
		puts((u*K+K)*(u*K+K)+u*u*K*K>D*D?"Utkarsh":"Ashish");
	}
}