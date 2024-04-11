#include<bits/stdc++.h>
using namespace std;
const int N=50;
char a[N+5][N+5];
bool vis[N+5][N+5],flag;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
bool check(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return true;
	return false;
}
void dfs(int x,int y,int fax,int fay)
{
	if(check(x,y)) return;
	if(a[x][y]!=a[fax][fay]) return;
	if(vis[x][y]) 
	{
		flag=1;
		return;
	}
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==fax&&ny==fay) continue;
		dfs(nx,ny,x,y);
		if(flag) return;
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++) 
		{
			if(!vis[i][j]) dfs(i,j,i,j);
			if(flag) break;
		}	
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}