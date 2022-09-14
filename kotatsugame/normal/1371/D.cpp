#include<cstdio>
using namespace std;
int T,N,K;
int A[333][333];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)A[i][j]=0;
		int cnt=0;
		for(int k=0;k<N;k++)for(int i=0;i<N;i++)
		{
			if(cnt<K)
			{
				cnt++;
				A[i][(i+k)%N]=1;
			}
		}
		int f=0;
		if(K%N!=0)
		{
			f=2;
		}
		printf("%d\n",f);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)printf("%d",A[i][j]);
			printf("\n");
		}
	}
}