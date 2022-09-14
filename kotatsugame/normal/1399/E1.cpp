#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N;
long long S;
vector<vector<pair<int,int> > >G;
priority_queue<pair<long long,pair<int,int> > >P;
long long sum;
pair<long long,pair<int,int> >f(int w,int c)
{
	return make_pair((long long)(w-w/2)*c,make_pair(w,c));
}
int dfs(int u,int p)
{
	int ch=0;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(v!=p)
		{
			int c=dfs(v,u);
			P.push(f(e.second,c));
			sum+=(long long)e.second*c;
			ch+=c;
		}
	}
	return ch+!ch;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&S);
		G.clear();
		G.assign(N,vector<pair<int,int> >());
		for(int i=1;i<N;i++)
		{
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			G[u].push_back(make_pair(v,w));
			G[v].push_back(make_pair(u,w));
		}
		while(!P.empty())P.pop();
		sum=0;
		dfs(0,-1);
		int ans=0;
		while(sum>S)
		{
			sum-=P.top().first;
			pair<int,int>p=P.top().second;
			P.pop();
			P.push(f(p.first/2,p.second));
			ans++;
		}
		printf("%d\n",ans);
	}
}