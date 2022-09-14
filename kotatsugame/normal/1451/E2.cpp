#include<cstdio>
using namespace std;
int N;
int X[1<<16];
int Y[1<<16];
int A[1<<16];
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		printf("XOR %d %d\n",1,i+1);
		fflush(stdout);
		scanf("%d",&X[i]);
	}
	int sA=-1,sB=-1;
	for(int i=1;i<N;i++)
	{
		if(X[i]==0)
		{
			sA=0,sB=i;
			break;
		}
		else if(Y[X[i]])
		{
			sA=Y[X[i]];
			sB=i;
			break;
		}
		else
		{
			Y[X[i]]=i;
		}
	}
	if(sA>=0)
	{
		printf("AND %d %d\n",sA+1,sB+1);
		fflush(stdout);
		scanf("%d",&A[sA]);
		printf("!");
		for(int i=0;i<N;i++)
		{
			if(sA!=i)
			{
				A[i]=X[i]^X[sA]^A[sA];
			}
			printf(" %d",A[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	else
	{
		int j=Y[1];
		int k=Y[2];
		int J,K;
		printf("AND 1 %d\n",j+1);
		fflush(stdout);
		scanf("%d",&J);
		printf("AND 1 %d\n",k+1);
		fflush(stdout);
		scanf("%d",&K);
		A[0]=J|K;
		printf("!");
		for(int i=0;i<N;i++)
		{
			if(i>0)
			{
				A[i]=X[i]^A[0];
			}
			printf(" %d",A[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}