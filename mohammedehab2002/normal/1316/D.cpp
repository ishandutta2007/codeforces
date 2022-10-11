#include <bits/stdc++.h>
using namespace std;
string ans[1005];
pair<int,int> d[1005][1005];
int n,darr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char c[4]={'R','L','D','U'};
void go(int sx,int sy)
{
	if (ans[sx][sy]!='.')
	{
		if (ans[sx][sy]!='X')
		{
			printf("INVALID");
			exit(0);
		}
		return;
	}
	if (d[sx][sy].first!=sx+1 || d[sx][sy].second!=sy+1)
	{
		printf("INVALID");
		exit(0);
	}
	ans[sx][sy]='X';
	queue<pair<int,int> > q;
	q.push({sx,sy});
	while (!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for (int i=0;i<4;i++)
		{
			int nx=x-darr[i][0],ny=y-darr[i][1];
			if (nx>=0 && nx<n && ny>=0 && ny<n && ans[nx][ny]=='.' && d[nx][ny]==d[x][y])
			{
				q.push({nx,ny});
				ans[nx][ny]=c[i];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		ans[i]=string(n,'.');
		for (int j=0;j<n;j++)
		scanf("%d%d",&d[i][j].first,&d[i][j].second);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (d[i][j].first!=-1)
			go(d[i][j].first-1,d[i][j].second-1);
			else if (ans[i][j]=='.')
			{
				for (int k=0;k<4;k++)
				{
					int ni=i-darr[k][0],nj=j-darr[k][1];
					if (ni>=0 && ni<n && nj>=0 && nj<n && d[ni][nj].first==-1)
					{
						ans[i][j]=c[k^1];
						if (ans[ni][nj]=='.')
						ans[ni][nj]=c[k];
						break;
					}
				}
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (ans[i][j]=='.')
			{
				printf("INVALID");
				exit(0);
			}
		}
	}
	puts("VALID");
	for (int i=0;i<n;i++)
	puts(ans[i].c_str());
}