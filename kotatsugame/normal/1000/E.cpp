#include<iostream>
#include<cstdio>
using namespace std;
//Two Edge Connected Components
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
	void dfs(int u,int p,int&cnt)
	{
		low[u]=ord[u]=cnt++;
		for(int&v:G[u])
		{
			if(ord[v]==-1)
			{
				dfs(v,u,cnt);
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
struct TECC:bridge{
	vector<int>comp;
	TECC(int n_=0):bridge(n_),comp(n_,-1){}
	int operator[](int a){return comp[a];}
	void dfs(int u,int p,int&k)
	{
		comp[u]=p==-1||is_bridge(p,u)?k++:comp[p];
		for(int&v:G[u])if(comp[v]==-1)dfs(v,u,k);
	}
	int build()
	{
		bridge::build();
		int k=0;
		dfs(0,-1,k);
		return k;
	}
	int build(vector<vector<int> >&H)
	{
		int k=build();
		H.assign(k,vector<int>());
		for(pair<int,int>&e:bridges)
		{
			int x=comp[e.first],y=comp[e.second];
			H[x].push_back(y);
			H[y].push_back(x);
		}
		return k;
	}
};
#include<vector>
#include<algorithm>
template<typename T>
pair<T,int>diameter_dfs(const vector<vector<pair<int,T> > >&G,int u,int p)
{
	pair<T,int>ans(0,u);
	for(const pair<int,T>&e:G[u])
	{
		if(e.first!=p)
		{
			pair<T,int>q=diameter_dfs(G,e.first,u);
			q.first+=e.second;
			ans=max(ans,q);
		}
	}
	return ans;
}
template<typename T>
T diameter(const vector<vector<pair<int,T> > >&G)
{
	pair<T,int>p=diameter_dfs(G,0,-1);
	pair<T,int>q=diameter_dfs(G,p.second,-1);
	return q.first;
}
int diameter(const vector<vector<int> >&G)
{
	vector<vector<pair<int,int> > >H(G.size());
	for(int i=0;i<G.size();i++)for(const int&e:G[i])H[i].push_back(make_pair(e,1));
	return diameter(H);
}
main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	TECC P(n);
	for(int i=0;i<m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		a--,b--;
		P.add_edge(a,b);
	}
	vector<vector<int> >G;
	m=n;
	n=P.build(G);
	cout<<diameter(G)<<endl;
}