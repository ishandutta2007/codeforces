#include<cstdio>
using namespace std;
int N;
long long A[30][30];
main()
{
	scanf("%d",&N);
	for(int i=1;i<2*N-1;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int x=j,y=i-j;
			if(x<0||y<0||x>=N||y>=N)continue;
			A[x][y]=x%2==1?0:(1LL<<(i-1));
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)printf("%lld%c",A[i][j],j+1==N?'\n':' ');
	}
	fflush(stdout);
	int Q;scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		long long K;
		scanf("%lld",&K);
		printf("1 1\n");
		int x=0,y=0;
		for(int j=1;j<2*N-1;j++)
		{
			if((K>>(j-1))&1LL)
			{
				if((x+1)%2==0)x++;
				else y++;
			}
			else
			{
				if((x+1)%2==0)y++;
				else x++;
			}
			printf("%d %d\n",x+1,y+1);
		}
		fflush(stdout);
	}
}