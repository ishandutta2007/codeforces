#include<cstdio>
using namespace std;
int T,N,M;
bool A[101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=1;i<=100;i++)A[i]=false;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			A[a]=true;
		}
		int ans=0;
		for(int i=0;i<M;i++)
		{
			int b;scanf("%d",&b);
			if(A[b])ans++;
		}
		printf("%d\n",ans);
	}
}