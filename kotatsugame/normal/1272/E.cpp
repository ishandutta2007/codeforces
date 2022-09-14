#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,A[2<<17];
int dist[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<N;i++)dist[i]=1e9;
	for(int r=0;r<2;r++)
	{
		vector<vector<int> >G(N+1);
		for(int i=0;i<N;i++)if(A[i]%2==r)
		{
			if(i-A[i]>=0)
			{
				int j=i-A[i];
				if(A[j]%2==r)G[j].push_back(i);
				else G[N].push_back(i);
			}
			if(i+A[i]<N)
			{
				int j=i+A[i];
				if(A[j]%2==r)G[j].push_back(i);
				else G[N].push_back(i);
			}
		}
		queue<int>P;
		P.push(N);
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				P.push(v);
			}
		}
	}
	for(int i=0;i<N;i++)printf("%d%c",dist[i]<(int)1e9?dist[i]:-1,i+1==N?10:32);
}