//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m;
//vector<pii> edges[100005];
//int depth[100005],par[100005];
//int que[100005],l,r;
//int wdepth[100005];
//
//void bfs()
//{
//	memset(depth,-1,sizeof(depth));
//	que[r++]=0;depth[0]=0;
//	while(l!=r)
//	{
//		int x=que[l++];
//		for(auto [u,w]:edges[x])
//		{
//			if(depth[u]==-1) depth[u]=depth[x]+1,que[r++]=u,par[u]=x,wdepth[u]=wdepth[x]^w;
//		}
//	}
//}
//
//map<int,int> ids;
//int tot;
//int states[1005];
//int to[405][405];
//const int K=5;
//
//void go(int space)
//{
//	if(ids.count(space)) return;
//	states[tot]=space;
//	ids[space]=tot++;
//	for(int i=0;i<(1<<K);i++)
//	{
//		if(space & (1<<i)) continue;
//		int nspace=space | (1<<i);
//		for(int j=0;j<(1<<K);j++)
//		{
//			if((1<<j) & space) nspace|=(1<<(j^i));
//		}
//		if(nspace & 1) nspace=1;
//		go(nspace);
//	}
//}
//
//struct DSU
//{
//	int fa[100005],sp[100005];
//	void init(int n)
//	{
//		for(int i=0;i<n;i++) fa[i]=0,sp[i]=0;
//	}
//	int find(int x)
//	{
//		return (fa[x]==x?x:fa[x]=find(fa[x]));
//	}
//	void merge(int x,int y)
//	{
//		x=find(x);
//		y=find(y);
//		fa[x]=y;
//		sp[y]=to[sp[y]][sp[x]];
//	}
//};
//
//int ord[100005],vis[100005],T,pos[100005];
//tuple<int,int,int> edge[100005];
//int sp[100005],tri[100005];
//
//int dfs(int x,int col)
//{
//	int res=0;
//	vis[x]=col;
//	for(auto [u,w]:edges[x])
//	{
//		if(::par[u]!=x && ::par[x]!=u && !(::par[x]==0 && ::par[u]==0) && u<x)
//		{
//			// cout<<x<<' '<<u<<' '<<ids[1<<(w^wdepth[x]^wdepth[u])]<<endl;
//			// cout<<"Bef: "<<res<<endl;
//			res=to[res][ids[1<<(w^wdepth[x]^wdepth[u])]];
//			// cout<<x<<' '<<u<<' '<<w<<' '<<wdepth[x]<<' '<<wdepth[u]<<' '<<(w^wdepth[x]^wdepth[u])<<' '<<ids[1<<(w^wdepth[x]^wdepth[u])]<<endl;
//			// cout<<"Aft: "<<res<<endl;
//			// cout<<res<<endl;
//		}
//		if(vis[u]==col) continue;
//		// if(to[res][dfs(u,x,col)]==1) cout<<res<<' '<<dfs(u,x,col)<<endl;
//		res=to[res][dfs(u,col)];
//	}
//	// debug(res);
//	return res;
//}
//
//int dp[100005][405];
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	for(int i=0;i<m;i++)
//	{
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z);
//		x--;y--;
//		edges[x].emplace_back(y,z);
//		edges[y].emplace_back(x,z);
//		edge[i]=mt(x,y,z);
//	}
//	states[tot]=0;ids[0]=tot++;
//	states[tot]=1;ids[1]=tot++;
//	for(int i=1;i<32;i++) go((1<<i));
//	for(int i=0;i<tot;i++)
//	{
//		for(int j=0;j<tot;j++)
//		{
//			int nspace=states[i] | states[j];
//			for(int a=0;a<32;a++)
//			{
//				for(int b=0;b<32;b++)
//				{
//					if((states[i] & (1<<a)) && (states[j] & (1<<b))) nspace|=(1<<(a^b));
//				}
//			}
//			if(nspace & 1) nspace=1;
//			to[i][j]=ids[nspace];
//		}
//	}
//	bfs();
//	for(int i=0;i<m;i++)
//	{
//		auto [x,y,w]=edge[i];
//		if(depth[x]==1 && depth[y]==1)
//		{
//			vis[x]=vis[y]=1;
//			pos[x]=T;ord[T++]=x;
//			pos[y]=T;ord[T++]=y;
//			sp[pos[x]]=ids[1<<(w^wdepth[x]^wdepth[y])];
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		if(depth[i]==1 && !vis[i])
//		{
//			pos[i]=T;
//			ord[T++]=i;
//		}
//	}
//	// cout<<to[to[305][120]][2]<<endl;
//	// cout<<to[to[305][2]][120]<<endl;
//	// cout<<to[to[120][2]][305]<<endl;
//	memset(vis,-1,sizeof(vis));
//	// debug(T);
//	// for(int i=0;i<T;i++) cout<<ord[i]<<' ';
//	// cout<<endl;
//	for(int i=0;i<T;i++)
//	{
//		vis[0]=i;
//		tri[i]=dfs(ord[i],i);
//		// return 0;
//	}
//	// for(int i=0;i<n;i++) cout<<depth[i]<<' '<<par[i]<<endl;
//	// cout<<endl;
//	// for(int i=0;i<T;i++) cout<<ord[i]<<' ';
//	// cout<<endl;
//	// cout<<states[tri[0]]<<' '<<states[tri[1]]<<' '<<states[tri[2]]<<endl;
//	// cout<<tri[0]<<endl;
//	// return 0;
//	dp[0][0]=1;
//	int res=1;
//	for(int i=0;i<T;i++)
//	{
//		res=(res+res)%mod;
//		for(int j=0;j<tot;j++)
//		{
//			int w=dp[i][j];
//			if(!w) continue;
//			if(!sp[i])
//			{
//				chadd(dp[i+1][to[j][tri[i]]],w);
//				chadd(dp[i+1][j],w);
//			}
//			else
//			{
//				// cout<<i<<' '<<j<<" "<<to[j][to[tri[i]][sp[i]]]<<' '<<w<<endl;
//				chadd(dp[i+2][j],w);
//				chadd(dp[i+2][to[j][tri[i]]],2*w%mod);
//				chadd(dp[i+2][to[j][to[tri[i]][sp[i]]]],w);
//			}
//		}
//	}
//	cout<<(res-dp[T][1]+mod)%mod<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
#include <time.h>
#define Endl endl
#define mp(a,b) make_pair(a,b)
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
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
		std::cout<<(x&1);
		x>>=1;
		len--;
		// vec.push_back(x&1);
		// x>>=1;
	}
	while(len--) cout<<0;
	// reverse(vec.begin(),vec.end());
	// for(int i=(int)vec.size();i<len;i++)
	// {
	// 	putchar('0');
	// }
	// for(size_t i=0;i<vec.size();i++)
	// {
	// 	std::cout<<vec[i];
	// }
	// std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
using namespace std;
int n,m;
vector<pii> edges[100005];
int depth[100005],par[100005];
int que[100005],l,r;
int wdepth[100005];

void bfs()
{
	memset(depth,-1,sizeof(depth));
	que[r++]=0;depth[0]=0;
	while(l!=r)
	{
		int x=que[l++];
		for(auto [u,w]:edges[x])
		{
			if(depth[u]==-1) depth[u]=depth[x]+1,que[r++]=u,par[u]=x,wdepth[u]=wdepth[x]^w;
		}
	}
}

map<int,int> ids;
int tot;
int states[1005];
int to[405][405];
const int K=5;

void go(int space)
{
	if(ids.count(space)) return;
	states[tot]=space;
	ids[space]=tot++;
	for(int i=0;i<(1<<K);i++)
	{
		if(space & (1<<i)) continue;
		int nspace=space | (1<<i);
		for(int j=0;j<(1<<K);j++)
		{
			if((1<<j) & space) nspace|=(1<<(j^i));
		}
		if(nspace & 1) nspace=1;
		go(nspace);
	}
}

struct DSU
{
	int fa[100005],sp[100005];
	void init(int n)
	{
		for(int i=0;i<n;i++) fa[i]=0,sp[i]=0;
	}
	int find(int x)
	{
		return (fa[x]==x?x:fa[x]=find(fa[x]));
	}
	void merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		fa[x]=y;
		sp[y]=to[sp[y]][sp[x]];
	}
};

int ord[100005],vis[100005],T,pos[100005];
tuple<int,int,int> edge[100005];
int sp[100005],tri[100005];

int dfs(int x,int col)
{
	int res=0;
	vis[x]=col;
	for(auto [u,w]:edges[x])
	{
		if(::par[u]!=x && ::par[x]!=u && !(::par[x]==0 && ::par[u]==0) && u<x)
		{
			// cout<<x<<' '<<u<<' '<<ids[1<<(w^wdepth[x]^wdepth[u])]<<endl;
			// cout<<"Bef: "<<res<<endl;
			res=to[res][ids[1<<(w^wdepth[x]^wdepth[u])]];
			// cout<<x<<' '<<u<<' '<<w<<' '<<wdepth[x]<<' '<<wdepth[u]<<' '<<(w^wdepth[x]^wdepth[u])<<' '<<ids[1<<(w^wdepth[x]^wdepth[u])]<<endl;
			// cout<<"Aft: "<<res<<endl;
			// cout<<res<<endl;
		}
		if(vis[u]==col) continue;
		// if(to[res][dfs(u,x,col)]==1) cout<<res<<' '<<dfs(u,x,col)<<endl;
		res=to[res][dfs(u,col)];
	}
	// debug(res);
	return res;
}

int dp[100005][405];
int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--;y--;
		edges[x].emplace_back(y,z);
		edges[y].emplace_back(x,z);
		edge[i]=mt(x,y,z);
	}
	states[tot]=0;ids[0]=tot++;
	states[tot]=1;ids[1]=tot++;
	for(int i=1;i<32;i++) go((1<<i));
	for(int i=0;i<tot;i++)
	{
		for(int j=0;j<tot;j++)
		{
			int nspace=states[i] | states[j];
			for(int a=0;a<32;a++)
			{
				for(int b=0;b<32;b++)
				{
					if((states[i] & (1<<a)) && (states[j] & (1<<b))) nspace|=(1<<(a^b));
				}
			}
			if(nspace & 1) nspace=1;
			to[i][j]=ids[nspace];
		}
	}
	bfs();
	for(int i=0;i<m;i++)
	{
		auto [x,y,w]=edge[i];
		if(depth[x]==1 && depth[y]==1)
		{
			vis[x]=vis[y]=1;
			pos[x]=T;ord[T++]=x;
			pos[y]=T;ord[T++]=y;
			sp[pos[x]]=ids[1<<(w^wdepth[x]^wdepth[y])];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(depth[i]==1 && !vis[i])
		{
			pos[i]=T;
			ord[T++]=i;
		}
	}
	// cout<<to[to[305][120]][2]<<endl;
	// cout<<to[to[305][2]][120]<<endl;
	// cout<<to[to[120][2]][305]<<endl;
	memset(vis,-1,sizeof(vis));
	// debug(T);
	// for(int i=0;i<T;i++) cout<<ord[i]<<' ';
	// cout<<endl;
	for(int i=0;i<T;i++)
	{
		vis[0]=i;
		tri[i]=dfs(ord[i],i);
		// return 0;
	}
	// for(int i=0;i<n;i++) cout<<depth[i]<<' '<<par[i]<<endl;
	// cout<<endl;
	// for(int i=0;i<T;i++) cout<<ord[i]<<' ';
	// cout<<endl;
	// cout<<states[tri[0]]<<' '<<states[tri[1]]<<' '<<states[tri[2]]<<endl;
	// cout<<tri[0]<<endl;
	// return 0;
	dp[0][0]=1;
	int res=1;
	for(int i=0;i<T;i++)
	{
		res=(res+res)%mod;
		for(int j=0;j<tot;j++)
		{
			int w=dp[i][j];
			if(!w) continue;
			if(!sp[i])
			{
				chadd(dp[i+1][to[j][tri[i]]],w);
				chadd(dp[i+1][j],w);
			}
			else
			{
				// cout<<i<<' '<<j<<" "<<to[j][to[tri[i]][sp[i]]]<<' '<<w<<endl;
				chadd(dp[i+2][j],w);
				chadd(dp[i+2][to[j][tri[i]]],2*w%mod);
				chadd(dp[i+2][to[j][to[tri[i]][sp[i]]]],w);
			}
		}
	}
	cout<<(res-dp[T][1]+mod)%mod<<endl;
	return 0;
}