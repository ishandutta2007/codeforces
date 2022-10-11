#include <iostream>
#include <string.h>
#include <deque>
using namespace std;
#define x first
#define y second
char arr[2005][2005];
int dist[2005][2005];
int main()
{
	int n,m,sx,sy,l,r;
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&l,&r);
	sx--;
	sy--;
	getchar();
	for (int i=0;i<n;i++)
	gets(arr[i]);
	memset(dist,-1,sizeof(dist));
	deque<pair<int,pair<int,int> > > d;
	d.push_back({0,{sx,sy}});
	dist[sx][sy]=0;
	while (!d.empty())
	{
		int dep=d.front().first;
		auto c=d.front().second;
		d.pop_front();
		for (int dx=-1;dx<=1;dx++)
		{
			for (int dy=-1;dy<=1;dy++)
			{
				if (abs(dx)+abs(dy)==1 && c.x+dx>=0 && c.x+dx<n && c.y+dy>=0 && c.y+dy<m && arr[c.x+dx][c.y+dy]=='.')
				{
					int tmp=dist[c.x+dx][c.y+dy];
					if (tmp==-1 || dep+(dy==1)<tmp)
					{
						if (dy==1)
						d.push_back({dep+1,{c.x+dx,c.y+dy}});
						else
						d.push_front({dep,{c.x+dx,c.y+dy}});
						dist[c.x+dx][c.y+dy]=dep+(dy==1);
					}
				}
			}
		}
	}
	int ans=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		ans+=(dist[i][j]!=-1 && dist[i][j]<=r && sy+dist[i][j]-j<=l);
	}
	printf("%d",ans);
}