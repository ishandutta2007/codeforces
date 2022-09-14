#include<cstdio>
using namespace std;
int T,N;
int P[1010];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		if(N>=4)
		{
			int sz=0;
			for(int i=2-N%2;i<=N;i+=2)P[sz++]=i;
			P[sz++]=N-3;
			P[sz++]=N-1;
			for(int i=N-5;i>=1;i-=2)P[sz++]=i;
			for(int i=0;i<N;i++)printf("%d%c",P[i],i+1==N?10:32);
		}
		else
		{
			puts("-1");
			continue;
		}
	}
}