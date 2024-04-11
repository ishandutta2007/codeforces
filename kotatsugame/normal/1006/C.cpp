#include<cstdio>
using namespace std;
int N,A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	long long L=0,R=0;
	int r=N;
	long long ans=0;
	for(int l=0;l<N;l++)
	{
		L+=A[l];
		while(L>R&&r>0)R+=A[--r];
		if(r<=l)break;
		if(L==R)ans=L;
	}
	printf("%lld\n",ans);
}