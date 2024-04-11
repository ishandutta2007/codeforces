#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[1<<17];
int B[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	long long ans=0;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	for(int i=0;i<M;i++)scanf("%d",&B[i]);
	sort(B,B+M);
	if(B[0]<A[N-1])
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<N;i++)ans+=(long long)A[i]*M;
	if(B[0]==A[N-1])ans+=B[0]-A[N-1];
	else ans+=B[0]-A[N-2];
	for(int i=1;i<M;i++)ans+=B[i]-A[N-1];
	printf("%lld\n",ans);
}