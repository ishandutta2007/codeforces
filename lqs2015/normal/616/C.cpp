#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
char ans[1111][1111];
int q[2222222];
int u[1111][1111];
int v[1111111];
int ql,qr,l,n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool in(int i,int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}
void pu(int i,int j)
{
	if (u[i][j]==0)
	{
		u[i][j]=l;
		q[qr++]=i;
		q[qr++]=j;
	}
}
void bfs(int i,int j)
{
	ql=qr=0;
	l++;
	pu(i,j);
	while(ql<qr)
	{
		i=q[ql];ql++;
		j=q[ql];ql++;
		for (int ii=0;ii<4;ii++)
		{
			int x=i+dx[ii];
			int y=j+dy[ii];
			if (in(x,y) && ans[x][y]=='.' && u[x][y]==0)
			{
				pu(x,y);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",&ans[i]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (ans[i][j]=='.' && u[i][j]==0) bfs(i,j);
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		v[u[i][j]]++;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (ans[i][j]=='*')
			{
				int a[4],t=0;
				for (int k=0;k<4;k++)
				{
					int ii=i+dx[k];
					int jj=j+dy[k];
					if (in(ii,jj) && ans[ii][jj]=='.') a[t++]=u[ii][jj];
				}
				sort(a,a+t);
				t=unique(a,a+t)-a;
				int x=1;
				for (int k=0;k<t;k++)
				{
					x+=v[a[k]];
				}
				ans[i][j]='0'+(x%10);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
}