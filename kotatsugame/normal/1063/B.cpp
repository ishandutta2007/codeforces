#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
int N,M,sx,sy;
int X,Y;
char S[2020][2020];
int dist[2020][2020];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[2020][2020];
main()
{
	scanf("%d%d%d%d%d%d",&N,&M,&sx,&sy,&X,&Y);
	sx--,sy--;
	for(int i=0;i<N;i++)
	{
		scanf("%s",S[i]);
		for(int j=0;j<M;j++)dist[i][j]=2e9;
	}
	dist[sx][sy]=0;
	deque<pair<int,int> >P;
	P.push_back(make_pair(sx,sy));
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop_front();
		if(vis[x][y])continue;
		vis[x][y]=true;
		for(int r=0;r<4;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(tx<0||ty<0||tx>=N||ty>=M||S[tx][ty]=='*'||vis[tx][ty])continue;
			int nxt=dist[x][y];
			int c=0;
			if(abs(sy-y)>abs(sy-ty))c=1;
			if(dist[tx][ty]>nxt+c)
			{
				dist[tx][ty]=nxt+c;
				if(c==0)P.push_front(make_pair(tx,ty));
				else P.push_back(make_pair(tx,ty));
			}
		}
	}
	int cnt=0;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(dist[i][j]<(int)2e9)
	{
		int x=dist[i][j],y=dist[i][j];
		if(j<sy)x+=sy-j;
		else y+=j-sy;
		if(x<=X&&y<=Y)cnt++;
	}
	printf("%d\n",cnt);
}