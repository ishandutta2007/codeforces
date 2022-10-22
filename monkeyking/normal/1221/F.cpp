//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//
////quality guarantee
//template <typename T>
//struct SegmentTreeMaxAdd //[)
//{
//	pair<T,int> *data;
//	T *tagSum;
//	int nn;
//	T inf;
//	int size()
//	{
//		return nn;
//	}
//	void init(int size, T _inf)
//	{
//		nn = 1;
//		inf = _inf;
//		while (nn < size)
//		{
//			nn <<= 1;
//		}
//		data = new pair<T,int>[nn * 2 + 5];
//		tagSum = new T[nn * 2 + 5];
//		for (int i = 0; i <= nn * 2; i++)
//		{
//			tagSum[i] = 0;
//		}
//		for(int i=0;i<size;i++)
//		{
//			data[i+nn]=mp(inf,i);
//		}
//		for(int i=nn-1;i>=1;i--)
//		{
//			data[i]=max(data[i*2],data[i*2+1]);
//		}
//	}
//	inline void pushdown(int x)
//	{
//		if (x >= nn) return;
//		data[x * 2].first += tagSum[x];
//		data[x * 2 + 1].first += tagSum[x];
//		tagSum[x * 2] += tagSum[x];
//		tagSum[x * 2 + 1] += tagSum[x];
//		tagSum[x] = 0;
//	}
//	void add(int l, int r, T value)
//	{
//		add(1, 0, nn, l, r, value);
//	}
//	void add(int x, int l, int r, int ql, int qr, T value)
//	{
//		if (l >= qr || r <= ql) return;
//		pushdown(x);
//		if (l >= ql && r <= qr)
//		{
//			data[x].first+=value;
//			tagSum[x] += value;
//			return;
//		}
//		add(x * 2, l, (l + r) >> 1, ql, qr, value);
//		add(x * 2 + 1, (l + r) >> 1, r, ql, qr, value);
//		data[x] = max(data[x * 2], data[x * 2 + 1]);
//	}
//	T query()
//	{
//		return data[1];
//	}
//	pair<T,int> query(int ql, int qr)
//	{
//		return query(1, 0, nn, ql, qr);
//	}
//	pair<T,int> query(int x, int l, int r, int ql, int qr)
//	{
//		if (l >= qr || r <= ql)	return mp(inf,-1);
//		pushdown(x);
//		if (l >= ql && r <= qr)
//		{
//			return data[x];
//		}
//		return max(query(x * 2, l, (l + r) >> 1, ql, qr), query(x * 2 + 1, (l + r) >> 1, r, ql, qr));
//	}
//	void build(int a[], int len)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			data[i + nn] = a[i];
//		}
//		for (int i = nn - 1; i >= 1; i--)
//		{
//			data[i] = max(data[i * 2], data[i * 2 + 1]);
//		}
//	}
//	inline void print(int l,int r)
//	{
//		cout<<"Range["<<l<<','<<r<<')'<<":";
//		for(int i=l;i<r;i++)
//		{
//			cout<<query(i,i+1)<<' ';
//		}
//		cout<<endl;
//	}
//};
//SegmentTreeMaxAdd <ll> sgt;
//int n;
//vector <int> lsh;
//vector <tuple<int,int,int> > points;
//vector <pii> vInsert[1000005];
//int m;
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		int x,y,c;
//		scanf("%d%d%d",&x,&y,&c);
//		lsh.push_back(x);
//		lsh.push_back(y);
//		points.push_back(make_tuple(x,y,c));
//	}
//	sort(all(lsh));
//	lsh.erase(unique(all(lsh)),lsh.end());
//	m=lsh.size();
//	sgt.init(m,-llinf);
//	for(auto &[x,y,c]:points)
//	{
//		x=lower_bound(all(lsh),x)-lsh.begin();
//		y=lower_bound(all(lsh),y)-lsh.begin();
//		vInsert[max(x,y)].push_back(mp(min(x,y),c));
//	}
//	pair<ll,pii> res=mp(-llinf,mp(-1,-1));
//	for(int i=0;i<m;i++)
//	{
//		auto [t,id]=sgt.query(i,i+1);
//		sgt.add(i,i+1,-t);
//		for(auto &p:vInsert[i])
//		{
//			sgt.add(0,p.first+1,p.second);
//		}
//		if(i) sgt.add(0,i,-(lsh[i]-lsh[i-1]));
//		pair<ll,int> o=sgt.query(0,i+1);
//		chmax(res,mp(o.first,mp(o.second,i)));
//	}
//	ll x=lsh[res.second.first];
//	ll y=lsh[res.second.second];
//	if(res.first<0)
//	{
//		res.first=0;
//		x=inf;
//		y=inf;
//	}
//	cout<<res.first<<endl;
//	cout<<x<<' '<<x<<' '<<y<<' '<<y<<endl;
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
#endif
using namespace std;


//quality guarantee
template <typename T>
struct SegmentTreeMaxAdd //[)
{
	pair<T,int> *data;
	T *tagSum;
	int nn;
	T inf;
	int size()
	{
		return nn;
	}
	void init(int size, T _inf)
	{
		nn = 1;
		inf = _inf;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new pair<T,int>[nn * 2 + 5];
		tagSum = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			tagSum[i] = 0;
		}
		for(int i=0;i<size;i++)
		{
			data[i+nn]=mp(inf,i);
		}
		for(int i=nn-1;i>=1;i--)
		{
			data[i]=max(data[i*2],data[i*2+1]);
		}
	}
	inline void pushdown(int x)
	{
		if (x >= nn) return;
		data[x * 2].first += tagSum[x];
		data[x * 2 + 1].first += tagSum[x];
		tagSum[x * 2] += tagSum[x];
		tagSum[x * 2 + 1] += tagSum[x];
		tagSum[x] = 0;
	}
	void add(int l, int r, T value)
	{
		add(1, 0, nn, l, r, value);
	}
	void add(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql) return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x].first+=value;
			tagSum[x] += value;
			return;
		}
		add(x * 2, l, (l + r) >> 1, ql, qr, value);
		add(x * 2 + 1, (l + r) >> 1, r, ql, qr, value);
		data[x] = max(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	pair<T,int> query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	pair<T,int> query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)	return mp(inf,-1);
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return max(query(x * 2, l, (l + r) >> 1, ql, qr), query(x * 2 + 1, (l + r) >> 1, r, ql, qr));
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = max(data[i * 2], data[i * 2 + 1]);
		}
	}
	inline void print(int l,int r)
	{
		cout<<"Range["<<l<<','<<r<<')'<<":";
		for(int i=l;i<r;i++)
		{
			cout<<query(i,i+1)<<' ';
		}
		cout<<endl;
	}
};
SegmentTreeMaxAdd <ll> sgt;
int n;
vector <int> lsh;
vector <tuple<int,int,int> > points;
vector <pii> vInsert[1000005];
int m;

int main()
{
//	// freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		lsh.push_back(x);
		lsh.push_back(y);
		points.push_back(make_tuple(x,y,c));
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	m=lsh.size();
	sgt.init(m,-llinf);
	for(auto &[x,y,c]:points)
	{
		x=lower_bound(all(lsh),x)-lsh.begin();
		y=lower_bound(all(lsh),y)-lsh.begin();
		vInsert[max(x,y)].push_back(mp(min(x,y),c));
	}
	pair<ll,pii> res=mp(-llinf,mp(-1,-1));
	for(int i=0;i<m;i++)
	{
		auto [t,id]=sgt.query(i,i+1);
		sgt.add(i,i+1,-t);
		for(auto &p:vInsert[i])
		{
			sgt.add(0,p.first+1,p.second);
		}
		if(i) sgt.add(0,i,-(lsh[i]-lsh[i-1]));
		pair<ll,int> o=sgt.query(0,i+1);
		chmax(res,mp(o.first,mp(o.second,i)));
	}
	ll x=lsh[res.second.first];
	ll y=lsh[res.second.second];
	if(res.first<0)
	{
		res.first=0;
		x=inf;
		y=inf;
	}
	cout<<res.first<<endl;
	cout<<x<<' '<<x<<' '<<y<<' '<<y<<endl;
	return 0;
}