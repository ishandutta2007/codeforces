#include<cstdio>
#include<queue>
using namespace std;
int N,M;
int C[600][600];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)C[i][j]=2e9;
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		C[a][b]=c;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<2*N;j++)
		{
			int u=j%N,v=u==N-1?0:u+1;
			if(C[i][v]>C[i][u]+1)C[i][v]=C[i][u]+1;
		}
	}
	for(int st=0;st<N;st++)
	{
		int dist[600];
		for(int i=0;i<N;i++)dist[i]=2e9;
		dist[st]=0;
		priority_queue<pair<int,int> >P;
		P.push(make_pair(0,st));
		while(!P.empty())
		{
			int u=P.top().second;
			int c=-P.top().first;
			P.pop();
			if(dist[u]<c)continue;
			int tm=c%N;
			for(int v=0;v<N;v++)if(C[u][v]<(int)2e9)
			{
				if(dist[tm]>c+C[u][v])
				{
					dist[tm]=c+C[u][v];
					P.push(make_pair(-dist[tm],tm));
				}
				tm++;
				if(tm==N)tm=0;
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",dist[i],i+1==N?10:32);
	}
}