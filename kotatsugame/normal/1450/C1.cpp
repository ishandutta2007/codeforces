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
		for(int i=0;i<N;i++)scanf("%s\n",S[i]);
		for(int k=0;k<3;k++)
		{
			int all=0,cnt=0;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<=N;j++)
				{
					A[i][j]=S[i][j];
					if(S[i][j]=='X')all++;
				}
			}
			for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(((i-j)%3+3)%3==k)
			{
				if(A[i][j]=='.')continue;
				bool fn=false;
				for(int r=0;r<4;r++)if(i+dx[r]*2>=0&&i+dx[r]*2<N&&j+dy[r]*2>=0&&j+dy[r]*2<N)
				{
					if(A[i+dx[r]][j+dy[r]]!='X')continue;
					if(A[i+dx[r]*2][j+dy[r]*2]!='X')continue;
					fn=true;
				}
				if(0<i&&i+1<N&&A[i-1][j]=='X'&&A[i+1][j]=='X')fn=true;
				if(0<j&&j+1<N&&A[i][j-1]=='X'&&A[i][j+1]=='X')fn=true;
				if(fn)
				{
					cnt++;
					A[i][j]='O';
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