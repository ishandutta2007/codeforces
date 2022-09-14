#include<cstdio>
using namespace std;
int T,N;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d%d",&A[i],&B[i]);
		int L=1,R=N+1;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int now=0;
			for(int i=0;i<N;i++)
			{
				if(A[i]>=mid-now-1&&B[i]>=now)now++;
			}
			if(now>=mid)L=mid;
			else R=mid;
		}
		printf("%d\n",L);
	}
}