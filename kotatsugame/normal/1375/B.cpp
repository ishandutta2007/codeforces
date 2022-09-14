#include<cstdio>
using namespace std;
int T,N,M;
int A[300][300];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		bool ok=true;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
			int cnt=0;
			for(int r=0;r<4;r++)
			{
				int x=i+dx[r],y=j+dy[r];
				if(0<=x&&x<N&&0<=y&&y<M)cnt++;
			}
			if(A[i][j]>cnt)ok=false;
			else A[i][j]=cnt;
		}
		if(ok)
		{
			puts("YES");
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)printf("%d%c",A[i][j],j+1==M?'\n':' ');
			}
		}
		else puts("NO");
	}
}