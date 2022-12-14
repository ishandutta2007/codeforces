#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,cnt,ct;
char s[1111][1111];
bool flg,used[1111][1111],h[1111],v[1111];
bool In(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}
void dfs(int x,int y)
{
	used[x][y]=1;h[x]=v[y]=1;
	for (int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if (!In(xx,yy) || used[xx][yy] || s[xx][yy]=='.') continue;
		dfs(xx,yy);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for (int i=0;i<n;i++)
	{
		cnt=0;
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='#' && (!j || s[i][j-1]=='.')) cnt++;
		}
		if (cnt>1) 
		{
			flg=1;
			break;
		}
	}
	for (int j=0;j<m;j++)
	{
		cnt=0;
		for (int i=0;i<n;i++)
		{
			if (s[i][j]=='#' && (!i || s[i-1][j]=='.')) cnt++;
		}
		if (cnt>1) 
		{
			flg=1;
			break;
		}
	}
	if (flg)
	{
		printf("-1\n");
		return 0;
	}
	cnt=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='.') continue;
			if (!used[i][j]) 
			{
				cnt++;
				dfs(i,j);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (!h[i] && !v[j]) s[i][j]='#';
		}
	}
	for (int i=0;i<n;i++)
	{
		ct=0;
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='#') ct++;
		}
		if (!ct) flg=1;
	}
	for (int j=0;j<m;j++)
	{
		ct=0;
		for (int i=0;i<n;i++)
		{
			if (s[i][j]=='#') ct++;
		}
		if (!ct) flg=1;
	}
	if (flg)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",cnt);
	return 0;
}