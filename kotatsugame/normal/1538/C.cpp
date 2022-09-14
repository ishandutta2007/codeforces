#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,L,R;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&L,&R);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			if(A[i]*2>=L&&A[i]*2<=R)ans--;
			int l=lower_bound(A,A+N,L-A[i])-A;
			int r=upper_bound(A,A+N,R-A[i])-A;
			ans+=r-l;
		}
		printf("%lld\n",ans/2);
	}
}