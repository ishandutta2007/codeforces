//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/rand>
//using namespace std;
//const int B=2;
//int rd[B][500005];
//int n;
//int a[500005];
//int s[500005];
//ll hh[B][500005];
//map <ll,int> m[B];
//map <int,int> ap;
//set <pii> squ;
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	scanf("%d",&n);
//	for(int i=0;i<B;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			rd[i][j]=rand(1,1e9);
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//		a[i]--;
//		s[a[i]]++;
//		for(int j=0;j<B;j++)
//		{
//			if(s[a[i]]%3==0)
//			{
//				hh[j][i]=-2*rd[j][a[i]];
//			}
//			else
//			{
//				hh[j][i]=rd[j][a[i]];
//			}
//		}
//	}
//	for(int i=0;i<B;i++)
//	{
////		cout<<hh[i][0]<<' ';
//		for(int j=1;j<n;j++)
//		{
//			hh[i][j]+=hh[i][j-1];
////			cout<<hh[i][j]<<' ';
//		}
////		cout<<endl;
//	}
//	for(int i=0;i<B;i++)
//	{
//		m[i][0]++;
//	}
//	ll res=0;
//	int l=0;
//	for(int i=0;i<n;i++)
//	{
//		if(ap.find(a[i])!=ap.end()) squ.erase(mp(ap[a[i]],a[i]));
//		ap[a[i]]++;
//		squ.insert(mp(ap[a[i]],a[i]));
//		while((--squ.end())->first>3)
//		{
//			squ.erase(mp(ap[a[l]],a[l]));
//			ap[a[l]]--;
//			squ.insert(mp(ap[a[l]],a[l]));
//			for(int j=0;j<B;j++)
//			{
//				m[j][(l?hh[j][l-1]:0)]--;
//			}
//			l++;
//		}
//		int s=inf;
//		for(int j=0;j<B;j++)
//		{
//			chmin(s,m[j][hh[j][i]]);
//		}
//		res+=s;
//		for(int j=0;j<B;j++)
//		{
//			m[j][hh[j][i]]++;
//		}
//	}
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
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=998244353;
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
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
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
#define rand(l,r) uniform_int_distribution<ll>(l,r)(rng)
#endif
#endif
using namespace std;
const int B=2;
int rd[B][500005];
int n;
int a[500005];
int s[500005];
ll hh[B][500005];
map <ll,int> m[B];
map <int,int> ap;
set <pii> squ;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<B;i++)
	{
		for(int j=0;j<n;j++)
		{
			rd[i][j]=rand(1,1e9);
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
		s[a[i]]++;
		for(int j=0;j<B;j++)
		{
			if(s[a[i]]%3==0)
			{
				hh[j][i]=-2*rd[j][a[i]];
			}
			else
			{
				hh[j][i]=rd[j][a[i]];
			}
		}
	}
	for(int i=0;i<B;i++)
	{
//		cout<<hh[i][0]<<' ';
		for(int j=1;j<n;j++)
		{
			hh[i][j]+=hh[i][j-1];
//			cout<<hh[i][j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=0;i<B;i++)
	{
		m[i][0]++;
	}
	ll res=0;
	int l=0;
	for(int i=0;i<n;i++)
	{
		if(ap.find(a[i])!=ap.end()) squ.erase(mp(ap[a[i]],a[i]));
		ap[a[i]]++;
		squ.insert(mp(ap[a[i]],a[i]));
		while((--squ.end())->first>3)
		{
			squ.erase(mp(ap[a[l]],a[l]));
			ap[a[l]]--;
			squ.insert(mp(ap[a[l]],a[l]));
			for(int j=0;j<B;j++)
			{
				m[j][(l?hh[j][l-1]:0)]--;
			}
			l++;
		}
		int s=inf;
		for(int j=0;j<B;j++)
		{
			chmin(s,m[j][hh[j][i]]);
		}
		res+=s;
		for(int j=0;j<B;j++)
		{
			m[j][hh[j][i]]++;
		}
	}
	cout<<res<<endl;
	return 0;
}