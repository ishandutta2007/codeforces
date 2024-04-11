#include<iostream>
#include<queue>
using namespace std;
int dist[1<<15];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=0;i<1<<15;i++)dist[i]=1e9;
	dist[0]=0;
	queue<int>P;
	P.push(0);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		{
			int v=(u+(1<<15)-1)&(1<<15)-1;
			if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				P.push(v);
			}
		}
		if(u%2==0)
		{
			{
				int v=u/2;
				if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					P.push(v);
				}
			}
			{
				int v=(u|1<<15)/2;
				if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					P.push(v);
				}
			}
		}
	}
	int N;cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		cout<<dist[a]<<(i+1==N?"\n":" ");
	}
}