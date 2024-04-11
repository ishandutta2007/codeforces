#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int N,M;
vector<int>G[400];
int dist[400][400];
int indeg[400][400];
int pr[400][400];
bool ng[400][400];
long long ans[400][400];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)dist[i][j]=1e9;
		pr[i][i]=-1;
		ng[i][i]=false;
		indeg[i][i]=1;
		queue<int>P;
		P.push(i);
		dist[i][i]=0;
		while(!P.empty())
		{
			int u=P.front();P.pop();
			if(indeg[i][u]>=2)ng[i][u]=true;
			for(int v:G[u])
			{
				if(dist[i][v]>dist[i][u]+1)
				{
					dist[i][v]=dist[i][u]+1;
					P.push(v);
				}
				if(dist[i][v]==dist[i][u]+1)
				{
					indeg[i][v]++;
					pr[i][v]=u;
					if(ng[i][u])ng[i][v]=true;
				}
			}
		}
		ans[i][i]=1;
		for(int j=0;j<N;j++)
		{
			ans[i][i]=ans[i][i]*indeg[i][j]%mod;
		}
	}
	for(int x=0;x<N;x++)for(int y=0;y<N;y++)if(x!=y&&!ng[x][y])
	{
		queue<int>P;
		vector<int>vs;
		vector<int>deg(N,0);
		{
			int now=y;
			P.push(now);
			vs.push_back(now);
			deg[now]=1;
			while(now!=x)
			{
				now=pr[x][now];
				P.push(now);
				vs.push_back(now);
				deg[now]=1;
			}
		}
		reverse(vs.begin(),vs.end());
		vector<int>col(N);
		int D=dist[x][y];
		bool out=false;
		for(int i=0;i<N;i++)
		{
			int L=dist[x][i]-dist[y][i]+D;
			if(L%2==1||L<0||L>2*D)out=true;
			else col[i]=L/2;
		}
		if(out)continue;
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])if(col[u]==col[v]
				&&dist[x][v]==dist[x][u]+1
				&&dist[y][v]==dist[y][u]+1)
			{
				if(!deg[v]++)P.push(v);
			}
		}
		ans[x][y]=1;
		for(int i=0;i<N;i++)ans[x][y]=ans[x][y]*deg[i]%mod;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)printf("%lld%c",ans[i][j],j+1==N?10:32);
	}
}