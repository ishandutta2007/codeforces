#include<bits/stdc++.h>
using namespace std;
const int N=100;
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,-1,1,1,-1};
int a,b,c,d;
int vis[N+5][N+5];
bool calc(int x,int y,int k)
{
	if(x<1||x>50||y<1||y>50) return true;
	if(vis[x][y]==k) return true;
	return false;
}
bool check(int x,int y,int k)
{
	for(int i=0;i<=7;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(calc(nx,ny,k)) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a--;
	b--;
	c--;
	d--;
	printf("50 50\n");
	for(int i=1;i<=25;i++) for(int j=1;j<=25;j++) vis[i][j]=1;
	for(int i=26;i<=50;i++) for(int j=1;j<=25;j++) vis[i][j]=2;
	for(int i=26;i<=50;i++) for(int j=26;j<=50;j++) vis[i][j]=3;
	for(int i=1;i<=25;i++) for(int j=26;j<=50;j++) vis[i][j]=4;
	for(int i=2;i<=24;i++)
	{
		for(int j=2;j<=24;j++)
		{
			if(b==0) break;
			if(check(i,j,2))
			{
				vis[i][j]=2;
				b--;
			}
		}
	}
	for(int i=27;i<=49;i++)
	{
		for(int j=2;j<=24;j++)
		{
			if(c==0) break;
			if(check(i,j,3))
			{
				vis[i][j]=3;
				c--;
			}
		}
	}
	for(int i=27;i<=49;i++)
	{
		for(int j=27;j<=49;j++)
		{
			if(d==0) break;
			if(check(i,j,4))
			{
				vis[i][j]=4;
				d--;
			}
		}
	}
	for(int i=2;i<=24;i++)
	{
		for(int j=27;j<=49;j++)
		{
			if(a==0) break;
			if(check(i,j,1))
			{
				vis[i][j]=1;
				a--;
			}
		}
	}
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			if(vis[i][j]==1) printf("A");
			if(vis[i][j]==2) printf("B");
			if(vis[i][j]==3) printf("C");
			if(vis[i][j]==4) printf("D");
		}
		printf("\n");
	}
	return 0;		
}