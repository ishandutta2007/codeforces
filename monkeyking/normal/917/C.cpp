//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,k,q,x;
//
//struct Matrix
//{
//	int n,m;
//	vector<vector<ll> > v;
//	void init(int _n,int _m)
//	{
//		n=_n;
//		m=_m;
//		v.resize(n,vector<ll>(m,llinf));
//	}
//	Matrix operator * (const Matrix &oth)const{
//		Matrix res;
//		res.init(n,oth.m);
//		assert(m==oth.n);
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				for(int k=0;k<oth.m;k++)
//				{
//					chmin(res.v[i][k],v[i][j]+oth.v[j][k]);
//				}
//			}
//		}
//		return res;
//	}
//	void E()
//	{
//		assert(n==m);
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<n;j++)
//			{
//				v[i][j]=(i==j?0:llinf);
//			}
//		}
//	}
//};
//Matrix mat[35];
//
//int cnt[256],ids[256],tot,states[105];
//int c[9];
//vector<pii> sp;
//
//void eat(Matrix &v,int x)
//{
//	for(int i=29;i>=0;i--)
//	{
//		if((1<<i) & x) v=v*mat[i];
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>x>>k>>n>>q;
//	for(int i=0;i<k;i++) cin>>c[i];
//	memset(ids,-1,sizeof(ids));
//	for(int i=1;i<(1<<k);i++)
//	{
//		cnt[i]=cnt[i>>1]+(i & 1);
//		if(cnt[i]==x)
//		{
//			states[tot]=i;
//			ids[i]=tot++;
//		}
//	}
//	for(int i=0;i<q;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		sp.emplace_back(x,y);
//	}
//	sp.emplace_back(n-x+1,0);
//	sort(all(sp));
//	mat[0].init(tot,tot);
//	for(int i=0;i<(1<<k);i++)
//	{
//		if(ids[i]==-1) continue;
//		if(!(i & 1))
//		{
//			mat[0].v[ids[i]][ids[i>>1]]=0;
//			continue;
//		}
//		int u=(i>>1);
//		for(int j=0;j<k;j++)
//		{
//			if((1<<j) & u) continue;
//			int mask=(u | (1<<j));
//			mat[0].v[ids[i]][ids[mask]]=c[j];
//		}
//	}
//	for(int i=1;i<=30;i++) mat[i]=mat[i-1]*mat[i-1];
//	Matrix v;
//	v.init(1,tot);
//	v.v[0][ids[(1<<x)-1]]=0;
//	// for(int i=0;i<tot;i++) cout<<mat[1].v[i]<<endl;
//	int pre=1,t;
//	for(t=0;t<(int)sp.size();t++)
//	{
//		int pos=sp[t].first,w=sp[t].second;
//		eat(v,pos-pre);pre=pos;
//		for(int i=0;i<tot;i++)
//		{
//			if(states[i] & 1) v.v[0][i]+=w;
//		}
//		if(pos==n-x+1) break;
//	}
//	for(t++;t<(int)sp.size();t++)
//	{
//		int pos=sp[t].first,w=sp[t].second;
//		for(int i=0;i<tot;i++)
//		{
//			if(states[i] & ((1<<(pos-pre)))) v.v[0][i]+=w;
//		}
//	}
//	cout<<v.v[0][ids[(1<<x)-1]]<<endl;
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
#define mp(a,b) make_pair(a,b)
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
int n,k,q,x;

struct Matrix
{
	int n,m;
	vector<vector<ll> > v;
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		v.resize(n,vector<ll>(m,llinf));
	}
	Matrix operator * (const Matrix &oth)const{
		Matrix res;
		res.init(n,oth.m);
		assert(m==oth.n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<oth.m;k++)
				{
					chmin(res.v[i][k],v[i][j]+oth.v[j][k]);
				}
			}
		}
		return res;
	}
	void E()
	{
		assert(n==m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				v[i][j]=(i==j?0:llinf);
			}
		}
	}
};
Matrix mat[35];

int cnt[256],ids[256],tot,states[105];
int c[9];
vector<pii> sp;

void eat(Matrix &v,int x)
{
	for(int i=29;i>=0;i--)
	{
		if((1<<i) & x) v=v*mat[i];
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>x>>k>>n>>q;
	for(int i=0;i<k;i++) cin>>c[i];
	memset(ids,-1,sizeof(ids));
	for(int i=1;i<(1<<k);i++)
	{
		cnt[i]=cnt[i>>1]+(i & 1);
		if(cnt[i]==x)
		{
			states[tot]=i;
			ids[i]=tot++;
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		sp.emplace_back(x,y);
	}
	sp.emplace_back(n-x+1,0);
	sort(all(sp));
	mat[0].init(tot,tot);
	for(int i=0;i<(1<<k);i++)
	{
		if(ids[i]==-1) continue;
		if(!(i & 1))
		{
			mat[0].v[ids[i]][ids[i>>1]]=0;
			continue;
		}
		int u=(i>>1);
		for(int j=0;j<k;j++)
		{
			if((1<<j) & u) continue;
			int mask=(u | (1<<j));
			mat[0].v[ids[i]][ids[mask]]=c[j];
		}
	}
	for(int i=1;i<=30;i++) mat[i]=mat[i-1]*mat[i-1];
	Matrix v;
	v.init(1,tot);
	v.v[0][ids[(1<<x)-1]]=0;
	// for(int i=0;i<tot;i++) cout<<mat[1].v[i]<<endl;
	int pre=1,t;
	for(t=0;t<(int)sp.size();t++)
	{
		int pos=sp[t].first,w=sp[t].second;
		eat(v,pos-pre);pre=pos;
		for(int i=0;i<tot;i++)
		{
			if(states[i] & 1) v.v[0][i]+=w;
		}
		if(pos==n-x+1) break;
	}
	for(t++;t<(int)sp.size();t++)
	{
		int pos=sp[t].first,w=sp[t].second;
		for(int i=0;i<tot;i++)
		{
			if(states[i] & ((1<<(pos-pre)))) v.v[0][i]+=w;
		}
	}
	cout<<v.v[0][ids[(1<<x)-1]]<<endl;
	return 0;
}