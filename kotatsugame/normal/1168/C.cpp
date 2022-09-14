#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,Q;
int A[3<<17];
const int B=19;
vector<int>G[B][B];
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<B;i++)for(int j=i+1;j<B;j++)G[i][j].assign(N,N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		for(int j=0;j<B;j++)if(A[i]>>j&1)for(int k=j+1;k<B;k++)if(A[i]>>k&1)
		{
			G[j][k][i]=i;
		}
	}
	for(int i=0;i<B;i++)for(int j=i+1;j<B;j++)
	{
		for(int k=N-1;k--;)
		{
			if(G[i][j][k]==N)G[i][j][k]=G[i][j][k+1];
		}
	}
	for(;Q--;)
	{
		int st,go;scanf("%d%d",&st,&go);st--,go--;
		if(A[st]==0||A[go]==0)
		{
			puts("Fou");
			continue;
		}
		if(A[st]&A[go])
		{
			puts("Shi");
			continue;
		}
		vector<int>dist(B,N);
		priority_queue<pair<int,int> >P;
		for(int i=0;i<B;i++)if(A[st]>>i&1)
		{
			dist[i]=st;
			P.push(make_pair(-st,i));
		}
		int ans=N;
		while(!P.empty())
		{
			int cost=-P.top().first,u=P.top().second;
			P.pop();
			if(dist[u]<cost)continue;
			if(A[go]>>u&1)
			{
				ans=cost;
				break;
			}
			for(int v=0;v<B;v++)if(dist[v]>dist[u])
			{
				int nu=u,nv=v;
				if(nu>nv)swap(nu,nv);
				int nxt=G[nu][nv][dist[u]];
				if(dist[v]>nxt)
				{
					dist[v]=nxt;
					P.push(make_pair(-dist[v],v));
				}
			}
		}
		puts(ans<=go?"Shi":"Fou");
	}
}