#include<cstdio>
using namespace std;
int N,Q;
int T[2][1<<17];
main()
{
	scanf("%d%d",&N,&Q);
	int out=0;
	for(int i=0;i<Q;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		x--,y--;
		if(T[x][y]==0)
		{
			T[x][y]=1;
			for(int r=-1;r<=1;r++)
			{
				int tx=1-x,ty=y+r;
				if(ty<0||ty>=N)continue;
				if(T[tx][ty]==1)out++;
			}
		}
		else
		{
			T[x][y]=0;
			for(int r=-1;r<=1;r++)
			{
				int tx=1-x,ty=y+r;
				if(ty<0||ty>=N)continue;
				if(T[tx][ty]==1)out--;
			}
		}
		puts(out?"No":"Yes");
	}
}