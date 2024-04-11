#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
int L[2<<17],R[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=1;
	L[0]=1;
	for(int i=1;i<N;i++)
	{
		if(A[i-1]<A[i])L[i]=L[i-1]+1;
		else L[i]=1;
		ans=max(ans,L[i]);
	}
	R[N-1]=1;
	for(int i=N-1;i--;)
	{
		if(A[i]<A[i+1])R[i]=R[i+1]+1;
		else R[i]=1;
		ans=max(ans,R[i]);
	}
	for(int i=1;i<N-1;i++)
	{
		if(A[i-1]<A[i+1])ans=max(ans,L[i-1]+R[i+1]);
	}
	printf("%d\n",ans);
}