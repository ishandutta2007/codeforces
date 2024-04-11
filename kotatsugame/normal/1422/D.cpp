#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
int sx,sy,gx,gy;
int X[1<<17],Y[1<<17];
vector<int>G[1<<17];
long long dist[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
	long long ans=abs(sx-gx)+abs(sy-gy);
	vector<pair<int,int> >x(M),y(M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		x[i]=make_pair(X[i],i);
		y[i]=make_pair(Y[i],i);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=0;i<M-1;i++)
	{
		G[x[i].second].push_back(x[i+1].second);
		G[x[i+1].second].push_back(x[i].second);
		G[y[i].second].push_back(y[i+1].second);
		G[y[i+1].second].push_back(y[i].second);
	}
	priority_queue<pair<long long,int> >P;
	for(int i=0;i<M;i++)
	{
		dist[i]=min(abs(sx-X[i]),abs(sy-Y[i]));
		P.push(make_pair(-dist[i],i));
	}
	while(!P.empty())
	{
		long long cost=-P.top().first;
		int u=P.top().second;
		P.pop();
		if(dist[u]<cost)continue;
		for(int v:G[u])
		{
			long long nxt=cost+(long long)min(abs(X[u]-X[v]),abs(Y[u]-Y[v]));
			if(dist[v]>nxt)
			{
				dist[v]=nxt;
				P.push(make_pair(-nxt,v));
			}
		}
	}
	for(int i=0;i<M;i++)
	{
		ans=min(ans,dist[i]+(long long)abs(gx-X[i])+(long long)abs(gy-Y[i]));
	}
	printf("%lld\n",ans);
}