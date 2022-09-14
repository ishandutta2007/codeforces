#include<cstdio>
#include<algorithm>
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
		int mx=0,mn=0;
		for(int i=1;i<N;i++)
		{
			if(A[mx]<A[i])mx=i;
			if(A[mn]>A[i])mn=i;
		}
		int L=mx,R=mn;
		if(L>R)swap(L,R);
		int ans=L+1+N-R;
		ans=min(ans,R+1);
		ans=min(ans,N-L);
		printf("%d\n",ans);
	}
}