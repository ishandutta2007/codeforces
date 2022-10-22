//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/st-table>
//using namespace std;
//const int prime=23333;
//int n,q;
//char c[200005];
//pii queries[200005];
//int res[200005];
//int s[26][200005];
//int nxt[200005],pre[200005];
//ull hh[200005],e[200005];
//ll hh2[200005],e2[200005];
//StTableFast<int,greater<int> > stl;
//StTableFast<int,less<int> > str;
//int sa1[200005],sa2[200005];
//int rk[200005];
//
//int nstates;
//struct State
//{
//	State *link;
//	State *go[26];
//	int len,id,key;
//	State(int,int,int);
//}*last,*root,*states[400005];
//State::State(int _len,int _key,int _id)
//{
//	len=_len;
//	key=_key;
//	id=_id;
//	states[id]=this;
//	link=0;
//	memset(go,0,sizeof(go));
//}
//
//void extend(int ch,int key)
//{
//	State *T=last,*Tx=new State(last->len+1,key,nstates++);
//	last=Tx;
//	while(T && !T->go[ch])
//	{
//		T->go[ch]=Tx;
//		T=T->link;
//	}
//	if(!T)
//	{
//		Tx->link=root;
//		return;
//	}
//	State *p=T->go[ch];
//	if(p->len==T->len+1)
//	{
//		Tx->link=p;
//	}
//	else
//	{
//		State *q=new State(T->len+1,-1,nstates++);
//		memcpy(q->go,p->go,sizeof(p->go));
//		q->link=p->link;
//		p->link=Tx->link=q;
//		while(T && T->go[ch]==p)
//		{
//			T->go[ch]=q;
//			T=T->link;
//		}
//	}
//}
//
//namespace AAB
//{
//	int l[200005],r[200005];
//	vector<int> edges[400005];
//	set<int> squ[400005];
//	int ed[400005];
//	int pos;
//	void insert(set<int> &s,int key,int lim,int res[])
//	{
//		auto it=s.insert(key).first;
//		if(next(it)!=s.end() && *next(it)-*it<=lim) chmax(res[*next(it)],*it);
//		if(it!=s.begin() && *it-*prev(it)<=lim) chmax(res[*it],*prev(it));
//	}
//	void dfs(int x,int res[])
//	{
//		for(auto u:edges[x])
//		{
//			dfs(u,res);
//			if(squ[u].size()>squ[x].size()) swap(squ[u],squ[x]);
//			for(auto key:squ[u]) insert(squ[x],key,states[x]->len,res);
//			if(ed[u]!=-1) ed[x]=ed[u];
//		}
//		if(states[x]->key!=-1) insert(squ[x],states[x]->key,states[x]->len,res),ed[x]=states[x]->key;
//	}
//	void dfs2(int x,int sa[])
//	{
//		int len=states[x]->len;
//		sort(all(edges[x]),[=](int a,int b){
//			return c[ed[a]-len]<c[ed[b]-len];
//		});
//		if(states[x]->key!=-1) sa[pos++]=states[x]->key;
//		for(auto u:edges[x])
//		{
//			dfs2(u,sa);
//		}
//	}
//	void solve(int res[],int sa[])
//	{
//		nstates=0;pos=0;
//		memset(res,-1,sizeof(int)*n);
//		last=root=new State(0,-1,nstates++);
//		for(int i=0;i<n;i++) extend(c[i]-'a',i);
//		for(int i=0;i<nstates;i++)
//		{
//			if(!states[i]->link) continue;
//			edges[states[i]->link->id].emplace_back(states[i]->id);
//		}
//		// for(int i=0;i<nstates;i++)
//		// {
//		// 	cout<<i<<' '<<edges[i]<<'\n';
//		// }
//		// exit(0);
//		dfs(0,res);
//		dfs2(0,sa);
//		for(int i=0;i<nstates;i++)
//		{
//			edges[i].clear();
//			squ[i].clear();
//		}
//		for(int i=0;i<n;i++)
//		{
//			if(res[i]==-1) continue;
//			res[i]=res[i]-(i-res[i]);
//			assert(res[i]>=-1);
//		}
//	}
//	void solve()
//	{
//		solve(l,sa1);
//		reverse(c,c+n);
//		solve(r,sa2);
//		reverse(c,c+n);
//		reverse(r,r+n);
//		for(int i=0;i<n;i++)
//		{
//			r[i]=n-1-r[i];
//		}
//		stl.init(l,l+n);
//		str.init(r,r+n);
//		for(int i=0;i<q;i++)
//		{
//			int ql=queries[i].first,qr=queries[i].second;
//			if(ql<=l[qr] || qr>=r[ql]) res[i]=2;
//		}
//	}
//}
//
//namespace R3
//{
//	void solve()
//	{
//		for(int i=n-1;i>=0;i--)
//		{
//			nxt[i]=inf;
//			for(int j=i+1;j<n;j++) if(c[j]==c[i])
//			{
//				nxt[i]=j;
//				break;
//			}
//		}
//		for(int i=0;i<n;i++)
//		{
//			pre[i]=-1;
//			for(int j=i-1;j>=0;j--) if(c[j]==c[i])
//			{
//				pre[i]=j;
//				break;
//			}
//		}
//		for(int i=0;i<q;i++)
//		{
//			int l=queries[i].first,r=queries[i].second;
//			if(nxt[l]<=r) chmin(res[i],3);
//			if(pre[r]>=l) chmin(res[i],3);
//			if(stl.query(l,r+1)>=l) chmin(res[i],3);
//			if(str.query(l,r+1)<=r) chmin(res[i],3);
//		}
//	}
//}
//
//int same(int l,int r,int len)
//{
//	return ((l?hh[l-1]:0)*e[len]+hh[r+len-1]==(r?hh[r-1]:0)*e[len]+hh[l+len-1]) &&
//	(1LL*(l?hh2[l-1]:0)*e2[len]+hh2[r+len-1])%mod==(1LL*(r?hh2[r-1]:0)*e2[len]+hh2[l+len-1])%mod;
//}
//
//inline bool check(int l,int r,int len)
//{
//	return same(l,l+len,r-l+1-len);
//}
//
//namespace R1
//{
//	void solve()
//	{
//		for(int i=0;i<q;i++)
//		{
//			int l=queries[i].first,r=queries[i].second,len=r-l+1;
//			for(int a=1;a*a<=len;a++)
//			{
//				if(len%a==0)
//				{
//					if((a!=len && check(l,r,a)) || (a!=1 && check(l,r,len/a)))
//					{
//						res[i]=1;
//						break;
//					}
//				}
//			}
//		}
//	}
//}
//
//const int B=500;
//namespace ABA
//{
//	void solve()
//	{
//		for(int i=0;i<q;i++)
//		{
//			int l=queries[i].first,r=queries[i].second;
//			for(int len=1;len<=min(r-l,B);len++)
//			{
//				if(same(l,r-len+1,len))
//				{
//					chmin(res[i],2);
//					break;
//				}
//			}
//			if(res[i]<=2) continue;
//			int pos=rk[r];
//			for(int j=max(0,pos-B);j<min(n,pos+B);j++)
//			{
//				int t=sa1[j];
//				if(t<l || t>=r) continue;
//				int len=t-l+1;
//				if(same(l,r-len+1,len))
//				{
//					chmin(res[i],2);
//					break;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	// freopen("string.in","r",stdin);
//	// freopen("string.out","w",stdout);
//	scanf("%d",&n);
//	scanf("%s",c);
//	for(int i=0;i<n;i++)
//	{
//		s[c[i]-'a'][i]++;
//	}
//	for(int i=0;i<26;i++)
//	{
//		for(int j=1;j<n;j++) s[i][j]+=s[i][j-1];
//	}
//	scanf("%d",&q);
//	for(int i=0;i<q;i++)
//	{
//		scanf("%d%d",&queries[i].first,&queries[i].second);
//		queries[i].first--;
//		queries[i].second--;
//		int l=queries[i].first,r=queries[i].second;
//		bool nice=0;
//		for(int j=0;j<26;j++)
//		{
//			nice|=(s[j][r]-(l?s[j][l-1]:0)>=2);
//		}
//		res[i]=(nice?4:-1);
//	}
//	e[0]=1;e2[0]=1;for(int i=1;i<=n;i++) e[i]=e[i-1]*prime,e2[i]=1LL*e2[i-1]*prime%mod;
//	for(int i=0;i<n;i++) hh[i]=(i?hh[i-1]:0)*prime+c[i],hh2[i]=(1LL*(i?hh2[i-1]:0)*prime+c[i])%mod;
//	AAB::solve();
//	for(int i=0;i<n;i++) rk[sa1[i]]=i;
//	ABA::solve();
//	R3::solve();
//	R1::solve();
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
#ifndef __SELF_ST_TABLE
#define __SELF_ST_TABLE 1

template <typename T,typename _Compare=std::less<T> >
struct StTableFast //
{
    std::vector <std::vector<T> > table;
    std::vector <int> logTable;
    _Compare comp;
    template <typename Iterator>
    void init(Iterator begin,Iterator end)
    {
        int n=end-begin;
        int lg=0;
        int nn=1;
        while(nn<=n)
        {
            nn<<=1;
            lg++;
        }
        lg--;
        table.resize(lg+1);
        for(int i=0;i<=lg;i++)
        {
            table[i].resize(n-(1<<i)+1);
        }
        logTable.resize(n+1);
        for(Iterator it=begin;it!=end;it++)
        {
            table[0][it-begin]=*it;
        }
        T ta,tb;
        for(int i=1;i<=lg;i++)
        {
            for(int j=0;j<n-(1<<i)+1;j++)
            {
                ta=table[i-1][j];
                tb=table[i-1][j+(1<<(i-1))];
                if(comp(ta,tb)) table[i][j]=ta;else table[i][j]=tb;
            }
        }
        logTable[1]=0;
        for(int i=2;i<=n;i++)
        {
            logTable[i]=logTable[i/2]+1;
        }
    }
    T query(int l,int r) //[)
    {
        assert(l<r);
        int n=r-l;
        int lg=logTable[n];
        T a=table[lg][l];
        T b=table[lg][r-(1<<lg)];
        if(comp(a,b)) return a;else return b;
    }
};

#endif
using namespace std;
const int prime=23333;
int n,q;
char c[200005];
pii queries[200005];
int res[200005];
int s[26][200005];
int nxt[200005],pre[200005];
ull hh[200005],e[200005];
ll hh2[200005],e2[200005];
StTableFast<int,greater<int> > stl;
StTableFast<int,less<int> > str;
int sa1[200005],sa2[200005];
int rk[200005];

int nstates;
struct State
{
	State *link;
	State *go[26];
	int len,id,key;
	State(int,int,int);
}*last,*root,*states[400005];
State::State(int _len,int _key,int _id)
{
	len=_len;
	key=_key;
	id=_id;
	states[id]=this;
	link=0;
	memset(go,0,sizeof(go));
}

void extend(int ch,int key)
{
	State *T=last,*Tx=new State(last->len+1,key,nstates++);
	last=Tx;
	while(T && !T->go[ch])
	{
		T->go[ch]=Tx;
		T=T->link;
	}
	if(!T)
	{
		Tx->link=root;
		return;
	}
	State *p=T->go[ch];
	if(p->len==T->len+1)
	{
		Tx->link=p;
	}
	else
	{
		State *q=new State(T->len+1,-1,nstates++);
		memcpy(q->go,p->go,sizeof(p->go));
		q->link=p->link;
		p->link=Tx->link=q;
		while(T && T->go[ch]==p)
		{
			T->go[ch]=q;
			T=T->link;
		}
	}
}

namespace AAB
{
	int l[200005],r[200005];
	vector<int> edges[400005];
	set<int> squ[400005];
	int ed[400005];
	int pos;
	void insert(set<int> &s,int key,int lim,int res[])
	{
		auto it=s.insert(key).first;
		if(next(it)!=s.end() && *next(it)-*it<=lim) chmax(res[*next(it)],*it);
		if(it!=s.begin() && *it-*prev(it)<=lim) chmax(res[*it],*prev(it));
	}
	void dfs(int x,int res[])
	{
		for(auto u:edges[x])
		{
			dfs(u,res);
			if(squ[u].size()>squ[x].size()) swap(squ[u],squ[x]);
			for(auto key:squ[u]) insert(squ[x],key,states[x]->len,res);
			if(ed[u]!=-1) ed[x]=ed[u];
		}
		if(states[x]->key!=-1) insert(squ[x],states[x]->key,states[x]->len,res),ed[x]=states[x]->key;
	}
	void dfs2(int x,int sa[])
	{
		int len=states[x]->len;
		sort(all(edges[x]),[=](int a,int b){
			return c[ed[a]-len]<c[ed[b]-len];
		});
		if(states[x]->key!=-1) sa[pos++]=states[x]->key;
		for(auto u:edges[x])
		{
			dfs2(u,sa);
		}
	}
	void solve(int res[],int sa[])
	{
		nstates=0;pos=0;
		memset(res,-1,sizeof(int)*n);
		last=root=new State(0,-1,nstates++);
		for(int i=0;i<n;i++) extend(c[i]-'a',i);
		for(int i=0;i<nstates;i++)
		{
			if(!states[i]->link) continue;
			edges[states[i]->link->id].emplace_back(states[i]->id);
		}
		// for(int i=0;i<nstates;i++)
		// {
		// 	cout<<i<<' '<<edges[i]<<'\n';
		// }
		// exit(0);
		dfs(0,res);
		dfs2(0,sa);
		for(int i=0;i<nstates;i++)
		{
			edges[i].clear();
			squ[i].clear();
		}
		for(int i=0;i<n;i++)
		{
			if(res[i]==-1) continue;
			res[i]=res[i]-(i-res[i]);
			assert(res[i]>=-1);
		}
	}
	void solve()
	{
		solve(l,sa1);
		reverse(c,c+n);
		solve(r,sa2);
		reverse(c,c+n);
		reverse(r,r+n);
		for(int i=0;i<n;i++)
		{
			r[i]=n-1-r[i];
		}
		stl.init(l,l+n);
		str.init(r,r+n);
		for(int i=0;i<q;i++)
		{
			int ql=queries[i].first,qr=queries[i].second;
			if(ql<=l[qr] || qr>=r[ql]) res[i]=2;
		}
	}
}

namespace R3
{
	void solve()
	{
		for(int i=n-1;i>=0;i--)
		{
			nxt[i]=inf;
			for(int j=i+1;j<n;j++) if(c[j]==c[i])
			{
				nxt[i]=j;
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			pre[i]=-1;
			for(int j=i-1;j>=0;j--) if(c[j]==c[i])
			{
				pre[i]=j;
				break;
			}
		}
		for(int i=0;i<q;i++)
		{
			int l=queries[i].first,r=queries[i].second;
			if(nxt[l]<=r) chmin(res[i],3);
			if(pre[r]>=l) chmin(res[i],3);
			if(stl.query(l,r+1)>=l) chmin(res[i],3);
			if(str.query(l,r+1)<=r) chmin(res[i],3);
		}
	}
}

int same(int l,int r,int len)
{
	return ((l?hh[l-1]:0)*e[len]+hh[r+len-1]==(r?hh[r-1]:0)*e[len]+hh[l+len-1]) &&
	(1LL*(l?hh2[l-1]:0)*e2[len]+hh2[r+len-1])%mod==(1LL*(r?hh2[r-1]:0)*e2[len]+hh2[l+len-1])%mod;
}

inline bool check(int l,int r,int len)
{
	return same(l,l+len,r-l+1-len);
}

namespace R1
{
	void solve()
	{
		for(int i=0;i<q;i++)
		{
			int l=queries[i].first,r=queries[i].second,len=r-l+1;
			for(int a=1;a*a<=len;a++)
			{
				if(len%a==0)
				{
					if((a!=len && check(l,r,a)) || (a!=1 && check(l,r,len/a)))
					{
						res[i]=1;
						break;
					}
				}
			}
		}
	}
}

const int B=500;
namespace ABA
{
	void solve()
	{
		for(int i=0;i<q;i++)
		{
			int l=queries[i].first,r=queries[i].second;
			for(int len=1;len<=min(r-l,B);len++)
			{
				if(same(l,r-len+1,len))
				{
					chmin(res[i],2);
					break;
				}
			}
			if(res[i]<=2) continue;
			int pos=rk[r];
			for(int j=max(0,pos-B);j<min(n,pos+B);j++)
			{
				int t=sa1[j];
				if(t<l || t>=r) continue;
				int len=t-l+1;
				if(same(l,r-len+1,len))
				{
					chmin(res[i],2);
					break;
				}
			}
		}
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	// freopen("string.in","r",stdin);
	// freopen("string.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",c);
	for(int i=0;i<n;i++)
	{
		s[c[i]-'a'][i]++;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<n;j++) s[i][j]+=s[i][j-1];
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&queries[i].first,&queries[i].second);
		queries[i].first--;
		queries[i].second--;
		int l=queries[i].first,r=queries[i].second;
		bool nice=0;
		for(int j=0;j<26;j++)
		{
			nice|=(s[j][r]-(l?s[j][l-1]:0)>=2);
		}
		res[i]=(nice?4:-1);
	}
	e[0]=1;e2[0]=1;for(int i=1;i<=n;i++) e[i]=e[i-1]*prime,e2[i]=1LL*e2[i-1]*prime%mod;
	for(int i=0;i<n;i++) hh[i]=(i?hh[i-1]:0)*prime+c[i],hh2[i]=(1LL*(i?hh2[i-1]:0)*prime+c[i])%mod;
	AAB::solve();
	for(int i=0;i<n;i++) rk[sa1[i]]=i;
	ABA::solve();
	R3::solve();
	R1::solve();
	for(int i=0;i<q;i++)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}