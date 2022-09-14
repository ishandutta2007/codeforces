#include<cstdio>
using namespace std;
int T,A,B,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&A,&B,&K);
		if(K==1)
		{
			puts((A%B==0||B%A==0)&&A!=B?"YES":"NO");
			continue;
		}
		for(int i=2;i*i<=A;i++)if(A%i==0)
		{
			while(A%i==0)
			{
				A/=i;
				K--;
			}
		}
		if(A>1)K--;
		for(int i=2;i*i<=B;i++)if(B%i==0)
		{
			while(B%i==0)
			{
				B/=i;
				K--;
			}
		}
		if(B>1)K--;
		puts(K>0?"NO":"YES");
	}
}