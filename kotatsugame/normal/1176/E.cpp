#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<vector<int> >G(N);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int>col(N,-1);
		col[0]=0;
		vector<int>A[2];
		queue<int>P;
		P.push(0);
		while(!P.empty())
		{
			int u=P.front();P.pop();
			A[col[u]].push_back(u);
			for(int v:G[u])if(col[v]==-1)
			{
				col[v]=1-col[u];
				P.push(v);
			}
		}
		int id=A[0].size()>A[1].size();
		printf("%d\n",(int)A[id].size());
		for(int i=0;i<A[id].size();i++)printf("%d%c",A[id][i]+1,i+1==A[id].size()?10:32);
	}
}