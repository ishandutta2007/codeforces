#include<cstdio>
using namespace std;
int T,N,A[1<<20],B[1<<20];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		int T=B[0];
		bool out=false;
		for(int i=1;i<N;i++)
		{
			if(B[i]+T<A[i])
			{
				out=true;
				break;
			}
			if(T>A[i])T=B[i];
			else T=B[i]+T-A[i];
		}
		if(out)
		{
			puts("NO");
			continue;
		}
		if(A[0]>T)
		{
			B[0]-=A[0]-T;
			A[0]=T;
			if(B[0]<0)
			{
				puts("NO");
				continue;
			}
		}
		T=B[0];
		for(int i=1;i<N;i++)
		{
			if(B[i]+T<A[i])
			{
				out=true;
				break;
			}
			if(T>A[i])T=B[i];
			else T=B[i]+T-A[i];
		}
		puts(out||T<A[0]?"NO":"YES");
	}
}