#include<bits/stdc++.h>
using namespace std;
int d,s,x,y;
int get(int i,int j)
{
	return i*(s+1)+j+1;
}
vector<int> g[3333333];
int dist[3333333];
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	memset(dist,-1,sizeof(dist));
	dist[x]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to); 
			}
		}
	} 
}
int main()
{
	scanf("%d%d",&d,&s);
	for (int i=0;i<d;i++)
	{
		for (int j=0;j<=s;j++)
		{
			for (int k=0;k<=9;k++)
			{
				if (j+k<=s) g[get((i*10+k)%d,j+k)].push_back(get(i,j));
			}
		}
	}
	bfs(get(0,s));
	if (!~dist[get(0,0)]) 
	{
		printf("-1\n");
		return 0;
	}
	x=0;y=0;
	while(x!=0 || y!=s)
	{
		for (int i=0;i<=9;i++)
		{
			if (dist[get((x*10+i)%d,i+y)]==dist[get(x,y)]-1) 
			{
				printf("%d",i);
				x=(x*10+i)%d;y+=i;
				break;
			}
		}
	}
	printf("\n");
	return 0;
}