//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/tree>
//using namespace std;
//int n;
//
//Graph g;
//int a,b,da,db;
//int depth[100005];
//
//void solve()
//{
//	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
//	g.clear(n);
//	a--;
//	b--;
//	int x,y;
//	for(int i=0;i<n-1;i++)
//	{
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		g.addEdges(x,y);
//	}
//	tree::GetDiameter gd;
//	int d=gd.getDiameter(g)-1;
//	if(!(db>2*da && d>2*da))
//	{
//		puts("Alice");
//		return;
//	}
//	tree::GetDepth gde;
//	gde.getDepArray(depth,g,a);
//	if(depth[b]<=da)
//	{
//		puts("Alice");
//		return;
//	}
//	puts("Bob");
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	g.init(100005);
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		solve();
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
#ifndef _SELF_GRAPH
#define _SELF_GRAPH 1
#include <vector>
using namespace std;
struct Graph
{
	public:
	bool unDirected;
	vector <vector <int> > edges;
	int n;
	int m;
	int isTree;
	void init(int _n,bool _unDirected=true)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
		unDirected=_unDirected;
		isTree=-1;
	}
	bool testTree()
	{
		if(isTree!=-1) return isTree;
		assert(unDirected==true);
		if(n!=m+1) return isTree=false;
		queue <int> que;
		vector <int> visit(n,0);
		que.push(0);
		while(que.size())
		{
			int x=que.front();
			visit[x]=true;
			que.pop();
			for(auto u:edges[x])
			{
				if(visit[u]) continue;
				que.push(u);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!visit[i]) return isTree=false;
		}
		return isTree=true;
	}
	void feedEdges(vector <int> _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y)
	{
		edges[x].push_back(y);
		if(unDirected) edges[y].push_back(x);
		m++;
	}
	void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	void clear()
	{
		clear(n);
	}
	void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j)) cout<<"("<<i<<'-'<<j<<")"<<endl;
			}
		}
	}
};

template <typename T>
struct GraphWithCost
{
	public:
	bool unDirected;
	vector <vector <pair<int,T> > > edges;
	int n;
	int m;
	int isTree;
	void init(int _n,bool _unDirected)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
//		dfn.resize(n+5);
//		low.resize(n+5);
		unDirected=_unDirected;
		isTree=-1;
	}
	void feedEdges(vector <pair<int,T> > _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y,int cost)
	{
		edges[x].push_back(mp(y,cost));
		if(unDirected) edges[y].push_back(mp(x,cost));
		m++;
	}
	void clear()
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j.first)) cout<<"("<<i<<'-'<<j.first<<")"<<endl;
			}
		}
	}
};
#endif
namespace tree
{
	struct GetParent
	{
		template <typename T>
		void dfs(int x,int p,T &arr,Graph &g)
		{
			arr[x]=p;
			for(auto &u:g.edges[x])
			{
				if(u==p) continue;
				dfs(u,x,arr,g);
			}
		}
		template <typename T>
		void getParArray(Graph &g,int rt,T &arr)
		{
			dfs(rt,-1,arr,g);
		}
	};
	
	struct GetDepth
	{
		template <typename T>
		void dfs(int x,int p,int depth,T &arr,Graph &g)
		{
			arr[x]=depth;
			for(auto &u:g.edges[x])
			{
				if(u==p) continue;
				dfs(u,x,depth+1,arr,g);
			}
		}
		template <typename T>
		void getDepArray(T &arr,Graph &g,int rt=0)
		{
			dfs(rt,-1,0,arr,g);
		}
	};
	
	struct LCA
	{
		int N;
		int LOGN;
		vector <int> depth;
		vector <vector<int> > par;
		void error(string s)
		{
			cout<<s<<endl;
			exit(0);
		}
		void init(Graph &g)
		{
			if(g.unDirected==false)
			{
				error("Error occured! Now LCA-algorithm only supports undirected graph!");
			}
			N=g.n;
			int tn=N;
			LOGN=0;
			while(tn)
			{
				tn/=2;
				LOGN++;
			}
			depth.resize(N);
			par.resize(LOGN);
			for(int i=0;i<LOGN;i++)
			{
				par[i].resize(N);
			}
			GetDepth ta;
			GetParent tb;
			ta.getDepArray(depth,g,0);
			tb.getParArray(g,0,par[0]);
			for(int k=0;k<LOGN-1;k++)
			{
				for(int i=0;i<g.n;i++)
				{
					if(par[k][i]==-1)
					{
						par[k+1][i]=-1;
					}
					else
					{
						par[k+1][i]=par[k][par[k][i]];
					}
				}
			}
		}
		int lca(int a,int b)
		{
			if(depth[a]<depth[b]) swap(a,b);
			int t=depth[a]-depth[b];
			for(int i=0;i<LOGN;i++)
			{
				if((t & (1<<i))) a=par[i][a];
			}
			if(a==b) return a;
			for(int i=LOGN-1;i>=0;i--)
			{
				if(par[i][a]!=par[i][b])
				{
					a=par[i][a];
					b=par[i][b];
				}
			}
			return par[0][a];
		}
	};
	
	struct GetDiameter
	{
		pair<int,int> dfs(Graph &g,int x,int par)
		{
			pair<int,int> res=make_pair(1,x);
			for(auto u:g.edges[x])
			{
				if(u==par) continue;
				chmax(res,dfs(g,u,x)+make_pair(1,0));
			}
			return res;
		}
		int getDiameter(Graph &g,int x=0,int par=-1)
		{
			int a=dfs(g,x,par).second;
			return dfs(g,a,-1).first;
		}
	};
	
	struct GetPSum
	{
		void dfs(Graph &g,int dst[],int src[],int x=0,int par=-1)
		{
			dst[x]=src[x];
			for(auto u:g.edges[x])
			{
				if(u==par) continue;
				dfs(g,dst,src,u,x);
				dst[x]+=dst[u];
			}
		}
	};
	
	struct MarkLeaf
	{
		void dfs(Graph &g,int arr[],int x=0,int par=-1)
		{
			for(int i=0;i<g.n;i++)
			{
				if((int)g.edges[i].size()<=1) arr[i]=true;else arr[i]=false;
			}
		}
	};
	
	struct JustVisit
	{
		int dfs(Graph &g,int arr[],int x=0,int par=-1)
		{
			arr[x]=true;
			int cnt=1;
			for(auto u:g.edges[x])
			{
				if(u==par) continue;
				cnt+=dfs(g,arr,u,x);
			}
			return cnt;
		}
	};
	
	struct BulidSPTree
	{
		vector <int> dist;
		template <typename T>
		inline vector <pair<int,T> > build(GraphWithCost <T> &g,int rt)
		{
			vector <pair<int,T> > v(g.n);
			dist.resize(g.n);
			priority_queue <pii,vector<pii>,greater<pii> > que;
			for(int i=0;i<g.n;i++)
			{
				dist[i]=inf;
			}
			dist[rt]=0;
			que.push(mp(0,rt));
			while(que.size())
			{
				int x=que.top().second;
				int s=que.top().first;
				que.pop();
				if(s!=dist[x]) continue;
				for(int i=0;i<g.edges[x].size();i++)
				{
					int u=g.edges[x][i].first,ct=g.edges[x][i].second;
					if(dist[u]<=dist[x]+ct) continue;
					dist[u]=dist[x]+ct;
					v[u]=mp(x,ct);
					que.push(mp(dist[u],u));
				}
			}
			v[0]=mp(-1,0);
			return v;
		}
	};
};
using namespace std;
int n;

Graph g;
int a,b,da,db;
int depth[100005];

void solve()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	g.clear(n);
	a--;
	b--;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		g.addEdges(x,y);
	}
	tree::GetDiameter gd;
	int d=gd.getDiameter(g)-1;
	if(!(db>2*da && d>2*da))
	{
		puts("Alice");
		return;
	}
	tree::GetDepth gde;
	gde.getDepArray(depth,g,a);
	if(depth[b]<=da)
	{
		puts("Alice");
		return;
	}
	puts("Bob");
}

int main()
{
//	freopen("input.txt","r",stdin);
	g.init(100005);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}