#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<vector>
#include<algorithm>
struct bridge{
	vector<int>ord,low;
	vector<bool>art;
	vector<pair<int,int> >bridges;
	vector<vector<int> >G;
	bridge(int n_=0):ord(n_,-1),low(n_),art(n_,false),G(n_){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool operator[](int a){return art[a];}
	bool is_bridge(int a,int b)
	{
		if(ord[a]>ord[b])swap(a,b);
		return ord[a]<low[b];
	}
	void dfs(int u,int p,int&k)
	{
		low[u]=ord[u]=k++;
		for(int&v:G[u])
		{
			if(ord[v]==-1)
			{
				dfs(v,u,k);
				low[u]=min(low[u],low[v]);
				art[u]=art[u]|ord[u]<=low[v];
				if(ord[u]<low[v])bridges.push_back(u<v?make_pair(u,v):make_pair(v,u));
			}
			else if(v!=p)
			{
				low[u]=min(low[u],ord[v]);
			}
		}
	}
	void build()
	{
		int k=1,cnt=0;
		low[0]=ord[0]=0;
		for(int&v:G[0])if(ord[v]==-1)
		{
			dfs(v,0,k);
			if(ord[0]<low[v])bridges.push_back(make_pair(0,v));
			cnt++;
		}
		if(cnt>=2)art[0]=true;
	}
};
int N,M;
vector<pair<int,int> >E;
bool used[100];
int ans=1e9;
vector<pair<int,int> >au;
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		E.push_back(make_pair(a,b));
	}
	for(int ccc=0;ccc<2000;ccc++)
	{
		random_shuffle(E.begin(),E.end());
		for(int i=0;i<M;i++)used[i]=0;
		for(int i=0;i<M;i++)
		{
			bridge C(N);
			used[i]=1;
			for(int j=0;j<M;j++)
			{
				if(used[j])continue;
				C.add_edge(E[j].first,E[j].second);
			}
			C.build();
			bool f=1;
			for(int j=0;j<M;j++)
			{
				if(used[j])continue;
				f&=!C.is_bridge(E[j].first,E[j].second);
				if(!f)break;
			}
			if(!f)
			{
				used[i]=0;
			}
		}
		bridge D(N);
		int cnt=0;
		for(int i=0;i<M;i++)
		{
			if(used[i])continue;
			cnt++;
			D.add_edge(E[i].first,E[i].second);
		}
		if(cnt>=ans)continue;
		D.build();
		bool f=1;
		for(int i=0;i<M;i++)
		{
			if(used[i])continue;
			f&=!D.is_bridge(E[i].first,E[i].second);
			if(!f)break;
		}
		if(f)
		{
			ans=cnt;
			au.clear();
			for(int i=0;i<M;i++)
			{
				if(used[i])continue;
				au.push_back(E[i]);
			}
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
	{
		cout<<au[i].first+1<<" "<<au[i].second+1<<endl;
	}
}