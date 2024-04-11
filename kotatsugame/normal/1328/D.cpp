#include<cstdio>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		bool one=true;
		int nxt=-1;
		for(int i=0;i<N;i++)
		{
			if(A[i]!=A[0])one=false;
			if(A[i]==A[(i+1)%N])nxt=i;
		}
		if(one)
		{
			printf("1\n");
			for(int i=0;i<N;i++)printf("1%c",i+1==N?'\n':' ');
		}
		else if(N%2==0)
		{
			printf("2\n");
			for(int i=0;i<N;i++)printf("%d%c",i%2+1,i+1==N?'\n':' ');
		}
		else if(nxt!=-1)
		{
			printf("2\n");
			int k=0;
			for(int i=0;i<N;i++)
			{
				printf("%d%c",(i+k)%2+1,i+1==N?'\n':' ');
				if(i==nxt)k=1;
			}
		}
		else
		{
			printf("3\n");
			for(int i=0;i<N-1;i++)printf("%d ",i%2+1);
			printf("3\n");
		}
	}
}