#include<cstdio>
using namespace std;
int T,N,M;
int A[30][30];
int cnt[100][2];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<100;i++)cnt[i][0]=cnt[i][1]=0;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
			int d=i+j;
			int e=N-i-1+M-j-1;
			if(d>e)d=e;
			cnt[d][A[i][j]]++;
		}
		int ans=0;
		for(int k=0;k<100;k++)
		{
			if(N+M-2!=k*2)
			{
				int x=cnt[k][0],y=cnt[k][1];
				if(x<y)ans+=x;
				else ans+=y;
			}
		}
		printf("%d\n",ans);
	}
}