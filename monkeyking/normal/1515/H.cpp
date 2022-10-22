//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//const int U=(1<<20)-1;
//int n,q;
//int inv[(1<<20)];
//
//struct Node
//{
//	Node *l=0,*r=0;
//	int sz;
//	int ed;
//	int swp=0;
//	int hasl=0,hasr=0;
//	Node(int _v):sz(_v),ed(_v){}
//	void pushup()
//	{
//		sz=(l?l->sz:0)+(r?r->sz:0)+ed;
//		hasl=((l?l->hasl:0)|(r?r->hasl:0))<<1|bool(l);
//		hasr=((l?l->hasr:0)|(r?r->hasr:0))<<1|bool(r);
//	}
//	void pushswp(int x)
//	{
//		if(x&1)
//		{
//			swap(l,r);
//		}
//		swp^=x;
//		int wl=(hasl&x),wr=(hasr&x);
//		hasl^=wl;hasr^=wr;
//		swap(wl,wr);
//		hasl|=wl;hasr|=wr;
//	}
//	void pushdown()
//	{
//		if(l) l->pushswp(swp>>1);
//		if(r) r->pushswp(swp>>1);
//		swp=0;
//	}
//}*rt;
//
//Node* make(int x,int l=20)
//{
//	if(l==0) return new Node(1);
//	Node *rt=new Node(0);
//	if(x&1) rt->r=make(x>>1,l-1);
//	else rt->l=make(x>>1,l-1);
//	rt->pushup();
//	return rt;
//}
//
//pair<Node*,Node*> split(Node *rt,int key,int l=20)
//{
//	if(key<0) return mp(nullptr,rt);
//	if(!rt) return mp(nullptr,nullptr);
//	if(l==0) return mp(rt,nullptr);
//	rt->pushdown();
//	if(key&1)
//	{
//		auto o=split(rt->r,key>>1,l-1);
//		rt->r=o.first;
//		rt->pushup();
//		auto tr=new Node(0);
//		tr->r=o.second;
//		tr->pushup();
//		return mp(rt,tr);
//	}
//	else
//	{
//		auto o=split(rt->l,key>>1,l-1);
//		rt->l=o.second;
//		rt->pushup();
//		auto tl=new Node(0);
//		tl->l=o.first;
//		tl->pushup();
//		return mp(tl,rt);
//	}
//}
//
//Node* merge(Node *a,Node *b)
//{
//	if(!a) return b;
//	if(!b) return a;
//	a->pushdown();
//	b->pushdown();
//	a->l=merge(a->l,b->l);
//	a->r=merge(a->r,b->r);
//	a->pushup();
//	return a;
//}
//
//tuple<Node*,Node*,Node*> splitlr(Node *&a,int l,int r)
//{
//	auto o=split(a,r);
//	auto o2=split(o.first,l);
//	return mt(o2.first,o2.second,o.second);
//}
//
//Node* mergelr(tuple<Node*,Node*,Node*> o)
//{
//	Node *a,*b,*c;
//	tie(a,b,c)=o;
//	return merge(merge(a,b),c);
//}
//
//void flip(Node *&rt,int w)
//{
//	if(!rt) return;
//	rt->pushswp(w);
//}
//
//void print(Node *&rt,int mask=0)
//{
//	rt->pushdown();
//	if(rt->ed)
//	{
//		cout<<mask<<endl;
//		return;
//	}
//	if(rt->l) print(rt->l,mask<<1);
//	if(rt->r) print(rt->r,(mask<<1)|1);
//}
//
//void push(Node *&rt,int w,int l=20)
//{
//	if(!rt) return;
//	int m=(rt->hasr^U)&w;
//	flip(rt,m);
//	w^=m;
//	if(!(rt->hasl&w)) return;
//	rt->pushdown();
//	if(rt->l) push(rt->l,w>>1,l-1);
//	if(rt->r) push(rt->r,w>>1,l-1);
//	if(w&1)
//	{
//		rt->r=merge(rt->l,rt->r);
//		rt->l=0;
//	}
//	rt->pushup();
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	for(int i=1;i<(1<<20);i++)
//	{
//		inv[i]=(inv[i>>1]>>1)|(((i&1)<<19));
//	}
//	cin>>n>>q;
//	rt=new Node(0);
//	for(int i=0;i<n;i++)
//	{
//		int x;
//		scanf("%d",&x);
//		x=inv[x];
//		rt=merge(rt,make(x));
//	}
//	for(int i=0;i<q;i++)
//	{
//		int type;
//		scanf("%d",&type);
//		int l,r;
//		scanf("%d%d",&l,&r);
//		auto o=splitlr(rt,(l==0?-1:inv[l-1]),inv[r]);
//		auto &tr=get<1>(o);
//		if(type==4)
//		{
//			printf("%d\n",(tr?tr->sz:0));
//		}
//		else if(type==3)
//		{
//			int x;
//			scanf("%d",&x);
//			x=inv[x];
//			flip(tr,x);
//		}
//		else if(type==2)
//		{
//			int x;
//			scanf("%d",&x);
//			x=inv[x];
//			push(tr,x);
//		}
//		else
//		{
//			int x;
//			scanf("%d",&x);
//			x=inv[x];
//			flip(tr,((1<<20)-1));
//			push(tr,((1<<20)-1)^x);
//			flip(tr,((1<<20)-1));
//		}
//		rt=mergelr(o);
//	}
//	// print(rt);
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
const int U=(1<<20)-1;
int n,q;
int inv[(1<<20)];

struct Node
{
	Node *l=0,*r=0;
	int sz;
	int ed;
	int swp=0;
	int hasl=0,hasr=0;
	Node(int _v):sz(_v),ed(_v){}
	void pushup()
	{
		sz=(l?l->sz:0)+(r?r->sz:0)+ed;
		hasl=((l?l->hasl:0)|(r?r->hasl:0))<<1|bool(l);
		hasr=((l?l->hasr:0)|(r?r->hasr:0))<<1|bool(r);
	}
	void pushswp(int x)
	{
		if(x&1)
		{
			swap(l,r);
		}
		swp^=x;
		int wl=(hasl&x),wr=(hasr&x);
		hasl^=wl;hasr^=wr;
		swap(wl,wr);
		hasl|=wl;hasr|=wr;
	}
	void pushdown()
	{
		if(l) l->pushswp(swp>>1);
		if(r) r->pushswp(swp>>1);
		swp=0;
	}
}*rt;

Node* make(int x,int l=20)
{
	if(l==0) return new Node(1);
	Node *rt=new Node(0);
	if(x&1) rt->r=make(x>>1,l-1);
	else rt->l=make(x>>1,l-1);
	rt->pushup();
	return rt;
}

pair<Node*,Node*> split(Node *rt,int key,int l=20)
{
	if(key<0) return mp(nullptr,rt);
	if(!rt) return mp(nullptr,nullptr);
	if(l==0) return mp(rt,nullptr);
	rt->pushdown();
	if(key&1)
	{
		auto o=split(rt->r,key>>1,l-1);
		rt->r=o.first;
		rt->pushup();
		auto tr=new Node(0);
		tr->r=o.second;
		tr->pushup();
		return mp(rt,tr);
	}
	else
	{
		auto o=split(rt->l,key>>1,l-1);
		rt->l=o.second;
		rt->pushup();
		auto tl=new Node(0);
		tl->l=o.first;
		tl->pushup();
		return mp(tl,rt);
	}
}

Node* merge(Node *a,Node *b)
{
	if(!a) return b;
	if(!b) return a;
	a->pushdown();
	b->pushdown();
	a->l=merge(a->l,b->l);
	a->r=merge(a->r,b->r);
	a->pushup();
	return a;
}

tuple<Node*,Node*,Node*> splitlr(Node *&a,int l,int r)
{
	auto o=split(a,r);
	auto o2=split(o.first,l);
	return mt(o2.first,o2.second,o.second);
}

Node* mergelr(tuple<Node*,Node*,Node*> o)
{
	Node *a,*b,*c;
	tie(a,b,c)=o;
	return merge(merge(a,b),c);
}

void flip(Node *&rt,int w)
{
	if(!rt) return;
	rt->pushswp(w);
}

void print(Node *&rt,int mask=0)
{
	rt->pushdown();
	if(rt->ed)
	{
		cout<<mask<<endl;
		return;
	}
	if(rt->l) print(rt->l,mask<<1);
	if(rt->r) print(rt->r,(mask<<1)|1);
}

void push(Node *&rt,int w,int l=20)
{
	if(!rt) return;
	int m=(rt->hasr^U)&w;
	flip(rt,m);
	w^=m;
	if(!(rt->hasl&w)) return;
	rt->pushdown();
	if(rt->l) push(rt->l,w>>1,l-1);
	if(rt->r) push(rt->r,w>>1,l-1);
	if(w&1)
	{
		rt->r=merge(rt->l,rt->r);
		rt->l=0;
	}
	rt->pushup();
}

int main()
{
//	// freopen("input.txt","r",stdin);
	for(int i=1;i<(1<<20);i++)
	{
		inv[i]=(inv[i>>1]>>1)|(((i&1)<<19));
	}
	cin>>n>>q;
	rt=new Node(0);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		x=inv[x];
		rt=merge(rt,make(x));
	}
	for(int i=0;i<q;i++)
	{
		int type;
		scanf("%d",&type);
		int l,r;
		scanf("%d%d",&l,&r);
		auto o=splitlr(rt,(l==0?-1:inv[l-1]),inv[r]);
		auto &tr=get<1>(o);
		if(type==4)
		{
			printf("%d\n",(tr?tr->sz:0));
		}
		else if(type==3)
		{
			int x;
			scanf("%d",&x);
			x=inv[x];
			flip(tr,x);
		}
		else if(type==2)
		{
			int x;
			scanf("%d",&x);
			x=inv[x];
			push(tr,x);
		}
		else
		{
			int x;
			scanf("%d",&x);
			x=inv[x];
			flip(tr,((1<<20)-1));
			push(tr,((1<<20)-1)^x);
			flip(tr,((1<<20)-1));
		}
		rt=mergelr(o);
	}
	// print(rt);
	return 0;
}