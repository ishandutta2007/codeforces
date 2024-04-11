#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,Q;
int c[251][505][505];
char s[505][505];
int xc[4][505][505];
main()
{
	scanf("%d%d%d\n",&N,&M,&Q);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)scanf("%c",&s[i][j]);
		scanf("\n");
	}
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		int id=s[i][j]=='R'?0:s[i][j]=='G'?1:s[i][j]=='Y'?2:3;
		xc[id][i+1][j+1]=min(xc[id][i][j],min(xc[id][i+1][j],xc[id][i][j+1]))+1;
	}
	for(int k=1;k<=250;k++)
	{
		for(int i=0;i+2*k<=N;i++)for(int j=0;j+2*k<=M;j++)
		{
			c[k][i+1][j+1]+=c[k][i+1][j]+c[k][i][j+1]-c[k][i][j];
			if(xc[0][i+k][j+k]>=k&&
				xc[1][i+k][j+2*k]>=k&&
				xc[2][i+2*k][j+k]>=k&&
				xc[3][i+2*k][j+2*k]>=k)c[k][i+1][j+1]++;
		}
	}
	for(;Q--;)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1--,y1--;
		int ans=0;
		for(int k=250;k>=1;k--)
		{
			int rx=x2-2*k+1;
			int ry=y2-2*k+1;
			if(x1<rx&&y1<ry)
			{
				if(c[k][rx][ry]-c[k][rx][y1]-c[k][x1][ry]+c[k][x1][y1]>0)
				{
					ans=4*k*k;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}