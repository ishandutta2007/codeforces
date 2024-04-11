//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/HashTable>
//#include <self/combinatorics>
//using combinatorics::fac;
//using combinatorics::ifac;
//const int prime=1000000;
//using namespace std;
//int n,k;
//int go[12][12];
//
//struct State
//{
//	int a[12];
//};
//
//int tmp[12];
//void lsh(State &x)
//{
//	memset(tmp,-1,sizeof(tmp));
//	int cnt=1;
//	for(int i=0;i<n;i++)
//	{
//		if(x.a[i]==0) continue;
//		if(tmp[x.a[i]]==-1) tmp[x.a[i]]=cnt++;
//		x.a[i]=tmp[x.a[i]];
//	}
//}
//
//ostream & operator << (ostream&cout,const State &s)
//{
//	vector<int> v;
//	for(int i=0;i<n;i++) v.push_back(s.a[i]);
//	cout<<v;
//	return cout;
//}
//
//int to[12];
//struct HashState
//{
//	inline int operator () (const State &s)const
//	{
//		int res=0;
//		memset(to,-1,sizeof(to));
//		int cnt=0;
//		for(int i=0;i<n;i++)
//		{
//			if(to[s.a[i]]==-1) to[s.a[i]]=++cnt;
//			res=(1LL*res*prime+to[s.a[i]])%mod;
//		}
//		return res;
//	}
//};
//struct HashPiiState
//{
//	inline int operator () (const pair<pii,State> &s)const
//	{
//		int x=s.first.first,y=s.first.second;
//		if(x>y) swap(x,y);
//		int res=x*n+y;
//		memset(to,-1,sizeof(to));
//		int cnt=0;
//		for(int i=0;i<n;i++)
//		{
//			if(to[s.second.a[i]]==-1) to[s.second.a[i]]=++cnt;
//			res=(1LL*res*prime+to[s.second.a[i]])%mod;
//		}
//		return res;
//	}
//};
//HashState hs;
//bool operator == (State a,State b)
//{
//	lsh(a);
//	lsh(b);
//	for(int i=0;i<n;i++)
//	{
//		if(a.a[i]!=b.a[i]) return false;
//	}
//	return true;
//}
//HashTable<State,bool,HashState,1000000,2000003> ht;
//HashTable<pair<pii,State>,bool,HashPiiState,2000000,2000003> ht2;
//HashTable<State,bool,HashState,1000000,2000003> hfuck;
//
//// int cols[12];
//void dfs(State now)
//{
//	// debug(now);
//	if(ht.exist(now)) return;
//	ht[now]=1;
//	int cols[12];
//	for(int i=0;i<n;i++)
//	{
//		cols[i]=now.a[i];
//	}
//	sort(cols,cols+n);
//	int k=unique(cols,cols+n)-cols;
//	// for(int i=0;i<k;i++) debug(cols[i]);
//	for(int i=0;i<k;i++)
//	{
//		for(int j=i+1;j<k;j++)
//		{
//			State nxt=now;
//			for(int t=0;t<n;t++)
//			{
//				if(nxt.a[t]==cols[j]) nxt.a[t]=cols[i];
//			}
//			// if(i==0 && j==2) debug(nxt);
//			dfs(nxt);
//		}
//	}
//}
//
//vector<State> vs;
//void bfs(State now,int x,int y,int p)
//{
//	if(p==n/2+1)
//	{
//		if(hfuck.exist(now)) return;
//		hfuck[now]=1;
//		vs.emplace_back(now);
//		return;
//	}
//	if(ht2.exist(mp(mp(x,y),now))) return;
//	// debug("FUCK");
//	ht2[mp(mp(x,y),now)]=1;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(i==j) continue;
//			if(now.a[i] || now.a[j] || !go[x][i] || !go[y][j]) continue;
//			// debug(i,j,now.a[i],now.a[j]);
//			now.a[i]=now.a[j]=p;
//			bfs(now,i,j,p+1);
//			now.a[i]=now.a[j]=0;
//		}
//	}
//}
//
//void read()
//{
//	int m;
//	cin>>n>>m>>k;
//	while(m--)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		go[x][y]=go[y][x]=1;
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	combinatorics::init(12,mod);
//	read();
//	State st;
//	memset(st.a,0,sizeof(st.a));
//	// st.a[4]=st.a[5]=1;
//	// bfs(st,4,5,2);
//	// assert(go[4][5]);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//		{
//			// if(i!=4 || j!=5) continue;
//			if(!go[i][j]) continue;
//			st.a[i]=st.a[j]=1;
//			bfs(st,i,j,2);
//			st.a[i]=st.a[j]=0;
//		}
//	}
//	// debug(vs);
//	for(auto x:vs)
//	{
//		dfs(x);
//	}
//	ll res=0;
//	for(int i=1;i<ht.cnt;i++)
//	{
//		st=ht.key[i];
//		map<int,int> m;
//		for(int j=0;j<n;j++)
//		{
//			m[st.a[j]]++;
//		}
//		if((int)m.size()>k) continue;
//		// cout<<m.size()<<endl;
//		// cout<<1LL*fac[k]*ifac[k-m.size()]%mod<<endl;
//		res+=1LL*fac[k]*ifac[k-m.size()]%mod;
//	}
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
namespace HASHTABLE
{
	struct HashInt
	{
		int operator () (int x)
		{
			x^=(x>>13);
			// x^=(x<<7);
			return x;
		}
	};
}

template <typename Key,typename Value,typename Hash,int N,int mod>
struct HashTable
{
	int head[mod+5];
	int nxt[N+5];
	Value val[N+5];
	Key key[N+5];
	Hash hash;
	int cnt;
	HashTable():cnt(1){}
	inline bool exist(const Key &k)
	{
		int t=hash(k)%mod;
		for(int i=head[t];i;i=nxt[i])
		{
			if(key[i]==k) return true;
		}
		return false;
	}
	inline Value& at(const Key &k)
	{
		int t=hash(k)%mod;
		for(int i=head[t];i;i=nxt[i])
		{
			if(key[i]==k) return val[i];
		}
		key[cnt]=k;
		nxt[cnt]=head[t];
		head[t]=cnt;
		assert(cnt<=N);
		return val[cnt++];
	}
	inline Value& operator [] (const Key &k)
	{
		return at(k);
	}
	inline void clear()
	{
		cnt=1;
		memset(head,0,sizeof(head));
	}
};
namespace combinatorics
{
	int *fac;
	int *ifac;
	int __Tmod;
	inline int add(int a,int b)
	{
		return (a+b)%__Tmod;
	}
	inline int sub(int a,int b)
	{
		return (a-b+__Tmod)%__Tmod;
	}
	inline int mult(int a,int b)
	{
		return (1LL*a*b)%__Tmod;
	}
	inline int fastpow(int basic,int x)
	{
		chmod(x,__Tmod-1);
		if(x==0) return 1;
		int res=1;
		while(x)
		{
			if(x&1)	res=mult(res,basic);
			basic=mult(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,__Tmod-2);
	}
	inline int div(int a,int b)
	{
		return mult(a,inv(b));
	}
	void init(int n,int tmod)
	{
		__Tmod=tmod;
		fac=new int[n+5];
		ifac=new int[n+5];
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mult(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=mult(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		if(n<m || n<0 || m<0) return 0;
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
}

using combinatorics::fac;
using combinatorics::ifac;
const int prime=1000000;
using namespace std;
int n,k;
int go[12][12];

struct State
{
	int a[12];
};

int tmp[12];
void lsh(State &x)
{
	memset(tmp,-1,sizeof(tmp));
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		if(x.a[i]==0) continue;
		if(tmp[x.a[i]]==-1) tmp[x.a[i]]=cnt++;
		x.a[i]=tmp[x.a[i]];
	}
}

ostream & operator << (ostream&cout,const State &s)
{
	vector<int> v;
	for(int i=0;i<n;i++) v.push_back(s.a[i]);
	cout<<v;
	return cout;
}

int to[12];
struct HashState
{
	inline int operator () (const State &s)const
	{
		int res=0;
		memset(to,-1,sizeof(to));
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(to[s.a[i]]==-1) to[s.a[i]]=++cnt;
			res=(1LL*res*prime+to[s.a[i]])%mod;
		}
		return res;
	}
};
struct HashPiiState
{
	inline int operator () (const pair<pii,State> &s)const
	{
		int x=s.first.first,y=s.first.second;
		if(x>y) swap(x,y);
		int res=x*n+y;
		memset(to,-1,sizeof(to));
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(to[s.second.a[i]]==-1) to[s.second.a[i]]=++cnt;
			res=(1LL*res*prime+to[s.second.a[i]])%mod;
		}
		return res;
	}
};
HashState hs;
bool operator == (State a,State b)
{
	lsh(a);
	lsh(b);
	for(int i=0;i<n;i++)
	{
		if(a.a[i]!=b.a[i]) return false;
	}
	return true;
}
HashTable<State,bool,HashState,1000000,2000003> ht;
HashTable<pair<pii,State>,bool,HashPiiState,2000000,2000003> ht2;
HashTable<State,bool,HashState,1000000,2000003> hfuck;

// int cols[12];
void dfs(State now)
{
	// debug(now);
	if(ht.exist(now)) return;
	ht[now]=1;
	int cols[12];
	for(int i=0;i<n;i++)
	{
		cols[i]=now.a[i];
	}
	sort(cols,cols+n);
	int k=unique(cols,cols+n)-cols;
	// for(int i=0;i<k;i++) debug(cols[i]);
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			State nxt=now;
			for(int t=0;t<n;t++)
			{
				if(nxt.a[t]==cols[j]) nxt.a[t]=cols[i];
			}
			// if(i==0 && j==2) debug(nxt);
			dfs(nxt);
		}
	}
}

vector<State> vs;
void bfs(State now,int x,int y,int p)
{
	if(p==n/2+1)
	{
		if(hfuck.exist(now)) return;
		hfuck[now]=1;
		vs.emplace_back(now);
		return;
	}
	if(ht2.exist(mp(mp(x,y),now))) return;
	// debug("FUCK");
	ht2[mp(mp(x,y),now)]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(now.a[i] || now.a[j] || !go[x][i] || !go[y][j]) continue;
			// debug(i,j,now.a[i],now.a[j]);
			now.a[i]=now.a[j]=p;
			bfs(now,i,j,p+1);
			now.a[i]=now.a[j]=0;
		}
	}
}

void read()
{
	int m;
	cin>>n>>m>>k;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		go[x][y]=go[y][x]=1;
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	combinatorics::init(12,mod);
	read();
	State st;
	memset(st.a,0,sizeof(st.a));
	// st.a[4]=st.a[5]=1;
	// bfs(st,4,5,2);
	// assert(go[4][5]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			// if(i!=4 || j!=5) continue;
			if(!go[i][j]) continue;
			st.a[i]=st.a[j]=1;
			bfs(st,i,j,2);
			st.a[i]=st.a[j]=0;
		}
	}
	// debug(vs);
	for(auto x:vs)
	{
		dfs(x);
	}
	ll res=0;
	for(int i=1;i<ht.cnt;i++)
	{
		st=ht.key[i];
		map<int,int> m;
		for(int j=0;j<n;j++)
		{
			m[st.a[j]]++;
		}
		if((int)m.size()>k) continue;
		// cout<<m.size()<<endl;
		// cout<<1LL*fac[k]*ifac[k-m.size()]%mod<<endl;
		res+=1LL*fac[k]*ifac[k-m.size()]%mod;
	}
	cout<<res<<endl;
	return 0;
}