//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/graph>
//#include <self/Tree>
//using namespace std;
//int dfn[2005];
//int low[2005];
//int stk[2005];
//int col[2005];
//int k,c;
//int n;
//int m;
//Graph g;
//Graph ng;
//int visit[2005];
//
//namespace tarjan
//{
//	void dfs(int x,int par)
//	{
//		static int Time=0;
//		dfn[x]=low[x]=Time++;
//		stk[k++]=x;
//		for(auto u:g.edges[x])
//		{
//			if(u==par) continue;
//			if(dfn[u]==-1) dfs(u,x);
//			chmin(low[x],low[u]);
//		}
//		if(dfn[x]==low[x])
//		{
//			do
//			{
//				col[stk[k-1]]=c;
//				k--;
//			}while(k && stk[k]!=x);
//			c++;
//		}
//	}
//};
//
//void shrink(Graph &g)
//{
//	Graph ng;
//	ng.init(c,true);
//	for(int i=0;i<n;i++)
//	{
//		for(auto &j:g.edges[i])
//		{
//			if(col[i]==col[j]) continue;
//			ng.addEdges(col[i],col[j]);
//		}
//	}
//	for(int i=0;i<c;i++)
//	{
//		sort(all(ng.edges[i]));
//		ng.edges[i].erase(unique(all(ng.edges[i])),ng.edges[i].end());
//	}
//	g=ng;
//}
//
//int best;
//int dfs(int x,int par)
//{
//	visit[x]=true;
//	int m1=-1,m2=-1;
//	for(auto u:g.edges[x])
//	{
//		if(u==par) continue;
//		chmax(m2,dfs(u,x));
//		if(m1<m2) swap(m1,m2);
//	}
//	int res=(int)g.edges[x].size()+1;
//	if(m1!=-1) chmax(res,m1+(int)g.edges[x].size()-1);
//	chmax(best,res);
//	if(m2!=-1) chmax(best,res+m2-2);
//	return res;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	ios_base::sync_with_stdio(false);
//	cin>>n>>m;
//	int x,y;
//	g.init(n,true);
//	for(int i=0;i<m;i++)
//	{
//		cin>>x>>y;
//		x--;
//		y--;
//		g.addEdges(x,y);
//	}
//	memset(col,-1,sizeof(col));
//	memset(dfn,-1,sizeof(dfn));
//	for(int i=0;i<n;i++)
//	{
//		if(dfn[i]==-1) tarjan::dfs(i,-1);
//	}
//	shrink(g);
//	int res=0;
//	tree::MarkLeaf ml;
//	tree::GetPSum gps;
//	tree::GetDiameter gd;
//	tree::JustVisit jv;
//	int isLeaf[g.n];
//	int sumLeaf[g.n];
//	for(int i=0;i<g.n;i++)
//	{
//		if(visit[i]) continue;
//		int cnt=jv.dfs(g,visit,i);
//		if(cnt==1) continue;
//		ml.dfs(g,isLeaf);
//		gps.dfs(g,sumLeaf,isLeaf,i);
//		int d=gd.getDiameter(g,i);
//		cnt=sumLeaf[i];
//		res+=cnt+d-2-1;
//	}
//	cout<<n-res-1<<endl;
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
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
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
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

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
				if(!unDirected || (i<j)) cout<<"("<<i<<'-'<<j<<")"<<endl;
			}
		}
	}
};
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
				if(!unDirected || (i<j)) cout<<"("<<i<<'-'<<j<<")"<<endl;
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
		void getDepArray(Graph &g,int rt,T &arr)
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
			ta.getDepArray(g,0,depth);
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
};
using namespace std;
int dfn[2005];
int low[2005];
int stk[2005];
int col[2005];
int k,c;
int n;
int m;
Graph g;
Graph ng;
int visit[2005];

namespace tarjan
{
	void dfs(int x,int par)
	{
		static int Time=0;
		dfn[x]=low[x]=Time++;
		stk[k++]=x;
		for(auto u:g.edges[x])
		{
			if(u==par) continue;
			if(dfn[u]==-1) dfs(u,x);
			chmin(low[x],low[u]);
		}
		if(dfn[x]==low[x])
		{
			do
			{
				col[stk[k-1]]=c;
				k--;
			}while(k && stk[k]!=x);
			c++;
		}
	}
};

void shrink(Graph &g)
{
	Graph ng;
	ng.init(c,true);
	for(int i=0;i<n;i++)
	{
		for(auto &j:g.edges[i])
		{
			if(col[i]==col[j]) continue;
			ng.addEdges(col[i],col[j]);
		}
	}
	for(int i=0;i<c;i++)
	{
		sort(all(ng.edges[i]));
		ng.edges[i].erase(unique(all(ng.edges[i])),ng.edges[i].end());
	}
	g=ng;
}

int best;
int dfs(int x,int par)
{
	visit[x]=true;
	int m1=-1,m2=-1;
	for(auto u:g.edges[x])
	{
		if(u==par) continue;
		chmax(m2,dfs(u,x));
		if(m1<m2) swap(m1,m2);
	}
	int res=(int)g.edges[x].size()+1;
	if(m1!=-1) chmax(res,m1+(int)g.edges[x].size()-1);
	chmax(best,res);
	if(m2!=-1) chmax(best,res+m2-2);
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int x,y;
	g.init(n,true);
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		g.addEdges(x,y);
	}
	memset(col,-1,sizeof(col));
	memset(dfn,-1,sizeof(dfn));
	for(int i=0;i<n;i++)
	{
		if(dfn[i]==-1) tarjan::dfs(i,-1);
	}
	shrink(g);
	int res=0;
	tree::MarkLeaf ml;
	tree::GetPSum gps;
	tree::GetDiameter gd;
	tree::JustVisit jv;
	int isLeaf[g.n];
	int sumLeaf[g.n];
	for(int i=0;i<g.n;i++)
	{
		if(visit[i]) continue;
		int cnt=jv.dfs(g,visit,i);
		if(cnt==1) continue;
		ml.dfs(g,isLeaf);
		gps.dfs(g,sumLeaf,isLeaf,i);
		int d=gd.getDiameter(g,i);
		cnt=sumLeaf[i];
		res+=cnt+d-2-1;
	}
	cout<<n-res-1<<endl;
	return 0;
}