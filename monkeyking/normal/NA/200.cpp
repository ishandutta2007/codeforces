//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/graph>
//#include <self/rand>
//using namespace std;
//int n,m;
//int best;
//bool a[14][14];
//bool choose[196];
//pii edge[196];
//Graph g;
//int low[14];
//int dfn[14];
//bool visit[14];
//bool f;
//int ti;
//Graph ans;
//
//void dfs(int x,int p)
//{
//	visit[x]=true;
//	low[x]=dfn[x]=ti++;
//	for(auto u:g.edges[x])
//	{
//		if(u==p) continue;
//		if(!visit[u])
//		{
//			dfs(u,x);
//		}
//		chmin(low[x],low[u]);
//		if(low[u]>dfn[x]) f=false;
//	}
//}
//
//bool bcc()
//{
//	ti=0;
//	memset(visit,0,sizeof(visit));
//	g.clear();
//	f=true;
//	for(int i=0;i<m;i++)
//	{
//		if(choose[i])
//		{
//			g.addEdges(edge[i].first,edge[i].second);
//		}
//	}
//	dfs(0,-1);
//	for(int i=0;i<n;i++)
//	{
//		if(!visit[i]) return false;
//	}
//	return f;
//}
//
//void solve()
//{
//	memset(choose,1,sizeof(choose));
//	int now=m;
//	assert(bcc());
//	for(double T=200000;T>=0.00001;T*=0.9999)
//	{
//		int id=rand(0,m-1);
//		int delta=inf;
//		if(choose[id])
//		{
//			choose[id]=false;
//			if(bcc()) delta=-1;else delta=inf;
//			choose[id]=true;
//		}
//		else
//		{
//			delta=1;
//		}
//		if(exp(-delta/T)>=rand(1,1000000000)/1000000000.0)
//		{
//			assert(delta!=inf);
//			now+=delta;
//			choose[id]=!choose[id];
//		}
//		if(now<best)
//		{
//			assert(bcc());
//			best=now;
//			ans=g;
////			ans.print();
//		}
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	int x,y;
//	g.init(n,true);
//	ans.init(n,true);
//	for(int i=0;i<m;i++)
//	{
//		cin>>x>>y;
//		x--;
//		y--;
//		edge[i]=mp(x,y);
//		g.addEdges(x,y);
//	}
//	memset(choose,1,sizeof(choose));
//	best=inf;
//	for(int i=0;i<20;i++)
//	{
//		solve();
//	}
//	cout<<best<<endl;
//	for(int i=0;i<ans.n;i++)
//	{
//		for(auto u:ans.edges[i])
//		{
//			if(u>i) cout<<i+1<<' '<<u+1<<endl;
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
/*
todo: class
todo: 
*/ 
#include <vector>
using namespace std;
struct Graph
{
	bool unDirected;
	vector <vector <int> > edges;
	int n;
	int m;
	void init(int _n,bool _unDirected)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
		unDirected=_unDirected;
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
#ifndef _SELF_RAND
#define _SELF_RAND 1
#if __cplusplus < 201103L
long long _Rand_Gen_Num() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=_Rand_Gen_Num();return x%(r-l+1)+l;}
#else
#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
#endif
#endif
using namespace std;
int n,m;
int best;
bool a[14][14];
bool choose[196];
pii edge[196];
Graph g;
int low[14];
int dfn[14];
bool visit[14];
bool f;
int ti;
Graph ans;

void dfs(int x,int p)
{
	visit[x]=true;
	low[x]=dfn[x]=ti++;
	for(auto u:g.edges[x])
	{
		if(u==p) continue;
		if(!visit[u])
		{
			dfs(u,x);
		}
		chmin(low[x],low[u]);
		if(low[u]>dfn[x]) f=false;
	}
}

bool bcc()
{
	ti=0;
	memset(visit,0,sizeof(visit));
	g.clear();
	f=true;
	for(int i=0;i<m;i++)
	{
		if(choose[i])
		{
			g.addEdges(edge[i].first,edge[i].second);
		}
	}
	dfs(0,-1);
	for(int i=0;i<n;i++)
	{
		if(!visit[i]) return false;
	}
	return f;
}

void solve()
{
	memset(choose,1,sizeof(choose));
	int now=m;
	assert(bcc());
	for(double T=200000;T>=0.00001;T*=0.9999)
	{
		int id=rand(0,m-1);
		int delta=inf;
		if(choose[id])
		{
			choose[id]=false;
			if(bcc()) delta=-1;else delta=inf;
			choose[id]=true;
		}
		else
		{
			delta=1;
		}
		if(exp(-delta/T)>=rand(1,1000000000)/1000000000.0)
		{
			assert(delta!=inf);
			now+=delta;
			choose[id]=!choose[id];
		}
		if(now<best)
		{
			assert(bcc());
			best=now;
			ans=g;
//			ans.print();
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x,y;
	g.init(n,true);
	ans.init(n,true);
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		edge[i]=mp(x,y);
		g.addEdges(x,y);
	}
	memset(choose,1,sizeof(choose));
	best=inf;
	for(int i=0;i<20;i++)
	{
		solve();
	}
	cout<<best<<endl;
	for(int i=0;i<ans.n;i++)
	{
		for(auto u:ans.edges[i])
		{
			if(u>i) cout<<i+1<<' '<<u+1<<endl;
		}
	}
	return 0;
}