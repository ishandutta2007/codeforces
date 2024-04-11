#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
int A[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<K;i++)
		{
			scanf("%d",&A[i]);
			A[i]=N-A[i];
		}
		sort(A,A+K);
		int ans=0,rest=N-1;
		while(ans<K&&rest>=A[ans])rest-=A[ans++];
		printf("%d\n",ans);
	}
}