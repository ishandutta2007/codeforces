#include<cstdio>
using namespace std;
int T,N;
int P[1010],L[1010],R[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&P[i]);
		L[0]=0;
		for(int i=1;i<N;i++)
		{
			L[i]=L[i-1];
			if(P[i]<P[L[i]])L[i]=i;
		}
		R[N-1]=N-1;
		for(int i=N-1;i--;)
		{
			R[i]=R[i+1];
			if(P[i]<P[R[i]])R[i]=i;
		}
		bool ok=false;
		for(int i=0;i<N;i++)if(P[L[i]]<P[i]&&P[i]>P[R[i]])
		{
			ok=true;
			printf("YES\n%d %d %d\n",L[i]+1,i+1,R[i]+1);
			break;
		}
		if(!ok)puts("NO");
	}
}