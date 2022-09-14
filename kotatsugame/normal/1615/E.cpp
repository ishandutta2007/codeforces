#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,K;
vector<int>G[2<<17];
vector<int>rs;
int dfs(int u,int p)
{
	int mx=0;
	for(int v:G[u])if(v!=p)
	{
		int now=dfs(v,u);
		if(mx>=now)rs.push_back(now);
		else
		{
			if(mx!=0)rs.push_back(mx);
			mx=now;
		}
	}
	return mx+1;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		G[i].clear();
	}
	for(int i=0;i<N-1;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int mc=dfs(0,-1);
	rs.push_back(mc);
	sort(rs.begin(),rs.end());
	reverse(rs.begin(),rs.end());
	int mb=N;
	int mbmx=N/2;
	int r=0;
	long long ans=(long long)(N-mbmx)*-mbmx;
	for(int i=0;i<K&&i<rs.size();i++)
	{
		mb-=rs[i];
		int ni=min(mbmx,mb);
		r++;
		ans=max(ans,(long long)(N-r-ni)*(r-ni));
	}
	if(rs.size()<=K)
	{
		int ni=max((int)rs.size(),min(mbmx,K));
		ans=max(ans,(long long)(N-ni)*ni);
	}
	cout<<ans<<"\n";
}