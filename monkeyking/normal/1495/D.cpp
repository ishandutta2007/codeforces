//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m;
//vector<int> edges[405];
//int res[405][405];
//int dist[405][405];
//
//int solve(int x)
//{
//	vector<vector<int> > v(n);
//	for(int i=0;i<n;i++)
//	{
//		v[dist[x][i]].push_back(i);
//	}
//	int res=1;
//	for(int i=1;i<n;i++)
//	{
//		for(auto &z:v[i])
//		{
//			int cnt=0;
//			for(auto &u:v[i-1])
//			{
//				if(dist[u][z]==1) cnt++;
//			}
//			res=1LL*res*cnt%mod;
//		}
//	}
//	return res;
//}
//
//// void solve(int x,vector<int> U)
//// {
//// 	vector<vector<int> > v(n);
//// 	for(auto i:U)
//// 	{
//// 		v[dist[x][i]].push_back(i);
//// 	}
//// 	int res=1;
//// 	for(int i=1;i<n;i++)
//// 	{
//// 		for(auto &z:v[i])
//// 		{
//// 			int cnt=0;
//// 			for(auto &u:v[i-1])
//// 			{
//// 				if(dist[u][z]==1) cnt++;
//// 			}
//// 			res=1LL*res*cnt%mod;
//// 		}
//// 	}
//// 	return res;
//// }
//
//// int solve(int x,int y)
//// {
//// 	for(int i=0;i<n;i++)
//// 	{
//// 		if(dist[i][x]==dist[i][y]) return 0;
//// 	}
//// 	vector<int> v1,v2;
//// 	for(int i=0;i<n;i++)
//// 	{
//// 		if(dist[i][x]<dist[i][y]) v1.push_back(i);
//// 		else v2.push_back(i);
//// 	}
//// 	return 1LL*solve(x,v1)*solve(x,v2)%mod;
//// }
//
//// vector<int> V[405][405];
//int key[405];
//int solve2(int x,int y)
//{
//	memset(key,0,sizeof(key));
//	for(int i=0;i<n;i++)
//	{
//		if(dist[i][x]+dist[i][y]==dist[x][y]) key[i]=true;
//	}
//	int sk=accumulate(key,key+n,0);
//	if(sk!=dist[x][y]+1) return 0;
//	// vector<pii> vSort(n);
//	// for(int i=0;i<n;i++)
//	// {
//	// 	vSort[i]=mp(dist[x][i],i);
//	// 	// V[dist[x][i]][dist[y][i]].push_back(i);
//	// }
//	// sort(all(vSort));
//	// int res=1;
//	// for(auto [i,_]:vSort)
//	int res=1;
//	for(int i=0;i<n;i++)
//	{
//		if(key[i]) continue;
//		// if(dist[x][i]==0 )
//		int cnt=0;
//		for(auto j:edges[i])
//		{
//			if(dist[x][j]==dist[x][i]-1 && dist[y][j]==dist[y][i]-1) cnt++;
//		}
//		res=1LL*res*cnt%mod;
//	}
//	return res;
//	// int cnt=0;
//	// for(int i=0;i<n;i++)
//	// {
//
//	// 	cnt+=((dist[i][x]+dist[x][y]!=dist[i][y]) && (dist[i][y]+dist[y][x]!=dist[i][x]));
//	// }
//	// if(cnt!=(n-(dist[x][y]-1))) return 0;
//
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	memset(dist,0x3f,sizeof(dist));
//	for(int i=0;i<m;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		dist[x][y]=dist[y][x]=1;
//		edges[x].push_back(y);
//		edges[y].push_back(x);
//	}
//	for(int i=0;i<n;i++) dist[i][i]=0;
//	for(int k=0;k<n;k++)
//	{
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<n;j++)
//			{
//				chmin(dist[i][j],dist[i][k]+dist[k][j]);
//			}
//		}
//	}
//	// for(int i=0;i<n;i++)
//	// {
//	// 	for(auto j:edges[i])
//	// 	{
//	// 		if(i>j) continue;
//	// 		res[i][j]=res[j][i]=solve(i,j);
//	// 	}
//	// }
//	for(int i=0;i<n;i++)
//	{
//		res[i][i]=solve(i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//		{
//			int t=solve2(i,j);
//			res[i][j]=res[j][i]=t;
//			// if(res[i][j]==0) res[i][j]=res[j][i]=t;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			printf("%d ",res[i][j]);
//		}
//		puts("");
//	}
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_CONST_MOD 998244353
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
#define mp make_pair
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
const double eps=1e-9;
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
ostream &operator<<(ostream &cout, vector<T> vec)
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
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
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
vector<int> edges[405];
int res[405][405];
int dist[405][405];

int solve(int x)
{
	vector<vector<int> > v(n);
	for(int i=0;i<n;i++)
	{
		v[dist[x][i]].push_back(i);
	}
	int res=1;
	for(int i=1;i<n;i++)
	{
		for(auto &z:v[i])
		{
			int cnt=0;
			for(auto &u:v[i-1])
			{
				if(dist[u][z]==1) cnt++;
			}
			res=1LL*res*cnt%mod;
		}
	}
	return res;
}

// void solve(int x,vector<int> U)
// {
// 	vector<vector<int> > v(n);
// 	for(auto i:U)
// 	{
// 		v[dist[x][i]].push_back(i);
// 	}
// 	int res=1;
// 	for(int i=1;i<n;i++)
// 	{
// 		for(auto &z:v[i])
// 		{
// 			int cnt=0;
// 			for(auto &u:v[i-1])
// 			{
// 				if(dist[u][z]==1) cnt++;
// 			}
// 			res=1LL*res*cnt%mod;
// 		}
// 	}
// 	return res;
// }

// int solve(int x,int y)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		if(dist[i][x]==dist[i][y]) return 0;
// 	}
// 	vector<int> v1,v2;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(dist[i][x]<dist[i][y]) v1.push_back(i);
// 		else v2.push_back(i);
// 	}
// 	return 1LL*solve(x,v1)*solve(x,v2)%mod;
// }

// vector<int> V[405][405];
int key[405];
int solve2(int x,int y)
{
	memset(key,0,sizeof(key));
	for(int i=0;i<n;i++)
	{
		if(dist[i][x]+dist[i][y]==dist[x][y]) key[i]=true;
	}
	int sk=accumulate(key,key+n,0);
	if(sk!=dist[x][y]+1) return 0;
	// vector<pii> vSort(n);
	// for(int i=0;i<n;i++)
	// {
	// 	vSort[i]=mp(dist[x][i],i);
	// 	// V[dist[x][i]][dist[y][i]].push_back(i);
	// }
	// sort(all(vSort));
	// int res=1;
	// for(auto [i,_]:vSort)
	int res=1;
	for(int i=0;i<n;i++)
	{
		if(key[i]) continue;
		// if(dist[x][i]==0 )
		int cnt=0;
		for(auto j:edges[i])
		{
			if(dist[x][j]==dist[x][i]-1 && dist[y][j]==dist[y][i]-1) cnt++;
		}
		res=1LL*res*cnt%mod;
	}
	return res;
	// int cnt=0;
	// for(int i=0;i<n;i++)
	// {

	// 	cnt+=((dist[i][x]+dist[x][y]!=dist[i][y]) && (dist[i][y]+dist[y][x]!=dist[i][x]));
	// }
	// if(cnt!=(n-(dist[x][y]-1))) return 0;

}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		dist[x][y]=dist[y][x]=1;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for(int i=0;i<n;i++) dist[i][i]=0;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				chmin(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(auto j:edges[i])
	// 	{
	// 		if(i>j) continue;
	// 		res[i][j]=res[j][i]=solve(i,j);
	// 	}
	// }
	for(int i=0;i<n;i++)
	{
		res[i][i]=solve(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int t=solve2(i,j);
			res[i][j]=res[j][i]=t;
			// if(res[i][j]==0) res[i][j]=res[j][i]=t;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",res[i][j]);
		}
		puts("");
	}
	return 0;
}