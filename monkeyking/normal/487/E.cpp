//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/graph>
//#include <self/tree>
//#include <self/SegmentTree>
//using namespace std;
//int n,m,q;
//int dat[100005];
//vector <int> vec[100005];
//int dfn[100005];
//int low[100005];
//int stk[100005];
//int top;
//vector <int> content[200005];
//Graph g;
//int nodes;
//int par[200005];
//int sz[200005];
//
//void tarjan(int x,int par=-1)
//{
//	static int Time=0;
//	dfn[x]=low[x]=Time++;
//	stk[top++]=x;
//	for(auto u:vec[x])
//	{
//		if(u==par) continue;
//		if(dfn[u]==-1)
//		{
//			tarjan(u,x);
//			chmin(low[x],low[u]);
//			if(low[u]>=dfn[x])
//			{
//				while(top && stk[top-1]!=u)
//				{
//					content[nodes].push_back(stk[--top]);
//					g.addEdges(nodes,stk[top]);
//				}
//				content[nodes].push_back(stk[--top]);
//				g.addEdges(nodes,stk[top]);
//				content[nodes].push_back(x);
//				g.addEdges(nodes,x);
//				nodes++;
//			}
//		}
//		else
//		{
//			chmin(low[x],dfn[u]);
//		}
//	}
////	cout<<dfn[x]<<'-'<<low[x]<<endl;
//}
//
//int heavy[200005];
//int links;
//vector <vector<int> > segnodes;
//int heavyid[200005];
//int heavyid2[200005];
//int heavyHead[200005];
//multiset <int> minValue[200005];
//vector <SegmentTreeMinChange <int> > sgts;
//multiset <int> minValueForAP[100005];
//
//int countSubtreeSize(int x,int par=-1)
//{
//	sz[x]=1;
//	pii o=mp(-1,-1);
//	for(auto u:g.edges[x])
//	{
//		if(u==par) continue;
//		sz[x]+=countSubtreeSize(u,x);
//		chmax(o,mp(sz[u],u));
//	}
//	if(o.second!=-1)
//	{
//		heavy[o.second]=true;
//	}
//	return sz[x];
//}
//
//void build(int x,int par=-1)
//{
//	if(heavy[x])
//	{
////		cout<<x<<" is heavy"<<endl;
//		heavyid[x]=heavyid[par];
//		heavyid2[x]=segnodes[heavyid[x]].size();
//		heavyHead[x]=heavyHead[par];
//		segnodes[heavyid[x]].push_back(x);
//	}
//	else
//	{
//		heavyid[x]=links++;
//		heavyid2[x]=0;
//		segnodes.push_back(*new vector <int> (1,x));
////		preLink[heavyid[x]]=(par==-1?-1:heavyid[par]);
//		heavyHead[x]=x;
//	}
//	::par[x]=par;
//	for(auto u:g.edges[x])
//	{
//		if(u==par) continue;
//		build(u,x);
//	}
//}
//
//inline void updateSingle(int x,int value)
//{
//	sgts[heavyid[x]].change(heavyid2[x],heavyid2[x]+1,value);
//}
//
//inline void update(int x,int oriValue,int value)
//{
//	updateSingle(x,value);
//	if(par[x]!=-1)
//	{
////		if(par[x]==7) cout<<"orivalue="<<oriValue<<' '<<"new value="<<value<<endl;
//		if(minValue[par[x]].find(oriValue)!=minValue[par[x]].end()) minValue[par[x]].erase(minValue[par[x]].find(oriValue));
//		minValue[par[x]].insert(value);
//		updateSingle(par[x],*minValue[par[x]].begin());
//	}
//}
//
//inline int query(int x,int par)
//{
//	int srcLink=heavyid[x];
//	int res=inf;
//	int dstLink=heavyid[par];
////	cout<<x<<'-'<<::par[heavyHead[x]]<<endl;
////	cout<<heavy[0]<<' '<<heavy[1]<<' '<<heavy[2]<<' '<<heavy[3]<<endl;
////	cout<<x<<'-'<<par<<endl;
////	cout<<srcLink<<' '<<dstLink<<endl;
////	cout<<heavyid[0]<<' '<<heavyid[7]<<' '<<heavyid[2]<<endl;
////	cout<<::par[0]<<' '<<::par[7]<<' '<<::par[2]<<endl;
////	cout<<heavy[0]<<' '<<heavy[7]<<' '<<heavy[2]<<' '<<heavy[5]<<' '<<heavy[4]<<endl;
////	cout<<x<<' '<<par<<' '<<srcLink<<' '<<dstLink<<endl;
//	int srcID=heavyid2[x];
//	int dstID=heavyid2[par];
////	if(debug) cout<<srcLink<<' '<<srcID<<endl;
//	while(srcLink!=dstLink)
//	{
//		chmin(res,sgts[srcLink].query(0,srcID+1));
//		x=::par[heavyHead[x]];
//		srcID=heavyid2[x];
//		srcLink=heavyid[x];
//	}
//	chmin(res,sgts[srcLink].query(dstID,srcID+1));
//	return res;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m>>q;
//	nodes=n;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",dat+i);
//	}
//	int x,y,z;
//	g.init(2*n);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		vec[x].push_back(y);
//		vec[y].push_back(x);
//	}
//	memset(dfn,-1,sizeof(dfn));
//	tarjan(0);
////	g.print();
//	tree::LCA lca;
//	lca.init(g);
//	countSubtreeSize(0);
//	build(0);
//	sgts.resize(links);
//	for(int i=0;i<links;i++)
//	{
//		sgts[i].init(segnodes[i].size()); 
//	}
//	for(int i=0;i<n;i++)
//	{
//		update(i,-1,dat[i]);
//	}
//	char type;
//	for(int i=0;i<q;i++)
//	{
//		type=0;
//		while(type!='A' && type!='C') type=getchar();
//		if(type=='A')
//		{
//			scanf("%d%d",&x,&y);
//			x--;
//			y--;
//			z=lca.lca(x,y);
////			cout<<x<<' '<<y<<' '<<z<<endl;
////			cout<<par[z]<<endl;
////			cout<<minValue[7]<<endl;
////			cout<<heavy[7]<<' '<<heavy[2]<<endl;
////			cout<<sgts[heavyid[5]][heavyid2[5]]<<endl;
////			cout<<y<<' '<<z<<' '<<query(y,z)<<endl;
////			cout<<query(4,0)<<endl;
////			exit(0);
//			printf("%d\n",min({query(x,z),query(y,z),(z>=n?dat[par[z]]:inf)}));
//		}
//		else
//		{
//			scanf("%d%d",&x,&y);
//			x--;
//			update(x,dat[x],y);
//			dat[x]=y;
////			cout<<heavyid[7]<<' '<<heavyid2[7]<<' ';
////			cout<<sgts[heavyid[7]][heavyid2[7]]<<endl;
//		}
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
const int mod=200003;
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
//quality not guarantee
template <typename T>
struct SegmentTreeMinUpdate//[)
{
	T* data;
	T* tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=1e18;
			tag[i]=1e18;
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]=min(data[x*2],tag[x]);
		data[x*2+1]=min(data[x*2+1],tag[x]);
		tag[x*2]=min(tag[x*2],tag[x]);
		tag[x*2+1]=min(tag[x*2+1],tag[x]);
		tag[x]=1e18;//warning
	}
	void update(int ql,int qr,T value)
	{
		update(1,0,nn,ql,qr,value);
	}
	void update(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=min(data[x],value);
			tag[x]=min(tag[x],value);
			return;
		}
		update(x*2,l,l+r>>1,ql,qr,value);
		update(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return 1e18;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMinAdd//[)
{
//	#define ll int
	T* data;
	T* tagSum;
	int nn;
	T inf;
	int size()
	{
		return nn;
	}
	void init(int size,T _inf)
	{
		nn=1;
		inf=_inf;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tagSum=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=inf;
			tagSum[i]=0;
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]+=tagSum[x];
		data[x*2+1]+=tagSum[x];
		tagSum[x*2]+=tagSum[x];
		tagSum[x*2+1]+=tagSum[x];
		tagSum[x]=0;
	}
	void add(int l,int r,T value)
	{
		add(1,0,nn,l,r,value);
	}
	void add(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=data[x]+value;
			tagSum[x]+=value;
			return;
		}
		add(x*2,l,l+r>>1,ql,qr,value);
		add(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return inf;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
	void build(int a[],int len)
	{
		for(int i=0;i<len;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMinChange//[)
{
	const T unchanged=-1;
	const T maxValue=1e9;
	T* data;
	T* tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=maxValue;
			tag[i]=unchanged;
		}
	}
	void build(int a[],int len)
	{
		for(int i=0;i<len;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		if(tag[x]==unchanged) return;
		data[x*2]=tag[x];
		data[x*2+1]=tag[x];
		tag[x*2]=tag[x];
		tag[x*2+1]=tag[x];
		tag[x]=unchanged;
	}
	void change(int ql,int qr,T value)
	{
		change(1,0,nn,ql,qr,value);
	}
	void change(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]=value;
			tag[x]=value;
			return;
		}
		change(x*2,l,l+r>>1,ql,qr,value);
		change(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	inline T operator [] (int pos)
	{
		return query(pos,pos+1);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return maxValue;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
};

template <typename T>
struct FenwickTree
{
	const T E=0;
	T *bit;
	int nn;
	inline void init(int n)
	{
		n++;
		nn=1;
		while(nn<n) nn<<=1;
		bit=new T[nn+5];
		for(int i=0;i<=nn;i++)
		{
			bit[i]=0;
		}
	}
	inline void clear(int n)
	{
		nn=1;
		while(nn<n) nn<<=1;
		for(int i=0;i<=nn;i++)
		{
			bit[i]=0;
		}
	}
	inline void add(int x,T delta)
	{
		x++;
		while(x<=nn)
		{
			bit[x]+=delta;
			x+=x&-x;
		}
	}
	inline T query(int x)
	{
		T res=E;
		while(x)
		{
			res+=bit[x];
			x&=x-1;
		}
		return res;
	}
	inline T query(int l,int r)//[]
	{
		l++;
		r++;
		return query(r)-(l>1?query(l-1):0);
	}
};

template <typename T>
struct SegmentTreeIntervalSum
{
	const T E=0;
	int nn;
	T *data;
	T *tag;
	void init(int _n)
	{
		nn=1;
		while(nn<_n) nn<<=1;
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<2*nn;i++)
		{
			tag[i]=E;
			data[i]=E;
		}
	}
	void pushdown(int x,int l,int r)
	{
		if(x>=nn) return;
		data[x*2]+=tag[x]*(r-l>>1);
		data[x*2+1]+=tag[x]*(r-l>>1);
		tag[x*2]+=tag[x];
		tag[x*2+1]+=tag[x];
		tag[x]=0;
	}
	void build(T a[],int n)
	{
		for(int i=0;i<n;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=data[i*2]+data[i*2+1];
		}
	}
	void add(int x,int ql,int qr,int l,int r,T delta)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x,l,r);
		if(l>=ql && r<=qr)
		{
			tag[x]+=delta;
			data[x]+=delta*(r-l);
			return;
		}
		add(x*2,ql,qr,l,l+r>>1,delta);
		add(x*2+1,ql,qr,l+r>>1,r,delta);
		data[x]=data[x*2]+data[x*2+1];
	}
	T query(int x,int ql,int qr,int l,int r)
	{
		if(l>=qr || r<=ql) return E;
		pushdown(x,l,r);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return query(x*2,ql,qr,l,l+r>>1)+query(x*2+1,ql,qr,l+r>>1,r);
	}
	inline void add(int l,int r,int delta)
	{
		add(1,l,r,0,nn,delta);
	}
	inline T query(int l,int r)
	{
		return query(1,l,r,0,nn);
	}
};

template <typename T>
struct SegmentTreeMinIntervalAdd//[)
{
	T* data;
	T* tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while(nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for(int i=0;i<=nn*2;i++)
		{
			data[i]=inf;
			tag[i]=0;
		}
	}
	void build(T a[],int n)
	{
		for(int i=0;i<n;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
	void pushdown(int x)
	{
		if(x>=nn) return;
		data[x*2]+=tag[x];
		data[x*2+1]+=tag[x];
		tag[x*2]+=tag[x];
		tag[x*2+1]+=tag[x];
		tag[x]=0;
	}
	void add(int ql,int qr,T value)
	{
		add(1,0,nn,ql,qr,value);
	}
	void add(int x,int l,int r,int ql,int qr,T value)
	{
		if(l>=qr || r<=ql) return;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			data[x]+=value;
			tag[x]+=value;
			return;
		}
		add(x*2,l,l+r>>1,ql,qr,value);
		add(x*2+1,l+r>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int ql,int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return inf;
		pushdown(x);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
	}
	//used in debug
	void print()
	{
		for(int i=0;i<nn;i++)
		{
			cout<<query(i,i+1)<<' ';
		}
		cout<<endl;
	}
};


template <typename T>
struct SegmentTreeMutChange
{
	T E=0;
	int nn;
	T *data;
	T *tag;
	bool *unChanged;
	void init(int _n)
	{
		nn=1;
		while(nn<_n) nn<<=1;
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		unChanged=new bool[nn*2+5];
		for(int i=0;i<2*nn;i++)
		{
			tag[i]=E;
			data[i]=E;
			unChanged[i]=true;
		}
	}
	void pushdown(int x,int l,int r)
	{
		if(x>=nn) return;
		if(unChanged[x]) return;
		data[x*2]=fastpow(tag[x],(r-l)>>1);
		data[x*2+1]=fastpow(tag[x],(r-l)>>1);
		tag[x*2]*=tag[x];
		tag[x*2+1]*=tag[x];
		unChanged[x]=true;
	}
	void build(T a[],int n)
	{
		for(int i=0;i<n;i++)
		{
			data[i+nn]=a[i];
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=data[i*2]*data[i*2+1];
		}
	}
	void change(int x,int ql,int qr,int l,int r,T value)
	{
		if(l>=qr || r<=ql) return;
		if(l>=ql && r<=qr)
		{
			tag[x]=value;
			data[x]=fastpow(value,qr-ql);
			unChanged[x]=false;
			return;
		}
		pushdown(x,l,r);
		change(x*2,ql,qr,l,l+r>>1,value);
		change(x*2+1,ql,qr,l+r>>1,r,value);
		data[x]=data[x*2]*data[x*2+1];
	}
	T query(int x,int ql,int qr,int l,int r)
	{
		if(l>=qr || r<=ql) return E;
		pushdown(x,l,r);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return query(x*2,ql,qr,l,l+r>>1)*query(x*2+1,ql,qr,l+r>>1,r);
	}
	bool IntChanged=false;
	bool SinChanged=false;
	inline void error()
	{
		cout<<"Error occured in Segment Tree"<<endl;
		exit(0);
	}
	inline void change(int l,int r,T value)
	{
		IntChanged=true;
		if(SinChanged) error();
		change(1,l,r,0,nn,value);
	}
	inline void change(int pos,T value)
	{
		SinChanged=true;
		if(IntChanged) error();
		pos+=nn;
		data[pos]=value;
		pos/=2;
		while(pos)
		{
			data[pos]=data[pos*2]*data[pos*2+1];
			pos/=2;
		}
	}
	inline T query(int l,int r)
	{
		return query(1,l,r,0,nn);
	}
	inline T query()
	{
		return data[1];
	}
};
using namespace std;
int n,m,q;
int dat[100005];
vector <int> vec[100005];
int dfn[100005];
int low[100005];
int stk[100005];
int top;
vector <int> content[200005];
Graph g;
int nodes;
int par[200005];
int sz[200005];

void tarjan(int x,int par=-1)
{
	static int Time=0;
	dfn[x]=low[x]=Time++;
	stk[top++]=x;
	for(auto u:vec[x])
	{
		if(u==par) continue;
		if(dfn[u]==-1)
		{
			tarjan(u,x);
			chmin(low[x],low[u]);
			if(low[u]>=dfn[x])
			{
				while(top && stk[top-1]!=u)
				{
					content[nodes].push_back(stk[--top]);
					g.addEdges(nodes,stk[top]);
				}
				content[nodes].push_back(stk[--top]);
				g.addEdges(nodes,stk[top]);
				content[nodes].push_back(x);
				g.addEdges(nodes,x);
				nodes++;
			}
		}
		else
		{
			chmin(low[x],dfn[u]);
		}
	}
//	cout<<dfn[x]<<'-'<<low[x]<<endl;
}

int heavy[200005];
int links;
vector <vector<int> > segnodes;
int heavyid[200005];
int heavyid2[200005];
int heavyHead[200005];
multiset <int> minValue[200005];
vector <SegmentTreeMinChange <int> > sgts;
multiset <int> minValueForAP[100005];

int countSubtreeSize(int x,int par=-1)
{
	sz[x]=1;
	pii o=mp(-1,-1);
	for(auto u:g.edges[x])
	{
		if(u==par) continue;
		sz[x]+=countSubtreeSize(u,x);
		chmax(o,mp(sz[u],u));
	}
	if(o.second!=-1)
	{
		heavy[o.second]=true;
	}
	return sz[x];
}

void build(int x,int par=-1)
{
	if(heavy[x])
	{
//		cout<<x<<" is heavy"<<endl;
		heavyid[x]=heavyid[par];
		heavyid2[x]=segnodes[heavyid[x]].size();
		heavyHead[x]=heavyHead[par];
		segnodes[heavyid[x]].push_back(x);
	}
	else
	{
		heavyid[x]=links++;
		heavyid2[x]=0;
		segnodes.push_back(*new vector <int> (1,x));
//		preLink[heavyid[x]]=(par==-1?-1:heavyid[par]);
		heavyHead[x]=x;
	}
	::par[x]=par;
	for(auto u:g.edges[x])
	{
		if(u==par) continue;
		build(u,x);
	}
}

inline void updateSingle(int x,int value)
{
	sgts[heavyid[x]].change(heavyid2[x],heavyid2[x]+1,value);
}

inline void update(int x,int oriValue,int value)
{
	updateSingle(x,value);
	if(par[x]!=-1)
	{
//		if(par[x]==7) cout<<"orivalue="<<oriValue<<' '<<"new value="<<value<<endl;
		if(minValue[par[x]].find(oriValue)!=minValue[par[x]].end()) minValue[par[x]].erase(minValue[par[x]].find(oriValue));
		minValue[par[x]].insert(value);
		updateSingle(par[x],*minValue[par[x]].begin());
	}
}

inline int query(int x,int par)
{
	int srcLink=heavyid[x];
	int res=inf;
	int dstLink=heavyid[par];
//	cout<<x<<'-'<<::par[heavyHead[x]]<<endl;
//	cout<<heavy[0]<<' '<<heavy[1]<<' '<<heavy[2]<<' '<<heavy[3]<<endl;
//	cout<<x<<'-'<<par<<endl;
//	cout<<srcLink<<' '<<dstLink<<endl;
//	cout<<heavyid[0]<<' '<<heavyid[7]<<' '<<heavyid[2]<<endl;
//	cout<<::par[0]<<' '<<::par[7]<<' '<<::par[2]<<endl;
//	cout<<heavy[0]<<' '<<heavy[7]<<' '<<heavy[2]<<' '<<heavy[5]<<' '<<heavy[4]<<endl;
//	cout<<x<<' '<<par<<' '<<srcLink<<' '<<dstLink<<endl;
	int srcID=heavyid2[x];
	int dstID=heavyid2[par];
//	if(debug) cout<<srcLink<<' '<<srcID<<endl;
	while(srcLink!=dstLink)
	{
		chmin(res,sgts[srcLink].query(0,srcID+1));
		x=::par[heavyHead[x]];
		srcID=heavyid2[x];
		srcLink=heavyid[x];
	}
	chmin(res,sgts[srcLink].query(dstID,srcID+1));
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>q;
	nodes=n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",dat+i);
	}
	int x,y,z;
	g.init(2*n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	memset(dfn,-1,sizeof(dfn));
	tarjan(0);
//	g.print();
	tree::LCA lca;
	lca.init(g);
	countSubtreeSize(0);
	build(0);
	sgts.resize(links);
	for(int i=0;i<links;i++)
	{
		sgts[i].init(segnodes[i].size()); 
	}
	for(int i=0;i<n;i++)
	{
		update(i,-1,dat[i]);
	}
	char type;
	for(int i=0;i<q;i++)
	{
		type=0;
		while(type!='A' && type!='C') type=getchar();
		if(type=='A')
		{
			scanf("%d%d",&x,&y);
			x--;
			y--;
			z=lca.lca(x,y);
//			cout<<x<<' '<<y<<' '<<z<<endl;
//			cout<<par[z]<<endl;
//			cout<<minValue[7]<<endl;
//			cout<<heavy[7]<<' '<<heavy[2]<<endl;
//			cout<<sgts[heavyid[5]][heavyid2[5]]<<endl;
//			cout<<y<<' '<<z<<' '<<query(y,z)<<endl;
//			cout<<query(4,0)<<endl;
//			exit(0);
			printf("%d\n",min({query(x,z),query(y,z),(z>=n?dat[par[z]]:inf)}));
		}
		else
		{
			scanf("%d%d",&x,&y);
			x--;
			update(x,dat[x],y);
			dat[x]=y;
//			cout<<heavyid[7]<<' '<<heavyid2[7]<<' ';
//			cout<<sgts[heavyid[7]][heavyid2[7]]<<endl;
		}
	}
	return 0;
}