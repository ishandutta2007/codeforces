#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[410][410],i,j,k1,k2;
	for(i=0;i<m;i++)
	{
		cin>>k1>>k2;
		a[--k1][--k2]=1;
		a[k2][k1]=1;
	}
	if(a[0][n-1])
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]^=1;
			}
		}
	}
	int dist[n];
	fill(dist,dist+n,2147483647);
	dist[0]=0;
	queue <int> que;
	que.push(0);
	while(!que.empty())
	{
		int k=que.front();
		que.pop();
		if(k==n-1)
		{
			cout<<dist[k]<<endl;
			return 0;
		}
		for(i=0;i<n;i++)
		{
			if(a[k][i] && dist[i]==2147483647)
			{
				dist[i]=dist[k]+1;
				que.push(i);
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}