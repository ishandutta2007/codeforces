#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
bool vis[1010];
vector<pair<int,int> >G[1010];
vector<int>del;
void dfs(int u,int p,int sz)
{
	if(vis[u]||del.size()>=sz)return;
	vis[u]=true;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(v==p)continue;
		del.push_back(e.second);
		dfs(v,u,sz);
		if(del.size()>=sz)return;
	}
}
main()
{
	cin>>N;
	vector<pair<int,int> >E;
	for(int i=0;i<N-1;i++)
	{
		int a,b;cin>>a>>b;
		E.push_back(make_pair(a,b));
	}
	cout<<"? "<<N;
	for(int i=1;i<=N;i++)cout<<" "<<i;
	cout<<endl;
	int mx;
	cin>>mx;
	while(E.size()>1)
	{
		for(int i=1;i<=N;i++)G[i].clear(),vis[i]=false;
		for(int i=0;i<E.size();i++)
		{
			int a=E[i].first,b=E[i].second;
			G[a].push_back(make_pair(b,i));
			G[b].push_back(make_pair(a,i));
		}
		del.clear();
		for(int i=1;i<=N;i++)dfs(i,-1,E.size()/2);
		vector<int>now;
		for(int id:del)now.push_back(E[id].first),now.push_back(E[id].second);
		sort(now.begin(),now.end());
		now.erase(unique(now.begin(),now.end()),now.end());
		cout<<"? "<<now.size();
		for(int v:now)cout<<" "<<v;
		cout<<endl;
		int ret;
		cin>>ret;
		if(ret==mx)
		{
			vector<pair<int,int> >nE;
			for(int id:del)nE.push_back(E[id]);
			E.swap(nE);
		}
		else
		{
			vector<int>usd(E.size());
			for(int id:del)usd[id]=1;
			vector<pair<int,int> >nE;
			for(int i=0;i<E.size();i++)if(usd[i]==0)nE.push_back(E[i]);
			E.swap(nE);
		}
	}
	cout<<"! "<<E[0].first<<" "<<E[0].second<<endl;
}