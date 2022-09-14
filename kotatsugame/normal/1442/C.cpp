#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const long long mod=998244353;
int N,M;
vector<pair<int,bool> >G[2<<17];
const int LIM=20;
int dist[2<<17][LIM];
pair<int,int>dist2[2<<17][2];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(make_pair(v,false));
		G[v].push_back(make_pair(u,true));
	}
	for(int i=0;i<N;i++)for(int j=0;j<LIM;j++)dist[i][j]=1e9;
	for(int i=0;i<N;i++)dist2[i][0]=dist2[i][1]=make_pair((int)1e9,(int)1e9);
	dist[0][0]=0;
	long long ans=-1;
	for(int k=0;k<LIM-1;k++)
	{
		priority_queue<pair<int,int> >P;
		for(int i=0;i<N;i++)if(dist[i][k]<(int)1e9)P.push(make_pair(-dist[i][k],i));
		while(!P.empty())
		{
			int cost=-P.top().first,u=P.top().second;
			P.pop();
			if(dist[u][k]<cost)continue;
			for(pair<int,bool>e:G[u])
			{
				int v=e.first;
				if(k%2==1?e.second:!e.second)
				{
					if(dist[v][k]>cost+1)
					{
						dist[v][k]=cost+1;
						P.push(make_pair(-cost-1,v));
					}
				}
				else
				{
					if(dist[v][k+1]>cost+1)
					{
						dist[v][k+1]=cost+1;
					}
				}
			}
		}
		if(dist[N-1][k]<(int)1e9)
		{
			long long now=(1LL<<k)-1+dist[N-1][k];
			if(ans==-1||ans>now)ans=now;
		}
	}
	priority_queue<pair<pair<int,int>,int> >P;
	for(int i=0;i<N;i++)
	{
		if(dist[i][LIM-2]<(int)1e9)
		{
			dist2[i][(LIM-2)%2]=make_pair(LIM-2,dist[i][LIM-2]);
			P.push(make_pair(make_pair(-LIM+2,-dist[i][LIM-2]),i));
		}
		if(dist[i][LIM-1]<(int)1e9)
		{
			dist2[i][(LIM-1)%2]=make_pair(LIM-1,dist[i][LIM-1]);
			P.push(make_pair(make_pair(-LIM+1,-dist[i][LIM-1]),i));
		}
	}
	while(!P.empty())
	{
		int A=-P.top().first.first,B=-P.top().first.second,u=P.top().second;
		P.pop();
		if(dist2[u][A%2]<make_pair(A,B))continue;
		for(pair<int,bool>e:G[u])
		{
			int v=e.first;
			int nA=A,nB=B+1;
			if(A%2==1?!e.second:e.second)nA++;
			if(dist2[v][nA%2]>make_pair(nA,nB))
			{
				dist2[v][nA%2]=make_pair(nA,nB);
				P.push(make_pair(make_pair(-nA,-nB),v));
			}
		}
	}
	if(ans>=0)printf("%lld\n",ans%mod);
	else
	{
		pair<int,int>p=dist2[N-1][0];
		pair<int,int>q=dist2[N-1][1];
		if(p>q)p=q;
		long long ans=1;
		for(int i=0;i<p.first;i++)ans=ans*2%mod;
		ans=(ans+mod-1+p.second)%mod;
		printf("%lld\n",ans);
	}
}