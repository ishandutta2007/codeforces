#include<cstdio>
using namespace std;
const long long mod=1e9+7;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int cz=0,all=-1;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			all&=A[i];
		}
		for(int i=0;i<N;i++)cz+=all==A[i];
		{
			if(cz<2)puts("0");
			else
			{
				long long ans=1;
				ans*=cz;
				ans*=cz-1;
				ans%=mod;
				for(int i=1;i<=N-2;i++)
				{
					ans*=i;
					ans%=mod;
				}
				printf("%lld\n",ans);
			}
		}
	}
}