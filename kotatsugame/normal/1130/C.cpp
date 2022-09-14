#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int N;
char S[55][55];
bool vis[2][55][55];
int d[5]={0,1,0,-1};
void f(int x,int y,int id)
{
	vis[id][x][y]=true;
	queue<pair<int,int> >P;
	P.push(make_pair(x,y));
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop();
		for(int r=0;r<4;r++)
		{
			int tx=x+d[r],ty=y+d[r+1];
			if(tx<0||ty<0||tx>=N||ty>=N||vis[id][tx][ty]||S[tx][ty]=='1')continue;
			vis[id][tx][ty]=true;
			P.push(make_pair(tx,ty));
		}
	}
}
main()
{
	int sx,sy,gx,gy;
	scanf("%d%d%d%d%d",&N,&sx,&sy,&gx,&gy);
	sx--,sy--,gx--,gy--;
	for(int i=0;i<N;i++)scanf("%s",S[i]);
	f(sx,sy,0);
	f(gx,gy,1);
	int ans=1e9;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(vis[0][i][j])
	{
		for(int k=0;k<N;k++)for(int l=0;l<N;l++)if(vis[1][k][l])
		{
			ans=min(ans,(i-k)*(i-k)+(j-l)*(j-l));
		}
	}
	printf("%d\n",ans);
}