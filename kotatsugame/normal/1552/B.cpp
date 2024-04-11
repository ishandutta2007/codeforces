#include<cstdio>
using namespace std;
int T,N;
int R[50000][5];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<5;j++)scanf("%d",&R[i][j]);
		}
		int mi=0;
		for(int i=1;i<N;i++)
		{
			int cnt=0;
			for(int j=0;j<5;j++)
			{
				if(R[i][j]>R[mi][j])cnt++;
			}
			if(cnt<3)mi=i;
		}
		bool ok=true;
		for(int i=0;i<N;i++)if(mi!=i)
		{
			int cnt=0;
			for(int j=0;j<5;j++)if(R[i][j]>R[mi][j])cnt++;
			if(cnt<3)ok=false;
		}
		printf("%d\n",ok?mi+1:-1);
	}
}