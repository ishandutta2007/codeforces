//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int a[100005];
//string s;
//
//inline void print(vector<char> &v)
//{
//	for(int i=0;i<n;i++)
//	{
//		putchar(a[i]+'0');
//		putchar(i==n-1?'\n':v[i]);
//	}
//}
//
//namespace am
//{
//	vector<char> sgn(100005-1,0);
//	map <int,int> dp[100005];
//	map <int,pair<int,char> > trace[100005];
//	inline void Solve(int l,int r)
//	{
//		if(r-l<=1) return;
//		// leftmost and rightmost are not 1 or 0
//		dp[l][a[l]]=0;
//		trace[l][a[l]]=mp(-1,0);
//		int mut=1;
//		int allc=false;
//		for(int i=l;i<r;i++)
//		{
//			mut*=a[i];
//			if(mut>=n*100)
//			{
//				allc=true;
//				break;
//			}
//		}
//		if(allc)
//		{
//			for(int i=l;i<r-1;i++)
//			{
//				sgn[i]='*';
//			}
//			return;
//		}
//		for(int i=l;i<r-1;i++)
//		{
//			int ax=a[i+1];
//			for(auto [key,value]:dp[i])
//			{
//				if(value>=dp[i+1][key*ax])
//				{
//					dp[i+1][key*ax]=value;
//					trace[i+1][key*ax]=mp(key,'*');
//				}
//				if(value+key>=dp[i+1][ax])
//				{
//					dp[i+1][ax]=value+key;
//					trace[i+1][ax]=mp(key,'+');
//				}
//			}
//		}
////		debug(dp[n-1]);
////		debug(trace[n-1]);
//		pii res=mp(-1,-1);
//		for(auto x:dp[r-1])
//		{
//			chmax(res,mp(x.second+x.first,x.first));
//		}
//		int key=res.second;
//		for(int i=r-1;i>l;i--)
//		{
//			sgn[i-1]=(trace[i][key].second);
//			key=trace[i][key].first;
//		}
////		for(int i=l;i<r;i++)
////		{
////			debug(dp[i],trace[i]);
////		}
////		debug(dp[n-1]);
//	}
//	inline void solve(int l,int r)
//	{
//		if(r-l<=1) return;
//		while(a[l]==1)
//		{
//			sgn[l]='+';
//			l++;
//		}
//		while(a[r-1]==1)
//		{
//			sgn[r-2]='+';
//			r--;
//		}
//		Solve(l,r);
//	}
//	inline void solve()
//	{
//		int lst=0;
//		for(int i=0;i<n-1;i++)
//		{
//			if(a[i]==0 || a[i+1]==0) sgn[i]='+';
//			if(a[i+1]==0)
//			{
//				solve(lst,i+1);
//				lst=i+2;
//			}
////			debug(a[i],a[i+1],i,sgn[0]);
//		}
//		solve(lst,n);
//		print(sgn);
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//	}
//	cin>>s;
//	if(find(all(s),'+')!=s.end())
//	{
//		if(find(all(s),'-')!=s.end()) s.erase(find(all(s),'-'));
//		int has=(find(all(s),'*')!=s.end());
//		if(!has)
//		{
//			for(int i=0;i<n-1;i++)
//			{
//				putchar(a[i]+'0');
//				putchar('+');
//			}
//			putchar(a[n-1]+'0');
//			return 0;
//		}
//		//with + and * 
//		am::solve();
//		return 0;
//	}
//	// without +
//	if(s=="*")
//	{
//		for(int i=0;i<n;i++)
//		{
//			putchar(a[i]+'0');
//			if(i==n-1) puts("");else putchar('*');
//		}
//		return 0;
//	}
//	if(s=="-")
//	{
//		for(int i=0;i<n;i++)
//		{
//			putchar(a[i]+'0');
//			if(i==n-1) puts("");else putchar('-');
//		}
//		return 0;
//	}
//	//only with * & -
//	int have0=false;
//	for(int i=0;i<n-1;i++)
//	{
//		putchar(a[i]+'0');
//		if(a[i+1]==0)
//		{
//			putchar('-');
//			have0=true;
//			continue;
//		}
//		putchar('*');
//	}
//	putchar(a[n-1]+'0');
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
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
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
int n;
int a[100005];
string s;

inline void print(vector<char> &v)
{
	for(int i=0;i<n;i++)
	{
		putchar(a[i]+'0');
		putchar(i==n-1?'\n':v[i]);
	}
}

namespace am
{
	vector<char> sgn(100005-1,0);
	map <int,int> dp[100005];
	map <int,pair<int,char> > trace[100005];
	inline void Solve(int l,int r)
	{
		if(r-l<=1) return;
		// leftmost and rightmost are not 1 or 0
		dp[l][a[l]]=0;
		trace[l][a[l]]=mp(-1,0);
		int mut=1;
		int allc=false;
		for(int i=l;i<r;i++)
		{
			mut*=a[i];
			if(mut>=n*100)
			{
				allc=true;
				break;
			}
		}
		if(allc)
		{
			for(int i=l;i<r-1;i++)
			{
				sgn[i]='*';
			}
			return;
		}
		for(int i=l;i<r-1;i++)
		{
			int ax=a[i+1];
			for(auto [key,value]:dp[i])
			{
				if(value>=dp[i+1][key*ax])
				{
					dp[i+1][key*ax]=value;
					trace[i+1][key*ax]=mp(key,'*');
				}
				if(value+key>=dp[i+1][ax])
				{
					dp[i+1][ax]=value+key;
					trace[i+1][ax]=mp(key,'+');
				}
			}
		}
//		debug(dp[n-1]);
//		debug(trace[n-1]);
		pii res=mp(-1,-1);
		for(auto x:dp[r-1])
		{
			chmax(res,mp(x.second+x.first,x.first));
		}
		int key=res.second;
		for(int i=r-1;i>l;i--)
		{
			sgn[i-1]=(trace[i][key].second);
			key=trace[i][key].first;
		}
//		for(int i=l;i<r;i++)
//		{
//			debug(dp[i],trace[i]);
//		}
//		debug(dp[n-1]);
	}
	inline void solve(int l,int r)
	{
		if(r-l<=1) return;
		while(a[l]==1)
		{
			sgn[l]='+';
			l++;
		}
		while(a[r-1]==1)
		{
			sgn[r-2]='+';
			r--;
		}
		Solve(l,r);
	}
	inline void solve()
	{
		int lst=0;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]==0 || a[i+1]==0) sgn[i]='+';
			if(a[i+1]==0)
			{
				solve(lst,i+1);
				lst=i+2;
			}
//			debug(a[i],a[i+1],i,sgn[0]);
		}
		solve(lst,n);
		print(sgn);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	cin>>s;
	if(find(all(s),'+')!=s.end())
	{
		if(find(all(s),'-')!=s.end()) s.erase(find(all(s),'-'));
		int has=(find(all(s),'*')!=s.end());
		if(!has)
		{
			for(int i=0;i<n-1;i++)
			{
				putchar(a[i]+'0');
				putchar('+');
			}
			putchar(a[n-1]+'0');
			return 0;
		}
		//with + and * 
		am::solve();
		return 0;
	}
	// without +
	if(s=="*")
	{
		for(int i=0;i<n;i++)
		{
			putchar(a[i]+'0');
			if(i==n-1) puts("");else putchar('*');
		}
		return 0;
	}
	if(s=="-")
	{
		for(int i=0;i<n;i++)
		{
			putchar(a[i]+'0');
			if(i==n-1) puts("");else putchar('-');
		}
		return 0;
	}
	//only with * & -
	int have0=false;
	for(int i=0;i<n-1;i++)
	{
		putchar(a[i]+'0');
		if(a[i+1]==0)
		{
			putchar('-');
			have0=true;
			continue;
		}
		putchar('*');
	}
	putchar(a[n-1]+'0');
	return 0;
}