//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
////bool ohno;
//int n,m;
//map <int,map<int,int> > fp;
//struct Segment
//{
//	int x,y;
//	int len;
//};
//ostream & operator << (ostream &cout,const Segment &x)
//{
//	cout<<vector<int>{x.x,x.y,x.len};
//	return cout;
//}
//vector<Segment> points;
//vector<pii> xs;
//vector<pii> ys;
//
//inline bool flush(int x,int y,int &i,int &j)
//{
//	int pi=i,pj=j;
//	while(i<n && xs[i].first<x) i++;
//	while(i<n && xs[i].first==x && xs[i].second>=y) i++;
//	while(j<n && ys[j].second<y) j++;
//	while(j<n && ys[j].second==y && ys[j].first>=x) j++;
//	return (i!=pi || j!=pj);
//}
//
//inline void build()
//{
////	assert(xs[n]==mp(inf,inf));
////	assert(ys[n]==mp(inf,inf));
////	debug(xs,ys);
//	int x=0,y=0;
//	int i=0,j=0;
//	while(true)
//	{
////		static int cnt=0;
////		cnt++;
////		if(cnt>=10000 && cnt<=10100) cout<<x<<' '<<y<<' '<<i<<' '<<j<<endl;
////		if(cnt==10100) exit(0);
//		if(fp[x][y])
//		{
//			x++;
//			y++;
//			continue;
//		}
//		int flushed=false;
//		flushed|=flush(x,y,i,j);
//		if(i<n && xs[i].first==x && xs[i].second<y) x++;
//		if(j<n && ys[j].second==y && ys[j].first<x) y++;
//		flushed|=flush(x,y,i,j);
//		if(i>=n && j>=n)
//		{
//			points.push_back({x,y,inf});
//			break;
//		}
//		if(flushed) continue;
////		if(xs[i].first<x)
////		{
////			cout<<x<<' '<<xs[i].first<<' '<<i<<endl;
////			cout<<y<<' '<<ys[j].second<<' '<<j<<endl;
////			exit(0);
////		}
////		if(ys[j].second<y)
////		{
////			cout<<x<<' '<<xs[i].first<<' '<<i<<endl;
////			cout<<y<<' '<<ys[j].second<<' '<<j<<endl;
////			exit(1);
////		}
////		assert(xs[i].first>=x);
////		assert(ys[j].second>=y);
//		int len=min(xs[i].first-x,ys[j].second-y);
//		points.push_back({x,y,len});
////		if((ll)(x+len)!=(ll)(x)+(ll)(len)) over("Oh no!!");
////		if((ll)(y+len)!=(ll)(y)+(ll)(len)) over("Oh no!!");
//		x+=len;
//		y+=len;
//	}
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	scanf("%d%d",&n,&m);
////	ohno=(n==1000 && m==577);
//	for(int i=0;i<n;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		if(x==0 && y==0) continue;
//		xs.push_back(mp(x,y));
//		ys.push_back(mp(x,y));
//		fp[x][y]=true;
//	}
//	n=xs.size();
////	debug(n);
////	cout<<xs.size()<<' '<<ys.size()<<endl;
////	cout<<xs.back()<<' '<<ys.back()<<endl;
//	xs.push_back(mp(inf,inf));
//	ys.push_back(mp(inf,inf));
//	sort(all(xs));
//	sort(all(ys),[](const pii &a,const pii &b)
//	{
//		if(a.second!=b.second) return a.second<b.second;
//		return a.first<b.first;
//	});
////	cout<<xs.size()<<' '<<ys.size()<<endl;
////	cout<<xs.back()<<' '<<ys.back()<<endl;
////	cout<<xs<<endl;
////	if(ohno) return 0;
//	build();
////	exit(9);
////	debug(points);
//	for(int i=0;i<m;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		bool lose=true;
//		Segment t=points[upper_bound(all(points),Segment({x,y,0}),[](const Segment &a,const Segment &b)
//		{
//			return a.x<b.x;
//		})-points.begin()-1];
//		if(t.x+t.len<=x) lose=false;
////		debug(lose,t,x,y);
//		if(x-y!=t.x-t.y) lose=false;
//		lose|=(fp[x][y]);
//		puts(lose?"LOSE":"WIN");
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
//bool ohno;
int n,m;
map <int,map<int,int> > fp;
struct Segment
{
	int x,y;
	int len;
};
ostream & operator << (ostream &cout,const Segment &x)
{
	cout<<vector<int>{x.x,x.y,x.len};
	return cout;
}
vector<Segment> points;
vector<pii> xs;
vector<pii> ys;

inline bool flush(int x,int y,int &i,int &j)
{
	int pi=i,pj=j;
	while(i<n && xs[i].first<x) i++;
	while(i<n && xs[i].first==x && xs[i].second>=y) i++;
	while(j<n && ys[j].second<y) j++;
	while(j<n && ys[j].second==y && ys[j].first>=x) j++;
	return (i!=pi || j!=pj);
}

inline void build()
{
//	assert(xs[n]==mp(inf,inf));
//	assert(ys[n]==mp(inf,inf));
//	debug(xs,ys);
	int x=0,y=0;
	int i=0,j=0;
	while(true)
	{
//		static int cnt=0;
//		cnt++;
//		if(cnt>=10000 && cnt<=10100) cout<<x<<' '<<y<<' '<<i<<' '<<j<<endl;
//		if(cnt==10100) exit(0);
		if(fp[x][y])
		{
			x++;
			y++;
			continue;
		}
		int flushed=false;
		flushed|=flush(x,y,i,j);
		if(i<n && xs[i].first==x && xs[i].second<y) x++;
		if(j<n && ys[j].second==y && ys[j].first<x) y++;
		flushed|=flush(x,y,i,j);
		if(i>=n && j>=n)
		{
			points.push_back({x,y,inf});
			break;
		}
		if(flushed) continue;
//		if(xs[i].first<x)
//		{
//			cout<<x<<' '<<xs[i].first<<' '<<i<<endl;
//			cout<<y<<' '<<ys[j].second<<' '<<j<<endl;
//			exit(0);
//		}
//		if(ys[j].second<y)
//		{
//			cout<<x<<' '<<xs[i].first<<' '<<i<<endl;
//			cout<<y<<' '<<ys[j].second<<' '<<j<<endl;
//			exit(1);
//		}
//		assert(xs[i].first>=x);
//		assert(ys[j].second>=y);
		int len=min(xs[i].first-x,ys[j].second-y);
		points.push_back({x,y,len});
//		if((ll)(x+len)!=(ll)(x)+(ll)(len)) over("Oh no!!");
//		if((ll)(y+len)!=(ll)(y)+(ll)(len)) over("Oh no!!");
		x+=len;
		y+=len;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
//	ohno=(n==1000 && m==577);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0 && y==0) continue;
		xs.push_back(mp(x,y));
		ys.push_back(mp(x,y));
		fp[x][y]=true;
	}
	n=xs.size();
//	debug(n);
//	cout<<xs.size()<<' '<<ys.size()<<endl;
//	cout<<xs.back()<<' '<<ys.back()<<endl;
	xs.push_back(mp(inf,inf));
	ys.push_back(mp(inf,inf));
	sort(all(xs));
	sort(all(ys),[](const pii &a,const pii &b)
	{
		if(a.second!=b.second) return a.second<b.second;
		return a.first<b.first;
	});
//	cout<<xs.size()<<' '<<ys.size()<<endl;
//	cout<<xs.back()<<' '<<ys.back()<<endl;
//	cout<<xs<<endl;
//	if(ohno) return 0;
	build();
//	exit(9);
//	debug(points);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		bool lose=true;
		Segment t=points[upper_bound(all(points),Segment({x,y,0}),[](const Segment &a,const Segment &b)
		{
			return a.x<b.x;
		})-points.begin()-1];
		if(t.x+t.len<=x) lose=false;
//		debug(lose,t,x,y);
		if(x-y!=t.x-t.y) lose=false;
		lose|=(fp[x][y]);
		puts(lose?"LOSE":"WIN");
	}
	return 0;
}