#include<cstdio>
using namespace std;
int N,M,K;
char S[1010][1010];
int vis[1010][1010];
int cnt[1<<20];
int d[5]={0,1,0,-1};
void dfs(int x,int y,int id)
{
	vis[x][y]=id;
	for(int r=0;r<4;r++)
	{
		int tx=x+d[r],ty=y+d[r+1];
		if(S[tx][ty]=='*')cnt[id]++;
		else if(!vis[tx][ty])
		{
			dfs(tx,ty,id);
		}
	}
}
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++)scanf("%s",S[i]);
	int sz=0;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(S[i][j]=='.'&&!vis[i][j])
	{
		++sz;
		dfs(i,j,sz);
	}
	for(;K--;)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",cnt[vis[x-1][y-1]]);
	}
}