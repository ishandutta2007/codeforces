#include<cstdio>
using namespace std;
int N,M,A[2<<17],B[2<<17];
int L[2<<17],R[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<M;i++)scanf("%d",&B[i]);
	for(int i=0;i<M;i++)L[i]=R[i]=-1;
	int bi=M-1;
	long long ans=1;
	for(int i=N;i--;)
	{
		while(bi>=0&&B[bi]>A[i])bi--;
		if(bi<0)
		{
			ans=0;
			break;
		}
		L[bi]=i;
		if(A[i]==B[bi])
		{
			if(R[bi]==-1)R[bi]=i;
		}
	}
	if(L[0]==-1||R[0]==-1)ans=0;
	for(int i=1;i<M;i++)
	{
		if(L[i]==-1||R[i]==-1)ans=0;
		else
		{
			ans*=R[i]-L[i]+1;
			ans%=998244353;
		}
	}
	printf("%lld\n",ans);
}