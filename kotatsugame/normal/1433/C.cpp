#include<cstdio>
using namespace std;
int T,N;
int A[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int mx=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			if(mx<A[i])mx=A[i];
		}
		int id=-1;
		for(int i=0;i<N;i++)
		{
			if(mx==A[i])
			{
				if(i>0&&A[i-1]<mx||i+1<N&&A[i+1]<mx)
				{
					id=i+1;
					break;
				}
			}
		}
		printf("%d\n",id);
	}
}