#include<cstdio>
using namespace std;
int T,N,K,A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		bool exs=false,flag=N==1;
		for(int i=0;i<N;i++)
		{
			if(A[i]==K)exs=true;
			if(A[i]>=K)
			{
				if(i>0&&A[i-1]>=K)flag=true;
				if(i<N-1&&A[i+1]>=K)flag=true;
				if(i<N-2&&A[i+2]>=K)flag=true;
			}
		}
		puts(exs&&flag?"yes":"no");
	}
}