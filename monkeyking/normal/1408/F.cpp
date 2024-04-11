//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//vector <pii> res;
//
//inline void make(int x,int y)
//{
//	res.push_back(mp(x+1,y+1));
//}
//
//inline void merge(int l,int r,int len)
//{
//	for(int i=0;i<len;i++)
//	{
//		make(l+i,r+i);
//	}
//}
//
//inline vector <int> merge(vector <int> a,vector <int> b)
//{
//	vector <int> c;
//	for(int i=0;i<(int)a.size();i++)
//	{
//		make(a[i],b[i]);
//		c.push_back(a[i]);
//		c.push_back(b[i]);
//	}
//	return c;
//}
//
//inline void stmerge(vector <int> &a,vector <int> &b)
//{
//	int lena=a.size();
//	vector <int> c;
//	for(int i=0;i<lena;i++)
//	{
//		make(a[i],b.back());
//		c.push_back(a[i]);
//		c.push_back(b.back());
//		b.pop_back();
//	}
//	a=c;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n;
//	vector <pii> rm;
//	int tn=n;
//	for(int lg=0;;lg++)
//	{
//		int i;
//		for(i=0;i+(1<<(lg+1))<=tn;i+=1<<(lg+1))
//		{
//			merge(i,i+(1<<lg),(1<<lg));
//		}
//		if(tn-i) rm.push_back(mp(i,tn-i));
//		tn=i;
//		if(tn==0) break;
//	}
//	vector <vector <int> > vec;
//	for(auto u:rm)
//	{
//		vector <int> t;
//		for(int i=0;i<u.second;i++)
//		{
//			t.push_back(u.first+i);
//		}
//		vec.push_back(t);
//	}
//	reverse(all(vec));
//	while(vec.size()>2)
//	{
//		while(vec.back().size()!=vec[(int)vec.size()-2].size())
//		{
//			stmerge(vec.back(),vec[0]);
//		}
//		vec[(int)vec.size()-2]=merge(vec[(int)vec.size()-2],vec.back());
//		vec.pop_back();
//	}
//	cout<<res.size()<<endl;
//	for(auto u:res)
//	{
//		printf("%d %d\n",u.first,u.second);
//	}
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
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
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

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
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
using namespace std;
int n;
vector <pii> res;

inline void make(int x,int y)
{
	res.push_back(mp(x+1,y+1));
}

inline void merge(int l,int r,int len)
{
	for(int i=0;i<len;i++)
	{
		make(l+i,r+i);
	}
}

inline vector <int> merge(vector <int> a,vector <int> b)
{
	vector <int> c;
	for(int i=0;i<(int)a.size();i++)
	{
		make(a[i],b[i]);
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	return c;
}

inline void stmerge(vector <int> &a,vector <int> &b)
{
	int lena=a.size();
	vector <int> c;
	for(int i=0;i<lena;i++)
	{
		make(a[i],b.back());
		c.push_back(a[i]);
		c.push_back(b.back());
		b.pop_back();
	}
	a=c;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	vector <pii> rm;
	int tn=n;
	for(int lg=0;;lg++)
	{
		int i;
		for(i=0;i+(1<<(lg+1))<=tn;i+=1<<(lg+1))
		{
			merge(i,i+(1<<lg),(1<<lg));
		}
		if(tn-i) rm.push_back(mp(i,tn-i));
		tn=i;
		if(tn==0) break;
	}
	vector <vector <int> > vec;
	for(auto u:rm)
	{
		vector <int> t;
		for(int i=0;i<u.second;i++)
		{
			t.push_back(u.first+i);
		}
		vec.push_back(t);
	}
	reverse(all(vec));
	while(vec.size()>2)
	{
		while(vec.back().size()!=vec[(int)vec.size()-2].size())
		{
			stmerge(vec.back(),vec[0]);
		}
		vec[(int)vec.size()-2]=merge(vec[(int)vec.size()-2],vec.back());
		vec.pop_back();
	}
	cout<<res.size()<<endl;
	for(auto u:res)
	{
		printf("%d %d\n",u.first,u.second);
	}
	return 0;
}