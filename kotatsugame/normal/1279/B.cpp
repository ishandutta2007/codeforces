#include<cstdio>
using namespace std;
int t;
int N;
long long S,A[1<<17];
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%lld",&N,&S);
		for(int i=0;i<N;i++)scanf("%lld",&A[i]);
		long long T=0;
		int i=0,id=0;
		long long m=-1;
		for(;i<N;i++)
		{
			T+=A[i];
			if(A[id]<A[i])id=i;
			if(T>S)break;
		}
		if(i==N)
		{
			puts("0");
			continue;
		}
		if(T-A[id]+A[i+1]<=S)printf("%d\n",id+1);
		else puts("0");
	}
}