#include<cstdio>
using namespace std;
int T,N;
int A[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		if(A[0]!=A[1])
		{
			printf("%d\n",A[0]==A[2]?2:1);
		}
		else
		{
			int id=0;
			while(A[id]==A[0])id++;
			printf("%d\n",id+1);
		}
	}
}