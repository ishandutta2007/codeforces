#include<cstdio>
using namespace std;
int N,M;
int A[2<<17];
int nxt[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	nxt[N-1]=N;
	for(int i=N-1;i--;)
	{
		if(A[i]!=A[i+1])nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	for(;M--;)
	{
		int L,R,X;
		scanf("%d%d%d",&L,&R,&X);
		L--;
		int ans;
		if(A[L]!=X)ans=L;
		else ans=nxt[L];
		printf("%d\n",ans<R?ans+1:-1);
	}
}