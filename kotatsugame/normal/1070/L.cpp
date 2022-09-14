#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
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
		bool one=true;
		for(int i=0;i<N;i++)if(G[i].size()%2)one=false;
		if(one)
		{
			puts("1");
			for(int i=0;i<N;i++)printf("1%c",i+1==N?10:32);
			continue;
		}
		vector<bitset<2001> >A(N);
		for(int i=0;i<N;i++)
		{
			if(G[i].size()%2==0)
			{
				for(int v:G[i])A[i][v]=1;
			}
			else
			{
				A[i][i]=1;
				for(int v:G[i])A[i][v]=1;
				A[i][N]=1;
			}
		}
		int sz=0;
		vector<int>ids(N,-1);
		for(int i=0;i<N;i++)
		{
			int id=sz;
			while(id<N&&A[id][i]==0)id++;
			if(id==N)continue;
			if(id>sz)
			{
				swap(A[sz],A[id]);
			}
			for(int j=0;j<N;j++)if(sz!=j&&A[j][i]==1)
			{
				A[j]^=A[sz];
			}
			ids[i]=sz++;
		}
		vector<int>ans(N);
		for(int i=0;i<N;i++)
		{
			if(ids[i]!=-1&&A[ids[i]][N]==1)ans[i]=1;
		}
		puts("2");
		for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?10:32);
	}
}