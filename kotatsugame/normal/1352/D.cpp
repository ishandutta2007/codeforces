#include<cstdio>
using namespace std;
int T,N;
int A[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int L=0,R=N;
		int X=0,Y=0,prv=0,turn=0;
		for(;L<R;turn++)
		{
			if(turn%2==0)
			{
				int now=0;
				while(L<R&&now<=prv)
				{
					now+=A[L++];
				}
				X+=now;
				prv=now;
			}
			else
			{
				int now=0;
				while(L<R&&now<=prv)
				{
					now+=A[--R];
				}
				Y+=now;
				prv=now;
			}
		}
		printf("%d %d %d\n",turn,X,Y);
	}
}