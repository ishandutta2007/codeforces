//Original Code:
//#define __TAKE_MOD 1
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//struct Mat
//{
//	int a[2][2];
//	Mat(){memset(a,0,sizeof(a));}
//	Mat(int b,int c,int d,int e){a[0][0]=b;a[0][1]=c;a[1][0]=d;a[1][1]=e;}
//	auto operator[] (int k)const
//	{
//		return a[k];
//	}
//	auto operator[] (int k)
//	{
//		return a[k];
//	}
//}E(1,0,0,1);
//ostream & operator << (ostream &cout,const Mat &x)
//{
//	cout<<mp(mp(x[0][0],x[0][1]),mp(x[1][0],x[1][1]));
//	return cout;
//}
//
//Mat operator * (const Mat &a,const Mat &b)
//{
//	Mat t;
//	for(int i=0;i<2;i++)
//	{
//		for(int k=0;k<2;k++)
//		{
//			for(int j=0;j<2;j++)
//			{
//				(t[i][j]+=1LL*a[i][k]*b[k][j]%mod);
//			}
//		}
//	}
//	for(int i=0;i<2;i++)
//	{
//		for(int j=0;j<2;j++)
//		{
//			if(t[i][j]>=mod) t[i][j]-=mod;
//		}
//	}
//	return t;
//}
//
//int n,m;
//struct SegmentTree
//{
//	Mat data[50000*4];
//	int nn;
//	inline void build(Mat a[],int n)
//	{
//		nn=1;
//		while(nn<n)
//		{
//			nn<<=1;
//		}
//		for(int i=0;i<n;i++)
//		{
//			data[nn+i]=a[i];
//		}
//		for(int i=n;i<nn;i++) data[i+nn]=E;
//		for(int i=nn-1;i>=1;i--) data[i]=data[i*2]*data[i*2+1];
//	}
//	Mat query(int x,int l,int r,int ql,int qr)
//	{
//		if(l>=qr || r<=ql) return E;
//		if(l>=ql && r<=qr) return data[x];
//		return query(x*2,l,l+r>>1,ql,qr)*query(x*2+1,l+r>>1,r,ql,qr);
//	}
//	inline Mat query(int l,int r)
//	{
//		return query(1,0,nn,l,r);
//	}
//	inline Mat query()
//	{
//		return data[1];
//	}
//	inline Mat queryL(int l)
//	{
//		return query(0,l+1);
//	}
//	inline Mat queryR(int r)
//	{
//		return query(r,nn);
//	}
//}sgt;
//ll k;
//int a[50005];
//Mat t[50005];
//vector<pair<ll,int> > vSort;
//map<ll,int> ma;
//
//int geta(ll pos)
//{
//	if(pos==-1) return 0;
//	if(ma.find(pos)==ma.end())
//	{
//		// debug(pos%n);
//		return a[pos%n];  
//	}
//	return ma[pos];
//}
//
//inline Mat fastpow(Mat basic,ll x)
//{
//	Mat res=E;
//	while(x)
//	{
//		if(x&1) res=res*basic;
//		basic=basic*basic;
//		x>>=1;
//	}
//	return res;
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>k>>mod;
//	if(k==0) over(0);
//	cin>>n;
//	for(int i=0;i<n;i++) scanf("%d",a+i);
//	// debug(a[0],a[1],a[2]);
//	// cout<<sgt.queryR(0)<<endl;
//	// while(n<=3)
//	// {
//	// 	for(int i=n;i<n*2;i++) a[i]=a[i-n];
//	// 	n<<=1;
//	// }
//	for(int i=0;i<n;i++)
//	{
//		int a1=a[(i+1)%n];
//		int a2=a[i];
//		Mat x(a1,1,a2,0);
//		t[i]=x;
//	}
//	sgt.build(t,n);
//
//	scanf("%d",&m);
//	for(int i=0;i<m;i++)
//	{
//		ll j,v;
//		scanf("%lld%lld",&j,&v);
//		ma[j]=v;
//		vSort.push_back(mp(j,v));
//	}
//	sort(all(vSort));
//	Mat now=E;
//	ll curPos=0;
//	while(vSort.size() && vSort.back().first>k) vSort.pop_back();
//	if(vSort.empty() || vSort.back().first!=k) vSort.push_back(mp(k,a[k%n]));
//	for(auto &[j,v]:vSort)
//	{
//		if(curPos==j-1)
//		{
//			now=now*Mat(geta(j),1,geta(j-1),0);
//			curPos++;
//			continue;
//		}
//		now=now*Mat(geta(curPos+1),1,geta(curPos),0);
//		curPos++;
//		if(curPos/n==(j-2)/n)
//		{
//			now=now*sgt.query(curPos%n,(j-2)%n+1);
//		}
//		else if(curPos<j-2)
//		{
//			now=now*sgt.queryR(curPos%n);
//			now=now*fastpow(sgt.query(),(j-2)/n-(curPos/n+1));
//			now=now*sgt.queryL((j-2)%n);
//		}
//		now=now*Mat(geta(j),1,geta(j-1),0);
//		curPos=j;
//	}
//	cout<<now[0][1]<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_MOD 1
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

struct Mat
{
	int a[2][2];
	Mat(){memset(a,0,sizeof(a));}
	Mat(int b,int c,int d,int e){a[0][0]=b;a[0][1]=c;a[1][0]=d;a[1][1]=e;}
	auto operator[] (int k)const
	{
		return a[k];
	}
	auto operator[] (int k)
	{
		return a[k];
	}
}E(1,0,0,1);
ostream & operator << (ostream &cout,const Mat &x)
{
	cout<<mp(mp(x[0][0],x[0][1]),mp(x[1][0],x[1][1]));
	return cout;
}

Mat operator * (const Mat &a,const Mat &b)
{
	Mat t;
	for(int i=0;i<2;i++)
	{
		for(int k=0;k<2;k++)
		{
			for(int j=0;j<2;j++)
			{
				(t[i][j]+=1LL*a[i][k]*b[k][j]%mod);
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(t[i][j]>=mod) t[i][j]-=mod;
		}
	}
	return t;
}

int n,m;
struct SegmentTree
{
	Mat data[50000*4];
	int nn;
	inline void build(Mat a[],int n)
	{
		nn=1;
		while(nn<n)
		{
			nn<<=1;
		}
		for(int i=0;i<n;i++)
		{
			data[nn+i]=a[i];
		}
		for(int i=n;i<nn;i++) data[i+nn]=E;
		for(int i=nn-1;i>=1;i--) data[i]=data[i*2]*data[i*2+1];
	}
	Mat query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return E;
		if(l>=ql && r<=qr) return data[x];
		return query(x*2,l,l+r>>1,ql,qr)*query(x*2+1,l+r>>1,r,ql,qr);
	}
	inline Mat query(int l,int r)
	{
		return query(1,0,nn,l,r);
	}
	inline Mat query()
	{
		return data[1];
	}
	inline Mat queryL(int l)
	{
		return query(0,l+1);
	}
	inline Mat queryR(int r)
	{
		return query(r,nn);
	}
}sgt;
ll k;
int a[50005];
Mat t[50005];
vector<pair<ll,int> > vSort;
map<ll,int> ma;

int geta(ll pos)
{
	if(pos==-1) return 0;
	if(ma.find(pos)==ma.end())
	{
		// debug(pos%n);
		return a[pos%n];  
	}
	return ma[pos];
}

inline Mat fastpow(Mat basic,ll x)
{
	Mat res=E;
	while(x)
	{
		if(x&1) res=res*basic;
		basic=basic*basic;
		x>>=1;
	}
	return res;
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>k>>mod;
	if(k==0) over(0);
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",a+i);
	// debug(a[0],a[1],a[2]);
	// cout<<sgt.queryR(0)<<endl;
	// while(n<=3)
	// {
	// 	for(int i=n;i<n*2;i++) a[i]=a[i-n];
	// 	n<<=1;
	// }
	for(int i=0;i<n;i++)
	{
		int a1=a[(i+1)%n];
		int a2=a[i];
		Mat x(a1,1,a2,0);
		t[i]=x;
	}
	sgt.build(t,n);

	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		ll j,v;
		scanf("%lld%lld",&j,&v);
		ma[j]=v;
		vSort.push_back(mp(j,v));
	}
	sort(all(vSort));
	Mat now=E;
	ll curPos=0;
	while(vSort.size() && vSort.back().first>k) vSort.pop_back();
	if(vSort.empty() || vSort.back().first!=k) vSort.push_back(mp(k,a[k%n]));
	for(auto &[j,v]:vSort)
	{
		if(curPos==j-1)
		{
			now=now*Mat(geta(j),1,geta(j-1),0);
			curPos++;
			continue;
		}
		now=now*Mat(geta(curPos+1),1,geta(curPos),0);
		curPos++;
		if(curPos/n==(j-2)/n)
		{
			now=now*sgt.query(curPos%n,(j-2)%n+1);
		}
		else if(curPos<j-2)
		{
			now=now*sgt.queryR(curPos%n);
			now=now*fastpow(sgt.query(),(j-2)/n-(curPos/n+1));
			now=now*sgt.queryL((j-2)%n);
		}
		now=now*Mat(geta(j),1,geta(j-1),0);
		curPos=j;
	}
	cout<<now[0][1]<<endl;
	return 0;
}