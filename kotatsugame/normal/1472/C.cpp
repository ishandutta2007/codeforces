#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=0;
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=N;i--;)
		{
			int now=A[i];
			if(i+A[i]<N)now+=A[i+A[i]];
			A[i]=now;
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
}