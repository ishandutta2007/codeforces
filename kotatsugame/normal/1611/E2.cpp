#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N,K;
vector<int>G[2<<17];
vector<int>dist(vector<int>st)
{
	vector<int>ret(N,(int)1e9);
	queue<int>P;
	for(int u:st)
	{
		P.push(u);
		ret[u]=0;
	}
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(int v:G[u])if(ret[v]>ret[u]+1)
		{
			ret[v]=ret[u]+1;
			P.push(v);
		}
	}
	return ret;
}
bool vis[2<<17];
main()
{
	scanf("%d",&T);
	vector<int>now,nxt;
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		vector<int>x(K);
		for(int i=0;i<K;i++)
		{
			scanf("%d",&x[i]);
			x[i]--;
		}
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int>B=dist(x);
		for(int i=0;i<N;i++)vis[i]=false;
		now.clear();
		now.push_back(0);
		vis[0]=true;
		bool out=false;
		int d=0;
		int ans=0;
		while(!now.empty())
		{
			nxt.clear();
			++d;
			for(int u:now)
			{
				if(u!=0&&G[u].size()==1)
				{
					out=true;
					break;
				}
				for(int v:G[u])if(!vis[v])
				{
					vis[v]=true;
					if(d>=B[v])ans++;
					else nxt.push_back(v);
				}
			}
			if(out)break;
			now.swap(nxt);
		}
		printf("%d\n",out?-1:ans);
	}
}