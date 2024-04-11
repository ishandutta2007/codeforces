#include <iostream>
#include <queue>
using namespace std;
int dist[1005][1005];
char arr[1005][1005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	getchar();
	for (int i=0;i<n;i++)
	gets(arr[i]);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		dist[i][x]=(1<<30);
	}
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(x1-1,y1-1),0));
	dist[x1-1][y1-1]=0;
	while (!q.empty())
	{
		pair<int,int> cur=q.front().first;
		int dep=q.front().second;
		q.pop();
		if (cur==make_pair(x2-1,y2-1))
		{
			printf("%d",dep);
			return 0;
		}
		for (int dx=-1;dx<=1;dx++)
		{
			for (int dy=-1;dy<=1;dy++)
			{
				if (dx+dy==-1 || dx+dy==1)
				{
					for (int j=1;j<=k;j++)
					{
						int nx=cur.first+dx*j,ny=cur.second+dy*j;
						if (nx<0 || nx>=n || ny<0 || ny>=m)
						break;
						if (arr[nx][ny]=='#' || dist[nx][ny]<dep+1)
						break;
						if (dist[nx][ny]!=dep+1)
						q.push(make_pair(make_pair(nx,ny),dep+1));
						dist[nx][ny]=dep+1;
					}
				}
			}
		}
	}
	printf("-1");
}