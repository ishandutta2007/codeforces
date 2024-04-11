#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
using namespace std;
int T,N;
int nxt[5<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >G(N);
		vector<int>indeg(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&nxt[i]);
			if(nxt[i]>0)nxt[i]--;
		}
		deque<pair<int,int> >P;
		for(int i=N;i--;)
		{
			if(nxt[i]==-1)
			{
				P.push_front(make_pair(i,i+1));
				continue;
			}
			if(nxt[i]<N)
			{
				G[nxt[i]].push_back(i);
				indeg[i]++;
			}
			int l=i,r=nxt[i];
			while(!P.empty()&&P.front().first<r)
			{
				int u=P.front().first;
				P.pop_front();
				G[i].push_back(u);
				indeg[u]++;
				if(r<u)r=u;
			}
			P.push_front(make_pair(l,r));
		}
		queue<int>Q;
		int sz=N;
		vector<int>ans(N);
		for(int i=0;i<N;i++)if(indeg[i]==0)Q.push(i);
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			ans[u]=sz--;
			for(int v:G[u])if(!--indeg[v])Q.push(v);
		}
		if(sz>0)puts("-1");
		else
		{
			for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
		}
	}
}