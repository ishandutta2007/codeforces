#include<cstdio>
using namespace std;
int T;
long long N,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&N,&A,&B);
		bool fn=false;
		long long P=1;
		while(P<=N)
		{
			if((N-P)%B==0)fn=true;
			P*=A;
			if(A==1)break;
		}
		puts(fn?"Yes":"No");
	}
}