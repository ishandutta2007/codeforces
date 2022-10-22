//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/ModInt>
//using namespace std;
//using Int=ModInt <1000000007>;
//Int f[200005];
//int n;
//vector <int> edges[200005];
//Int res[200005];
//vector <Int> pre[200005];
//vector <Int> suf[200005];
//
//void go(int x,int par=-1)
//{
//    f[x]=1;
//    for(int it=0;it<edges[x].size();it++)
//    {
//        pre[x][it]=(it?pre[x][it-1]:1);
//        int u=edges[x][it];
//        if(u==par) continue;
//        go(u,x);
//        f[x]*=f[u];
//        pre[x][it]=f[x];
//    }
//    Int tmp=1;
//    for(int it=(int)edges[x].size()-1;it>=0;it--)
//    {
//        suf[x][it]=(it==((int)edges[x].size())-1?1:suf[x][it+1]);
//        int u=edges[x][it];
//        if(u==par) continue;
//        tmp*=f[u];
//        suf[x][it]=tmp;
//    }
//    f[x]++;
//}
//
//void dfs(int x,int par=-1)
//{
//    res[x]=f[x]-1;
//    Int newFx,newFu;
//    for(int it=0;it<edges[x].size();it++)
//    {
//        int u=edges[x][it];
//        if(u==par) continue;
//        newFx=(it?pre[x][it-1]:1)*(it+1>=edges[x].size()?1:suf[x][it+1])*(par==-1?1:f[par])+1;
//        newFu=(f[u]-1)*newFx+1;
//        swap(f[x],newFx);
//        swap(f[u],newFu);
//        dfs(u,x);
//        swap(f[u],newFu);
//        swap(f[x],newFx);
//    }
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    int n;
//    cin>>n;
//    for(int i=1;i<n;i++)
//    {
//        int par;
//        scanf("%d",&par);
//        par--;
//        edges[par].push_back(i);
//        edges[i].push_back(par);
//    }
//    for(int i=0;i<n;i++)
//    {
//        pre[i].resize(edges[i].size());
//        suf[i].resize(edges[i].size());
//    }
//    go(0);
//    dfs(0);
//    for(int i=0;i<n;i++)
//    {
//        cout<<res[i]<<endl;
//    }
//    return 0;
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
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=1e9+7;
#endif
const int gmod=2;
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

template <typename T> 
void operator *= (vector <T> &vec,int k)
{
	for(auto &x:vec) x*=k;
}

template <typename T>
void operator -= (vector <T> &a,const vector <T> &b)
{
	assert(a.size()==b.size());
	for(size_t it=0;it<a.size();it++)
	{
		a[it]-=b[it];
	}
}

template <typename T>
vector <T> operator * (const vector <T> &vec,int k)
{
	vector <T> res(vec);
	res*=k;
	return res;
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

template <typename T1,typename T2,typename T3>
ostream & operator << (ostream &cout,map <T1,T2,T3> m)
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
	ModInt(ll _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
	ModInt <mod> operator ++(int)
	{
		int t=x;
		x++;
		if(x==mod) x=0;
		return t;
	}
	ModInt <mod>& operator --()// prefix
	{
		--x;
		if(x==-1) x+=mod;
		return *this;
	}
	ModInt <mod> operator --(int)
	{
		int t=x;
		x--;
		if(x==-1) x+=mod;
		return t;
	}
};

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
void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod,typename T>
void operator -= (ModInt <mod> &a,const T &b)
{
	a.x-=b;
	a.x+=(a.x>>31&mod);
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,int b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
void operator *= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a*b;
}

template <int mod,typename T>
void operator *= (ModInt <mod> &a,const T &b)
{
	a=a*b;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod,typename T>
void operator +=(ModInt <mod> &a,const T &b)
{
	a.x+=b;
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
using namespace std;
using Int=ModInt <1000000007>;
Int f[200005];
int n;
vector <int> edges[200005];
Int res[200005];
vector <Int> pre[200005];
vector <Int> suf[200005];

void go(int x,int par=-1)
{
    f[x]=1;
    for(int it=0;it<edges[x].size();it++)
    {
        pre[x][it]=(it?pre[x][it-1]:1);
        int u=edges[x][it];
        if(u==par) continue;
        go(u,x);
        f[x]*=f[u];
        pre[x][it]=f[x];
    }
    Int tmp=1;
    for(int it=(int)edges[x].size()-1;it>=0;it--)
    {
        suf[x][it]=(it==((int)edges[x].size())-1?1:suf[x][it+1]);
        int u=edges[x][it];
        if(u==par) continue;
        tmp*=f[u];
        suf[x][it]=tmp;
    }
    f[x]++;
}

void dfs(int x,int par=-1)
{
    res[x]=f[x]-1;
    Int newFx,newFu;
    for(int it=0;it<edges[x].size();it++)
    {
        int u=edges[x][it];
        if(u==par) continue;
        newFx=(it?pre[x][it-1]:1)*(it+1>=edges[x].size()?1:suf[x][it+1])*(par==-1?1:f[par])+1;
        newFu=(f[u]-1)*newFx+1;
        swap(f[x],newFx);
        swap(f[u],newFu);
        dfs(u,x);
        swap(f[u],newFu);
        swap(f[x],newFx);
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int par;
        scanf("%d",&par);
        par--;
        edges[par].push_back(i);
        edges[i].push_back(par);
    }
    for(int i=0;i<n;i++)
    {
        pre[i].resize(edges[i].size());
        suf[i].resize(edges[i].size());
    }
    go(0);
    dfs(0);
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}