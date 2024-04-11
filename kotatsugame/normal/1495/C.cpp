#include<iostream>
using namespace std;
int T,N,M;
char S[505][505];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
		{
			scanf("%s",S[i]);
			if(i%3==0)
			{
				for(int j=0;j<M;j++)S[i][j]='X';
			}
		}
		for(int t=3;t<N;t+=3)
		{
			int j=0;
			while(j<M-1)
			{
				if(S[t-2][j]=='X'||S[t-1][j]=='X')break;
				j++;
			}
			S[t-2][j]=S[t-1][j]='X';
		}
		if(N%3==0)
		{
			for(int j=0;j<M;j++)
			{
				if(S[N-2][j]=='X'||S[N-1][j]=='X')
				{
					S[N-2][j]=S[N-1][j]='X';
				}
			}
		}
		for(int i=0;i<N;i++)puts(S[i]);
	}
}