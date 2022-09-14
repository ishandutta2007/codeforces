#include<cstdio>
#include<queue>
using namespace std;
int N,M,T;
char mp[1000][1001];
int dist[1000][1000];
int d[4]={0,1,0,-1};
main()
{
	scanf("%d%d%d\n",&N,&M,&T);
	for(int i=0;i<N;i++)
	{
		scanf("%s\n",mp[i]);
	}
	queue<pair<int,int> >P;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		dist[i][j]=1e9;
		for(int r=0;r<4;r++)
		{
			int x=i+d[r],y=j+d[r^1];
			if(0<=x&&x<N&&0<=y&&y<M&&mp[x][y]==mp[i][j])dist[i][j]=0;
		}
		if(dist[i][j]==0)
		{
			P.push(make_pair(i,j));
		}
	}
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop();
		for(int r=0;r<4;r++)
		{
			int tx=x+d[r],ty=y+d[r^1];
			if(0<=tx&&tx<N&&0<=ty&&ty<M&&dist[tx][ty]>dist[x][y]+1)
			{
				dist[tx][ty]=dist[x][y]+1;
				P.push(make_pair(tx,ty));
			}
		}
	}
	for(;T--;)
	{
		int x,y;
		long long p;
		scanf("%d%d%lld",&x,&y,&p);
		x--,y--;
		char ans;
		if(dist[x][y]<(int)1e9)
		{
			if(p<dist[x][y])ans=mp[x][y];
			else
			{
				if((p-dist[x][y])%2==0)ans=mp[x][y];
				else ans=mp[x][y]^'0'^'1';
			}
		}
		else ans=mp[x][y];
		putchar(ans);
		putchar('\n');
	}
}