#include<cstdio>
using namespace std;
int T,N,P[2<<17],A[2<<17];
int W[2<<17];
int D[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&P[i]),P[i]--;
		for(int i=0;i<N;i++)scanf("%d",&A[i]),A[i]--;
		for(int i=0;i<N;i++)D[i]=-1;
		if(P[A[0]]!=A[0])
		{
			puts("-1");
			continue;
		}
		W[A[0]]=0;
		D[A[0]]=0;
		bool out=false;
		for(int i=1;i<N;i++)
		{
			int u=A[i];
			int p=P[u];
			if(D[p]==-1)
			{
				out=true;
				break;
			}
			D[u]=i;
			W[u]=D[u]-D[p];
		}
		if(out)
		{
			puts("-1");
			continue;
		}
		for(int i=0;i<N;i++)printf("%d%c",W[i],i+1==N?10:32);
	}
}