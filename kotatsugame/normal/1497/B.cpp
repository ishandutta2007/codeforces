#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,M;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<M;i++)A[i]=0;
		for(int i=0;i<N;i++)
		{
			int X;
			scanf("%d",&X);
			A[X%M]++;
		}
		int ans=0;
		if(A[0])ans++;
		if(M%2==0&&A[M/2])ans++;
		for(int i=1;i<(M+1)/2;i++)
		{
			int x=A[i],y=A[M-i];
			if(x>y)
			{
				int t=x;x=y;y=t;
			}
			if(x==y)
			{
				if(x)ans++;
			}
			else
			{
				ans++;
				y-=x+1;
				ans+=y;
			}
		}
		printf("%d\n",ans);
	}
}