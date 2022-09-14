#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int T,N,M;
vector<int>calc(int st,const vector<vector<int> >&G)
{
	vector<int>ret(N,(int)1e9);
	ret[st]=0;
	queue<int>P;P.push(st);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(int v:G[u])
		{
			if(ret[v]>ret[u]+1)
			{
				ret[v]=ret[u]+1;
				P.push(v);
			}
		}
	}
	return ret;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c;
		scanf("%d%d%d%d%d",&N,&M,&a,&b,&c);
		a--,b--,c--;
		vector<int>p(M);
		for(int i=0;i<M;i++)scanf("%d",&p[i]);
		sort(p.begin(),p.end());
		vector<long long>sum(M+1,0LL);
		for(int i=0;i<M;i++)sum[i+1]=sum[i]+p[i];
		vector<vector<int> >G(N);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int>da=calc(a,G);
		vector<int>db=calc(b,G);
		vector<int>dc=calc(c,G);
		long long ans=9e18;
		for(int i=0;i<N;i++)
		{
			if(da[i]+db[i]+dc[i]>M)continue;
			ans=min(ans,sum[da[i]+db[i]+dc[i]]+sum[db[i]]);
		}
		printf("%lld\n",ans);
	}
}