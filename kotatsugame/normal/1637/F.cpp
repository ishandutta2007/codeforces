#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,H[2<<17];
vector<int>G[2<<17];
pair<int,long long>dfs(int u,int p)
{
	long long ret=0;
	vector<int>mxs(1,0);
	for(int v:G[u])if(v!=p)
	{
		pair<int,long long>q=dfs(v,u);
		ret+=q.second;
		mxs.push_back(q.first);
	}
	if(p!=-1)
	{
		int mx=0;
		for(int h:mxs)mx=max(mx,h);
		if(H[u]>mx)ret+=H[u]-mx,mx=H[u];
		return make_pair(mx,ret);
	}
	else
	{
		sort(mxs.begin(),mxs.end());
		ret+=H[u]-mxs.back();
		ret+=H[u]-mxs[mxs.size()-2];
		return make_pair(H[u],ret);
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	int mid=0;
	for(int i=0;i<N;i++)
	{
		cin>>H[i];
		if(H[mid]<H[i])mid=i;
	}
	for(int i=1;i<N;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<dfs(mid,-1).second<<endl;
}