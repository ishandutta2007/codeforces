//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//ll n,m;
//int k;
//ll a[10005],b[10005];
//ll in[10005];
//
//ll gcd(ll x,ll y)
//{
//	return (x?gcd(y%x,x):y);
//}
//
//ll UltimateMultiply(ll a,ll b,ll mod)
//{
//	ll res=0;
//	while(b)
//	{
//		if(b&1)
//		{
//			res+=a;
//			if(res>=mod) res-=mod;
//		}
//		b>>=1;
//		a+=a;
//		if(a>=mod) a-=mod;;
//	}
//	return res;
//}
//
//struct ShengyuDingli
//{
//	ll UltimateMultiply(ll a,ll b,ll mod)
//	{
//		ll res=0;
//		while(b)
//		{
//			if(b&1)
//			{
//				res+=a;
//				if(res>=mod) res-=mod;
//			}
//			b>>=1;
//			a+=a;
//			if(a>=mod) a-=mod;;
//		}
//		return res;
//	}
//	inline ll exgcd(ll a,ll b,ll &x,ll &y)
//	{
//		if(a==0)
//		{
//			x=0;
//			y=1;
//			return b;
//		}
//		ll gcd=exgcd(b%a,a,x,y);
//		swap(x,y);
//		x-=(b/a)*y;
//		return gcd;
//	}
//	inline bool exgcd(ll a,ll b,ll c,ll &x,ll &y)
//	{
////		cout<<a<<' '<<b<<' '<<c<<' ';
//		ll mx(1),my(1);
//		if(a<0) a=-a,mx=-mx;
//		if(b<0) b=-b,my=-my;
//		ll gcd=exgcd(a,b,x,y);
//		if(c%gcd!=0) return false;
//		if(gcd<0) gcd=-gcd;
//		c/=gcd;
//		x*=c*mx;
//		y*=c*my;
////		cout<<x<<' '<<y<<endl;
//		return true;
//	}
//	void test()
//	{
//		ll x0,y0;
//		ll a,b,c;
//		cin>>a>>b>>c;
//		ll gcd=exgcd(a,b,x0,y0);
//		cout<<x0<<' '<<y0<<' '<<gcd<<endl;
//	}
//	bool solve2eq(ll a1,ll m1,ll a2,ll m2,ll &a0,ll &m0)
//	{
//		if(a1>a2)
//		{
//			swap(a1,a2);
//			swap(m1,m2);
//		}
//		ll x,y;
//		ll gcd=exgcd(m1,-m2,x,y);//a2-a1,
////		cout<<a1<<' '<<m1<<' '<<a2<<' '<<m2<<' '<<gcd<<endl;
//		if((a2-a1)%gcd) return false;
//		ll multiplier=(a2-a1)/gcd;
//		ll nm=m1/abs(gcd)*m2;
//		chmod(multiplier,nm);
//		if(m1<0) return false;
//		x=UltimateMultiply(multiplier,x,nm);
//		ll x0=UltimateMultiply(x,m1,nm)+a1;
//		chmod(x0,nm);
//		a0=x0;
//		m0=nm;
//		return true;
//	}
//	bool solve(ll a[],ll m[],int len,ll &a0,ll &m0)
//	{
//		a0=a[0];
//		m0=m[0];
//		for(int i=1;i<len;i++)
//		{
//			if(!solve2eq(a0,m0,a[i],m[i],a0,m0)) return false;
//		}
//		return true;
//	}
//}solver;
//
//bool check(ll x,ll y)
//{
//	for(int i=0;i<k;i++)
//	{
//		if(__gcd(x,y+i)!=in[i]) return false;
//	}
//	return true;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
////	solver.test();
////	exit(0);
//	quickcin;
//	cin>>n>>m>>k;
////	ll m0=1;
//	ll i0=1,j0;
//	for(int i=0;i<k;i++)
//	{
//		cin>>in[i];
//		a[i]=in[i]-i;
//		b[i]=in[i];
//		chmod(a[i],b[i]);
//		i0=i0/gcd(i0,b[i])*b[i];
//	}
//	ll a0,m0;
//	bool f=solver.solve(a,b,k,a0,m0);
//	if(!f) over("NO");
//	if(a0==0) j0=m0;else j0=a0;
//	if(i0>n) over("NO");
//	if(j0+k-1>m) over("NO");
//	if(!check(i0,j0)) over("NO");
//	puts("YES");
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
using namespace std;
ll n,m;
int k;
ll a[10005],b[10005];
ll in[10005];

ll gcd(ll x,ll y)
{
	return (x?gcd(y%x,x):y);
}

ll UltimateMultiply(ll a,ll b,ll mod)
{
	ll res=0;
	while(b)
	{
		if(b&1)
		{
			res+=a;
			if(res>=mod) res-=mod;
		}
		b>>=1;
		a+=a;
		if(a>=mod) a-=mod;;
	}
	return res;
}

struct ShengyuDingli
{
	ll UltimateMultiply(ll a,ll b,ll mod)
	{
		ll res=0;
		while(b)
		{
			if(b&1)
			{
				res+=a;
				if(res>=mod) res-=mod;
			}
			b>>=1;
			a+=a;
			if(a>=mod) a-=mod;;
		}
		return res;
	}
	inline ll exgcd(ll a,ll b,ll &x,ll &y)
	{
		if(a==0)
		{
			x=0;
			y=1;
			return b;
		}
		ll gcd=exgcd(b%a,a,x,y);
		swap(x,y);
		x-=(b/a)*y;
		return gcd;
	}
	inline bool exgcd(ll a,ll b,ll c,ll &x,ll &y)
	{
//		cout<<a<<' '<<b<<' '<<c<<' ';
		ll mx(1),my(1);
		if(a<0) a=-a,mx=-mx;
		if(b<0) b=-b,my=-my;
		ll gcd=exgcd(a,b,x,y);
		if(c%gcd!=0) return false;
		if(gcd<0) gcd=-gcd;
		c/=gcd;
		x*=c*mx;
		y*=c*my;
//		cout<<x<<' '<<y<<endl;
		return true;
	}
	void test()
	{
		ll x0,y0;
		ll a,b,c;
		cin>>a>>b>>c;
		ll gcd=exgcd(a,b,x0,y0);
		cout<<x0<<' '<<y0<<' '<<gcd<<endl;
	}
	bool solve2eq(ll a1,ll m1,ll a2,ll m2,ll &a0,ll &m0)
	{
		if(a1>a2)
		{
			swap(a1,a2);
			swap(m1,m2);
		}
		ll x,y;
		ll gcd=exgcd(m1,-m2,x,y);//a2-a1,
//		cout<<a1<<' '<<m1<<' '<<a2<<' '<<m2<<' '<<gcd<<endl;
		if((a2-a1)%gcd) return false;
		ll multiplier=(a2-a1)/gcd;
		ll nm=m1/abs(gcd)*m2;
		chmod(multiplier,nm);
		if(m1<0) return false;
		x=UltimateMultiply(multiplier,x,nm);
		ll x0=UltimateMultiply(x,m1,nm)+a1;
		chmod(x0,nm);
		a0=x0;
		m0=nm;
		return true;
	}
	bool solve(ll a[],ll m[],int len,ll &a0,ll &m0)
	{
		a0=a[0];
		m0=m[0];
		for(int i=1;i<len;i++)
		{
			if(!solve2eq(a0,m0,a[i],m[i],a0,m0)) return false;
		}
		return true;
	}
}solver;

bool check(ll x,ll y)
{
	for(int i=0;i<k;i++)
	{
		if(__gcd(x,y+i)!=in[i]) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	solver.test();
//	exit(0);
	quickcin;
	cin>>n>>m>>k;
//	ll m0=1;
	ll i0=1,j0;
	for(int i=0;i<k;i++)
	{
		cin>>in[i];
		a[i]=in[i]-i;
		b[i]=in[i];
		chmod(a[i],b[i]);
		i0=i0/gcd(i0,b[i])*b[i];
	}
	ll a0,m0;
	bool f=solver.solve(a,b,k,a0,m0);
	if(!f) over("NO");
	if(a0==0) j0=m0;else j0=a0;
	if(i0>n) over("NO");
	if(j0+k-1>m) over("NO");
	if(!check(i0,j0)) over("NO");
	puts("YES");
	return 0;
}