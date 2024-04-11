#include<cstdio>
using namespace std;
int T,N;
long long K;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&K);
		int M=-2e9;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(M<A[i])M=A[i];
		}
		int MM=-2e9;
		for(int i=0;i<N;i++)
		{
			B[i]=M-A[i];
			if(MM<B[i])MM=B[i];
		}
		for(int i=0;i<N;i++)
		{
			A[i]=MM-B[i];
		}
		if(K%2==1)
		{
			for(int i=0;i<N;i++)printf("%d%c",B[i],i==N-1?'\n':' ');
		}
		else
		{
			for(int i=0;i<N;i++)printf("%d%c",A[i],i==N-1?'\n':' ');
		}
	}
}