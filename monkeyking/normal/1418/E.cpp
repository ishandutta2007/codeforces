//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/combinatorics>
//#include <self/ModInt>
//using namespace std;
//using namespace combinatorics;
//int n,m;
//int d[200005];
//int sum[200005];
//
//int getsum(int l,int r)
//{
//	int s=(r?sum[r-1]:0)-(l?sum[l-1]:0);
//	chmod(s,mod);
//	return s;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	init(0,mod);
//	cin>>n>>m;
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",d+i);
//	}
//	sort(d,d+n);
//	sum[0]=d[0];
//	for(int i=1;i<n;i++)
//	{
//		sum[i]=add(sum[i-1],d[i]);
//	}
//	int a,b;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&a,&b);
//		int la=lower_bound(d,d+n,b)-d;
//		int ra=n;
//		int lb=0;
//		int rb=la;
//		ModInt <mod> Sa=getsum(la,ra);
//		ModInt <mod> Sb=getsum(lb,rb);
//		ModInt <mod> sa=ra-la;
//		if(sa.x-a<0)
//		{
//			puts("0");
//			continue;
//		}
//		else
//		{
//			printf("%d\n",(Sa*(sa-a)/sa+Sb*(sa+1-a)/(sa+1)).x);
//		}
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
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
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
#endif

#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
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

template <typename T>
ostream & operator << (ostream & cout,set <T> s)
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
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
}

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
using namespace combinatorics;
int n,m;
int d[200005];
int sum[200005];

int getsum(int l,int r)
{
	int s=(r?sum[r-1]:0)-(l?sum[l-1]:0);
	chmod(s,mod);
	return s;
}

int main()
{
//	freopen("input.txt","r",stdin);
	init(0,mod);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",d+i);
	}
	sort(d,d+n);
	sum[0]=d[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=add(sum[i-1],d[i]);
	}
	int a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		int la=lower_bound(d,d+n,b)-d;
		int ra=n;
		int lb=0;
		int rb=la;
		ModInt <mod> Sa=getsum(la,ra);
		ModInt <mod> Sb=getsum(lb,rb);
		ModInt <mod> sa=ra-la;
		if(sa.x-a<0)
		{
			puts("0");
			continue;
		}
		else
		{
			printf("%d\n",(Sa*(sa-a)/sa+Sb*(sa+1-a)/(sa+1)).x);
		}
	}
	return 0;
}