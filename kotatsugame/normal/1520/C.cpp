#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[100][100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			int t=i*N;
			int x=i,y=0;
			for(int j=0;j<N;j++)
			{
				A[x][y]=++t;
				x=++x%N;
				y=++y%N;
			}
		}
		bool ok=true;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
		{
			if(i&&abs(A[i-1][j]-A[i][j])==1)ok=false;
			if(j&&abs(A[i][j-1]-A[i][j])==1)ok=false;
		}
		if(ok)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)printf("%d%c",A[i][j],j+1==N?10:32);
			}
		}
		else puts("-1");
	}
}