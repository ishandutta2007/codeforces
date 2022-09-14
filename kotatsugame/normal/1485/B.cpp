#include<cstdio>
using namespace std;
int N,Q,K;
int A[1<<17];
int S[1<<17];
main()
{
	scanf("%d%d%d",&N,&Q,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i+1<N;i++)
	{
		S[i]=S[i-1];
		S[i]+=A[i+1]-A[i-1]-2;
	}
	for(;Q--;)
	{
		int l,r;scanf("%d%d",&l,&r);
		l--,r--;
		if(l==r)
		{
			printf("%d\n",K-1);
		}
		else
		{
			int T=S[r-1]-S[l];
			T+=A[l+1]-2;
			T+=K-A[r-1]-1;
			printf("%d\n",T);
		}
	}
}