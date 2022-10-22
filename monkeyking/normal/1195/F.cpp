//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//#define dec dec_your_father
//
//template <typename T>
//struct SegmentTreeSumAdd
//{
//	const T E = 0;
//	int nn;
//	T *data;
//	T *tag;
//	void init(int _n)
//	{
//		nn = 1;
//		while (nn < _n)
//			nn <<= 1;
//		data = new T[nn * 2 + 5];
//		tag = new T[nn * 2 + 5];
//		for (int i = 0; i < 2 * nn; i++)
//		{
//			tag[i] = E;
//			data[i] = E;
//		}
//	}
//	void pushdown(int x, int l, int r)
//	{
//		if (x >= nn) return;
//		data[x * 2] += tag[x] * (r - l >> 1);
//		data[x * 2 + 1] += tag[x] * (r - l >> 1);
//		tag[x * 2] += tag[x];
//		tag[x * 2 + 1] += tag[x];
//		tag[x] = 0;
//	}
//	void build(T a[], int n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			data[i + nn] = a[i];
//		}
//		for (int i = nn - 1; i >= 1; i--)
//		{
//			data[i] = data[i * 2] + data[i * 2 + 1];
//		}
//	}
//	void add(int x, int ql, int qr, int l, int r, T delta)
//	{
//		if (l >= qr || r <= ql)
//			return;
//		pushdown(x, l, r);
//		if (l >= ql && r <= qr)
//		{
//			tag[x] += delta;
//			data[x] += delta * (r - l);
//			return;
//		}
//		add(x * 2, ql, qr, l, l + r >> 1, delta);
//		add(x * 2 + 1, ql, qr, l + r >> 1, r, delta);
//		data[x] = data[x * 2] + data[x * 2 + 1];
//	}
//	T query(int x, int ql, int qr, int l, int r)
//	{
//		if (l >= qr || r <= ql)
//			return E;
//		pushdown(x, l, r);
//		if (l >= ql && r <= qr)
//		{
//			return data[x];
//		}
//		return query(x * 2, ql, qr, l, l + r >> 1) + query(x * 2 + 1, ql, qr, l + r >> 1, r);
//	}
//	inline void add(int l, int r, T delta)
//	{
//		add(1, l, r, 0, nn, delta);
//	}
//	inline void add(int pos,T delta)
//	{
//		add(pos,pos+1,delta);
//	}
//	inline T query(int l, int r)
//	{
//		return query(1, l, r, 0, nn);
//	}
//	inline T query(int pos)
//	{
//		return query(pos,pos+1);
//	}
//};
//SegmentTreeSumAdd <int> sgt;
//
//struct Point
//{
//	int x,y;
//	Point(){}
//	Point(int _x,int _y):x(_x),y(_y){}
//};
//Point operator - (const Point &x,const Point &y)
//{
//	return Point(x.x-y.x,x.y-y.y);
//}
//bool operator < (const Point &x,const Point &y)
//{
//	int bx=(x.y>0 || x.y==0 && x.x>0);
//	int by=(y.y>0 || y.y==0 && y.x>0);
//	if(bx!=by) return (bx==1);
//	return 1LL*x.x*y.y>1LL*x.y*y.x;
//}
//bool operator == (const Point &x,const Point &y)
//{
//	return !((x<y) || (y<x));
//}
//
//int n;
//vector<Point> pts[100005];
//vector<int> a[100005];
//vector<Point> lsh;
//int q;
//vector<pair<pii,int> > queries[100005];
//vector<int> pos[300005];
//int colors;
//vector<int> dec[100005];
//int res[100005];
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		int k;
//		scanf("%d",&k);
//		Point fst;
//		Point lst;
//		for(int j=0;j<k;j++)
//		{
//			int x,y;
//			scanf("%d%d",&x,&y);
//			Point p=Point(x,y);
//			if(j==0) fst=p;
//			if(j!=0)
//			{
//				pts[i].push_back(p-lst);
//			}
//			lst=p;
//		}
//		pts[i].push_back(fst-lst);
//		for(auto &p:pts[i]) lsh.push_back(p);
//	}
//	sort(all(lsh));
//	lsh.erase(unique(all(lsh)),lsh.end());
//	for(int i=0;i<n;i++)
//	{
//		for(auto &p:pts[i])
//		{
//			a[i].push_back(lower_bound(all(lsh),p)-lsh.begin());
//		}
//	}
//	// for(int i=0;i<n;i++)
//	// {
//	// 	cout<<a[i]<<endl;
//	// }
//	cin>>q;
//	for(int i=0;i<q;i++)
//	{
//		int l,r;
//		scanf("%d%d",&l,&r);
//		l--;
//		queries[l].push_back(mp(mp(l,r),i));
//	}
//	colors=lsh.size();
//	// debug(colors);
//	for(int i=0;i<n;i++)
//	{
//		for(auto x:a[i]) pos[x].push_back(i);
//	}
//	sgt.init(n);
//	for(int i=0;i<colors;i++)
//	{
//		pos[i].push_back(-1);
//		pos[i].push_back(n);
//		sort(all(pos[i]));
//		for(int j=0;j<pos[i].size()-1;j++)
//		{
//			// debug(pos[i][j]+1,pos[i][j+1]);
//			// cout<<pos[i][j]+1<<' '<<pos[i][j+1]<<endl;
//			dec[pos[i][j]+1].push_back(pos[i][j+1]);
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(auto x:dec[i]) sgt.add(0,x,-1);
//		for(auto &q:queries[i])
//		{
//			res[q.second]=colors+sgt.query(q.first.second-1);
//		}
//	}
//	for(int i=0;i<q;i++)
//	{
//		printf("%d\n",res[i]);
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
#define dec dec_your_father

template <typename T>
struct SegmentTreeSumAdd
{
	const T E = 0;
	int nn;
	T *data;
	T *tag;
	void init(int _n)
	{
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
		}
	}
	void pushdown(int x, int l, int r)
	{
		if (x >= nn) return;
		data[x * 2] += tag[x] * (r - l >> 1);
		data[x * 2 + 1] += tag[x] * (r - l >> 1);
		tag[x * 2] += tag[x];
		tag[x * 2 + 1] += tag[x];
		tag[x] = 0;
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = data[i * 2] + data[i * 2 + 1];
		}
	}
	void add(int x, int ql, int qr, int l, int r, T delta)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			tag[x] += delta;
			data[x] += delta * (r - l);
			return;
		}
		add(x * 2, ql, qr, l, l + r >> 1, delta);
		add(x * 2 + 1, ql, qr, l + r >> 1, r, delta);
		data[x] = data[x * 2] + data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql)
			return E;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) + query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	inline void add(int l, int r, T delta)
	{
		add(1, l, r, 0, nn, delta);
	}
	inline void add(int pos,T delta)
	{
		add(pos,pos+1,delta);
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query(int pos)
	{
		return query(pos,pos+1);
	}
};
SegmentTreeSumAdd <int> sgt;

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};
Point operator - (const Point &x,const Point &y)
{
	return Point(x.x-y.x,x.y-y.y);
}
bool operator < (const Point &x,const Point &y)
{
	int bx=(x.y>0 || x.y==0 && x.x>0);
	int by=(y.y>0 || y.y==0 && y.x>0);
	if(bx!=by) return (bx==1);
	return 1LL*x.x*y.y>1LL*x.y*y.x;
}
bool operator == (const Point &x,const Point &y)
{
	return !((x<y) || (y<x));
}

int n;
vector<Point> pts[100005];
vector<int> a[100005];
vector<Point> lsh;
int q;
vector<pair<pii,int> > queries[100005];
vector<int> pos[300005];
int colors;
vector<int> dec[100005];
int res[100005];

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		Point fst;
		Point lst;
		for(int j=0;j<k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Point p=Point(x,y);
			if(j==0) fst=p;
			if(j!=0)
			{
				pts[i].push_back(p-lst);
			}
			lst=p;
		}
		pts[i].push_back(fst-lst);
		for(auto &p:pts[i]) lsh.push_back(p);
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<n;i++)
	{
		for(auto &p:pts[i])
		{
			a[i].push_back(lower_bound(all(lsh),p)-lsh.begin());
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<a[i]<<endl;
	// }
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		queries[l].push_back(mp(mp(l,r),i));
	}
	colors=lsh.size();
	// debug(colors);
	for(int i=0;i<n;i++)
	{
		for(auto x:a[i]) pos[x].push_back(i);
	}
	sgt.init(n);
	for(int i=0;i<colors;i++)
	{
		pos[i].push_back(-1);
		pos[i].push_back(n);
		sort(all(pos[i]));
		for(int j=0;j<pos[i].size()-1;j++)
		{
			// debug(pos[i][j]+1,pos[i][j+1]);
			// cout<<pos[i][j]+1<<' '<<pos[i][j+1]<<endl;
			dec[pos[i][j]+1].push_back(pos[i][j+1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(auto x:dec[i]) sgt.add(0,x,-1);
		for(auto &q:queries[i])
		{
			res[q.second]=colors+sgt.query(q.first.second-1);
		}
	}
	for(int i=0;i<q;i++)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}