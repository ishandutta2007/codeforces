#include<cstdio>
#include<vector>
using namespace std;
int T,N;
vector<pair<int,int> >G[2<<17];
long long B,C;
int dfs(int u,int p)
{
	int ch=1;
	for(pair<int,int>e:G[u])if(e.first!=p)
	{
		int c=dfs(e.first,u);
		if(c%2==1)
		{
			B+=e.second;
		}
		C+=(long long)e.second*min(c,N-c);
		ch+=c;
	}
	return ch;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		N*=2;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=0;i<N-1;i++)
		{
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
		}
		B=C=0;
		dfs(0,-1);
		printf("%lld %lld\n",B,C);
	}
}