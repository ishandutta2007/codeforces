#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[1<<17],B[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<M;i++)scanf("%d",&B[i]);
	sort(A,A+N);
	sort(B,B+M);
	int bi=0;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		while(bi<M&&B[bi]<A[i])bi++;
		int now=2e9;
		if(bi<M)now=min(now,B[bi]-A[i]);
		if(bi>0)now=min(now,A[i]-B[bi-1]);
		ans=max(ans,now);
	}
	printf("%d\n",ans);
}