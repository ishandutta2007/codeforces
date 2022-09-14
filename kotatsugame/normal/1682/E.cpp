#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cassert>
using namespace std;
int N,M,P[2<<17];
map<int,int>G[2<<17];
vector<int>ans;
bool vis[2<<17];
inline void flip(int val,set<int>&S)
{
	auto it=S.lower_bound(val);
	if(it!=S.end()&&*it==val)S.erase(it);
	else S.insert(it,val);
}
set<int>ret[2<<17];
void dfs2(int);
void dfs1(int u)
{
	//cout<<"dfs1("<<u<<")"<<endl;
	vis[u]=true;
	map<int,int>tmp;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		G[v].erase(u);
		dfs1(v);
		int w=P[v];
		auto it=ret[v].begin();
		if(*it==w)it++;
		else
		{
			it++;
			assert(*it==w);
			it--;
		}
		tmp[*it]=v;
	}
	while(!G[u].empty())
	{
		auto it=tmp.find(P[u]);
		if(it==tmp.end())break;
		int v=it->second;
		tmp.erase(it);
		ans.push_back(G[u][v]);
		G[u].erase(v);
		swap(P[u],P[v]);
		dfs2(v);
	}
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		for(int w:ret[v])flip(w,ret[u]);
	}
	flip(u,ret[u]);
	flip(P[u],ret[u]);
	//cout<<"return u:";
	//for(int v:ret[u])cout<<" "<<v;cout<<endl;
	if(u!=P[u])assert(ret[u].size()==2);
}
void dfs2(int u)
{
	//cout<<"dfs2("<<u<<")"<<endl;
	map<int,int>tmp;
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		int w=P[v];
		auto it=ret[v].begin();
		if(*it==w)it++;
		else
		{
			it++;
			assert(*it==w);
			it--;
		}
		tmp[*it]=v;
	}
	while(!G[u].empty())
	{
		auto it=tmp.find(P[u]);
		if(it==tmp.end())
		{
			cout<<"ERROR"<<endl;
			break;
		}
		int v=it->second;
		tmp.erase(it);
		ans.push_back(G[u][v]);
		G[u].erase(v);
		swap(P[u],P[v]);
		dfs2(v);
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>P[i];
		P[i]--;
		if(i==P[i])vis[i]=true;
	}
	for(int i=1;i<=M;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		G[u][v]=i;
		G[v][u]=i;
	}
	for(int i=0;i<N;i++)if(!vis[i])dfs1(i);
	for(int i=0;i<M;i++)
	{
		cout<<ans[i]<<(i+1==M?"\n":" ");
	}
}