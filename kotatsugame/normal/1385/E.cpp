#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<vector<int> >G(N);
		vector<pair<int,int> >E;
		vector<int>indeg(N,0);
		for(int i=0;i<M;i++)
		{
			int f,u,v;scanf("%d%d%d",&f,&u,&v);
			u--,v--;
			if(f==1)
			{
				G[u].push_back(v);
				indeg[v]++;
			}
			else
			{
				E.push_back(make_pair(u,v));
			}
		}
		vector<int>id(N);
		int sz=0;
		queue<int>Q;
		for(int i=0;i<N;i++)if(indeg[i]==0)
		{
			Q.push(i);
		}
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			id[u]=sz++;
			for(int v:G[u])if(--indeg[v]==0)Q.push(v);
		}
		if(sz!=N)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(pair<int,int>e:E)
			{
				int u=e.first,v=e.second;
				if(id[e.first]>id[e.second])u=e.second,v=e.first;
				G[u].push_back(v);
			}
			for(int i=0;i<N;i++)for(int v:G[i])printf("%d %d\n",i+1,v+1);
		}
	}
}