#include<cstdio>
#include<algorithm>
using namespace std;
long long H;
int N;
int d[2<<17];
long long M[2<<17];
main()
{
	scanf("%lld%d",&H,&N);
	long long cd=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&d[i]);
		cd-=d[i];
		M[i+1]=max(M[i],cd);
	}
	long long ans=0;
	if(H>M[N])
	{
		if(cd<=0)
		{
			puts("-1");
			return 0;
		}
		long long T=H-M[N];
		ans=(T+cd-1)/cd;
		H-=ans*cd;
		ans*=N;
	}
	ans+=lower_bound(M,M+N+1,H)-M;
	printf("%lld\n",ans);
}