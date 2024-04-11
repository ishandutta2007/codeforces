//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/SegmentTree>
//using namespace std;
//SegmentTreeMinMaxChange<ll> sgt1,sgt2;
//int n,q;
//ll a[100005],b[100005];
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n>>q;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%lld",a+i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		scanf("%lld",b+i);
//	}
//	for(int i=0;i<n;i++)
//	{
//		a[i]-=b[i];
//	}
//	for(int i=n-1;i>=0;i--)
//	{
//		b[i]=a[i]+b[i+1];
//	}
//	sgt1.init(n);
//	for(int i=0;i<n;i++)
//	{
//		sgt1.change(i,b[i]);
//	}
//	for(int i=0;i<q;i++)
//	{
//		int l,r;
//		scanf("%d%d",&l,&r);
//		l--;
//		if(b[l]!=b[r] || sgt1.query(l,r).first!=b[r])
//		{
//			puts("-1");
//			continue;
//		}
//		else
//		{
//			printf("%lld\n",sgt1.query(l,r).second-b[r]);
//		}
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
//quality guarantee
template <typename T>
struct SegmentTreeMinUpdate //[)
{
	T maxValue = 1e9;
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while (nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for (int i=0;i<=nn*2;i++)
		{
			data[i]=maxValue;
			tag[i]=maxValue;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn) return;
		data[x * 2] = min(data[x * 2], tag[x]);
		data[x * 2 + 1] = min(data[x * 2 + 1], tag[x]);
		tag[x * 2] = min(tag[x * 2], tag[x]);
		tag[x * 2 + 1] = min(tag[x * 2 + 1], tag[x]);
		tag[x] = maxValue;
	}
	void update(int pos,T value)
	{
		update(pos,pos+1,value);
	}
	void update(int ql, int qr, T value)
	{
		update(1, 0, nn, ql, qr, value);
	}
	void update(int x, int l, int r, int ql, int qr, T value)
	{
		if (l>=qr || r<=ql)	return;
		pushdown(x);
		if (l>=ql && r<=qr)
		{
			data[x]=min(data[x],value);
			tag[x]=min(tag[x],value);
			return;
		}
		update(x*2,l,(l+r)>>1,ql,qr,value);
		update(x*2+1,(l+r)>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int pos)
	{
		return query(pos,pos+1);
	}
	T query(int ql, int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l>=qr || r<=ql)	return maxValue;
		pushdown(x);
		if (l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,(l+r)>>1,ql,qr),query(x*2+1,(l+r)>>1,r,ql,qr));
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMinAdd //[)
{
	//	#define ll int
	T *data;
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
		data = new T[nn * 2 + 5];
		tagSum = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = inf;
			tagSum[i] = 0;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] += tagSum[x];
		data[x * 2 + 1] += tagSum[x];
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
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = data[x] + value;
			tagSum[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMaxAdd //[)
{
	T *data;
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
		data = new T[nn * 2 + 5];
		tagSum = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = -inf;
			tagSum[i] = 0;
		}
	}
	inline void pushdown(int x)
	{
		if (x >= nn) return;
		data[x * 2] += tagSum[x];
		data[x * 2 + 1] += tagSum[x];
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
			data[x] = data[x] + value;
			tagSum[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = max(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)	return -inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return max(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
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
};

//quality guarantee
template <typename T>
struct SegmentTreeMinChange //[)
{
	const T unchanged = -1;
	const T maxValue = 1e9;
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = maxValue;
			tag[i] = unchanged;
		}
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		if (tag[x] == unchanged)
			return;
		data[x * 2] = tag[x];
		data[x * 2 + 1] = tag[x];
		tag[x * 2] = tag[x];
		tag[x * 2 + 1] = tag[x];
		tag[x] = unchanged;
	}
	void change(int ql, int qr, T value)
	{
		change(1, 0, nn, ql, qr, value);
	}
	void change(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = value;
			tag[x] = value;
			return;
		}
		change(x * 2, l, l + r >> 1, ql, qr, value);
		change(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	inline T operator[](int pos)
	{
		return query(pos, pos + 1);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return maxValue;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
};

template <typename T>
struct FenwickTree
{
	const T E = 0;
	T *bit;
	int nn;
	inline void init(int n)
	{
		n++;
		nn = 1;
		while (nn < n)
			nn <<= 1;
		bit = new T[nn + 5];
		for (int i = 0; i <= nn; i++)
		{
			bit[i] = 0;
		}
	}
	inline void clear(int n)
	{
		nn = 1;
		while (nn < n)
			nn <<= 1;
		for (int i = 0; i <= nn; i++)
		{
			bit[i] = 0;
		}
	}
	inline void add(int x, T delta)
	{
		x++;
		while (x <= nn)
		{
			bit[x] += delta;
			x += x & -x;
		}
	}
	inline T query(int x)
	{
		x++;
		T res = E;
		while (x)
		{
			res += bit[x];
			x &= x - 1;
		}
		return res;
	}
	inline T query(int l, int r) //[]
	{
		return query(r) - (l > 0 ? query(l - 1) : 0);
	}
};

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

template <typename T>
struct SegmentTreeMinIntervalAdd //[)
{
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = inf;
			tag[i] = 0;
		}
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] += tag[x];
		data[x * 2 + 1] += tag[x];
		tag[x * 2] += tag[x];
		tag[x * 2 + 1] += tag[x];
		tag[x] = 0;
	}
	void add(int ql, int qr, T value)
	{
		add(1, 0, nn, ql, qr, value);
	}
	void add(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] += value;
			tag[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	//used in debug
	void print()
	{
		for (int i = 0; i < nn; i++)
		{
			cout << query(i, i + 1) << ' ';
		}
		cout << endl;
	}
};

template <typename T>
struct SegmentTreeMutChange // 
{
	T E;
	int nn;
	T *data;
	T *tag;
	bool *unChanged;
	void init(int _n,T _E)
	{
		E=_E;
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		unChanged = new bool[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
			unChanged[i] = true;
		}
	}
	void pushdown(int x, int l, int r)
	{
		if (x >= nn)
			return;
		if (unChanged[x])
			return;
		data[x * 2] = fastpow(tag[x], (r - l) >> 1);
		data[x * 2 + 1] = fastpow(tag[x], (r - l) >> 1);
		tag[x * 2] *= tag[x];
		tag[x * 2 + 1] *= tag[x];
		unChanged[x] = true;
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = data[i * 2] * data[i * 2 + 1];
		}
	}
	void change(int x, int ql, int qr, int l, int r, T value)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			tag[x] = value;
			data[x] = fastpow(value, qr - ql);
			unChanged[x] = false;
			return;
		}
		pushdown(x, l, r);
		change(x * 2, ql, qr, l, l + r >> 1, value);
		change(x * 2 + 1, ql, qr, l + r >> 1, r, value);
		data[x] = data[x * 2] * data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql) return E;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) * query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	void multiplicate(int x,int l,int r,int ql,int qr,T &res)
	{
		if (l >= qr || r <= ql) return;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			res=data[x]*res;
			return;
		}
		multiplicate(x*2+1,(l+r)>>1,r,ql,qr,res);
		multiplicate(x*2,l,(l+r)>>1,ql,qr,res);
	}
	void multiplicate(int l,int r,T &res)
	{
		multiplicate(1,0,nn,l,r,res);
	}
	bool IntChanged = false;
	bool SinChanged = false;
	inline void error()
	{
		cout << "Error occured in Segment Tree" << endl;
		exit(0);
	}
	inline void change(int l, int r, T value)
	{
		IntChanged = true;
		if (SinChanged)
			error();
		change(1, l, r, 0, nn, value);
	}
	inline void change(int pos, T value)
	{
		SinChanged = true;
		if (IntChanged)
			error();
		pos += nn;
		data[pos] = value;
		pos /= 2;
		while (pos)
		{
			data[pos] = data[pos * 2] * data[pos * 2 + 1];
			pos /= 2;
		}
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query()
	{
		return data[1];
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMaxUpdate //[)
{
	T minValue = -1e9;
	T *data = 0;
	T *tag = 0;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		if (data)
			delete data;
		if (tag)
			delete tag;
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = minValue;
			tag[i] = minValue;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] = max(data[x * 2], tag[x]);
		data[x * 2 + 1] = max(data[x * 2 + 1], tag[x]);
		tag[x * 2] = max(tag[x * 2], tag[x]);
		tag[x * 2 + 1] = max(tag[x * 2 + 1], tag[x]);
		tag[x] = minValue;
	}
	void update(int pos, T value)
	{
		update(pos, pos + 1, value);
	}
	void update(int ql, int qr, T value)
	{
		update(1, 0, nn, ql, qr, value);
	}
	void update(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = max(data[x], value);
			tag[x] = max(tag[x], value);
			return;
		}
		update(x * 2, l, l + r >> 1, ql, qr, value);
		update(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = max(data[x * 2], data[x * 2 + 1]);
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return minValue;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return max(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	~SegmentTreeMaxUpdate()
	{
		delete data;
		delete tag;
	}
};

template <typename T>
struct SegmentTreeMinMaxChange //[)
{
	const T inf=llinf;
	const T maxValue = inf;
	const T minValue = -inf;
	T *dataMax;
	T *dataMin;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		dataMax = new T[nn * 2 + 5];
		dataMin = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			dataMin[i] = maxValue;
			dataMax[i] = minValue;
		}
	}
	void build(T a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			dataMax[i + nn] = a[i];
			dataMin[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			dataMin[i] = min(dataMin[i * 2], dataMin[i * 2 + 1]);
			dataMax[i] = max(dataMax[i * 2], dataMax[i * 2 + 1]);
		}
	}
	void change(int pos,ll v)
	{
		pos+=nn;
		dataMin[pos]=v;
		dataMax[pos]=v;
		pos>>=1;
		while(pos)
		{
			dataMin[pos]=min(dataMin[pos*2],dataMin[pos*2+1]);
			dataMax[pos]=max(dataMax[pos*2],dataMax[pos*2+1]);
			pos>>=1;
		}
	}
	void erase(int pos)
	{
		erase(1, 0, nn, pos, pos + 1);
	}
	void erase(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			dataMax[x] = minValue;
			dataMin[x] = maxValue;
			return;
		}
		erase(x * 2, l, l + r >> 1, ql, qr);
		erase(x * 2 + 1, l + r >> 1, r, ql, qr);
		dataMin[x] = min(dataMin[x * 2], dataMin[x * 2 + 1]);
		dataMax[x] = max(dataMax[x * 2], dataMax[x * 2 + 1]);
	}
	pair<T, T> query(int x, int l, int r, int ql, int qr)
	{
		if (r <= ql || l >= qr)
			return mp(maxValue, minValue);
		if (l >= ql && r <= qr)
		{
			return mp(dataMin[x], dataMax[x]);
		}
		pair<T, T> o1 = query(x * 2, l, l + r >> 1, ql, qr);
		pair<T, T> o2 = query(x * 2 + 1, l + r >> 1, r, ql, qr);
		return mp(min(o1.first, o2.first), max(o1.second, o2.second));
	}
	inline pair<T, T> query(int l, int r)
	{
		return query(1, 0, nn, l, r);
	}
};

template <typename T>
struct SegmentTreeWeightedSumChange
{
	T E = 0;
	int nn;
	T *data;
	T *tag;
	T *weight;
	T *weightSum;
	bool *unChanged;
	void init(int _n)
	{
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		weight = new T[nn * 2 + 5];
		weightSum = new T[nn * 2 + 5];
		unChanged = new bool[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
			unChanged[i] = true;
			weightSum[i] = E;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		if (unChanged[x])
			return;
		data[x * 2] = tag[x] * weightSum[x * 2];
		data[x * 2 + 1] = tag[x] * weightSum[x * 2 + 1];
		tag[x * 2] = tag[x];
		tag[x * 2 + 1] = tag[x];
		unChanged[x] = true;
		unChanged[x * 2] = false;
		unChanged[x * 2 + 1] = false;
	}
	void build(T a[], T weight[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i] * weight[i];
			weightSum[i + nn] = weight[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			weightSum[i] = weightSum[i * 2] + weightSum[i * 2 + 1];
			data[i] = data[i * 2] + data[i * 2 + 1];
		}
	}
	void change(int x, int ql, int qr, int l, int r, T value)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			tag[x] = value;
			data[x] = value * weightSum[x];
			unChanged[x] = false;
			return;
		}
		pushdown(x);
		change(x * 2, ql, qr, l, l + r >> 1, value);
		change(x * 2 + 1, ql, qr, l + r >> 1, r, value);
		data[x] = data[x * 2] + data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql)
			return E;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) + query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	inline void error()
	{
		cout << "Error occured in Segment Tree" << endl;
		exit(0);
	}
	inline void change(int l, int r, T value)
	{
		change(1, l, r, 0, nn, value);
	}
	inline void change(int pos, T value)
	{
		change(pos, pos + 1, value);
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query()
	{
		return data[1];
	}
};
using namespace std;
SegmentTreeMinMaxChange<ll> sgt1,sgt2;
int n,q;
ll a[100005],b[100005];

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",b+i);
	}
	for(int i=0;i<n;i++)
	{
		a[i]-=b[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		b[i]=a[i]+b[i+1];
	}
	sgt1.init(n);
	for(int i=0;i<n;i++)
	{
		sgt1.change(i,b[i]);
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		if(b[l]!=b[r] || sgt1.query(l,r).first!=b[r])
		{
			puts("-1");
			continue;
		}
		else
		{
			printf("%lld\n",sgt1.query(l,r).second-b[r]);
		}
	}
	return 0;
}