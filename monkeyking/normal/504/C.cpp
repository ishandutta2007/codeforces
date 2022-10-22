//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int a[100005];
//int cntL[100005];
//int cntR[100005];
//int cnt1,cnt2,cnt3;//L<R,l=R,L>R
//ll res;
//int midLLimit; // L<=midLLimit
//int sideRLimit; // R>=sideRLimit
//
//inline void test()
//{
//	set <int> squ;
//	for(int i=0;i<n;i++)
//	{
//		if(squ.find(a[i])!=squ.end()) squ.erase(a[i]);
//		else squ.insert(a[i]);
//	}
//	if(squ.size()>1) over(0);
//}
//
//inline void incR(int x,int value)
//{
//	if(x==-1 || x==n) return;
//	x=a[x];
//	if(cntR[x]==cntL[x]) cnt2--;
//	if(cntR[x]>cntL[x]) cnt1--;
//	if(cntR[x]<cntL[x]) cnt3--;
//	cntR[x]+=value;
//	if(cntR[x]==cntL[x]) cnt2++;
//	if(cntR[x]>cntL[x]) cnt1++;
//	if(cntR[x]<cntL[x]) cnt3++;
//}
//
//inline void incL(int x,int value)
//{
//	if(x==-1 || x==n) return;
//	x=a[x];
//	if(cntR[x]==cntL[x]) cnt2--;
//	if(cntR[x]>cntL[x]) cnt1--;
//	if(cntR[x]<cntL[x]) cnt3--;
//	cntL[x]+=value;
//	if(cntR[x]==cntL[x]) cnt2++;
//	if(cntR[x]>cntL[x]) cnt1++;
//	if(cntR[x]<cntL[x]) cnt3++;
//}
//
//inline void inc(int &l)
//{
//	incR(l,-1);
//	int oR=min(l-1,n-1-l);
//	int nR=min(l+1-1,n-1-l-1);
//	if(oR+1==nR)
//	{
//		incL(nR,1);
//	}
//	else if(oR-1==nR)
//	{
//		incL(oR,-1);
//	}
//	l++;
//}
//
//inline void dec(int &l)
//{
//	incR(l-1,1);
//	int oR=min(l-1,n-1-l);
//	int nR=min(l-1-1,n-1-(l-1));
//	if(oR+1==nR)
//	{
//		incL(nR,1);
//	}
//	else if(oR-1==nR)
//	{
//		incL(oR,-1);
//	}
//	l--;
//}
//
//inline bool ok(int l,int r)
//{
//	if(l+r<n-1) return false;
//	if(l>r) return false;
//	if(cnt1!=0 && cnt3!=0) return false;
//	if(l>midLLimit) return false;
//	if(r<sideRLimit) return false;
//	return true;
//}
//
//inline void dec2(int r)
//{
//	incR(r,-1);
//	incL(n-1-r,-1);
//}
//
//inline void solve()
//{
//	cnt1=cnt3=0;
//	cnt2=n;
//	memset(cntL,0,sizeof(cntL));
//	memset(cntR,0,sizeof(cntR));
//	sideRLimit=n/2;
//	midLLimit=n-1;
//	for(int i=n-1;i>=n/2;i--)
//	{
//		if(a[i]!=a[n-1-i])
//		{
//			sideRLimit=i;
//			break;
//		}
//	}
//	for(int i=n/2;i<n;i++)
//	{
//		if(a[i]!=a[n-1-i])
//		{
//			midLLimit=i;
//			break;
//		}
//	}
//	// cout<<midLLimit<<' '<<sideRLimit<<endl;
//	for(int i=0;i<n;i++)
//	{
//		incR(i,1);
//	}
//	int l=0,r=n-1;
//	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
//	inc(l);
//	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
//	while(ok(l,r) && l<r) inc(l);
//	// cout<<l<<' '<<r<<endl;
//	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
//	// cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
//	// cout<<l<<endl;
//	for(r=n-1;r>=sideRLimit;r--)
//	{
//		while(!ok(l,r) && l+r>=n-1) dec(l);
//		// cout<<ok(l,r)<<':'<<'['<<l<<','<<r<<']'<<' '<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
//		if(ok(l,r)) res+=l-(n-1-r)+1;
//		dec2(r);
//	}
//	// cout<<"Total res="<<res<<endl;
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//	}
//	test();
//	solve();
//	// return 0;
//	reverse(a,a+n);
//	solve();
//	res-=(n-sideRLimit);
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
const int gmod=5;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
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

template <typename T>
void operator*=(vector<T> &vec, int k)
{
	for (auto &x : vec)
		x *= k;
}

template <typename T>
void operator-=(vector<T> &a, const vector<T> &b)
{
	assert(a.size() == b.size());
	for (size_t it = 0; it < a.size(); it++)
	{
		a[it] -= b[it];
	}
}

template <typename T>
vector<T> operator*(const vector<T> &vec, int k)
{
	vector<T> res(vec);
	res *= k;
	return res;
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

template <typename T>
T operator*(vector<T> v1, vector<T> v2)
{
	assert(v1.size() == v2.size());
	int n = v1.size();
	T res = 0;
	for (int i = 0; i < n; i++)
	{
		res += v1[i] * v2[i];
	}
	return res;
}

template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y)
{
	return make_pair(x.first + y.first, x.second + y.second);
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
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
int a[100005];
int cntL[100005];
int cntR[100005];
int cnt1,cnt2,cnt3;//L<R,l=R,L>R
ll res;
int midLLimit; // L<=midLLimit
int sideRLimit; // R>=sideRLimit

inline void test()
{
	set <int> squ;
	for(int i=0;i<n;i++)
	{
		if(squ.find(a[i])!=squ.end()) squ.erase(a[i]);
		else squ.insert(a[i]);
	}
	if(squ.size()>1) over(0);
}

inline void incR(int x,int value)
{
	if(x==-1 || x==n) return;
	x=a[x];
	if(cntR[x]==cntL[x]) cnt2--;
	if(cntR[x]>cntL[x]) cnt1--;
	if(cntR[x]<cntL[x]) cnt3--;
	cntR[x]+=value;
	if(cntR[x]==cntL[x]) cnt2++;
	if(cntR[x]>cntL[x]) cnt1++;
	if(cntR[x]<cntL[x]) cnt3++;
}

inline void incL(int x,int value)
{
	if(x==-1 || x==n) return;
	x=a[x];
	if(cntR[x]==cntL[x]) cnt2--;
	if(cntR[x]>cntL[x]) cnt1--;
	if(cntR[x]<cntL[x]) cnt3--;
	cntL[x]+=value;
	if(cntR[x]==cntL[x]) cnt2++;
	if(cntR[x]>cntL[x]) cnt1++;
	if(cntR[x]<cntL[x]) cnt3++;
}

inline void inc(int &l)
{
	incR(l,-1);
	int oR=min(l-1,n-1-l);
	int nR=min(l+1-1,n-1-l-1);
	if(oR+1==nR)
	{
		incL(nR,1);
	}
	else if(oR-1==nR)
	{
		incL(oR,-1);
	}
	l++;
}

inline void dec(int &l)
{
	incR(l-1,1);
	int oR=min(l-1,n-1-l);
	int nR=min(l-1-1,n-1-(l-1));
	if(oR+1==nR)
	{
		incL(nR,1);
	}
	else if(oR-1==nR)
	{
		incL(oR,-1);
	}
	l--;
}

inline bool ok(int l,int r)
{
	if(l+r<n-1) return false;
	if(l>r) return false;
	if(cnt1!=0 && cnt3!=0) return false;
	if(l>midLLimit) return false;
	if(r<sideRLimit) return false;
	return true;
}

inline void dec2(int r)
{
	incR(r,-1);
	incL(n-1-r,-1);
}

inline void solve()
{
	cnt1=cnt3=0;
	cnt2=n;
	memset(cntL,0,sizeof(cntL));
	memset(cntR,0,sizeof(cntR));
	sideRLimit=n/2;
	midLLimit=n-1;
	for(int i=n-1;i>=n/2;i--)
	{
		if(a[i]!=a[n-1-i])
		{
			sideRLimit=i;
			break;
		}
	}
	for(int i=n/2;i<n;i++)
	{
		if(a[i]!=a[n-1-i])
		{
			midLLimit=i;
			break;
		}
	}
	// cout<<midLLimit<<' '<<sideRLimit<<endl;
	for(int i=0;i<n;i++)
	{
		incR(i,1);
	}
	int l=0,r=n-1;
	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
	inc(l);
	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
	while(ok(l,r) && l<r) inc(l);
	// cout<<l<<' '<<r<<endl;
	// cout<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
	// cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
	// cout<<l<<endl;
	for(r=n-1;r>=sideRLimit;r--)
	{
		while(!ok(l,r) && l+r>=n-1) dec(l);
		// cout<<ok(l,r)<<':'<<'['<<l<<','<<r<<']'<<' '<<cntL[1]<<' '<<cntR[1]<<' '<<cntL[2]<<' '<<cntR[2]<<endl;
		if(ok(l,r)) res+=l-(n-1-r)+1;
		dec2(r);
	}
	// cout<<"Total res="<<res<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	test();
	solve();
	// return 0;
	reverse(a,a+n);
	solve();
	res-=(n-sideRLimit);
	cout<<res<<endl;
	return 0;
}