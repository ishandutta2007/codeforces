#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int n,m;

bool in(int x,int y)
{
	return (x>=0 && y>=0 && x<n && y<m);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	queue <pair<int,int> >que; 
	int k;
	cin>>n>>m>>k;
	int s=n*m-1;
	int x,y;
	bool visit[n][m];
	memset(visit,false,sizeof(visit));
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		que.push(make_pair(--x,--y));
		visit[x][y]=true;
	}
	while(s)
	{
		x=que.front().first;
		y=que.front().second;
		que.pop();
		s--;
//		cout<<s<<' '<<x<<' '<<y<<endl;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!in(nx,ny) || visit[nx][ny]) continue;
			visit[nx][ny]=true;
			que.push(make_pair(nx,ny));
		}
	}
	cout<<que.front().first+1<<' '<<que.front().second+1<<endl;
	return 0;
}