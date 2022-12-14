#include<iostream>
using namespace std;
bool dp[31][311][311][9],vis[311][311];
int n,t[33],ans;
int d1[9]={1,0,1,0,-1,2,3,6,5};
int d2[9]={3,2,5,6,-1,8,7,8,7}; 
void Search(int dep,int x,int y,int dir)
{
	if (dep>n) return;
	if (dp[dep][x][y][dir]) return;
	dp[dep][x][y][dir]=1;
	if (!vis[x][y]) ans++;
	vis[x][y]=1;
	int xx=dir/3-1,yy=dir%3-1,px=x,py=y;
	for (int i=1;i<t[dep];i++)
	{
		px+=xx;
		py+=yy;
		if (!vis[px][py]) ans++;
		vis[px][py]=1;
	}	
	int dir1=d1[dir],dir2=d2[dir];
	Search(dep+1,px+dir1/3-1,py+dir1%3-1,dir1);
	Search(dep+1,px+dir2/3-1,py+dir2%3-1,dir2);
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	Search(1,152,152,1);
	cout<<ans<<endl;
	return 0;
}