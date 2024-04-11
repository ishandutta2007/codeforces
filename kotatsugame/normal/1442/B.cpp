#include<cstdio>
using namespace std;
const long long mod=998244353;
int T,N,K;
int A[2<<17],B[2<<17];
int invA[2<<17],invB[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++)invA[i]=invB[i]=-1;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			invA[A[i]]=i;
		}
		for(int i=0;i<K;i++)
		{
			scanf("%d",&B[i]);
			invB[B[i]]=i;
		}
		long long ans=1;
		for(int i=0;i<K;i++)
		{
			int ai=invA[B[i]];
			bool L=false,R=false;
			if(ai>0&&invB[A[ai-1]]<i)L=true;
			if(ai+1<N&&invB[A[ai+1]]<i)R=true;
			ans=ans*(L+R)%mod;
		}
		printf("%lld\n",ans);
	}
}