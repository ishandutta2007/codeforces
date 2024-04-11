//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/rand>
//using namespace std;
//const int IT=80;
//int n,m,k;
//vector <pair<int,int> > vec[200005];
//int tmp[200005];
//
//struct Hash
//{
//	typedef int T;
//	ll c[10][10];
//	inline bool checkPrime(T x)
//	{
//		for(T i=2;i*i<=x;i++)
//		{
//			if(x%i==0) return false;
//		}
//		return true;
//	}
//	inline int nextPrime(int x)
//	{
//		for(int i=x;;i++)
//		{
//			if(checkPrime(i)) return i;
//		}
//	}
//	void calc()
//	{
//		for(int i=0;i<n;i++)
//		{
//			tmp[i]=rand(0,1000000000);
//		}
//		int deg;
//		for(int i=0;i<n;i++)
//		{
//			deg=vec[i].size();
//			for(int ch=0;ch<deg;ch++)
//			{
//				c[deg][ch]+=tmp[i];
//				c[deg][ch]-=tmp[vec[i][ch].second];
//			}
//		}
//	}
//}h[IT];
//
//int trace[10];
//
//inline int solve()
//{
//	ll value=0;
//	for(int i=0;i<IT;i++)
//	{
//		value=0;
//		for(int j=1;j<=k;j++)
//		{
//			value+=h[i].c[j][trace[j]];
//		}
//		if(value!=0) return false;
//	}
//	return true;
//}
//
//int res;
//void dfs(int x)
//{
//	if(x==k+1)
//	{
//		res+=solve();
//		return;
//	}
//	for(int i=0;i<x;i++)
//	{
//		trace[x]=i;
//		dfs(x+1);
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m>>k;
//	int x,y,z;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d%d",&x,&y,&z);
//		x--;
//		y--;
//		vec[x].push_back(mp(z,y));
//	}
//	for(int i=0;i<n;i++)
//	{
//		sort(all(vec[i]));
//	}
//	for(int i=0;i<IT;i++)
//	{
//		h[i].calc();
//	}
//	dfs(1);
//	cout<<res<<endl;
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
const int IT=80;
int n,m,k;
vector <pair<int,int> > vec[200005];
int tmp[200005];

struct Hash
{
	typedef int T;
	ll c[10][10];
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
	inline int nextPrime(int x)
	{
		for(int i=x;;i++)
		{
			if(checkPrime(i)) return i;
		}
	}
	void calc()
	{
		for(int i=0;i<n;i++)
		{
			tmp[i]=rand(0,1000000000);
		}
		int deg;
		for(int i=0;i<n;i++)
		{
			deg=vec[i].size();
			for(int ch=0;ch<deg;ch++)
			{
				c[deg][ch]+=tmp[i];
				c[deg][ch]-=tmp[vec[i][ch].second];
			}
		}
	}
}h[IT];

int trace[10];

inline int solve()
{
	ll value=0;
	for(int i=0;i<IT;i++)
	{
		value=0;
		for(int j=1;j<=k;j++)
		{
			value+=h[i].c[j][trace[j]];
		}
		if(value!=0) return false;
	}
	return true;
}

int res;
void dfs(int x)
{
	if(x==k+1)
	{
		res+=solve();
		return;
	}
	for(int i=0;i<x;i++)
	{
		trace[x]=i;
		dfs(x+1);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		vec[x].push_back(mp(z,y));
	}
	for(int i=0;i<n;i++)
	{
		sort(all(vec[i]));
	}
	for(int i=0;i<IT;i++)
	{
		h[i].calc();
	}
	dfs(1);
	cout<<res<<endl;
	return 0;
}