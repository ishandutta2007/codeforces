//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/dsu>
//using namespace std;
//int n,m;
//int a[100005];
//int b[100005];
//vector <pair<int,pii> > vSort;
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//	}
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d",b+i);
//	}
//	ll tot=0;
//	int sz,x;
//	DSU dsu;
//	dsu.init(n+m);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&sz);
//		while(sz--)
//		{
//			scanf("%d",&x);
//			x--;
//			vSort.push_back(mp(a[i]+b[x],mp(i,x+n)));
//			tot+=a[i]+b[x];
//		}
//	}
//	sort(all(vSort));
//	reverse(all(vSort));
//	int s,y;
//	for(auto &e:vSort)
//	{
//		s=e.first;
//		x=e.second.first;
//		y=e.second.second;
//		if(dsu.merge(x,y)) tot-=s;
//	}
//	cout<<tot<<endl;
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
struct DSUAE
{
	int *f;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
		}
	}
	inline void init(int n)
	{
		f=new int[n+5];
		clear(n);
	}
	inline int find(int x)
	{
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline void merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(x&1) f[x]=y;else f[y]=x;
	}
};

struct DSU
{
	int *f;
	int *depth;
	int *sz;
	inline void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			f[i]=i;
			depth[i]=1;
			sz[i]=1;
		}
	}
	inline void init(int n)
	{
		f=new int[n+5];
		depth=new int [n+5];
		sz=new int [n+5];
		clear(n);
	}
	inline int find(int x)
	{
		return (f[x]==x?x:f[x]=find(f[x]));
	}
	inline int getSize(int x)
	{
		return sz[find(x)];
	}
	inline int merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return false;
		if(depth[x]>depth[y])
		{
			f[y]=x;
			sz[x]+=sz[y];
		}
		else if(depth[y]>depth[x])
		{
			f[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			sz[y]+=sz[x];
			f[x]=y;
			depth[y]++;
		}
		return true;
	}
};
using namespace std;
int n,m;
int a[100005];
int b[100005];
vector <pair<int,pii> > vSort;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",b+i);
	}
	ll tot=0;
	int sz,x;
	DSU dsu;
	dsu.init(n+m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&sz);
		while(sz--)
		{
			scanf("%d",&x);
			x--;
			vSort.push_back(mp(a[i]+b[x],mp(i,x+n)));
			tot+=a[i]+b[x];
		}
	}
	sort(all(vSort));
	reverse(all(vSort));
	int s,y;
	for(auto &e:vSort)
	{
		s=e.first;
		x=e.second.first;
		y=e.second.second;
		if(dsu.merge(x,y)) tot-=s;
	}
	cout<<tot<<endl;
	return 0;
}