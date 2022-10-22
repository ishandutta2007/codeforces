//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/ntt>
//using namespace std;
//int f[1505];
//int sz[1505*20];
//int cnt[1505];
//vector <int> vec[1505*20];
//vector <vector <int> > clusters;
//int n;
//int a[1505][1505];
//vector <pii> edges[1500*1500];
//int visit[1505];
//int coverID[1505];
//vector <int> dp[1505*12];
//
//int find(int x)
//{
//	return (f[x]==x?x:f[x]=find(f[x]));
//}
//
//inline void merge(int x,int y)
//{
//	x=find(x);
//	y=find(y);
//	if(x==y)
//	{
//		cnt[x]++;
//		return;
//	}
//	f[x]=y;
//	sz[y]+=sz[x];
//	cnt[y]+=cnt[x];
//	cnt[y]++;
//}
//
//void dfs(int x,vector <int> &v)
//{
//	visit[x]=1;
//	v.push_back(x);
//	for(auto u:vec[x])
//	{
//		if(visit[u]) continue;
//		dfs(u,v);
//	}
//}
//
//inline void push(int x)
//{
//	vector <int> v;
//	dfs(x,v);
//	for(auto u:v)
//	{
//		visit[u]=false;
//	}
//	clusters.push_back(v);
//}
//
//bool compareBySize(const vector <int> &a,const vector <int> &b)
//{
//	return a.size()>b.size();
//}
//
//NTT::Vector go(int x)
//{
//	NTT::Vector res;
//	res.push_back(0);
//	res.push_back(1);
//	res=NTT::ntt(res,0);
//	NTT::Vector v;
//	v.push_back(1);
//	v=NTT::ntt(v,0);
//	NTT::Vector v2;
//	for(auto u:vec[x])
//	{
//		v2=go(u);
//		for(int i=0;i<(int)v.size();i++)
//		{
//			v[i]*=v2[i];
//		}
//	}
//	if((int)vec[x].size()==0)
//	{
//		for(int i=0;i<(int)v.size();i++)
//		{
//			v[i]=0;
//		}
//	}
//	for(int i=0;i<(int)v.size();i++)
//	{
//		v[i]+=res[i];
//	}
//	return v;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	NTT::init();
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		f[i]=i;
//		cnt[i]=0;
//		sz[i]=1;
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			scanf("%d",a[i]+j);
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//		{
//			edges[a[i][j]].push_back(mp(i,j));
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		push(i);
//	}
//	for(int i=0;i<=n*(n-1)/2;i++)
//	{
//		vector <int> v;
//		for(auto &e:edges[i])
//		{
//			merge(e.first,e.second);
//		}
//		for(auto &e:edges[i])
//		{
//			v.push_back(find(e.first));
//			vec[e.first].push_back(e.second);
//			vec[e.second].push_back(e.first);
//		}
//		sort(all(v));
//		v.erase(unique(all(v)),v.end());
//		for(auto &x:v)
//		{
//			if(cnt[x]==sz[x]*(sz[x]-1)/2)
//			{
//				push(x);
//			}
//		}
//	}
//	sort(all(clusters),compareBySize);
//	for(int i=0;i<n;i++)
//	{
//		coverID[i]=0;
//	}
//	for(int it=0;it<(int)clusters.size();it++)
//	{
//		vector <int> &cluster=clusters[it];
//		sz[it]=cluster.size();
//		vec[it].clear();
//		if(it==0) continue;
//		vec[coverID[cluster[0]]].push_back(it);
//		for(auto &u:cluster)
//		{
//			coverID[u]=it;
//		}
//	}
////	for(int i=0;i<(int)clusters.size();i++)
////	{
////		cout<<sz[i]<<' '<<vec[i]<<endl;
////	}
//	NTT::Vector res=go(0);
//	res=NTT::ntt(res,1);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<res[i]<<' ';
//	}
//	cout<<endl;
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
const int mod=998244353;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
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
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
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
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
};

template <int mod>
bool operator < (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<b.x;
}

template <int mod>
bool operator > (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<a.x;
}

template <int mod>
bool operator == (ModInt <mod> a,ModInt <mod> b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator <= (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<=b.x;
}

template <int mod>
bool operator >= (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<=a.x;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
void operator *= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a*b;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
namespace NTT
{
	const int mod=998244353;
	using ModInt=ModInt <mod>;
	using Vector=vector <ModInt>;
	const ModInt g=3;
	const int LogN=11;
	const int MaxN=(1<<LogN);
	ModInt UnitRoot;
	int inv[MaxN];
	ModInt w[MaxN+1];
	inline ModInt fastpow(ModInt basic,int x)
	{
		ModInt res=1;
		while(x)
		{
			if(x&1)	res*=basic;
			basic*=basic;
			x>>=1;
		}
		return res;
	}
	inline void init()
	{
		inv[0]=0;
		for(int i=1;i<MaxN;i++)
		{
			inv[i]=(inv[(i>>1)]>>1) | ((i&1)<<(LogN-1));
		}
		UnitRoot=fastpow(g,(mod-1)>>LogN);
		w[0]=1;
		for(int i=1;i<=MaxN;i++)
		{
			w[i]=w[i-1]*UnitRoot;
		}
	}
	ModInt v[MaxN];
	ModInt buf[MaxN];
	inline ModInt zeta(int n,int k,int rev)
	{
		return (rev==0?w[MaxN/n*k]:w[MaxN/n*(n-k)]);
	}
	Vector ntt(Vector a,int rev)
	{
		for(int i=0;i<MaxN;i++)
		{
			v[i]=(inv[i]>=(int)a.size()?0:a[inv[i]]);
		}
		for(int m=2;m<=MaxN;m<<=1)
		{
			for(int b=0;b<MaxN;b+=m)
			{
				for(int i=0;i<(m>>1);i++)
				{
					buf[b+i]=v[b+i]+v[b+i+(m>>1)]*zeta(m,i,rev);
//					assert((v[b+i]-v[b+i+(m>>1)]*zeta(m,i,rev))==(v[b+i]+v[b+i+(m>>1)]*zeta(m,i+(m>>1),rev)));
					buf[b+i+(m>>1)]=v[b+i]-v[b+i+(m>>1)]*zeta(m,i,rev);
				}
			}
			for(int j=0;j<MaxN;j++)
			{
				v[j]=buf[j];
			}
		}
		Vector b(MaxN);
		for(int i=0;i<MaxN;i++)
		{
			b[i]=v[i];
		}
		if(rev==1)
		{
			for(int i=0;i<MaxN;i++)
			{
				b[i]/=(ModInt)MaxN;
			}
		}
		return b;
	}
	Vector multiply(Vector a,Vector b)
	{
		a=ntt(a,0);
		b=ntt(b,0);
		for(int i=0;i<MaxN;i++)
		{
			a[i]=a[i]*b[i];
		}
		a=ntt(a,1);
		while(a.back()==0) a.pop_back();
		return a;
	}
	vector <int> multiply(vector <int> &a,vector <int> &b)
	{
		Vector ta(a.size()),tb(b.size());
		for(int i=0;i<(int)a.size();i++)
		{
			ta[i]=a[i];
		}
		for(int i=0;i<(int)b.size();i++)
		{
			tb[i]=b[i];
		}
//		cout<<a<<' '<<b<<endl;
		ta=multiply(ta,tb);
//		cout<<ta<<endl;
		vector <int> c(ta.size());
		for(int i=0;i<(int)ta.size();i++)
		{
			c[i]=ta[i].x;
		}
		while(!c.empty() && c.back()==0) c.pop_back();
		return c;
	}
};
using namespace std;
int f[1505];
int sz[1505*20];
int cnt[1505];
vector <int> vec[1505*20];
vector <vector <int> > clusters;
int n;
int a[1505][1505];
vector <pii> edges[1500*1500];
int visit[1505];
int coverID[1505];
vector <int> dp[1505*12];

int find(int x)
{
	return (f[x]==x?x:f[x]=find(f[x]));
}

inline void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	{
		cnt[x]++;
		return;
	}
	f[x]=y;
	sz[y]+=sz[x];
	cnt[y]+=cnt[x];
	cnt[y]++;
}

void dfs(int x,vector <int> &v)
{
	visit[x]=1;
	v.push_back(x);
	for(auto u:vec[x])
	{
		if(visit[u]) continue;
		dfs(u,v);
	}
}

inline void push(int x)
{
	vector <int> v;
	dfs(x,v);
	for(auto u:v)
	{
		visit[u]=false;
	}
	clusters.push_back(v);
}

bool compareBySize(const vector <int> &a,const vector <int> &b)
{
	return a.size()>b.size();
}

NTT::Vector go(int x)
{
	NTT::Vector res;
	res.push_back(0);
	res.push_back(1);
	res=NTT::ntt(res,0);
	NTT::Vector v;
	v.push_back(1);
	v=NTT::ntt(v,0);
	NTT::Vector v2;
	for(auto u:vec[x])
	{
		v2=go(u);
		for(int i=0;i<(int)v.size();i++)
		{
			v[i]*=v2[i];
		}
	}
	if((int)vec[x].size()==0)
	{
		for(int i=0;i<(int)v.size();i++)
		{
			v[i]=0;
		}
	}
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]+=res[i];
	}
	return v;
}

int main()
{
//	freopen("input.txt","r",stdin);
	NTT::init();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		f[i]=i;
		cnt[i]=0;
		sz[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",a[i]+j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			edges[a[i][j]].push_back(mp(i,j));
		}
	}
	for(int i=0;i<n;i++)
	{
		push(i);
	}
	for(int i=0;i<=n*(n-1)/2;i++)
	{
		vector <int> v;
		for(auto &e:edges[i])
		{
			merge(e.first,e.second);
		}
		for(auto &e:edges[i])
		{
			v.push_back(find(e.first));
			vec[e.first].push_back(e.second);
			vec[e.second].push_back(e.first);
		}
		sort(all(v));
		v.erase(unique(all(v)),v.end());
		for(auto &x:v)
		{
			if(cnt[x]==sz[x]*(sz[x]-1)/2)
			{
				push(x);
			}
		}
	}
	sort(all(clusters),compareBySize);
	for(int i=0;i<n;i++)
	{
		coverID[i]=0;
	}
	for(int it=0;it<(int)clusters.size();it++)
	{
		vector <int> &cluster=clusters[it];
		sz[it]=cluster.size();
		vec[it].clear();
		if(it==0) continue;
		vec[coverID[cluster[0]]].push_back(it);
		for(auto &u:cluster)
		{
			coverID[u]=it;
		}
	}
//	for(int i=0;i<(int)clusters.size();i++)
//	{
//		cout<<sz[i]<<' '<<vec[i]<<endl;
//	}
	NTT::Vector res=go(0);
	res=NTT::ntt(res,1);
	for(int i=1;i<=n;i++)
	{
		cout<<res[i]<<' ';
	}
	cout<<endl;
	return 0;
}