#include <iostream>
#include <queue>
using namespace std;
char arr[1005][1005];
bool vis[1005][1005];
int main()
{
	int r,c,ei,ex,dist=(1<<30),ans=0;
	scanf("%d%d",&r,&c);
	for (int i=0;i<r;i++)
	{
		getchar();
		for (int x=0;x<c;x++)
		{
			arr[i][x]=getchar();
			if (arr[i][x]=='E')
			{
				ei=i;
				ex=x;
			}
		}
	}
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(ei,ex),0));
	while (!q.empty())
	{
		int ci=q.front().first.first,cx=q.front().first.second,d=q.front().second;
		q.pop();
		if (ci<0 || cx<0 || ci>=r || cx>=c)
		continue;
		if (arr[ci][cx]=='T')
		continue;
		if (vis[ci][cx])
		continue;
		vis[ci][cx]=1;
		if (arr[ci][cx]=='S')
		dist=d;
		else if (d<=dist && arr[ci][cx]!='E')
		ans+=arr[ci][cx]-'0';
		for (int i=-1;i<=1;i++)
		{
			for (int x=-1;x<=1;x++)
			{
				if (i+x==1 || i+x==-1)
				q.push(make_pair(make_pair(ci+i,cx+x),d+1));
			}
		}
	}
	printf("%d",ans);
}