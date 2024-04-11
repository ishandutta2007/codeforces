#include<cstdio>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int T,N;
char S[333][333];
char A[333][333];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d\n",&N);
		int all=0;
		for(int i=0;i<N;i++)
		{
			scanf("%s\n",S[i]);
			for(int j=0;j<N;j++)if(S[i][j]!='.')all++;
		}
		for(int k=0;k<3;k++)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<=N;j++)
				{
					A[i][j]=S[i][j];
				}
			}
			int cnt=0;
			for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			{
				if((i+j)%3==k)
				{
					if(A[i][j]=='O')
					{
						A[i][j]='X';
						cnt++;
					}
				}
				if((i+j)%3==(k+1)%3)
				{
					if(A[i][j]=='X')
					{
						A[i][j]='O';
						cnt++;
					}
				}
			}
			if(cnt<=all/3)
			{
				for(int i=0;i<N;i++)puts(A[i]);
				break;
			}
		}
	}
}