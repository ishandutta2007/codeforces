#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[1<<17],B[1<<17],T[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	long long S=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
		T[i]=B[i]-A[i];
		S+=A[i];
	}
	sort(T,T+N);
	int id=0;
	while(S>M)
	{
		if(id==N)
		{
			puts("-1");
			return 0;
		}
		S+=T[id++];
	}
	printf("%d\n",id);
}