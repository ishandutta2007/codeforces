//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//int n,l;
//int pos[100005];
//inline void solve()
//{
//	cin>>n>>l;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>pos[i];
//	}
//	pos[0]=0;
//	pos[++n]=l;
//	n++;
//	long double a=0,b=l;
//	l=0;
//	int r=n-1;
//	long double res=0;
//	long double sa=1,sb=1;
//	while(true)
//	{
//		if(r-l==1)
//		{
//			res+=(b-a)/(sa+sb);
//			break;
//		}
//		long double ta=(pos[l+1]-a)/sa;
//		long double tb=(b-pos[r-1])/sb;
//		long double minTime=min(ta,tb);
//		a+=sa*minTime;
//		b-=sb*minTime;
//		res+=minTime;
//		if(ta>tb)
//		{
//			r--;
//			sb++;
//		}
//		else
//		{
//			l++;
//			sa++;
//		}
//	}
//	cout<<fixed;
//	cout.precision(20);
//	cout<<res<<endl;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	quickcin;
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		solve();
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

int n,l;
int pos[100005];
inline void solve()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>pos[i];
	}
	pos[0]=0;
	pos[++n]=l;
	n++;
	long double a=0,b=l;
	l=0;
	int r=n-1;
	long double res=0;
	long double sa=1,sb=1;
	while(true)
	{
		if(r-l==1)
		{
			res+=(b-a)/(sa+sb);
			break;
		}
		long double ta=(pos[l+1]-a)/sa;
		long double tb=(b-pos[r-1])/sb;
		long double minTime=min(ta,tb);
		a+=sa*minTime;
		b-=sb*minTime;
		res+=minTime;
		if(ta>tb)
		{
			r--;
			sb++;
		}
		else
		{
			l++;
			sa++;
		}
	}
	cout<<fixed;
	cout.precision(20);
	cout<<res<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}