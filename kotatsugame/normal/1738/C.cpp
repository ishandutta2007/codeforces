#include<iostream>
using namespace std;
int memo[101][101][2];
int ev=0,od=0;
bool dfs(int x,int y,int t)
{
	if(memo[x][y][t])return memo[x][y][t]==1;
	if(x+y==0)return t==0;
	if(t==0)
	{
		bool fn=false;
		if(x>0&&!dfs(x-1,y,1-y%2))fn=true;
		if(y>0&&!dfs(x,y-1,1-y%2))fn=true;
		if(fn)memo[x][y][t]=1;
		else memo[x][y][t]=-1;
	}
	else
	{
		bool fn=false;
		if(x>0&&!dfs(x-1,y,y%2))fn=true;
		if(y>0&&!dfs(x,y-1,y%2))fn=true;
		if(fn)memo[x][y][t]=1;
		else memo[x][y][t]=-1;
	}
	return memo[x][y][t]==1;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)for(int k=0;k<2;k++)memo[i][j][k]=0;
		ev=od=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(a%2==0)ev++;
			else od++;
		}
		cout<<(dfs(ev,od,0)?"Alice\n":"Bob\n");
	}
}