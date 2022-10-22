//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,q,a,b;
//int x[6005];
//#define double long double
//double ans[6005];
//
//struct F
//{
//	double a,b,c;
//	double minPlace(const double &l,const double &r)const
//	{
//		if((r-l)<=eps) return l;
//		if(a==0 && b==0) return l;
//		if(a==0) return (b>0?l:r);
//		if(a>0)
//		{
//			double t=-b/a/2;
//			if(t<l) t=l;
//			if(t>r) t=r;
//			return t;
//		}
//		else
//		{
//			double t=-b/a/2;
//			return mabs(t-l)>mabs(t-r)?l:r;
//		}
//	}
//	double operator () (const double &pos)const
//	{
//		return a*pos*pos+b*pos+c;
//	}
//	F shift(double xs)const{
//		return F({a,-2*a*xs+b,xs*xs*a-b*xs+c});
//	}
//};
//F f[12005];
//double w[12005];
//int len;
//char tr[12005][12005];
//int sz[12005];
//double xm[12005];
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	cin>>n>>q>>a>>b;
//	for(int i=0;i<n;i++) scanf("%d",x+i);
//	f[len++]=F({0,0,0});
//	w[0]=1;
//	w[1]=q;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<len;j++)
//		{
//			f[j].a++;
//			f[j].b-=(x[i]<<1);
//			f[j].c+=1LL*x[i]*x[i];
//		}
//		if(i==n-1) break;
//
//		//todo: cut the function f
//		pair<double,int> o=mp(INFINITY,0);
//		for(int j=0;j<len;j++)
//		{
//			double p=f[j].minPlace(w[j],w[j+1]);
//			chmin(o,mp(f[j](p),j));
//		}
//		int pos=o.second;
//		double xm=f[pos].minPlace(w[pos],w[pos+1]);
//		// assert(xm>=w[pos] && xm<=w[pos+1]);
//		for(int j=len+1;j>pos+1;j--)
//		{
//			f[j]=f[j-2].shift(b-a);
//			tr[i][j]=-2;
//			w[j+1]=w[j-1]+(b-a);
//		}
//		w[pos+1]=xm;
//		w[pos+2]=xm+(b-a);
//		f[pos+1]=F({0,0,f[pos](xm)});
//		tr[i][pos+1]=-1;
//		len+=2;
//		for(int j=0;j<=len;j++) w[j]+=a;
//		for(int j=0;j<len;j++) f[j]=f[j].shift(a);
//		sz[i]=len;
//		::xm[i]=xm;
//		while(w[len-1]>q) len--;
//	}
//	pair<double,pair<double,int> > res=mp(INFINITY,mp(0.0,0));
//	for(int i=0;i<len;i++)
//	{
//		if(w[i]>q) break;
//		chmin(res,mp(f[i](f[i].minPlace(w[i],min(w[i+1],(double)q))),mp(f[i].minPlace(w[i],min(w[i+1],(double)q)),i)));
//	}
//	int pos=res.second.second;
//	ans[n-1]=res.second.first;
//	for(int i=n-2;i>=0;i--)
//	{
//		if(tr[i][pos]==-2)
//		{
//			pos-=2;
//			ans[i]=ans[i+1]-b;
//		}
//		else if(tr[i][pos]==-1)
//		{
//			pos-=1;
//			ans[i]=xm[i];
//		}
//		else
//		{
//			ans[i]=ans[i+1]-a;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%.10Lf ",ans[i]);
//	}
//	cout<<endl;
//	cout.precision(10);
//	cout<<fixed;
//	cout<<res.first<<endl;
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
int n,q,a,b;
int x[6005];
#define double long double
double ans[6005];

struct F
{
	double a,b,c;
	double minPlace(const double &l,const double &r)const
	{
		if((r-l)<=eps) return l;
		if(a==0 && b==0) return l;
		if(a==0) return (b>0?l:r);
		if(a>0)
		{
			double t=-b/a/2;
			if(t<l) t=l;
			if(t>r) t=r;
			return t;
		}
		else
		{
			double t=-b/a/2;
			return mabs(t-l)>mabs(t-r)?l:r;
		}
	}
	double operator () (const double &pos)const
	{
		return a*pos*pos+b*pos+c;
	}
	F shift(double xs)const{
		return F({a,-2*a*xs+b,xs*xs*a-b*xs+c});
	}
};
F f[12005];
double w[12005];
int len;
char tr[12005][12005];
int sz[12005];
double xm[12005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>q>>a>>b;
	for(int i=0;i<n;i++) scanf("%d",x+i);
	f[len++]=F({0,0,0});
	w[0]=1;
	w[1]=q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<len;j++)
		{
			f[j].a++;
			f[j].b-=(x[i]<<1);
			f[j].c+=1LL*x[i]*x[i];
		}
		if(i==n-1) break;

		//todo: cut the function f
		pair<double,int> o=mp(INFINITY,0);
		for(int j=0;j<len;j++)
		{
			double p=f[j].minPlace(w[j],w[j+1]);
			chmin(o,mp(f[j](p),j));
		}
		int pos=o.second;
		double xm=f[pos].minPlace(w[pos],w[pos+1]);
		// assert(xm>=w[pos] && xm<=w[pos+1]);
		for(int j=len+1;j>pos+1;j--)
		{
			f[j]=f[j-2].shift(b-a);
			tr[i][j]=-2;
			w[j+1]=w[j-1]+(b-a);
		}
		w[pos+1]=xm;
		w[pos+2]=xm+(b-a);
		f[pos+1]=F({0,0,f[pos](xm)});
		tr[i][pos+1]=-1;
		len+=2;
		for(int j=0;j<=len;j++) w[j]+=a;
		for(int j=0;j<len;j++) f[j]=f[j].shift(a);
		sz[i]=len;
		::xm[i]=xm;
		while(w[len-1]>q) len--;
	}
	pair<double,pair<double,int> > res=mp(INFINITY,mp(0.0,0));
	for(int i=0;i<len;i++)
	{
		if(w[i]>q) break;
		chmin(res,mp(f[i](f[i].minPlace(w[i],min(w[i+1],(double)q))),mp(f[i].minPlace(w[i],min(w[i+1],(double)q)),i)));
	}
	int pos=res.second.second;
	ans[n-1]=res.second.first;
	for(int i=n-2;i>=0;i--)
	{
		if(tr[i][pos]==-2)
		{
			pos-=2;
			ans[i]=ans[i+1]-b;
		}
		else if(tr[i][pos]==-1)
		{
			pos-=1;
			ans[i]=xm[i];
		}
		else
		{
			ans[i]=ans[i+1]-a;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%.10Lf ",ans[i]);
	}
	cout<<endl;
	cout.precision(10);
	cout<<fixed;
	cout<<res.first<<endl;
	return 0;
}