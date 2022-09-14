#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17],B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<2<<17;i++)A[i]=B[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			A[a]++;
		}
		int ans=0;
		for(int i=1;i<2<<17;i++)
		{
			ans=max(ans,A[i]+=B[i]);
			for(int j=i+i;j<2<<17;j+=i)B[j]=max(B[j],A[i]);
		}
		printf("%d\n",N-ans);
	}
}