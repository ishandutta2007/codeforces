#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int Q,N,K;
vector<pair<int,int> >G[5<<17];
pair<long long,long long>dfs(int u,int p)
{
	vector<long long>A;
	long long ret=0;
	for(const pair<int,int>&q:G[u])
	{
		if(q.first==p)continue;
		pair<long long,long long>r=dfs(q.first,u);
		ret+=r.second+q.second;
		A.push_back(r.first-r.second-q.second);
	}
	sort(A.begin(),A.end());
	while(!A.empty()&&A.back()>=0)
	{
		ret+=A.back();
		A.pop_back();
	}
	while(A.size()>K)
	{
		ret+=A.back();
		A.pop_back();
	}
	if(A.size()<K)return make_pair(ret,ret);
	else return make_pair(ret,ret+A.back());
}
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			G[u].push_back(make_pair(v,w));
			G[v].push_back(make_pair(u,w));
		}
		pair<long long,long long>p=dfs(0,-1);
		printf("%lld\n",max(p.first,p.second));
	}
}