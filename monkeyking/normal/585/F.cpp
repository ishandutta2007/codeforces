//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//string s,a,b;
//
//int States;
//struct State
//{
//	int id;
//	int go[10];
//	int link;
//	int len;
//}states[2005];
//int root,last;
//
//int newState(int len)
//{
//	State &state=states[States];
//	state.len=len;
//	memset(state.go,-1,sizeof(state.go));
//	state.id=States;
//	state.link=-1;
//	return States++;
//}
//
//void extend(int w)
//{
//	int T=last,Tx=newState(states[T].len+1);
//	// debug(T,Tx);
//	last=Tx;
//	while(~T && states[T].go[w]==-1)
//	{
//		// debug(T,w,Tx);
//		states[T].go[w]=Tx;
//		T=states[T].link;
//	}
//	if(T==-1)
//	{
//		// debug(Tx,root);
//		states[Tx].link=root;
//		return;
//	}
//	int p=states[T].go[w];
//	if(states[p].len-1==states[T].len)
//	{
//		states[Tx].link=p;
//	}
//	else
//	{
//		int q=newState(states[T].len+1);
//		memcpy(states[q].go,states[p].go,sizeof(states[p].go));
//		states[q].link=states[p].link;
//		states[p].link=q;
//		states[Tx].link=q;
//		while(~T && states[T].go[w]==p)
//		{
//			states[T].go[w]=q;
//			T=states[T].link;
//		}
//	}
//}
//
//int dp[2005][55][55][2][2];//??,???,??combo,sm?,?????1/2
//int res;
//
//int solve(string a,int contain)
//{
//	int n=a.size();
//	memset(dp,0,sizeof(dp));
//	dp[0][0][0][1][0]=1;
//	for(int j=0;j<n;j++)
//	{
//		for(int i=0;i<States;i++)
//		{
//			for(int comb=0;comb<=j;comb++)
//			{
//				for(int sm=0;sm<2;sm++)
//				{
//					for(int ar=0;ar<2;ar++)
//					{
//						int val=dp[i][j][comb][sm][ar];
//						if(!val) continue;
//						for(int d=(j==0?1:0);d<10;d++)
//						{
//							if(sm && d>a[j]-'0') continue;
//							int ni=i,ncomb=comb;
//							while(~ni && states[ni].go[d]==-1)
//							{
//								ni=states[ni].link;
//								chmin(ncomb,(~ni?states[ni].len:0));
//							}
//							if(ni==-1) ni=0;else ni=states[ni].go[d],ncomb++;
//							chadd(dp[ni][j+1][ncomb][(sm && d==a[j]-'0')?1:0][ncomb>=n/2?1:ar],val);
//						}
//					}
//				}
//			}
//		}
//	}
//	// debug(States);
//	// cout<<dp[states[0].go[2]][1][1][1][1]<<endl;
//	// cout<<dp[states[0].go[9]][]
//	// cout<<dp[0][0][0][1][0]<<endl;
//	// cout<<dp[0][1][0][1][0]<<endl;
//	// cout<<dp[1][2][1][1][1]<<endl;
//	// cout<<dp[1][1][1][1][1]<<endl;
//	// exit(0);
//	int res=0;
//	for(int i=0;i<States;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			chadd(res,dp[i][n][j][0][1]);
//			if(contain) chadd(res,dp[i][n][j][1][1]);
//		}
//	}
//	// debug(res);
//	// exit(0);
//	return res;
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>s>>a>>b;
//	root=last=newState(0);
//	for(int i=0;i<s.size();i++) extend(s[i]-'0');
//	// cout<<states[states[0].go[0]].go[2]<<endl;
//	// cout<<states[0].go[2]<<endl;
//	// cout<<states[0].go[0]<<endl;
//	// cout<<solve(b,1)<<endl;
//	chadd(res,mod-solve(a,0));
//	chadd(res,solve(b,1));
//	cout<<res<<endl;
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
string s,a,b;

int States;
struct State
{
	int id;
	int go[10];
	int link;
	int len;
}states[2005];
int root,last;

int newState(int len)
{
	State &state=states[States];
	state.len=len;
	memset(state.go,-1,sizeof(state.go));
	state.id=States;
	state.link=-1;
	return States++;
}

void extend(int w)
{
	int T=last,Tx=newState(states[T].len+1);
	// debug(T,Tx);
	last=Tx;
	while(~T && states[T].go[w]==-1)
	{
		// debug(T,w,Tx);
		states[T].go[w]=Tx;
		T=states[T].link;
	}
	if(T==-1)
	{
		// debug(Tx,root);
		states[Tx].link=root;
		return;
	}
	int p=states[T].go[w];
	if(states[p].len-1==states[T].len)
	{
		states[Tx].link=p;
	}
	else
	{
		int q=newState(states[T].len+1);
		memcpy(states[q].go,states[p].go,sizeof(states[p].go));
		states[q].link=states[p].link;
		states[p].link=q;
		states[Tx].link=q;
		while(~T && states[T].go[w]==p)
		{
			states[T].go[w]=q;
			T=states[T].link;
		}
	}
}

int dp[2005][55][55][2][2];//??,???,??combo,sm?,?????1/2
int res;

int solve(string a,int contain)
{
	int n=a.size();
	memset(dp,0,sizeof(dp));
	dp[0][0][0][1][0]=1;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<States;i++)
		{
			for(int comb=0;comb<=j;comb++)
			{
				for(int sm=0;sm<2;sm++)
				{
					for(int ar=0;ar<2;ar++)
					{
						int val=dp[i][j][comb][sm][ar];
						if(!val) continue;
						for(int d=(j==0?1:0);d<10;d++)
						{
							if(sm && d>a[j]-'0') continue;
							int ni=i,ncomb=comb;
							while(~ni && states[ni].go[d]==-1)
							{
								ni=states[ni].link;
								chmin(ncomb,(~ni?states[ni].len:0));
							}
							if(ni==-1) ni=0;else ni=states[ni].go[d],ncomb++;
							chadd(dp[ni][j+1][ncomb][(sm && d==a[j]-'0')?1:0][ncomb>=n/2?1:ar],val);
						}
					}
				}
			}
		}
	}
	// debug(States);
	// cout<<dp[states[0].go[2]][1][1][1][1]<<endl;
	// cout<<dp[states[0].go[9]][]
	// cout<<dp[0][0][0][1][0]<<endl;
	// cout<<dp[0][1][0][1][0]<<endl;
	// cout<<dp[1][2][1][1][1]<<endl;
	// cout<<dp[1][1][1][1][1]<<endl;
	// exit(0);
	int res=0;
	for(int i=0;i<States;i++)
	{
		for(int j=0;j<=n;j++)
		{
			chadd(res,dp[i][n][j][0][1]);
			if(contain) chadd(res,dp[i][n][j][1][1]);
		}
	}
	// debug(res);
	// exit(0);
	return res;
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>s>>a>>b;
	root=last=newState(0);
	for(int i=0;i<s.size();i++) extend(s[i]-'0');
	// cout<<states[states[0].go[0]].go[2]<<endl;
	// cout<<states[0].go[2]<<endl;
	// cout<<states[0].go[0]<<endl;
	// cout<<solve(b,1)<<endl;
	chadd(res,mod-solve(a,0));
	chadd(res,solve(b,1));
	cout<<res<<endl;
	return 0;
}